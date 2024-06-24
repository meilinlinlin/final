#include <stdio.h>
#include "myhead.h"
#include <string.h>

#define MAX_STUDENT 100

void displayMenu() {
    saveDefaultColor();
    setColor(WHITE);
    setBackgroundColor(BLUE);
    printf("\nMenu:\n");
    resetColor();
    printf("1. Read student records from CSV\n");
    printf("2. Print student records\n");
    printf("3. Sort student records by total score\n");
    printf("4. Search student records by name or SID\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int searchRecords(SRecord srecords[], int numSRecords, const char *keyword) {
    for (int i = 0; i < numSRecords; i++) {
        if (strcmp(srecords[i].student.sid, keyword) == 0) {
            return i; // Found by sid
        }
        if (strcmp(srecords[i].student.name, keyword) == 0) {
            return i; // Found by name
        }
    }
    return -1; // Not found
}

int main() {
    SRecord srecords[MAX_STUDENT];
    int numSRecords = 0;
    int choice;
    char keyword[100];

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numSRecords = readSRecordsFromCSV("records.csv", srecords, MAX_STUDENT);
                printf("Number of records read: %d\n", numSRecords);
                break;
            case 2:
                if (numSRecords > 0) {
                    printSRecords(srecords, numSRecords);
                } else {
                    printf("No records to display. Please read records first.\n");
                }
                break;
            case 3:
                if (numSRecords > 0) {
                    sortSRecords(srecords, numSRecords, "rawScore");
                    printf("\n\nAfter sorting by rawScore:\n");
                    printSRecords(srecords, numSRecords);
                } else {
                    printf("No records to sort. Please read records first.\n");
                }
                break;
            case 4:
                printf("Enter search keyword (name or SID): ");
                scanf("%s", keyword); // Assuming keyword is a single word without spaces
                int foundIndex = searchRecords(srecords, numSRecords, keyword);
                if (foundIndex != -1) {
                        printf("%-15s %-12s %8d    %-10s %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n", srecords[foundIndex].student.name, srecords[foundIndex].student.department, srecords[foundIndex].student.grade, srecords[foundIndex].student.sid, srecords[foundIndex].homework, srecords[foundIndex].quiz, srecords[foundIndex].midterm, srecords[foundIndex].final, srecords[foundIndex].other, srecords[foundIndex].rawScore);
                } else {
                    printf("No record found for the keyword: %s\n", keyword);
                }
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 5);

    return 0;
}
