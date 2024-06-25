#include <stdlib.h>
#include <string.h>
#include "myhead.h"


// Comparison function for qsort
int compareStudents(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->sid, studentB->sid);
}

// Comparison function by name
int compareStudentsByName(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return strcmp(studentA->name, studentB->name);
}

// Comparison function by department for SRecord
int compareSRecordsByDepartment(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    return strcmp(srecordA->student.department, srecordB->student.department);
}

// Comparison function by rawScore for SRecord
int compareSRecordsByrawScore(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    if (srecordA->rawScore < 60 && srecordB->rawScore >= 60) return 1;
    if (srecordA->rawScore >= 60 && srecordB->rawScore < 60) return -1;
    if (srecordA->rawScore < srecordB->rawScore) return -1;
    if (srecordA->rawScore > srecordB->rawScore) return 1;
    return 0;
}
// Comparison function by SID for SRecord
int compareSRecordsBySID(const void* a, const void* b) {
    SRecord* srecordA = (SRecord*)a;
    SRecord* srecordB = (SRecord*)b;
    return strcmp(srecordA->student.sid, srecordB->student.sid);
}

void sortStudents(Student* students, int numStudents, const char* sortBy) {
    if (strcmp(sortBy, "sid") == 0) {
        qsort(students, numStudents, sizeof(Student), compareStudents);
    } else if (strcmp(sortBy, "name") == 0) {
        qsort(students, numStudents, sizeof(Student), compareStudentsByName);
    } else {
        // Handle invalid sortBy parameter
        // You can throw an error, print a message, or take any other appropriate action
    }
}


void sortSRecords(SRecord* srecords, int numSRecords, const char* sortBy) {
    if (strcmp(sortBy, "department") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsByDepartment);
    } else if (strcmp(sortBy, "rawScore") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsByrawScore);
    } else if (strcmp(sortBy, "sid") == 0) {
        qsort(srecords, numSRecords, sizeof(SRecord), compareSRecordsBySID);
    } else {
        // Handle invalid sortBy parameter
        // You can throw an error, print a message, or take any other appropriate action
    }
}
