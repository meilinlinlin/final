#ifndef MYHEAD_H
#define MYHEAD_H

#include <stdio.h>
#include "rlutil.h"

// 定義學生結構
typedef struct {
    char name[50];
    char department[50];
    int grade;
    char sid[50];
} Student;

typedef struct {
    Student student;
    // 作業,平時測驗,期中測驗,期末報告,其他(出席及平時表現),原始成績
    double homework, quiz, midterm, final, other, rawScore;
} SRecord;

#define homework_WEIGHT 0.2
#define QUIZ_WEIGHT 0.1
#define MIDTERM_WEIGHT 0.3
#define FINAL_WEIGHT 0.3
#define OTHER_WEIGHT 0.1

void printStudents(Student students[], int numStudents);
void printSRecords(SRecord srecords[], int numSRecords);
int readSRecordsFromCSV(const char* filename, SRecord srecords[], int maxNumSRecords);

void randomInitStudents(Student students[], int numStudents);

// void sortStudentsBySID(Student* students, int numStudents);
// void sortStudentsByName(Student* students, int numStudents);


void sortStudents(Student* students, int numStudents, const char* sortBy);
void sortSRecords(SRecord* srecords, int numSRecords, const char* sortBy);

#endif // MYHEAD_H
