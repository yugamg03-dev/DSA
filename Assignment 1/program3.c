#include <stdio.h>

struct emp {
    int empid;
    char name[20];
    float salary;
};

int main() {
    struct emp emp[5];
    FILE *fp;

    printf("Enter employee details:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter employee ID of emp%d: ", i + 1);
        scanf("%d", &emp[i].empid);

        printf("Enter name of emp%d: ", i + 1);
        scanf("%19s", emp[i].name);

        printf("Enter salary of emp%d: ", i + 1);
        scanf("%f", &emp[i].salary);
    }

    fp = fopen("lab1.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        fwrite(&emp[i], sizeof(struct emp), 1, fp);
    }
    fclose(fp);

    fp = fopen("lab1.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        fread(&emp[i], sizeof(struct emp), 1, fp);
        if (emp[i].salary >= 50000) {
            emp[i].salary += emp[i].salary * 0.05;
        } else if (emp[i].salary >= 20000 && emp[i].salary < 50000) {
            emp[i].salary += emp[i].salary * 0.10;
        } else {
            emp[i].salary += emp[i].salary * 0.15;
        }
    }
    fclose(fp);

    fp = fopen("lab1.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file for writing updated data.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        fwrite(&emp[i], sizeof(struct emp), 1, fp);
    }
    fclose(fp);

    fp = fopen("lab1.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file for display.\n");
        return 1;
    }

    printf("\nUpdated employee records:\n");
    for (int i = 0; i < 5; i++) {
        fread(&emp[i], sizeof(struct emp), 1, fp);
        printf("Employee %d: ID = %d, Name = %s, Salary = %.2f\n",
               i + 1, emp[i].empid, emp[i].name, emp[i].salary);
    }
    fclose(fp);

    return 0;
}