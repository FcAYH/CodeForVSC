#include <bits/stdc++.h>
#include <windows.h>
/*
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
*/

using namespace std;

typedef long long ll;

const int MaxSize = 31;
//The message of each student
struct Student
{
    char name[10];       //The name of the student
    char id[10];         //The student id
    double score[7];     //The score of each subject
    double sum, average; //The sum score of all the subjects and the average score of all the subjects
    char S_degree[7];    //The degree of each subject-->A for [90,100],B for [80,89],C for [70,79],D for [60,69],E for [0,59]
    void Init();
    void Getdegree(int I, double s);
    void Print(int N_sub);
};

void Student::Init()
{
    strcpy(this->name, "");
    strcpy(this->id, "");
    strcpy(this->S_degree, "");
    for (int i = 0; i < 7; i++)
        this->score[i] = 0.0;
    this->sum = 0.0, this->average = 0.0;
}
void Student::Getdegree(int I, double s)
{
    if (s >= 90)
        this->S_degree[I] = 'A';
    else if (s >= 80)
        this->S_degree[I] = 'B';
    else if (s >= 70)
        this->S_degree[I] = 'C';
    else if (s >= 60)
        this->S_degree[I] = 'D';
    else
        this->S_degree[I] = 'E';
}
void Student::Print(int N_sub)
{
    printf("  -------------------------\n");
    printf("  |     Name: %10s  |\n", this->name);
    printf("  |       Id: %10s  |\n", this->id);
    for (int i = 1; i <= N_sub; i++)
        printf("  |        %d: %10.1lf  |\n", i, this->score[i]);
    printf("  |      Sum: %10.1lf  |\n", this->sum);
    printf("  |  Average: %10.1lf  |\n", this->average);
    printf("  -------------------------\n");
    puts("");
}

//Student Achievement Management System
struct SAMS
{
    int N_stu, N_sub;   //The number of students and subjects in this system
    Student *stu;       //The array to storage the message of students
    double Sum[7];      //The sum score of each subject
    double Average[7];  //The average score of each subject
    int N_Degree[7][6]; //The amount of student of each degree
    int Init();
    void Insert();
    void Sort(int flag);
    void Calc(int flag);
    void Search(char *ch, int flag);
    void Analysis();
    void Print();
    void WriteToFile();
    void ReadFromFile();
    int ReadInitFromFile();
};

void Print_Id(int x)
{
    if (x == 1 || x == 21)
        printf(" This is the %dst student's information: \n", x);
    else if (x == 2 || x == 22)
        printf(" This is the %dnd student's information: \n", x);
    else if (x == 3 || x == 23)
        printf(" This is the %drd student's information: \n", x);
    else
        printf(" This is the %dth student's information: \n", x);
}
int SAMS::Init()
{
    this->N_stu = 0, this->N_sub = 0;
    this->stu = NULL;
    for (int i = 0; i < 7; i++)
        this->Sum[i] = 0.0, this->Average[i] = 0.0;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 6; j++)
            this->N_Degree[i][j] = 0;

    printf("Read data from file? (input 'Yes' for yes, others for no)\n");
    char ch[10];
    strcpy(ch, "");
    scanf("%s", ch);
    if (!strcmp(ch, "Yes"))
        return 1;

    printf(" Please input the amount of students (0 < n < 30) and subjects (0 < m < 7): ");
    scanf("%d%d", &this->N_stu, &this->N_sub);
    while (this->N_stu < 1 || this->N_stu > 30 || this->N_sub < 0 || this->N_sub > 6)
    {
        printf(" The number you input is invalid, please input again: ");
        scanf("%d%d", &this->N_stu, &this->N_sub);
    }

    printf(" Is creating for you");
    for (int i = 1; i <= 6; i++)
        printf("."), Sleep(180);
    printf("Complate\n");
    Sleep(300);
    printf("\n Now the SAMS has %d students and %d subjects.\n", this->N_stu, this->N_sub);
    printf(" You can add new students then, but you can't add new subjects.\n");

    printf("\n Now input the Initial data:");

    this->stu = (Student *)malloc(sizeof(Student) * (MaxSize));

    puts("");
    for (int i = 1; i <= this->N_stu; i++)
    {
        this->stu[i].Init();

        Print_Id(i);
        printf(" Please input the student's name: ");
        scanf("%s", this->stu[i].name);

        printf(" Please input the student's id: ");
        scanf("%s", this->stu[i].id);

        printf(" Please input scores of each subject: \n");
        for (int j = 1; j <= this->N_sub; j++)
        {
            printf(" %d: ", j);
            scanf("%lf", &this->stu[i].score[j]);
            this->stu[i].sum += this->stu[i].score[j];
            this->Sum[j] += this->stu[i].score[j];
            this->stu[i].Getdegree(j, this->stu[i].score[j]);
            this->N_Degree[j][this->stu[i].S_degree[j] - 'A' + 1]++;
        }
        this->stu[i].average = this->stu[i].sum / this->N_sub;

        puts("");
    }

    for (int i = 1; i <= this->N_sub; i++)
        this->Average[i] = this->Sum[i] / this->N_stu;

    return 0;
}
void SAMS::Insert()
{
    if (this->N_stu == 30)
    {
        printf("Fail to add new data, the SAMS is full!\n");
        return;
    }
    this->N_stu++;
    this->stu[this->N_stu].Init();

    Print_Id(this->N_stu);
    printf(" Please input the student's name: ");
    scanf("%s", this->stu[this->N_stu].name);

    printf(" Please input the student's id: ");
    scanf("%s", this->stu[this->N_stu].id);

    printf(" Please input scores of each subject: \n");
    for (int j = 1; j <= this->N_sub; j++)
    {
        printf(" %d: ", j);
        scanf("%lf", &this->stu[this->N_stu].score[j]);
        this->stu[this->N_stu].sum += this->stu[this->N_stu].score[j];
        this->Sum[j] += this->stu[this->N_stu].score[j];
        this->stu[this->N_stu].Getdegree(j, this->stu[this->N_stu].score[j]);
        this->N_Degree[j][this->stu[this->N_stu].S_degree[j] - 'A' + 1]++;
    }
    this->stu[this->N_stu].average = this->stu[this->N_stu].sum / this->N_sub;

    puts("");

    for (int i = 1; i <= this->N_sub; i++)
        this->Average[i] = this->Sum[i] / this->N_stu;
}
void SAMS::Sort(int flag)
{
    switch (flag)
    {
    case 0:
    {
        for (int i = 1; i < this->N_stu; i++)
        {
            for (int j = i + 1; j <= this->N_stu; j++)
            {
                if (this->stu[j].sum > this->stu[i].sum)
                {
                    Student t = this->stu[i];
                    this->stu[i] = this->stu[j], this->stu[j] = t;
                }
            }
        }
        break;
    }
    case 1:
    {
        for (int i = 1; i < this->N_stu; i++)
        {
            for (int j = i + 1; j <= this->N_stu; j++)
            {
                if (this->stu[j].sum < this->stu[i].sum)
                {
                    Student t = this->stu[i];
                    this->stu[i] = this->stu[j], this->stu[j] = t;
                }
            }
        }
        break;
    }
    case 2:
    {
        for (int i = 1; i < this->N_stu; i++)
        {
            for (int j = i + 1; j <= this->N_stu; j++)
            {
                if (strcmp(this->stu[j].id, this->stu[i].id) < 0)
                {
                    Student t = this->stu[i];
                    this->stu[i] = this->stu[j], this->stu[j] = t;
                }
            }
        }
        break;
    }
    case 3:
    {
        for (int i = 1; i < this->N_stu; i++)
        {
            for (int j = i + 1; j <= this->N_stu; j++)
            {
                if (strcmp(this->stu[j].name, this->stu[i].name) < 0)
                {
                    Student t = this->stu[i];
                    this->stu[i] = this->stu[j], this->stu[j] = t;
                }
            }
        }
        break;
    }
    }
    this->Print();
}
void SAMS::Calc(int flag)
{
    if (!flag)
    {
        printf("    SUBJECT     SUM   AVERAGE\n");
        for (int i = 1; i <= this->N_sub; i++)
            printf("          %d: %8.1lf%8.2lf\n", i, this->Sum[i], this->Average[i]);
        puts("");
    }
    else
    {
        printf("         ID          SUM   AVERAGE\n");
        for (int i = 1; i <= this->N_stu; i++)
            printf("    %12s: %8.1lf%8.2lf\n", this->stu[i].id, this->stu[i].sum, this->stu[i].average);
        puts("");
    }
}
void SAMS::Search(char *ch, int flag)
{
    int Not_find = 1;
    if (flag)
    {
        for (int i = 1; i <= this->N_stu; i++)
        {
            if (!strcmp(this->stu[i].id, ch))
            {
                Not_find = 0;
                printf(" This is the %s student:\n", ch);
                this->stu[i].Print(this->N_sub);
            }
        }
    }
    else
    {
        for (int i = 1; i <= this->N_stu; i++)
        {
            if (!strcmp(this->stu[i].name, ch))
            {
                Not_find = 0;
                printf(" This is the %s student:\n", ch);
                this->stu[i].Print(this->N_sub);
            }
        }
    }
    if (Not_find)
        printf(" Sorry, we failed to find the %s student in the SAMS.\n", ch);
}
void SAMS::Analysis()
{
    printf(" This is the statistic analysis for each course:\n");
    printf(" A for [90,100],B for [80,89],C for [70,79],D for [60,69],E for [0,59]\n");
    puts("");
    printf("     SUBJECT    A   B   C   D   E\n");
    for (int i = 1; i <= this->N_sub; i++)
    {
        printf("         %d:  ", i);
        for (int j = 1; j <= 5; j++)
        {
            printf("%4d", this->N_Degree[i][j]);
        }
        puts("");
    }
    puts("");
}
void SAMS::Print()
{
    int length = 10 + 12 + this->N_sub * 8 + 8 + 8 + 4 + 2;
    printf("    ");
    for (int i = 1; i <= length; i++)
        putchar('-');
    puts("");

    printf("    |     NAME        ID     ");
    for (int i = 1; i <= this->N_sub; i++)
        printf("    %d   ", i);
    printf("   SUM   AVERAGE  |\n");

    for (int i = 1; i <= this->N_stu; i++)
    {
        printf("    |  %10s%12s", this->stu[i].name, this->stu[i].id);
        for (int j = 1; j <= this->N_sub; j++)
            printf("%8.1lf", this->stu[i].score[j]);
        printf("%8.1lf%8.2lf  |", this->stu[i].sum, this->stu[i].average);
        puts("");
    }

    printf("    |         SUM:           ");
    for (int i = 1; i <= this->N_sub; i++)
        printf("%8.1lf", this->Sum[i]);
    puts("                  |");

    printf("    |     AVERAGE:           ");
    for (int i = 1; i <= this->N_sub; i++)
        printf("%8.2lf", this->Average[i]);
    puts("                  |");

    printf("    ");
    for (int i = 1; i <= length; i++)
        putchar('-');
    puts("\n");
}
void SAMS::WriteToFile()
{
    printf(" Please input the name of the file you write to: ");
    char ch[30];
    strcpy(ch, "");
    scanf("%s", ch);
    FILE *fp = fopen(ch, "w");

    int length = 10 + 12 + this->N_sub * 8 + 8 + 8 + 4 + 2;
    fprintf(fp, "    ");
    for (int i = 1; i <= length; i++)
        fprintf(fp, "-");
    fprintf(fp, "\n");

    fprintf(fp, "    |     NAME        ID     ");
    for (int i = 1; i <= this->N_sub; i++)
        fprintf(fp, "    %d   ", i);
    fprintf(fp, "   SUM   AVERAGE  |\n");

    for (int i = 1; i <= this->N_stu; i++)
    {
        fprintf(fp, "    |  %10s%12s", this->stu[i].name, this->stu[i].id);
        for (int j = 1; j <= this->N_sub; j++)
            fprintf(fp, "%8.1lf", this->stu[i].score[j]);
        fprintf(fp, "%8.1lf%8.2lf  |", this->stu[i].sum, this->stu[i].average);
        fprintf(fp, "\n");
    }

    fprintf(fp, "    |         SUM:           ");
    for (int i = 1; i <= this->N_sub; i++)
        fprintf(fp, "%8.1lf", this->Sum[i]);
    fprintf(fp, "                  |\n");

    fprintf(fp, "    |     AVERAGE:           ");
    for (int i = 1; i <= this->N_sub; i++)
        fprintf(fp, "%8.2lf", this->Average[i]);
    fprintf(fp, "                  |\n");

    fprintf(fp, "    ");
    for (int i = 1; i <= length; i++)
        fprintf(fp, "-");
    fprintf(fp, "\n\n");

    fclose(fp);

    printf(" ");
    for (int i = 1; i <= 6; i++)
        printf("."), Sleep(180);
    printf(" Write data complate.\n\n");
}
void SAMS::ReadFromFile()
{
    printf(" Please input the name of the file you read from: ");
    char ch[30];
    strcpy(ch, "");
    scanf("%s", ch);
    FILE *fp = fopen(ch, "r");

    int cnt = 0;
    fscanf(fp, "%d", &cnt);
    for (int i = 1; i <= cnt; i++)
    {
        if (this->N_stu == 30)
        {
            printf("Fail to add new data, the SAMS is full!");
            return;
        }
        this->N_stu++;
        this->stu[this->N_stu].Init();

        fscanf(fp, "%s", this->stu[this->N_stu].name);
        fscanf(fp, "%s", this->stu[this->N_stu].id);

        for (int j = 1; j <= this->N_sub; j++)
        {
            fscanf(fp, "%lf", &this->stu[this->N_stu].score[j]);
            this->stu[this->N_stu].sum += this->stu[this->N_stu].score[j];
            this->Sum[j] += this->stu[this->N_stu].score[j];
            this->stu[this->N_stu].Getdegree(j, this->stu[this->N_stu].score[j]);
            this->N_Degree[j][this->stu[this->N_stu].S_degree[j] - 'A' + 1]++;
        }
        this->stu[this->N_stu].average = this->stu[this->N_stu].sum / this->N_sub;

        for (int i = 1; i <= this->N_sub; i++)
            this->Average[i] = this->Sum[i] / this->N_stu;
    }

    fclose(fp);

    printf(" ");
    for (int i = 1; i <= 6; i++)
        printf("."), Sleep(180);
    printf(" Read data complate.\n\n");
}
int SAMS::ReadInitFromFile()
{
    printf(" Please input the name of the file you read from: ");
    char ch[30];
    scanf("%s", ch);
    FILE *fp = fopen(ch, "r");
    fscanf(fp, "%d%d", &this->N_stu, &this->N_sub);
    if (this->N_stu < 1 || this->N_stu > 30 || this->N_sub < 0 || this->N_sub > 6)
    {
        printf(" The data in the file is invalid, please check your file!\n");
        Sleep(200);
        printf(" If you have checked your file, press any key to reopen file.\n");
        return 0;
    }

    this->stu = (Student *)malloc(sizeof(Student) * (MaxSize));

    for (int i = 1; i <= this->N_stu; i++)
    {
        this->stu[i].Init();

        fscanf(fp, "%s", this->stu[i].name);
        fscanf(fp, "%s", this->stu[i].id);

        for (int j = 1; j <= this->N_sub; j++)
        {
            fscanf(fp, "%lf", &this->stu[i].score[j]);
            this->stu[i].sum += this->stu[i].score[j];
            this->Sum[j] += this->stu[i].score[j];
            this->stu[i].Getdegree(j, this->stu[i].score[j]);
            this->N_Degree[j][this->stu[i].S_degree[j] - 'A' + 1]++;
        }
        this->stu[i].average = this->stu[i].sum / this->N_sub;
    }

    for (int i = 1; i <= this->N_sub; i++)
        this->Average[i] = this->Sum[i] / this->N_stu;

    fclose(fp);

    printf(" ");
    for (int i = 1; i <= 6; i++)
        printf("."), Sleep(180);
    printf(" Read data complate.\n\n");

    return 1;
}
void Print_Menu()
{
    puts("");
    printf("  -----------------------------------------------------------------\n");
    printf("  | 1:  Input record.                                             |\n");
    printf("  | 2:  Calculate total and average score of every course.        |\n");
    printf("  | 3:  Calculate total and average score of every student.       |\n");
    printf("  | 4:  Sort in descending order by total score of every student. |\n");
    printf("  | 5:  Sort in ascending order by total score of every student.  |\n");
    printf("  | 6:  Sort in ascending order by number.                        |\n");
    printf("  | 7:  Sort in dictionary order by name.                         |\n");
    printf("  | 8:  Search by number.                                         |\n");
    printf("  | 9:  Search by name.                                           |\n");
    printf("  | 10: Statistic analysis for every course.                      |\n");
    printf("  | 11: List record.                                              |\n");
    printf("  | 12: Write to a file.                                          |\n");
    printf("  | 13: Read from a file.                                         |\n");
    printf("  | 14: Show menu again.                                          |\n");
    printf("  | 0:  Exit from the system.                                     |\n");
    printf("  -----------------------------------------------------------------\n");
    puts("");
}
void Print_Welcome_desk()
{
    char Wel[56] = " Welcome to this Student Achievement Management System!";
    for (int i = 0; i < 56; i++)
        putchar(Wel[i]), Sleep(50);

    puts("\n");
    for (int i = 0; i < 30; i++)
        printf(" ");

    char Name[19] = "Made by Gong Aolin";
    for (int i = 0; i < 19; i++)
        putchar(Name[i]), Sleep(50);

    printf("\n");
    for (int i = 0; i < 30; i++)
        printf(" ");

    char Id[23] = "Student Id: 2019113035";
    for (int i = 0; i < 23; i++)
        putchar(Id[i]), Sleep(50);

    puts("\n");
    char Next[49] = " Now you can press any key to call out the menu.";
    for (int i = 0; i < 49; i++)
        putchar(Next[i]), Sleep(50);

    getchar();

    Print_Menu();
}
void Print_Goodbye_desk()
{
    puts("");
    char Goodbye[39] = " Thank you to use this SAMS, goodbye!\n";
    for (int i = 0; i < 39; i++)
        putchar(Goodbye[i]), Sleep(50);
    Sleep(500);
}

void Solve()
{
    Print_Welcome_desk();

    SAMS Sams;
    int flag = Sams.Init();
    if (flag)
        while (!Sams.ReadInitFromFile())
            getchar();

    while (1)
    {
        printf(" Please enter your choice: ");

        int operate;
        scanf("%d", &operate);

        int ExitFlag = 0;
        switch (operate)
        {
        case 1:
            Sams.Insert();
            break;
        case 2:
            Sams.Calc(0);
            break;
        case 3:
            Sams.Calc(1);
            break;
        case 4:
            Sams.Sort(0);
            break;
        case 5:
            Sams.Sort(1);
            break;
        case 6:
            Sams.Sort(2);
            break;
        case 7:
            Sams.Sort(3);
            break;
        case 8:
        {
            printf(" Please input the number: ");
            char ch[20];
            scanf("%s", ch);
            Sams.Search(ch, 1);
            break;
        }
        case 9:
        {
            printf(" Please input the name: ");
            char ch[20];
            scanf("%s", ch);
            Sams.Search(ch, 0);
            break;
        }
        case 10:
            Sams.Analysis();
            break;
        case 11:
            Sams.Print();
            break;
        case 12:
            Sams.WriteToFile();
            break;
        case 13:
            Sams.ReadFromFile();
            break;
        case 14:
            Print_Menu();
            break;
        case 0:
            ExitFlag = 1;
            break;
        }
        if (ExitFlag)
            break;
    }

    Print_Goodbye_desk();
}

int main()
{
    Solve();

    return 0;
}
/*

3 3
AAA 1 90 89 92
BBB 2 82 87 79
CCC 3 67 83 90

*/
