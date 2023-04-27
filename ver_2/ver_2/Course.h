#pragma once
#ifndef COURSE_H
#define COURSE_H

#include "Grading.h"
using namespace std;

class Course {
public:
    Course(string course_name, string course_ID, string instructor) : course_name(course_name), course_ID(course_ID), instructor(instructor) {}

    string getCourseName() {
        return course_name;
    }

    string getCourseID() {
        return course_ID;
    }

    string getInstructor() {
        return instructor;
    }

    void enrollStudent(Grading* grade) {
        enrolledStudents.push_back(grade);
    }

    void recordScore(Student* student, double score) {
        for (int i = 0; i < enrolledStudents.size(); i++) {
            if (enrolledStudents[i]->getStudent() == student) {
                enrolledStudents[i]->addScore(score);
            }
        }
    }

    double getGPA (Student* student) {
        for (int i = 0; i < enrolledStudents.size(); i++) {
            if (enrolledStudents[i]->getStudent() == student) {
                return enrolledStudents[i]->getGPA();
            }
        }
    }

    void printStudent() {
        for (int i = 0; i < enrolledStudents.size(); i++) {
            cout << enrolledStudents[i]->getStudent()->getName() << " - " << enrolledStudents[i]->getStudent()->getId() << "\n";
        }
    }

private:
    string course_name;
    string course_ID;
    string instructor;
    vector<Grading*> enrolledStudents;
};

class CourseList {
public:
    CourseList() {}

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
        if (courses.empty()) {
            cout << "None of course\n";
            return;
        }
        for (int i = 0; i < courses.size(); i++) {
            cout << "Name: " << courses[i]->getCourseName() << endl;
            cout << "Instructor: " << courses[i]->getInstructor() << endl;
        }
    }
    Course* getCourse(string course_info) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i]->getCourseName() == course_info || courses[i]->getCourseID() == course_info) {
                return courses[i];
            }
        }
        return NULL;
    }

    
private:
    vector<Course*> courses;
};

#endif // COURSE_H