#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int q;
void Solve()
{
    ios::sync_with_stdio(false);
    cin>>s>>q;
    int len=s.size();
    int st=0;
    while(q--) 
    {
        char ch;
        cin>>ch;
        int x;
        cin>>x;
        if(ch=='A') cout<<s[(st+x-1)%len]<<endl;
        else 
        {
            if(x>0) st=(st+x)%len;
            else 
            {
                x=-x;
                st=(st+len-1)%len;
                st=(st-x+1+len)%len;
            }
        }
    }
}
int main() 
{
    Solve();
    system("pause");
    return 0;
}