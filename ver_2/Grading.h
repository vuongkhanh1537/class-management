#ifndef GRADING_H
#define GRADING_H

#include"main.h"

using namespace std;

class Grading {
public:
    Grading(Course* course, Student* student) : course(course), student(student) {}
    void addScore(double score) {
        this->score.push_back(score);
    }

    Course* getCourse() {
        return course;
    }

    Student* getStudent() {
        return student;
    }

    vector<double> getScore() {
        return score;
    }
private:
    Course* course;
    Student* student;
    vector<double> score;
};

class GradingList {
public:
    void addGrading (Course* course, Student* student) {
        Grading* grade = new Grading(course, student);
        gradeBook.push_back(grade);
    }
    void addScore(Course* course, Student* student, double score) {
        for (int i = 0; i < gradeBook.size(); i++) {
            if (gradeBook[i]->getCourse() == course && gradeBook[i]->getStudent() == student) {
                gradeBook[i]->addScore(score);
            }
        }
    }
    vector<double> getGrading (Course* course, Student* student) {
        for (int i = 0; i < gradeBook.size(); i++) {
            if (gradeBook[i]->getCourse() == course && gradeBook[i]->getStudent() == student) {
                return gradeBook[i]->getScore();
            }
        }
        vector<double> null(1,-1);
        return null;
    }
private:
    vector<Grading*> gradeBook;
};

#endif // GRADING_H