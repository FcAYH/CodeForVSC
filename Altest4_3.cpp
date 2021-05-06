#include <bits/stdc++.h>

using namespace std;

class Point
{
private:
    int x, y;

public:
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point &t) { this->x = t.x, this->y = t.y; }
    Point &operator=(const Point &t)
    {
        this->x = t.x, this->y = t.y;
        return *this;
    }

public:
    void Setx(int x) { this->x = x; }
    void Sety(int y) { this->y = y; }
    void SetXY(int x, int y) { this->x = x, this->y = y; }
    int Getx() { return this->x; }
    int Gety() { return this->y; }
};

class ChessKeyBoard
{
private:
    int k;
    int row;
    int **G;
    Point stain;

public:
    static int Nowid;

public:
    ChessKeyBoard() {}
    ~ChessKeyBoard() { delete[] G; }
    ChessKeyBoard(const ChessKeyBoard &t)
    {
        this->k = t.k, this->row = t.row;
        if (this->G == nullptr)
        {
            this->G = new int *[this->row + 1];
            for (int i = 0; i <= this->row; i++)
                this->G[i] = new int[this->row + 1];
        }

        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->row; j++)
                this->G[i][j] = t.G[i][j];
    }
    ChessKeyBoard &operator=(const ChessKeyBoard &t)
    {
        this->k = t.k, this->row = t.row;
        if (this->G == nullptr)
        {
            this->G = new int *[this->row + 1];
            for (int i = 0; i <= this->row; i++)
                this->G[i] = new int[this->row + 1];
        }

        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->row; j++)
                this->G[i][j] = t.G[i][j];
        return *this;
    }

public:
    void SetElement();
    void Coloring();
    void Print();

private:
    /*
    st means the position of the stain in the subproblem that the current function deals with;
    k means the keyboard's size is 2^k.
    */
    void SolveColoring(Point st, int left, int right, int up, int down, int k);
    void SetNewStain(Point st, Point &stLU, Point &stLD, Point &stRU, Point &stRD, int midx, int midy);
};
int ChessKeyBoard::Nowid = 1;

void ChessKeyBoard::SetElement()
{
    scanf("%d", &this->row);
    this->G = new int *[this->row + 1];
    for (int i = 0; i <= this->row; i++)
        this->G[i] = new int[this->row + 1];
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->row; j++)
            this->G[i][j] = 0;

    int tmp = 1;
    this->k = 0;
    while (!(tmp & this->row))
        tmp <<= 1, this->k++;

    //printf("<%d>\n", this->k);

    int x, y;
    scanf("%d%d", &x, &y);
    this->stain.Setx(x), this->stain.Sety(y);
}
void ChessKeyBoard::SetNewStain(Point st, Point &stLU, Point &stLD, Point &stRU, Point &stRD, int midx, int midy)
{
    stLU.SetXY(midx - 1, midy - 1);
    stLD.SetXY(midx, midy - 1);
    stRU.SetXY(midx - 1, midy);
    stRD.SetXY(midx, midy);

    //printf("<%d, %d>\n", st.Getx(), st.Gety());
    //check the location of st
    if (st.Getx() < midx && st.Gety() < midy) //leftup
    {
        this->G[midx - 1][midy] = Nowid;
        this->G[midx][midy - 1] = Nowid;
        this->G[midx][midy] = Nowid;
        stLU = st;
    }
    else if (st.Getx() >= midx && st.Gety() < midy) //leftdown
    {
        this->G[midx - 1][midy] = Nowid;
        this->G[midx - 1][midy - 1] = Nowid;
        this->G[midx][midy] = Nowid;
        stLD = st;
    }
    else if (st.Getx() < midx && st.Gety() >= midy) //rightup
    {
        this->G[midx][midy - 1] = Nowid;
        this->G[midx - 1][midy - 1] = Nowid;
        this->G[midx][midy] = Nowid;
        stRU = st;
    }
    else //rightdown
    {
        this->G[midx - 1][midy] = Nowid;
        this->G[midx - 1][midy - 1] = Nowid;
        this->G[midx][midy - 1] = Nowid;
        stRD = st;
    }
    Nowid++;
}
void ChessKeyBoard::SolveColoring(Point st, int left, int right, int up, int down, int k)
{
    if (k == 1)
    {
        for (int i = up; i <= down; i++)
            for (int j = left; j <= right; j++)
                if (i != st.Getx() || j != st.Gety())
                    this->G[i][j] = Nowid;
        Nowid++;
        return;
    }
    else
    {
        int midx = up + pow(2, k - 1), midy = left + pow(2, k - 1);

        Point stLU, stLD, stRU, stRD;

        SetNewStain(st, stLU, stLD, stRU, stRD, midx, midy);

        SolveColoring(stLU, left, midy - 1, up, midx - 1, k - 1);
        SolveColoring(stLD, left, midy - 1, midx, down, k - 1);
        SolveColoring(stRU, midy, right, up, midx - 1, k - 1);
        SolveColoring(stRD, midy, right, midx, down, k - 1);
    }
}
void ChessKeyBoard::Coloring()
{
    this->SolveColoring(this->stain, 0, this->row - 1, 0, this->row - 1, this->k);
}
void ChessKeyBoard::Print()
{
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->row; j++)
            printf("%4d", this->G[i][j]);
        puts("");
    }
}

void Solve()
{
    ChessKeyBoard chessKB;
    chessKB.SetElement();
    chessKB.Coloring();
    chessKB.Print();
}

int main()
{
    Solve();

    return 0;
}
/*
4
0 1

8
3 5
*/
