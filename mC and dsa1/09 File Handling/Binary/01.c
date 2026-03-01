#include <stdio.h>
#include <stdlib.h> //for malloc and all
#include <string.h>

// Define student structure
struct stu {
    int   roll;
    float per;
    float marks[5];
    char  name[18];
};
typedef struct stu S;

int main() {
    int   n;
    char  newname[16];
    FILE *f;
    S    *ptr;

    // 1) Write N student records to binary file
    printf("How many students: ");
    scanf("%d", &n);

    ptr = (S *)malloc(n * sizeof(S));
    if (!ptr) {
        perror("malloc");
        return 1;
    }

    f = fopen("binary.bin", "wb+");    // open for read/write, create/truncate
    if (!f) {
        perror("fopen");
        free(ptr);
        return 1;
    }

    printf("Enter the details for %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Student %d -> roll, per, marks in 5 sub, name:\n", i + 1);
        scanf("%d %f", &ptr[i].roll, &ptr[i].per);
        for (int j = 0; j < 5; j++) {
            scanf("%f", &ptr[i].marks[j]);
        }
        scanf("%17s", ptr[i].name);
    }

    fwrite(ptr, sizeof(S), n, f);
    fflush(f);

    // 2) Read back and display all
    rewind(f);
    fread(ptr, sizeof(S), n, f);

    for (int i = 0; i < n; i++) {
        printf("\nDetail of Student %d ->\n", i + 1);
        printf("Name : %s\n", ptr[i].name);
        printf("Roll : %d\n", ptr[i].roll);
        printf("Per  : %.2f\n", ptr[i].per);
        printf("Marks: ");
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", ptr[i].marks[j]);
        }
        printf("\n");
    }
    fclose(f);

    // 3) Update one record by name & roll
    f = fopen("binary.bin", "rb+");
    if (!f) {
        perror("fopen rb+");
        free(ptr);
        return 1;
    }

    printf("\nEnter index (1-%d) of student to correct, new NAME & new rollno:\n", n);
    int idx;
    scanf("%d", &idx);
    if (idx < 1 || idx > n) idx = 1;

    // Position to the (idx-1)-th record
    fseek(f, (idx - 1) * sizeof(S), SEEK_SET);
    fread(&ptr[idx-1], sizeof(S), 1, f);

    // Read new data
    scanf("%15s %d", newname, &ptr[idx-1].roll);
    strcpy(ptr[idx-1].name, newname);

    // Overwrite record
    fseek(f, (idx - 1) * sizeof(S), SEEK_SET);
    fwrite(&ptr[idx-1], sizeof(S), 1, f);
    fflush(f);

    // Display updated record
    printf("\nUpdated Detail of Student %d ->\n", idx);
    printf("Name : %s\n", ptr[idx-1].name);
    printf("Roll : %d\n", ptr[idx-1].roll);
    printf("Per  : %.2f\n", ptr[idx-1].per);
    printf("Marks: ");
    for (int j = 0; j < 5; j++) {
        printf("%.2f ", ptr[idx-1].marks[j]);
    }
    printf("\n");

    fclose(f);
    free(ptr);
    return 0;
}