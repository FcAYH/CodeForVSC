#include <bits/stdc++.h>

using namespace std;

int l, r, m, n;
vector<vector<int>> Map;
vector<int> tmp;

class Solution
{
private:
    inline vector<vector<int>> build2D_up(vector<vector<int>> &matrix, int index, int width, int length)
    {
        vector<vector<int>> matrix1(index, vector<int>(length - index));
        for (int i = 0; i < index; i++)
        {
            for (int j = index; j < length; j++)
            {
                matrix1[i][j - index] = matrix[i][j];
            }
        }
        return matrix1;
    }

    inline vector<vector<int>> build2D_down(vector<vector<int>> &matrix, int index, int width, int length)
    {
        vector<vector<int>> matrix1(width - index, vector<int>(index));
        for (int i = index; i < width; i++)
        {
            for (int j = 0; j < index; j++)
            {
                matrix1[i - index][j] = matrix[i][j];
            }
        }
        return matrix1;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int width = matrix.size();
        if (width == 0 || matrix[0].size() == 0)
            return false;
        int length = matrix[0].size();
        int i;
        for (i = 0; i < min(width, length); i++)
        {
            if (matrix[i][i] == target)
            {
                l = i, r = i;
                return true;
            }
            if (matrix[i][i] > target)
                break;
        }
        vector<vector<int>> matrix1 = build2D_up(matrix, i, width, length);
        vector<vector<int>> matrix2 = build2D_down(matrix, i, width, length);
        return (searchMatrix(matrix1, target) || searchMatrix(matrix2, target));
    }
};

int read_data(int x)
{
    n = x, m = x;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        tmp.clear();
        for (int j = 0; j < m; j++)
        {
            int t;
            t = cnt++;
            tmp.push_back(t);
        }
        Map.push_back(tmp);
    }
    int tar = cnt / 2;
    return tar;
}

int main()
{
    freopen("output.txt", "w", stdout);
    for (int i = 10; i <= 1000; i += 10)
    {
        Solution S;

        int target = read_data(i);
        clock_t start = clock();
        S.searchMatrix(Map, target);
        // if (S.searchMatrix(Map, target))
        //     cout << "true" << endl;
        // else
        //     cout << "false" << endl;
        clock_t end = clock();
        cout << end - start << endl;
    }
    return 0;
}
/*
3 3
1 2 3
4 5 6
7 8 9
10

*/
