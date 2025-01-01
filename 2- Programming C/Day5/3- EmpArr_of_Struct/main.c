#include <stdio.h>

// Define a structure to store employee information
typedef struct
{
    int id;
    char name[100];
    float salary;
    float bonus;
    float deduction;

} EmpArr_of_Struct;


// Function to take employee input
EmpArr_of_Struct inputEmployee()
{
    EmpArr_of_Struct emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    getchar();

    printf("Enter Employee Name: ");
    gets(emp.name);

    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    printf("Enter Employee Bonus: ");
    scanf("%f", &emp.bonus);

    printf("Enter Employee Deduction: ");
    scanf("%f", &emp.deduction);

    return emp;
}

// Function to display employee data
void displayEmployee(EmpArr_of_Struct emp)
{
    printf("\nEmployee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
    printf("Bonus: %.2f\n", emp.bonus);
    printf("Deduction: %.2f\n", emp.deduction);
    printf("Net Salary: %.2f\n", emp.salary + emp.bonus - emp.deduction);
}


int main() {
    int i;
    EmpArr_of_Struct employees[5];

    // Input data for 5 employees
    printf("Enter details for 5 employees:\n");
    for (i = 0; i < 5; i++) {
        printf("\nEmployee %d:\n", i + 1);
        employees[i] = inputEmployee();
    }

    // Display the information for all employees
    printf("\nDisplaying details of 5 employees:\n");
    for (i = 0; i < 5; i++) {
        printf("\nEmployee %d:\n", i + 1);
        displayEmployee(employees[i]);
    }

    return 0;
}
