#ifndef COURSE_H
#define COURSE_H

#include"main.h"

class Course {
private:
    string title;
    vector<Student> students;
    int maxErollment;
public:
    Course(string title, int maxEnrollment);
    string getTitle();
    void setMaxEnrollment(int maxEnrollment);
    int getMaxEnrollment();
    void addStudent(Student student);
    void removeStudent(Student student);
    vector<Student> getStudents();
    bool isEnrollmentFull();
};

#endif // COURSE_H