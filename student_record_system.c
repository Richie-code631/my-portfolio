#include <stdio.h>
#include <string.h>

//This defines the structure to represent a student
struct Student {
    char name[100]; // Full name of the student
    int age;        // Age of the student
    float gpa;      // Grade Point Average of the student
    int studentID;  // Unique identifier for the student
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void searchStudentByID(struct Student students[], int count);
void displayStudents(struct Student students[], int count);

int main() {
    struct Student students[50]; // This is an array to store up to 50 student records
    int count = 0;               // This shows the current number of students in the system
    int choice;                  // Variable to store user's menu choice

    do {
        //To display menu for choosing
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Search Student by ID\n");
        printf("3. Display All Students\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count); // Call function to add a student
                break;
            case 2:
                searchStudentByID(students, count); // Call function to search for a student by his/her ID
                break;
            case 3:
                displayStudents(students, count); // Call function to display all students
                break;
            case 4:
                printf("Exiting the program. Bye/Ciao!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new student
void addStudent(struct Student students[], int *count) {
    // Check if the student list is full
    if (*count >= 50) {
        printf("Student list is full. Cannot add more students.\n");
        return;
    }

    printf("\nEnter student details:\n");
    printf("Name: ");
    getchar(); // Clear the input buffer
    fgets(students[*count].name, 100, stdin); // Read student name
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0'; // Remove newline character

    printf("Age: ");
    scanf("%d", &students[*count].age); // Read student age

    printf("GPA: ");
    scanf("%f", &students[*count].gpa); // Read student GPA

    printf("Student ID: ");
    scanf("%d", &students[*count].studentID); // Read student ID

    (*count)++; // Increment the student count
    printf("Student added successfully!\n");
}

// Function to search for a student by ID
void searchStudentByID(struct Student students[], int count) {
    int id;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &id); // Read the ID to search for

    // Goes through the student array to find the matching ID
    for (int i = 0; i < count; i++) {
        if (students[i].studentID == id) {
            printf("\nStudent found:\n");
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("GPA: %.2f\n", students[i].gpa);
            printf("Student ID: %d\n", students[i].studentID);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id); // If no match is found
}

// Function to display all students
void displayStudents(struct Student students[], int count) {
    // Check if there are any students to display
    if (count == 0) {
        printf("\nNo students to display.\n");
        return;
    }

    printf("\nStudent Records:\n");
    // Iterate through the student array and print details of each student
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("Student ID: %d\n", students[i].studentID);
    }

    return 0;
}
