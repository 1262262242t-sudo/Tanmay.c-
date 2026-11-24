#include <stdio.h>

struct Student
{
    int roll_no;
    char name[50];
    float marks;
};

int main()
{
    struct Student s[100];
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll_no);

        printf("Enter Name: ");
        scanf("%49s", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\n----- STUDENT RESULTS -----\n");

    for(i = 0; i < n; i++)
    {
        printf("\nRoll Number: %d", s[i].roll_no);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f", s[i].marks);

        if(s[i].marks >= 40)
            printf("\nResult: PASS\n");
        else
            printf("\nResult: FAIL\n");
    }

    return 0;
}
