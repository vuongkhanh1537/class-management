#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

#include "Course.h"

class System {
private:
    StudentList* all_students;
    CourseList* all_courses;

protected:
    bool getInfo(Course* &course, Student* &student) {
        string student_info;
        string course_info;
        cout << "Name\\ID of Student: ";
        cin >> student_info;

        cout << "Name\\ID of Course: ";
        cin >> course_info;

        student = all_students->getStudent(student_info);
        course = all_courses->getCourse(course_info);

        if (!course && !student) {
            cout << "No info of course and student\n";
            return false;
        } 
        
        if (!course) {
            cout << "No info of course\n";
            return false;
        }

        if (!student) {
            cout << "No info of student\n";
            return false;
        }

        return true;
    }
    bool getCourseInfo(Course* &course) {
        string course_info;

        cout << "Name\\ID of Course: ";
        cin >> course_info;

        course = all_courses->getCourse(course_info);

        if (!course) {
            cout << "No info of course\n";
            return false;
        }
        return true;
    }

    bool getStudentInfo(Student* &student) {
        string student_info;

        cout << "Name\\ID of Student: ";
        cin >> student_info;

        student = all_students->getStudent(student_info);
        if (!student) {    
            cout << "No info of student\n";
            return false;
        }

        return true;
    }
public:
    void command() {
        cout << "1. Add a student\n";
        cout << "2. Add a course\n";
        cout << "3. Assign a student to a course\n";
        cout << "4. Record Score\n";
        cout << "5. Get GPA\n";
        cout << "6. Show List of Student of a Course\n";
        cout << "7. Show List of Course of a Student\n";
    }
    System(){
        this->all_students = new StudentList();
        this->all_courses = new CourseList();
    }

    void addStudent() {
        string name;
        string ID;
        string email;
        cout << "Name: "; cin >> name;
        cout << "ID: "; cin >> ID;
        cout << "Email: "; cin >> email;
        all_students->addStudent(new Student(name, ID, email));
        cout << "Completed.\n";
    }

    void addCourse() {
        string name;
        string ID;
        string instructor;
        cout << "Name: "; cin >> name;
        cout << "ID: "; cin >> ID;
        cout << "Instructor: "; cin >> instructor;
        this->all_courses->addCourse(new Course(name, ID, instructor));
        cout << "Completed.\n";
    }

    void assign() {
        Course* course;
        Student* student;
        bool success = getInfo(course, student);
        
        if (success) {
            Grading* grade = new Grading(student);
            student->enrollCourse(course->getCourseName(), course->getCourseID());
            course->enrollStudent(grade);
            cout << "Assign completed.\n";
        }
    }

    void recordScore() {
        Course* course;
        Student* student;
        double score;
        bool success = getInfo(course, student);
        if (success) {
            cout << "Score: ";
            cin >> score;
            course->recordScore(student, score);
        }
    }

    void getGPA () {
        Course* course;
        Student* student;
        bool success = getInfo(course, student);
        if (success) {
            cout << "GPA of " << student->getName() << " in " << course->getCourseName() << ": " << course->getGPA(student) << "\n";
        }
    }

    void getStudentsInCourse () {
        Course* course;
        bool success = getCourseInfo(course);
        if (success) {
            course->printStudent();
        }
    }

    void getCoursesInStudent () {
        Student* student;
        bool success = getStudentInfo(student);
        if (success) {
            student->printCourse();
        }
    }

    void printStudents() {
        cout << "List of All students:\n";
        all_students->printStudents();
    }    

    void printCourses() {
        cout << "List of All Courses:\n";
        all_courses->printCourses();
    }
};

#endif // SYSTEM_H