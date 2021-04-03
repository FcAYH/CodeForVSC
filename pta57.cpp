#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,sex,hight,weight;
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) 
    {
        scanf("%d%d%d",&sex,&hight,&weight);
        if(sex)
        {
            if(hight < 130) printf("duo chi yu! ");
            else if(hight == 130) printf("wan mei! ");
            else printf("ni li hai! ");
            
            if(weight < 27) printf("duo chi rou!\n");
            else if(weight == 27) printf("wan mei!\n");
            else printf("shao chi rou!\n");
        }
        else
        {
            if(hight < 129) printf("duo chi yu! ");
            else if(hight == 129) printf("wan mei! ");
            else printf("ni li hai! ");
            
            if(weight < 25) printf("duo chi rou!\n");
            else if(weight == 25) printf("wan mei!\n");
            else printf("shao chi rou!\n");
        }
    }
    system("pause");
    return 0;
}
/*
如果太矮了，输出：duo chi yu!（多吃鱼）；
如果太瘦了，输出：duo chi rou!（多吃肉）；
如果正标准，输出：wan mei!（完美）；
如果太高了，输出：ni li hai!（你厉害）；
如果太胖了，输出：shao chi rou!（少吃肉）.

国家给出了 8 岁男宝宝的标准身高为 130 厘米、标准体重为 27 公斤；8 岁女宝宝的标准身高为 129 厘米、标准体重为 25 公斤。
*/