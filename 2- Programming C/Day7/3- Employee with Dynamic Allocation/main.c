#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MyLibrary.h>

typedef struct {
    int id;
    char name[100];
    float salary;
    float bonus;
    float deduction;
    int isActive; // Flag to indicate if the employee is active or deleted
} Employee;

// Function prototypes
Employee AddNewEmployee();
void DisplayEmployee(Employee emp);
void DisplayAllEmployees(Employee employees[], int size);
void DeleteEmployee(Employee employees[], int size);
void DeleteAllEmployees(Employee employees[], int size);

int main()
{
    Employee* employees;
    int employeeCount = 0;
    int maxEmployees;
    int current_selection = 0; // Menu index
    int flag = 0; // Flag to control the menu loop
    char ch;
    char menu[6][12] = { "New", "Display", "Display All", "Delete", "Delete All", "Exit" };
    int i;

    // Prompt the user to enter the number of employees
    printf("Enter the maximum number of employees: ");
    scanf("%d", &maxEmployees);

    // Dynamically allocate memory for the employees array
    employees = (Employee*)malloc(maxEmployees * sizeof(Employee));
    if (employees == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit if memory allocation fails
    }

    // Initialize all employees as inactive
    for (i = 0; i < maxEmployees; i++) {
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

        ch = getch();
        switch (ch) {
            case -32:  // Extended Keys
            case 0:
            case 224:
                ch = getch();
                switch (ch) {
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
                        if (employeeCount < maxEmployees) {
                            int index;
                            printf("Enter index (0 to %d) to add employee (or -1 to cancel): ", maxEmployees - 1);
                            scanf("%d", &index);

                            if (index >= 0 && index < maxEmployees) {
                                employees[index] = AddNewEmployee();
                                employees[index].isActive = 1;
                                if (index == employeeCount) {
                                    employeeCount++; // Increment count if we added at the end
                                }
                                printf("Employee added successfully.\n");
                            } else if (index == -1) {
                                printf("Canceled adding employee.\n");
                            } else {
                                printf("Invalid index. Please try again.\n");
                            }
                        } else {
                            printf("Maximum employee limit reached. Cannot add more employees.\n");
                        }
                        break;

                    case 1: // Display Employee
                        {
                            int empID;
                            printf("Enter Employee ID to display (or -1 to display by index): ");
                            scanf("%d", &empID);
                            if (empID == -1) {
                                int index;
                                printf("Enter employee index (0 to %d) to display: ", maxEmployees - 1);
                                scanf("%d", &index);
                                if (index >= 0 && index < maxEmployees && employees[index].isActive) {
                                    DisplayEmployee(employees[index]);
                                } else {
                                    printf("Invalid index or employee not found.\n");
                                }
                            } else {
                                int found = 0;
                                for (i = 0; i < maxEmployees; i++) {
                                    if (employees[i].isActive && employees[i].id == empID) {
                                        DisplayEmployee(employees[i]);
                                        found = 1;
                                        break;
                                    }
                                }
                                if (!found) {
                                    printf("Employee with ID %d not found.\n", empID);
                                }
                            }
                        }
                        break;

                    case 2: // Display All Employees
                        DisplayAllEmployees(employees, maxEmployees);
                        break;

                    case 3: // Delete Employee
                        DeleteEmployee(employees, maxEmployees);
                        break;

                    case 4: // Delete All Employees
                        DeleteAllEmployees(employees, maxEmployees);
                        employeeCount = 0; // Reset employee count
                        break;

                    case 5: // Exit
                        textattr(0X07);  // NormalBrush
                        clrscr();
                        flag = 1;
                        break;
                }
                getch();
                break;
        }
    } while (flag == 0);


    // Free the dynamically allocated memory for employees
    free(employees);

    return 0;
}

// Function to add a new employee
Employee AddNewEmployee() {
    Employee emp;

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

    printf("Displaying all employees:\n");
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
    int id;
    int i;

    printf("Enter the Employee ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < size; i++) {
        if (employees[i].isActive && employees[i].id == id) {
            employees[i].isActive = 0;
            printf("Employee with ID %d deleted successfully.\n", id);
            return;
        }
    }

    printf("Employee with ID %d not found.\n", id);
}

// Function to delete all employees
void DeleteAllEmployees(Employee employees[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        employees[i].isActive = 0;
    }
    printf("All employees have been deleted.\n");
}
