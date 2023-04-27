#pragma once
#ifndef GRADING_H
#define GRADING_H

#include "Student.h"

using namespace std;

class Grading {
public:
    Grading(Student* student) : student(student) {}

    void addScore(double score) {
        this->score.push_back(score);
    }

    Student* getStudent() {
        return student;
    }

    vector<double> getScore() {
        return score;
    }

    double getGPA() {
        double gpa = 0;
        for (int i = 0; i < score.size(); i++) {
            gpa += score[i];
        }
        return 1.0*gpa / score.size(); 
    }
private:
    Student* student;
    vector<double> score;
};

#endif // GRADING_H