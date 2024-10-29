#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each task
typedef struct Task {
    char description[100];
    int priority;
    struct Task* next;
} Task;

Task* head = NULL; // Head of the linked list

// Function to create a new task
Task* createTask(char* description, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->description, description);
    newTask->priority = priority;
    newTask->next = NULL;
    return newTask;
}

// Function to add a task to the list
void addTask(char* description, int priority) {
    Task* newTask = createTask(description, priority);
    if (head == NULL || head->priority > priority) {
        newTask->next = head;
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newTask->next = temp->next;
        temp->next = newTask;
    }
    printf("Task added: %s (Priority: %d)\n", description, priority);
}

// Function to delete a task by description
void deleteTask(char* description) {
    if (head == NULL) {
        printf("No tasks to delete.\n");
        return;
    }
    Task* temp = head;
    Task* prev = NULL;

    // If head node itself holds the task to be deleted
    if (strcmp(head->description, description) == 0) {
        head = head->next;
        free(temp);
        printf("Task deleted: %s\n", description);
        return;
    }

    // Search for the task to be deleted
    while (temp != NULL && strcmp(temp->description, description) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If task was not found
    if (temp == NULL) {
        printf("Task not found: %s\n", description);
        return;
    }

    // Unlink the task from the list
    prev->next = temp->next;
    free(temp);
    printf("Task deleted: %s\n", description);
}

// Function to display all tasks
void displayTasks() {
    if (head == NULL) {
        printf("No tasks available.\n");
        return;
    }

    Task* temp = head;
    printf("\nTo-Do List:\n");
    while (temp != NULL) {
        printf("- %s (Priority: %d)\n", temp->description, temp->priority);
        temp = temp->next;
    }
}

// Main function to drive the program
int main() {
    int choice, priority;
    char description[100];

    while (1) {
        printf("\n--- To-Do List Manager ---\n");
        printf("1. Add Task\n2. Delete Task\n3. View Tasks\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline character
                printf("Enter task priority: ");
                scanf("%d", &priority);
                addTask(description, priority);
                break;
            case 2:
                printf("Enter task description to delete: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline character
                deleteTask(description);
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                printf("Exiting To-Do List Manager.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
