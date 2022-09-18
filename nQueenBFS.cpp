#include <iostream>
#include <queue>
using namespace std;
// 用来判断棋盘上的点(row, column) 是否安全
bool canPut(int row, int column, int *answer);
int main()
{
    int queens;
    //	current表示当前层数，activated表示当前活结点所在的column
    int activated = 0;
    int current = 0;
    cout << "输入皇后数：";
    cin >> queens;
    if (queens <= 3)
    {
        cout << "no solution！";
        return 0;
    }
    //	每一层都有一个队列保存可生成结点
    queue<int> Queue[queens];
    //	棋盘 ,改用answer保存
    //	int chessboard[queens][queens] = {0};
    //	answer作为辅助数组，下标表示层级，值表示column ,也就是棋盘
    int answer[queens] = {-1};
    //	第一层肯定全为活结点
    for (int i = 0; i < queens; i++)
    {
        Queue[0].push(i);
    }
    while (1)
    {
        //		当前层级没有安全位置或者回退
        if (Queue[current].empty())
        {
            current--;
            continue;
        }
        //		找不到解(边界问题)
        if (current == -1)
        {
            cout << "no solution!";
            break;
        }
        //		取当前层级队列头为活结点并弹出队列
        activated = Queue[current].front();
        Queue[current].pop();
        //		假设这就是答案，放置在棋盘里(存到answer中 )
        answer[current] = activated;
        //		current++找下一层可以安全放置的点加入队列
        current++;
        for (int i = 0; i < queens; i++)
        {
            if (canPut(current, i, (int *)answer))
            {
                Queue[current].push(i);
            }
        }
        //		如果当前层级是最后一层而且层级有结点，即已经找到解
        if (current == queens - 1 && !Queue[current].empty())
        {
            //			只需要最后一层的第一个结点作为答案即可
            answer[queens - 1] = Queue[current].front();
            for (int i = 0; i < queens; i++)
            {
                cout << answer[i] + 1 << " ";
            }
            break;
        }
    }
    return 0;
}
bool canPut(int row, int column, int *answer)
{
    int putActivated;
    for (int i = 0; i < row; i++)
    {
        //		当前层级 i 的棋子所在位置
        //      即棋盘上的（i, putActivated）点有棋子
        putActivated = answer[i];
        //		判断结点row, column可不可以生成，即皇后是否会互相攻击
        //		i - putActivated == row - column 即45度线相交
        //		column + row == putActivated + i 即135度线相交
        //		 putActivated == column 即同列
        //		行是不会相交的
        if (i - putActivated == row - column || column + row == putActivated + i || putActivated == column)
        {
            return false;
        }
    }
    return true;
}
