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
    void sort();                   // sort the Matrix form upper_left to button_right
    bool Bruteforce_search(int x); //force_search x from the Matrix
    bool Binary_search1(int x);    //binary_search x from the Matrix,row by row
    bool Binary_search2(int x);
    void build2D_up(int **matrix, int index, int width, int length);
    void build2D_down(int **matrix, int index, int width, int length); //binary_search x from the Matrix, one -> four
};

void Matrix::set_Element()
{
    printf("Please input the row and column of the Matrix:\n");

    scanf("%d%d", &this->row, &this->col);

    if (this->G != nullptr)
        delete[] G;

    this->G = new int *[this->row + 1];
    for (int i = 0; i <= this->row; i++)
        this->G[i] = new int[this->col + 1];

    printf("Please input the element of the Matrix");
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
                // Point reP(i, j);
                // return reP;
                return true;
            }
        }
    }
}
bool Matrix::Binary_search1(int x)
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
                // Point reP(i, mid);
                // return reP;
                return true;
            }

            if (this->G[i][mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
}

void Matrix::build2D_up(int **matrix, int index, int width, int length)
{
    this->row = width, this->col = length;
    this->G = new int *[this->row + 1];
    for (int i = 0; i <= this->row; i++)
        this->G[i] = new int[this->col + 1];

    for (int i = 1; i < index; i++)
    {
        for (int j = index; j < length; j++)
        {
            this->G[i][j - index] = matrix[i][j];
        }
    }
}

void Matrix::build2D_down(int **matrix, int index, int width, int length)
{
    this->row = width, this->col = length;
    this->G = new int *[this->row + 1];
    for (int i = 0; i <= this->row; i++)
        this->G[i] = new int[this->col + 1];

    for (int i = index; i <= width; i++)
    {
        for (int j = 1; j <= index; j++)
        {
            this->G[i - index][j] = matrix[i][j];
        }
    }
}
bool Matrix::Binary_search2(int x)
{
    int i = 0;
    for (i = 1; i <= min(this->row, this->col); i++)
    {
        if (this->G[i][i] == x)
            return true;

        if (this->G[i][i] > x)
            break;
    }
    Matrix matrix1, matrix2;
    matrix1.build2D_up(this->G, i, this->row, this->col);
    matrix2.build2D_down(this->G, i, this->row, this->col);
    return (matrix1.Binary_search2(x) || matrix2.Binary_search2(x));
}

void Solve()
{
    Matrix M;
    M.set_Element();

    int toFind;
    scanf("%d", &toFind);

    if (M.Bruteforce_search(toFind))
        puts("True");
    if (M.Binary_search1(toFind))
        puts("True");
    if (M.Binary_search2(toFind))
        puts("True");
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
