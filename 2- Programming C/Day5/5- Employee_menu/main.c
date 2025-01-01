#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MyLibrary.h>

#define MAX_EMPLOYEES 5

// Define a structure to store employee information
typedef struct {
    int id;
    char name[100];
    float salary;
    float bonus;
    float deduction;
    int isActive; // A flag to indicate if the employee is active or deleted
} Employee;

// Function prototypes
Employee AddNewEmployee();
void DisplayEmployee(Employee emp);
void DisplayAllEmployees(Employee employees[], int size);
void DeleteEmployee(Employee employees[], int size);
void DeleteAllEmployees(Employee employees[], int size);

int main()
{
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int current_selection = 0; // current_selection menu index
    int flag = 0; // Flag to control the menu loop
    char ch;
    char menu[6][12] = { "New", "Display", "Display All", "Delete", "Delete All", "Exit" };
    int i; // Loop variable

    // Initialize all employees as inactive
    for (i = 0; i < MAX_EMPLOYEES; i++) {
        employees[i].isActive = 0;
    }

    do {
        textattr(0X07);  // NormalBrush
        clrscr();

        // Display the menu
        for (i = 0; i < 6; i++) {
            if (current_selection == i)
                textattr(0X70);  // HighlightedBrush
            else
                textattr(0X07);  // NormalBrush

            gotoxy(15, 4 * i + 3);
            printf("%s\n", menu[i]);
        }

        ch = getche();
        switch (ch)
        {
            case -32:  // Extended Keys
            case 0:
            case 224:
            ch = getche();
            switch (ch)
            {
                case 72:  // Up
                    current_selection--;
                    if (current_selection < 0) current_selection = 5; // Wrap around to the last option
                    break;

                case 80:  // Down
                    current_selection++;
                    if (current_selection > 5) current_selection = 0; // Wrap around to the first option
                    break;

                case 71:  // Home
                    current_selection = 0;
                    break;

                case 79:  // End
                    break;
            }
            break;

            case 27:  // Esc
                flag = 1; // Exit the menu
                break;

            case 13:  // Enter
                clrscr(); // Clear screen on selection
                switch (current_selection) {
                    case 0: // New Employee
                        if (employeeCount < MAX_EMPLOYEES)
                        {
                            employees[employeeCount] = AddNewEmployee();
                            employees[employeeCount].isActive = 1;
                            employeeCount++;
                            printf("Employee added successfully.\n");
                        } else
                        {
                            printf("Maximum employee limit reached. Cannot add more employees.\n");
                        }
                        break;

                    case 1: // Display Employee
                        if (employeeCount > 0)
                        {
                            int empID;
                            printf("Enter Employee ID to display: ");
                            scanf("%d", &empID);
                            int found = 0;
                            for (i = 0; i < employeeCount; i++)
                            {
                                if (employees[i].isActive && employees[i].id == empID)
                                {
                                    DisplayEmployee(employees[i]);
                                    found = 1;
                                    break;
                                }
                            }

                            if (!found)
                            {
                                printf("Employee with ID %d not found.\n", empID);
                            }

                        }
                        else
                        {
                            printf("No employees to display.\n");
                        }
                        break;

                    case 2: // Display All Employees
                        DisplayAllEmployees(employees, employeeCount);
                        break;

                    case 3: // Delete Employee
                        DeleteEmployee(employees, employeeCount);
                        break;

                    case 4: // Delete All Employees
                        DeleteAllEmployees(employees, employeeCount);
                        employeeCount = 0; // Reset employee count
                        break;

                    case 5: // Exit
                        flag = 1; // Exit the menu
                        break;
                }
                getche(); // Wait for user input before returning to the menu
                break;
        }
    } while (flag == 0);

    return 0;
}

// Function to add a new employee
Employee AddNewEmployee() {
    Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    getchar(); // To consume the newline character left by scanf

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

// Function to display an employee's details
void DisplayEmployee(Employee emp) {
    printf("\nEmployee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
    printf("Bonus: %.2f\n", emp.bonus);
    printf("Deduction: %.2f\n", emp.deduction);
    printf("Net Salary: %.2f\n", emp.salary + emp.bonus - emp.deduction);
}

// Function to display all employees
void DisplayAllEmployees(Employee employees[], int size) {
    int found = 0; // Flag to check if any employee is active
    int i; // Loop variable

    printf("\nDisplaying all employees:\n");
    for (i = 0; i < size; i++) {
        if (employees[i].isActive) {
            DisplayEmployee(employees[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No employees to display.\n");
    }
}

// Function to delete a specific employee by ID
void DeleteEmployee(Employee employees[], int size) {
    int id; // ID to delete
    int i; // Loop variable

    printf("Enter the Employee ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < size; i++) {
        if (employees[i].isActive && employees[i].id == id)
        {
            employees[i].isActive = 0;
            employees[i].id = -1;
            printf("Employee with ID %d deleted successfully.\n", id);
            return;
        }
    }

    printf("Employee with ID %d not found.\n", id);
}

// Function to delete all employees
void DeleteAllEmployees(Employee employees[], int size) {
    int i; // Loop variable

    for (i = 0; i < size; i++) {
        employees[i].isActive = 0;
    }
    printf("All employees have been deleted.\n");
}
