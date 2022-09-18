#include <iostream>
#include <iomanip>
using namespace std;

double Salary[30];
double Fee[30];

int main()
{
    int i = 1;
    cin >> Salary[1];
    while (Salary[i] > 0)
    {
        if (Salary[i] < 5000)
        {
            Fee[i] = 0;
        }
        else if (Salary[i] >= 5000 && Salary[i] < 8000)
        {
            Fee[i] = (Salary[i] - 5000) * 0.03;
        }
        else if (Salary[i] >= 8000 && Salary[i] <= 17000)
        {
            Fee[i] = (Salary[i] - 8000) * 0.1 + 3000 * 0.03;
        }
        else
        {
            Fee[i] = (Salary[i] - 17000) * 0.2 + (9000) * 0.1 + 3000 * 0.03;
        }
        cout << i << " " << Salary[i] << " " << Fee[i] << endl;
        cin >> Salary[++i];
    }

    i--;
    double ans = 0.0;
    for (int j = 1; j <= i; j++)
        ans += Fee[j];
    cout << i << " " << ans << endl;
    return 0;
}
