#include <bits/stdc++.h>

using namespace std;

class Point
{
private:
    int x, y;

public:
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    ~Point() {}
    Point(const Point &t)
    {
        this->x = t.x, this->y = t.y;
    }
    Point &operator=(const Point &t)
    {
        this->x = t.x, this->y = t.y;
    }

    void print() { printf("(%d, %d)\n", this->x, this->y); }
};

class Matrix
{
private:
    int row, col;
    int **G;

public:
    static Point ANS;

public:
    Matrix() {}
    ~Matrix() { delete[] G; }
    Matrix(const Matrix &t)
    {
        this->row = t.row, this->col = t.col;

        if (this->G == nullptr)
        {
            this->G = new int *[this->row + 1];
            for (int i = 1; i <= this->row; i++)
                this->G[i] = new int[this->col + 1];
        }
        for (int i = 1; i <= t.row; i++)
            for (int j = 1; j <= t.col; j++)
                this->G[i][j] = t.G[i][j];
    }
    Matrix &operator=(const Matrix &t)
    {
        this->row = t.row, this->col = t.col;

        if (this->G == nullptr)
        {
            this->G = new int *[this->row + 1];
            for (int i = 1; i <= this->row; i++)
                this->G[i] = new int[this->col + 1];
        }

        for (int i = 1; i <= t.row; i++)
            for (int j = 1; j <= t.col; j++)
                this->G[i][j] = t.G[i][j];
    }

public:
    void set_Element();
    void sort();                       // sort the Matrix form upper_left to button_right
    bool Bruteforce_search(int x);     //force_search x from the Matrix
    bool Binary_search(int x);         //binary_search x from the Matrix,row by row
    bool Spacereduction_search(int x); //binary_search x from the Matrix, one -> four

private:
    bool SearchforSRs(int x, int left, int right, int up, int down);
};
Point tmp(0, 0);
Point Matrix::ANS = tmp;

void Matrix::set_Element()
{
    //printf("Please input the row and column of the Matrix:\n");
    scanf("%d%d", &this->row, &this->col);

    if (this->G != nullptr)
        delete[] G;

    this->G = new int *[this->row + 1];
    for (int i = 0; i <= this->row; i++)
        this->G[i] = new int[this->col + 1];

    //printf("Please input the element of the Matrix");
    for (int i = 1; i <= this->row; i++)
        for (int j = 1; j <= this->col; j++)
            scanf("%d", &this->G[i][j]);
}
void Matrix::sort()
{
    //TODO: Matrix sort
}
bool Matrix::Bruteforce_search(int x)
{
    for (int i = 1; i <= this->row; i++)
    {
        for (int j = 1; j <= this->col; j++)
        {
            if (this->G[i][j] == x)
            {
                Point rep(i, j);
                ANS = rep;
                return true;
            }
        }
    }

    return false;
}
bool Matrix::Binary_search(int x)
{
    //because the Matrix has been sorted
    //row by row

    for (int i = 1; i <= this->row; i++)
    {
        int l = 1, r = this->col;

        while (l <= r)
        {
            int mid = (l + r) >> 1;

            if (this->G[i][mid] == x)
            {
                Point rep(i, mid);
                ANS = rep;
                return true;
            }

            (this->G[i][mid] > x) ? r = mid - 1 : l = mid + 1;
        }
    }

    return false;
}
bool Matrix::SearchforSRs(int x, int left, int right, int up, int down)
{
    if (left > right || up > down)
        return false;
    if (this->G[up][left] > x || this->G[down][right] < x)
        return false;
    int row, mid;
    row = up;
    mid = (left + right) / 2;
    while (row <= down && x >= this->G[row][mid])
    {
        if (x == this->G[row][mid])
        {
            Point rep(row, mid);
            //ANS = rep;
            return true;
        }
        row = row + 1;
    }
    return this->SearchforSRs(x, left, mid - 1, row, down) || this->SearchforSRs(x, mid + 1, right, up, row - 1);
}
bool Matrix::Spacereduction_search(int x)
{
    return this->SearchforSRs(x, 1, this->col, 1, this->row);
}

void Solve()
{
    //freopen("output.txt", "w", stdout);

    Matrix M;
    M.set_Element();

    int toFind;
    scanf("%d", &toFind);

    if (M.Bruteforce_search(toFind))
    {
        printf("After bruteforce search, we find %d at ", toFind);
        Matrix::ANS.print();
    }
    if (M.Binary_search(toFind))
    {
        printf("After binary search, we find %d at ", toFind);
        Matrix::ANS.print();
    }
    if (M.Spacereduction_search(toFind))
    {
        printf("After Space reduction search , we find %d at ", toFind);
        Matrix::ANS.print();
    }

    // Point Ans;
    // Ans = M.Bruteforce_search(toFind);
    // printf("After Bruteforce_search, We find the number at ");
    // Ans.print();

    // Ans = M.Binary_search1(toFind);
    // printf("After Binary_search row by row, We find the number at ");
    // Ans.print();

    // Ans = M.Binary_search2(toFind);
    // printf("After Binary_search one to four, We find the number at ");
    // Ans.print();
}

int main()
{
    Solve();

    return 0;
}

/*
5 5
2 4 7 8 9
3 5 8 9 10
6 6 10 12 18
7 8 13 16 22
9 24 25 31 33
12
*/
/*
bool search(int (&p)[M][N],int target,int left,int right,int up,int down)
{
    if(left>right||up>down)
        return false;
    if(p[up][left]>target||p[down][right]<target)
        return false;
    int row,mid;
    row=up;
    mid=(left+right)/2;
    while(row<=down && target>=p[row][mid])
    {
        if(target==p[row][mid])
            return true;
        row=row+1;
    }
    return search(p,target,left,mid-1,row,down)||search(p,target,mid+1,right,up,row-1);
}
*/
