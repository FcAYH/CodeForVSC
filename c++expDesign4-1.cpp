//TODO: 输出不对
#include <iostream>
using namespace std;
class Goods
{
private:
    static int num;
    static int AllW;
    int weight;

public:
    Goods() {}
    Goods(int w) : weight(w) { num++, AllW += weight; }
    ~Goods() { num--, AllW -= weight; }
    static int getNum()
    {
        return Goods::num;
    }
    int getWeight()
    {
        return Goods::AllW;
    }
    void Set_element(int x = 0)
    {
        if (x)
            weight = x;
        else
            cin >> weight;
    }
};
int Goods::num = 0;
int Goods::AllW = 0;
int main()
{
    // Goods *Apple;
    // Apple = new Goods(100);

    // for (int i = 1; i <= 99; i++)
    //     Apple[i].Set_element(i);

    Goods apple(10);
    cout << "The weight of apple:" << apple.getWeight() << endl;
    Goods pear(20);
    cout << "The weight of pear:" << pear.getWeight() << endl;
    apple.~Goods();
    cout << "The weight of pear:" << pear.getWeight() << endl;
    Goods orange(30);
    cout << "The weight of orange:" << orange.getWeight() << endl;
    orange.~Goods();
    cout << "The weight of orange:" << orange.getWeight() << endl;
    pear.~Goods();
    cout << "The weight of orange:" << orange.getWeight() << endl;
}
