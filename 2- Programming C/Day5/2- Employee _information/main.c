#include <stdio.h>

// Define a structure to store employee information
typedef struct {
    int id;
    char name[100];
    float salary;
    float bonus;
    float deduction;
} Emp_Struct;


float calculateNetSalary(Emp_Struct emp)
{
    return emp.salary + emp.bonus - emp.deduction;
}

int main() {
    Emp_Struct emp;

    // Input employee information
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    getchar();

    printf("Enter Employee Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);

    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    printf("Enter Employee Bonus: ");
    scanf("%f", &emp.bonus);

    printf("Enter Employee Deduction: ");
    scanf("%f", &emp.deduction);

    // Calculate the net salary
    float netSalary = calculateNetSalary(emp);

    // Display employee information along with net salary
    printf("\nEmployee ID: %d\n", emp.id);
    printf("Employee Name: %s", emp.name);
    printf("Net Salary: %.2f\n", netSalary);

    getch();

    return 0;
}
