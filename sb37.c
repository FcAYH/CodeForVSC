#include <stdio.h>
int main()
{
    int score;
    char grade;
    printf("Please input  score:\n");
    scanf("%d", &score);
    if (score < 0 || score > 100)
    {
        printf("Input error!\n");
        return 0;
    }
    else if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'E';
    printf("grade: %c\n", grade);
    return 0;
}
