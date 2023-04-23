#ifndef COURSE_H
#define COURSE_H

#include "main.h"
#include "Student.h"
using namespace std;

class Student; //forward declaration
// class StudentList; //forward declaration

class Course {
public:
    Course(string course_name, string instructor, int num_students) : course_name(course_name), instructor(instructor) {
        this->course_name = course_name;
        this->instructor = instructor;
    }

    string getCourseName() {
        return course_name;
    }

    string getInstructor() {
        return instructor;
    }

    void enrollStudent(Student* student) {
        enrolledStudents.push_back(student);
    }



private:
    string course_name;
    string instructor;
    vector<Student*> enrolledStudents;
};

class CourseList {
public:
    void addCourse(Course* course) {
        courses.push_back(course);
    }

    void removeCourse(string name) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i]->getCourseName() == name) {
                courses.erase(courses.begin() + i);
                break;
            }
        }
    }

    void printCourses() {
        for (int i = 0; i < courses.size(); i++) {
            cout << "Name: " << courses[i]->getCourseName() << endl;
            cout << "Instructor: " << courses[i]->getInstructor() << endl;
        }
    }
    Course* getCourse(string course_name) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i]->getCourseName() == course_name) {
                return courses[i];
            }
        }
        return NULL;
    }

    
private:
    vector<Course*> courses;
};

#endif // COURSE_H