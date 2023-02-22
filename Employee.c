#include <stdio.h>
#include <stdlib.h>
void main()
{
    struct Employee
    {
        int empId;
        char empName[30];
        float totalSalary;
    };

    struct Node
    {
        struct Employee employee;
        struct Node *address;
    };

    struct Node *START = NULL;
    struct Node *PTR = NULL;
    struct Node *NEWNODE = NULL;
    struct Node *PREV = NULL;

    int choice;

    do
    {
        printf("\n\n-------- Employee Menu ----------");
        printf("\n1). Insert Employee Details");
        printf("\n2). Display Details in Tabular Form");
        printf("\n3). Find Highest and Lowest Salary Employee");
        printf("\n4). Identify Employee with Salary Rs.10000");
        printf("\n5). Exit");

        printf("\n\nEnter Your Choice: ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:

            NEWNODE = (struct Node *)malloc(sizeof(struct Node));
            NEWNODE->address = NULL;

            struct Employee inputEmployee;

            printf("\nEnter the Employee Name: ");
            scanf(" %[^\n]s", inputEmployee.empName);

            printf("\nEnter the Employee ID: ");
            scanf(" %d", &inputEmployee.empId);

            printf("\nEnter the Employee Salary: ");
            scanf(" %f", &inputEmployee.totalSalary);

            NEWNODE->employee = inputEmployee;

            if (START == NULL)
            {
                START = NEWNODE;
                PTR = NEWNODE;
            }
            else
            {
                PTR->address = NEWNODE;
                PTR = NEWNODE;
            }

            printf("\nData Insertion Completed!");
            break;
        case 2:

            if (START == NULL)
            {
                printf("\nNo Elements to Display");
                break;
            }
            else
            {
                printf("| Employee Name       | ID  | Salary          |\n");
                printf("|---------------------|-----|-----------------|\n");
            }

            PTR = START;
            int index = 1;

            while (PTR->address != NULL)
            {
                printf("| %s          | %d  | %f              |\n",
                       PTR->employee.empName, PTR->employee.empId, PTR->employee.totalSalary);
                PTR = PTR->address;
            }

            printf("| %s          | %d  | %f              |\n",
                   PTR->employee.empName, PTR->employee.empId, PTR->employee.totalSalary);

            break;

        case 3:
            struct Employee highestSalary = START->employee;
            struct Employee lowestSalary = START->employee;

            if (START == NULL)
            {
                printf("\nNo Elements to Display");
                break;
            }

            PTR = START;

            while (PTR->address != NULL)
            {
                if (PTR->employee.totalSalary > highestSalary.totalSalary)
                    highestSalary = PTR->employee;

                if (PTR->employee.totalSalary < lowestSalary.totalSalary)
                    lowestSalary = PTR->employee;

                PTR = PTR->address;
            }

            if (PTR->employee.totalSalary > highestSalary.totalSalary)
                highestSalary = PTR->employee;

            if (PTR->employee.totalSalary < lowestSalary.totalSalary)
                lowestSalary = PTR->employee;

            printf("\nEmployee With Highest Salary\n\n");
            printf("| Employee Name       | ID  | Salary          |\n");
            printf("|---------------------|-----|-----------------|\n");
            printf("| %s          | %d  | %f              |\n",
                   highestSalary.empName, highestSalary.empId, highestSalary.totalSalary);

            printf("\nEmployee With Lowest Salary\n\n");
            printf("| Employee Name       | ID  | Salary          |\n");
            printf("|---------------------|-----|-----------------|\n");
            printf("| %s          | %d  | %f              |\n",
                   lowestSalary.empName, lowestSalary.empId, lowestSalary.totalSalary);

            break;

        case 4:

            if (START == NULL)
            {
                printf("\nNo Elements to Display");
                break;
            }
            else
            {
                printf("\nEmployees With Salary 10000\n\n");
                printf("| Employee Name       | ID  | Salary          |\n");
                printf("|---------------------|-----|-----------------|\n");
            }

            PTR = START;

            while (PTR->address != NULL)
            {
                if (PTR->employee.totalSalary == 10000)
                {
                    printf("| %s          | %d  | %f              |\n",
                           PTR->employee.empName, PTR->employee.empId, PTR->employee.totalSalary);

                    PTR = PTR->address;
                }
            }
            if (PTR->employee.totalSalary == 10000)
            {
                printf("| %s          | %d  | %f              |\n",
                       PTR->employee.empName, PTR->employee.empId, PTR->employee.totalSalary);
            }

            break;

        default:
            printf("\nKindly Enter a Valid Choice!");
        }

    } while (choice != 5);
}
