#include <bits/stdc++.h>

using namespace std;

int l, r;
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

int read_data()
{
    int tar, n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        tmp.clear();
        for (int j = 0; j < m; j++)
        {
            int t;
            scanf("%d", &t);
            tmp.push_back(t);
        }
        Map.push_back(tmp);
    }
    scanf("%d", &tar);
    return tar;
}

int main()
{
    Solution S;

    int target = read_data();

    cout << S.searchMatrix(Map, target) << endl;
    cout << l + 1 << " " << r + 1 << endl;
    return 0;
}
/*
3 3
1 2 3
4 5 6
7 8 9
5
*/
