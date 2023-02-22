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


/*
                                                            Algorithm
                                                          ______________

Start
Declare a structure Employee with members emp_id, emp_name, total_salary and next pointer
Declare a global pointer variable head of Employee type and initialize it to NULL
Declare functions insert_employee_details(), display_employee_details(), display_highest_and_lowest_salary() and identify_employee_with_salary()
In insert_employee_details() function:
a. Allocate memory for a new employee using malloc()
b. Take employee details (emp_id, emp_name, total_salary) as input from user
c. Set next pointer of new_employee to NULL
d. If head is NULL, set head to new_employee
e. Else, traverse the list till the end and set the next pointer of last node to new_employee
In display_employee_details() function:
a. Display employee details in tabular format
In display_highest_and_lowest_salary() function:
a. Traverse the list and keep track of highest and lowest salary employees
b. Display details of highest and lowest salary employees in tabular format
In identify_employee_with_salary() function:
a. Traverse the list and identify employees with salary Rs.10000/
b. Display details of employees with salary Rs.10000/ in tabular format
In main() function:
a. Display menu options
b. Take choice as input from user
c. If choice is 1, call insert_employee_details() function
d. If choice is 2, call display_employee_details() function
e. If choice is 3, call display_highest_and_lowest_salary() function
f. If choice is 4, call identify_employee_with_salary() function
g. If choice is 5, exit the program
h. If choice is invalid, display error message
End

*/
