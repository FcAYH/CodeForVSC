// #include <iostream>

// class Singleton
// {
// private:
//     Singleton(){};
//     Singleton(const Singleton &) = delete;
//     Singleton(const Singleton &&) = delete;
//     Singleton &operator=(const Singleton &t) = delete;

// public:
//     static Singleton &getInstance()
//     {
//         static Singleton instance;
//         return instance;
//     }

//     void test()
//     {
//         std::cout << "Testing Singleton" << std::endl;
//     }
// };

// int main()
// {
//     Singleton &instance = Singleton::getInstance();
//     instance.test();
//     return 0;
// }

// #include <iostream>

// class Singleton
// {
// private:
//     static Singleton *instance;
//     Singleton() {}
//     Singleton(const Singleton &) = delete;
//     Singleton &operator=(const Singleton &) = delete;

// public:
//     static Singleton *getInstance()
//     {
//         if (instance == NULL)
//             instance = new Singleton();

//         return instance;
//     }

//     void Test()
//     {
//         std::cout << "Testing Singleton" << std::endl;
//     }
// };

#include <iostream>

class A
{
    int n;
    virtual void print()
    {
        std::cout << n << std::endl;
    }
};

class B
{
    int n;
    void print()
    {
        std::cout << n << std::endl;
    }
};

int main()
{
    std::cout << sizeof(A) << " " << sizeof(B) << std::endl;
}
