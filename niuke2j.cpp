#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int n,k,to[100007],vis[100007],ans[100007];
int a[100007];
vector<int>ho;
void dfs(int p){
	vis[p]=1;
	ho.push_back(a[p]);
	if(vis[to[p]]==0){
		dfs(to[p]);
	}
}
void go(){
	int len=ho.size(),inv;
	for(int i=0;i<len;i++){
		if((ll)i*k%len==1){
			inv=i;
			break;
		}
	}
	for(int i=0;i<len;i++){
		ans[ho[i]]=ho[(i+inv)%len];
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		to[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		ho.clear();
		if(vis[i]==0){
			dfs(i);
			go();
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}puts("");
    system("pause");
    return 0;
}