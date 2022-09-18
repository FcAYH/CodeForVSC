#include <iostream>
#include<iomanip>
using namespace std;
const int N=20;
int a[N][N];
int main ()
{
	int n;
	cout<<"2019113048  曾宇晴"<<endl;
	cout<<"请输入正方形层数：";
	cin>>n;
	int t,i,j,start=0,end=2*n-1,num=1;
	
	for (i=0,j=0,t=1;t<=n;t++,i++,j++,start++,end--)
	{
		for (i=start;i<end;i++)
			a[i][j]=num; 
		for(j=start;j<end;j++)
			a[i][j]=num;
		for (i=end;i>start;i--)
			a[i][j]=num;
		for (j=end;j>start;j--)
			a[i][j]=num;
		num++;
		if (start==end)
			a[i][j]=num;
	}
	for (i=0;i<2*n-1;i++)
		{ 
			for (j=0;j<2*n-1;j++)
				cout<<setw(5)<<a[i][j];
				cout<<endl;
		}

	system("pause");
}
