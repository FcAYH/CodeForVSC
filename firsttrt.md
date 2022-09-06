# C++类的实现

> 事情是因为面试的时候，被问到了一些奇奇怪怪的用法，所以来研究了一下C++中类对象在内存中是怎么存储的。

* [ ] 这一块内容挺多的，有必要单独开个文章写

## malloc和new的区别

先记录一下malloc和new的区别：

1. malloc返回一个void\*类型的指针，需要自己进行强转。而new根据指定类型返回指定类型的指针。

2. malloc需要自己指定分配内存的大小，以参数形式传入。而new不需要。

3. malloc是函数，而new是运算符。new可以被重载。

4. malloc不会调用类的构造函数，而new会调用。同理，free不会调用类的析构函数，而delete会。

## 奇怪的写法

> 当然了，个人认为这一系列的写法，都不符合标准，不管是在学习还是在生产中都应该避免使用上述写法。但是有时研究一下这些写法的结果，会让我们对C++的理解更加深刻。

首先我们定义类如下：

```cpp
class CppTest
{
public:
    int val;

    CppTest(int x) : val(x) {}
    ~CppTest()
    {
        cout << "free" << endl;
    }

    void FunA()
    {
        cout << "Hello world" << endl;
    }

    void FunB()
    {
        cout << "Good night" << endl;
    }
};

int main()
{
    CppTest* p = new CppTest(2);

    p->FunA();

    delete p;

    return 0;
}
```

### 在析构函数中delete

如果我们魔改一下析构函数，改成下面这样子：

```cpp
    ~CppTest()
    {
        cout << "free" << endl;
        delete this;
    }
```

会发生什么事？

### 在成员函数中delete

如果我们魔改一下FunA，改成下面这样子：

```cpp
    void FunA()
    {
        delete this;
        cout << "Hello world" << endl;
    }
```

会发生什么事？

如果再魔改一下，这样子：

```cpp
    void FunA()
    {
        delete this;
        cout << "Hello world" << endl;

        FunB();
    }
```

又会有怎么样的输出呢？

### 空指针能否调用函数？

如果我们修改调用方式如下：

```cpp
int main()
{
    CppTest* p = nullpter;
    p->FunA();

    return 0;
}
```

能否成功调用？

## 解答

**1\. 当在析构函数中调用delete时，会触发循环递归，导致程序无法正常退出**

首先delete会调用析构函数，故而`delete p;`会跳转到我们的`~CppTest()`，然而我们在`~CppTest()`中又触发`delete this`，就导致了又跳转回了`~CppTest()`，反复循环递归。

**2\. 在成员函数中delete，并不会中断成员函数的运行，也不会影响再调用其他成员函数**

即在`FunA()`中，运行`delete this;`，程序仍然会照常输出`Hello world`，同时也能正常调用`FunB()`，输出`Good night`。

这个现象我们就能够猜测，对于一个类对象，该对象本身并不会存储成员函数相关的内容，所以即使`delete this;`，CppTest类型的指针依然可以毫无障碍的调用到FunA，FunB。

**3\. nullpter也可以调用到成员函数**

即`CppTest* p = nullpter;`，`p->FunA();`可以输出`Hello world`。

基于这个现象我们基本就可以猜测，在C++中，成员函数的实现，应该就是在调用时，隐含着将自身作为参数传入。只要是CppTest类型的指针，不管有没有真正实例化一个对象，都可以调用成员函数。

## 再做几组测试

### delete后调用val

```cpp
int main()
{
    CppTest* p = new CppTest(2);
    delete p;
    cout << p->val << endl;
}
```

### 添加一个虚函数，并在delete后调用

```cpp
...
    virtual void FunVirtual()
    {
        cout << "Virtual function" << endl;
    }
...

int main()
{
    CppTest* p = new CppTest(2);
    delete p;
    p->FunVirtual();
}
```

### nullpter调用用val和虚函数

```cpp
int main()
{
    CppTest* p = nullpter;
    cout << p->val << endl;
    // p->FunVirtual(); 这两行二选一执行一下
}
```

### 验证

前两个运行一下我们发现，delete了之后，仍然可以正确输出val的值，以及调用虚函数可以看到输出了`Virtual function`。这里我们能够猜测，delete仅仅只是标记了这块内存可以被再次使用，并没有清理这块内存的内容。

第三个我们发现运行起来会崩溃，结合之前的猜测，我们可以得知，类对象内存中包含的就是类的成员变量，同时还有虚函数表指针。

想要去验证的话自然是应该去看编译后的汇编代码，以及代码运行时的内存分配情况。

## 结论

1. 类中成员函数保存在代码段中，只要是该类型的指针，就可以调用该类型的普通成员函数。实例化一个对象时，占用内存包括指向虚函数表的指针以及成员变量。

2. delete并不会清理内存，只是会标记该区域可再次被分配，同理new操作本身也不会清理内存。故而我们最好在构造函数中完成对各个参数的初始化。

3. 如果类中包含虚函数，则内存最开始是一个指向虚函数表的指针。而虚函数表的存储，在不同的编译器中不太相同，微软的编译器将其放在了常量数据段，有的则在只读数据段。（从网上查阅，以后自己去确认一下看看）




