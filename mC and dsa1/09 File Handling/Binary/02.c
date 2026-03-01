#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN    18
#define MARKS_COUNT 5

// Student record structure
typedef struct { // **
    int    roll;
    float  per;
    float  marks[MARKS_COUNT];
    char   name[NAME_LEN];
} Student;

// Print a single student's details
void print_student(const Student *s, int idx) {
    printf("\nStudent %d:\n", idx + 1);
    printf(" Name : %s\n", s->name);
    printf(" Roll : %d\n", s->roll);
    printf(" Per  : %.2f\n", s->per);
    printf(" Marks: ");
    for (int i = 0; i < MARKS_COUNT; i++)
        printf("%.2f ", s->marks[i]);
    printf("\n");
}

int main() {
    int       n;
    Student  *arr;
    FILE     *file;

    // 1) Read N and student data
    printf("Number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of students.\n");
        return 1;
    }

    arr = malloc(n * sizeof *arr);
    if (!arr) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter roll, per, %d marks, name for student %d:\n", MARKS_COUNT, i + 1);
        scanf("%d %f", &arr[i].roll, &arr[i].per);
        for (int j = 0; j < MARKS_COUNT; j++)
            scanf("%f", &arr[i].marks[j]);
        scanf("%17s", arr[i].name);
    }

    // 2) Write all records to a binary file
    file = fopen("students.bin", "wb+");
    if (!file) {
        perror("fopen");
        free(arr);
        return 1;
    }
    fwrite(arr, sizeof *arr, n, file);
    fflush(file);

    // 3) Display all from memory (no extra file reads)
    for (int i = 0; i < n; i++)
        print_student(&arr[i], i);

    // 4) Update one record in-place
    int idx;
    printf("\nSelect student (1-%d) to update: ", n);
    if (scanf("%d", &idx) != 1 || idx < 1 || idx > n)
        idx = 1;
    idx--; // zero-based index

    printf("Enter new name and new roll: ");
    scanf("%17s %d", arr[idx].name, &arr[idx].roll);

    // Overwrite the specific record on disk
    fseek(file, idx * sizeof *arr, SEEK_SET);
    fwrite(&arr[idx], sizeof *arr, 1, file);
    fflush(file);

    // 5) Print updated record
    print_student(&arr[idx], idx);

    // Cleanup
    fclose(file);
    free(arr);
    return 0;
}
