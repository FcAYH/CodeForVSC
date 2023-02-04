#include <bits/stdc++.h>

using namespace std;

struct Data
{
    int s, t, rank;
    string relation;
    vector<string> paths;

    string ToString()
    {
        string display;
        display = to_string(s) + " " + to_string(t) + " " + to_string(rank) + "\n";
        display += relation + "\n";
        for (int i = 0; i < paths.size(); i++)
        {
            display += paths[i] + "\n";
        }

        return display;
    }
};

vector<Data> dataVec;

int main()
{
    fstream readFile1;
    fstream readFile2;
    readFile1.open("LH_ReadFile_1.txt", ios::in);
    readFile2.open("LH_ReadFile_2.txt", ios::in);

    int s, t, rank;
    string relation;
    while (!readFile1.eof())
    {
        readFile1 >> s >> t >> rank >> relation;
        Data data;
        data.s = s;
        data.t = t;
        data.rank = rank;
        data.relation = relation;

        string path;
        while (!readFile2.eof() && path.length() <= 1)
        {
            getline(readFile2, path);
        }

        while (!readFile2.eof())
        {
            if (path.length() > 2)
                data.paths.push_back(path);
            else
                break;
            getline(readFile2, path);
        }

        dataVec.push_back(data);
    }

    readFile1.close();
    readFile2.close();

    fstream writeFile;
    writeFile.open("LH_WriteFile_1.txt", ios::out);

    for (int i = 0; i < dataVec.size(); i++)
    {
        writeFile << dataVec[i].ToString() << endl;
    }

    return 0;
}
