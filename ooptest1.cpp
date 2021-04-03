#include <iostream>

using namespace std;

int f(int x)
{

    switch (x)
    {

    case 0:
        throw 1.2;
        break;

    case 1:
        throw 5;
        break;

    case 2:
        throw 7;
        break;

    case 3:
        throw 3.0f;
        break;

    case 4:
        throw 4L;
        break;

    default:
        throw "error";
    }
}

int main()
{

    int k;

    while (1)
    {

        try
        {

            cin >> k;

            f(k);

            cout << "gohere!";
        }

        catch (double)
        {
            cout << "A" << endl;
        }

        catch (int e)
        {
            if (e == 5)
                cout << "B1" << endl;
            if (e == 7)
                cout << "B2" << endl;
        }

        catch (float)
        {
            cout << "C" << endl;
        }

        catch (long)
        {
            cout << "D" << endl;
        }

        catch (...)
        {
            cout << "E" << endl;
            return 0;
        }
    }
}
