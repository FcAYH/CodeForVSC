#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string s;
string ans;
int main()
{
	getline(cin,s);
	int len = s.length();
    for(int i = 0;i < len; i++)
    {
        if(s[i] == '6')
        {
            int cnt = 0;
            while(s[i] == '6') cnt++, i++;
            if(cnt > 3&&cnt <= 9) ans += '9';
            else if(cnt > 9) ans += '2', ans += '7';
            else for(int j = 1; j <= cnt; j++) ans += '6';
            i--;
        }
        else ans += s[i];
    }
    cout<<ans;
    system("pause");
	return 0;
}