#include <bits/stdc++.h>

using namespace std;

const int MaxSize = 10005;

struct LNode
{
    int val;
    LNode *next;
};

class CharList
{
private:
    LNode *Head;
    int Length;

private:
    void DeleteNodes(LNode *temp);

public:
    CharList(){};
    CharList(int x) : Length(x)
    {
        this->Head = new LNode;
    }
    ~CharList()
    {
        if (this->Head != nullptr)
            DeleteNodes(this->Head);
    }

public:
    void GetElement(char *data);
    void Delete(int pos);
    LNode *GetHead() { return this->Head; }
    void Print();
    int GetLength() { return this->Length; };
};

void CharList::DeleteNodes(LNode *temp)
{
    if (temp->next != nullptr)
        DeleteNodes(temp->next);

    delete temp;
}
void CharList::GetElement(char *data)
{
    LNode *p = new LNode();

    this->Head->val = data[1] - '0';
    this->Head->next = p;
    p->val = data[2] - '0';
    for (int i = 3; i <= this->Length; i++)
    {
        LNode *temp = new LNode();
        temp->val = data[i] - '0';
        temp->next = nullptr;
        p->next = temp;
        p = temp;
    }
}
void CharList::Delete(int pos)
{
    //printf("<%d>\n ", pos);
    if (pos == 1)
    {
        LNode *temp = new LNode();
        temp = this->Head;
        this->Head = this->Head->next;
        delete temp;
        this->Length--;
        return;
    }
    int nowPos = 1;
    for (LNode *i = this->Head; i != nullptr; i = i->next)
    {
        if (nowPos == pos - 1)
        {
            LNode *temp = new LNode();
            temp = i->next;

            i->next = temp->next;

            delete temp;
            this->Length--;
            break;
        }

        nowPos++;
    }
}
void CharList::Print()
{
    int flag = 0;
    for (LNode *i = this->Head; i != nullptr; i = i->next)
    {
        if (!flag && i->val == 0)
            continue;
        else
        {
            flag = 1;
            printf("%d", i->val);
        }
    }
    puts("");
}

void Solve()
{
    int k;
    char number[MaxSize];
    scanf("%s", number + 1);
    scanf("%d", &k);

    int length = strlen(number + 1);
    CharList *charList = new CharList(length);
    charList->GetElement(number);

    //charList->Print();

    while (k--)
    {
        //printf("[%d]\n", k);
        int nowPos = 1, flag = 1;
        for (LNode *i = charList->GetHead(); i->next != nullptr; i = i->next, nowPos++)
        {
            //printf("%d ", i->val);
            //printf(" \n %d %d \n", i->val, i->next->val);
            if (i->val > i->next->val)
            {
                charList->Delete(nowPos);
                flag = 0;
                break;
            }
        }
        //puts("");

        if (flag)
            charList->Delete(charList->GetLength());

        //charList->Print();
    }

    charList->Print();
}

int main()
{
    Solve();

    return 0;
}

/*
1432219
3

823141
2

8436592007534
10
*/
