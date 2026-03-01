#include <stdio.h>
#include <string.h>

// Define the structure
struct student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    // Create and initialize a student struct
    struct student s1 = {"John", 20, 3.5};

    // Create a pointer to the struct
    struct student *ptr = &s1;

    // Print using pointer to structure
    printf("Before Update:\n");
    printf("Name: %s\n", ptr->name);     // same as (*ptr).name
    printf("Age: %d\n", ptr->age);
    printf("GPA: %.1f\n", ptr->gpa);

    // Update struct using pointer
    strcpy(ptr->name, "Alex");
    ptr->age = 21;
    ptr->gpa = 4.0;

    // Print again to see the changes
    printf("\nAfter Update:\n");
    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);
    printf("GPA: %.1f\n", ptr->gpa);

    return 0;
}
