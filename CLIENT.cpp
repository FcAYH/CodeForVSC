#include "CLIENT.h"
int CLIENT :: ClientNum = 0;
char CLIENT :: ServerName[200] = {0};
void CLIENT :: ChangeServerName(const char ch[])
{
    int len = strlen(ch);
    for(int i = 0; i < len; i++)    ServerName[i] = ch[i];
    ServerName[len] = '\0';
}
void CLIENT :: print(){printf("%d %s\n",ClientNum,ServerName);}
CLIENT :: CLIENT(int t){a = t; ClientNum++;}
CLIENT :: CLIENT(CLIENT &p){a = p.a;}