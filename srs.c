#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    struct Student s;

    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter name: ");
    scanf(" %[^\n]", s.name);  // read string with spaces
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Record added successfully.\n");
}

void viewStudents() {
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;

    printf("\n--- All Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    int roll;
    int found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Record found: Roll: %d | Name: %s | Marks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found.\n");

    fclose(fp);
}

void deleteStudent() {
    int roll;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    int deleted = 0;

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll != roll)
            fwrite(&s, sizeof(s), 1, temp);
        else
            deleted = 1;
    }

    fclose(fp);
    fclose(temp);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (deleted)
        printf("Record deleted.\n");
    else
        printf("Record not found.\n");
}

void updateStudent() {
    int roll, found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb+");

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found.\n");
    else
        printf("Record updated successfully.\n");

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
