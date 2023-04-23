#ifndef STUDENT_H
#define STUDENT_H

#include "main.h"
#include "Course.h"
using namespace std;


class Course; //forward declaration

class Student {
public:
    Student() {}
    Student(string name, int id, string email) : name(name), id(id), email(email) {}

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    string getEmail() {
        return email;
    }

    void enrollCourse(Course* course) {
        enrolledCourse.push_back(course);
    }

    void printCourse() {
        for (int i = 0; i < enrolledCourse.size(); i++) {
            cout << enrolledCourse[i]->getCourseName();
        }
    }

private:
    string name;
    int id;
    string email;
    vector<Course*> enrolledCourse;
};

class StudentList {
public:
    StudentList() {}
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void removeStudent(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i]->getId() == id) {
                students.erase(students.begin() + i);
                break;
            }
        }
    }

    Student* getStudent(string name) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i]->getName() == name) {
                return students[i];
            }
        }
        return NULL;
    }

    void printStudents() {
        for (int i = 0; i < students.size(); i++) {
            cout << "Name: " << students[i]->getName() << endl;
            cout << "ID: " << students[i]->getId() << endl;
        }
    }

private:
    vector<Student*> students;
};

#endif // STUDENT_H