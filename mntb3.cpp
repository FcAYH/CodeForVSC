#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
void findMaxNumber(char *nums,int k,char *maxNumber) 
{
    int popCount=strlen(nums)-k;
    int i=0;
    int j=-1;
    if(k>0)
    {
        while(nums[i]) 
        {
            while(j>=0&&popCount&&maxNumber[j]<nums[i]) --j,--popCount;
            maxNumber[++j]=nums[i++];
        }
    }
    maxNumber[k] = '\0';
}

void merge(char *num1,char *num2,char* answer) 
{
    int i=0;
    int j=0;
    int answerIdx=0;
    while(num1[i]&&num2[j]) answer[answerIdx++]=strcmp(num1+i,num2+j)>0?num1[i++]:num2[j++]; 
    if(num1[i]) while(answer[answerIdx++]=num1[i++]);
    else while(answer[answerIdx++]=num2[j++]);
}
void Solve()
{
    char num1[305];
    char num2[305];
    int k;
    int t;
    char maxNumber1[305];
    char maxNumber2[305];
    char answer1[305]={'\0'};
    char answer2[305]={'\0'};
    scanf("%d",&t);
    while(t--) 
    {
        scanf("%s%s%d",num1,num2,&k);
        int num1Len=strlen(num1);
        int num2Len=strlen(num2);
        for(int i=0;i<=k;++i) 
        {
            if(num1Len>=i&&num2Len>=k-i)
            {
                findMaxNumber(num1,i,maxNumber1);
                findMaxNumber(num2,k-i,maxNumber2);
                merge(maxNumber1,maxNumber2,strcmp(answer1,answer2)<0?answer1:answer2);
            }
        }
        printf("%s\n",strcmp(answer1,answer2)>0?answer1:answer2);
        memset(answer1,'\0',sizeof(answer1));
        memset(answer2,'\0',sizeof(answer2));
    }
}
int main() 
{
    freopen("merge1.in","r",stdin);
    freopen("merge1.out","w",stdout);
    Solve();
    //system("pause");
    return 0;
}