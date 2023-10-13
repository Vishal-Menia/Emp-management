#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an employee
struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee* next;
};

// Function to create a new employee
struct Employee* createEmployee(int id, const char* name, float salary) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    if (newEmployee == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newEmployee->id = id;
    strncpy(newEmployee->name, name, sizeof(newEmployee->name));
    newEmployee->salary = salary;
    newEmployee->next = NULL;
    return newEmployee;
}

// Function to add a new employee to the linked list
struct Employee* addEmployee(struct Employee* head, int id, const char* name, float salary) {
    struct Employee* newEmployee = createEmployee(id, name, salary);
    newEmployee->next = head;
    return newEmployee;
}

// Function to display all employees in the linked list
void displayEmployees(struct Employee* head) {
    struct Employee* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", current->id, current->name, current->salary);
        current = current->next;
    }
}

// Function to search for an employee by ID
struct Employee* searchEmployee(struct Employee* head, int id) {
    struct Employee* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Employee not found
}

// Function to update employee information
void updateEmployee(struct Employee* employee, const char* name, float salary) {
    strncpy(employee->name, name, sizeof(employee->name));
    employee->salary = salary;
}

// Function to delete an employee by ID
struct Employee* deleteEmployee(struct Employee* head, int id) {
    struct Employee* current = head;
    struct Employee* prev = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head; // Employee not found, no changes
}

// Function to save employees to a file
void saveEmployeesToFile(struct Employee* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open the file for writing.\n");
        return;
    }

    struct Employee* current = head;
    while (current != NULL) {
        fprintf(file, "%d %s %.2f\n", current->id, current->name, current->salary);
        current = current->next;
    }

    fclose(file);
}

// Function to load employees from a file
struct Employee* loadEmployeesFromFile(const char* filename) {
    struct Employee* head = NULL;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return NULL;
    }

    int id;
    char name[50];
    float salary;
    while (fscanf(file, "%d %s %f", &id, name, &salary) == 3) {
        head = addEmployee(head, id, name, salary);
    }
    fclose(file);

    return head;
}

int main() {
    struct Employee* head = NULL;
    char choice;

    // Load employees from a file if the file exists
    head = loadEmployeesFromFile("employees.txt");

    do {
        int id;
        char name[50];
        float salary;

        printf("Enter employee details:\n");
        printf("ID: ");
        scanf("%d", &id);
        printf("Name: ");
        scanf(" %49[^\n]", name);  // Read up to 49 characters (with whitespace)
        printf("Salary: ");
        scanf("%f", &salary);

        head = addEmployee(head, id, name, salary);

        printf("Do you want to add another employee (y/n)? ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nEmployee List:\n");
    displayEmployees(head);

    // Search for an employee
    int searchId;
    printf("Enter the ID of the employee to search: ");
    scanf("%d", &searchId);
    struct Employee* foundEmployee = searchEmployee(head, searchId);
    if (foundEmployee != NULL) {
        printf("Employee found: ID: %d, Name: %s, Salary: %.2f\n", foundEmployee->id, foundEmployee->name, foundEmployee->salary);
    } else {
        printf("Employee not found.\n");
    }

    // Update employee information
    int updateId;
    printf("Enter the ID of the employee to update: ");
    scanf("%d", &updateId);
    struct Employee* employeeToUpdate = searchEmployee(head, updateId);
    if (employeeToUpdate != NULL) {
        char newName[50];
        float newSalary;
        printf("Enter the new name and salary: ");
        scanf(" %49[^\n] %f", newName, &newSalary);
        updateEmployee(employeeToUpdate, newName, newSalary);
        printf("Employee information updated.\n");
    } else {
        printf("Employee not found for updating.\n");
    }

    // Delete an employee
    int deleteId;
    printf("Enter the ID of the employee to delete: ");
    scanf("%d", &deleteId);
    head = deleteEmployee(head, deleteId);
    printf("Employee deleted (if found).\n");

    // Save employees to a file
    saveEmployeesToFile(head, "employees.txt");
    printf("Employee records have been saved to employees.txt.\n");

    // Clean up memory by freeing the linked list
    struct Employee* current = head;
    while (current != NULL) {
        struct Employee* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
