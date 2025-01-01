#include <stdio.h>

// Define a structure to store employee information
typedef struct {
    int id;
    char name[100];
    float salary;
    float bonus;
    float deduction;
} Employee;

// Function prototypes
Employee AddNewEmployee();
void DisplayEmployee(Employee emp);

int main() {
    Employee employees[2]; // Declare an array to hold 5 employees
    int i; // Declare the loop variable outside the loop

    // Input data for 5 employees using AddNewEmployee function
    printf("Enter details for 5 employees:\n");
    for (i = 0; i < 5; i++) {
        printf("\nEmployee %d:\n", i + 1);
        employees[i] = AddNewEmployee();
    }

    // Display the information for all employees using DisplayEmployee function
    printf("\nDisplaying details of 5 employees:\n");
    for (i = 0; i < 2; i++) {
        printf("\nEmployee %d:\n", i + 1);
        DisplayEmployee(employees[i]);
    }

    getch();

    return 0;
}

// Function to add a new employee
Employee AddNewEmployee() {
    Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // To consume the newline character left by scanf

    printf("Enter Employee Name: ");
    gets(emp.name); // Using gets to read the employee's name

    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    printf("Enter Employee Bonus: ");
    scanf("%f", &emp.bonus);

    printf("Enter Employee Deduction: ");
    scanf("%f", &emp.deduction);

    return emp;
}

// Function to display an employee's details
void DisplayEmployee(Employee emp) {
    printf("\nEmployee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
    printf("Bonus: %.2f\n", emp.bonus);
    printf("Deduction: %.2f\n", emp.deduction);
    printf("Net Salary: %.2f\n", emp.salary + emp.bonus - emp.deduction);
}
