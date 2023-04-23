#include "main.h"

#include "Student.h"
#include "Course.h"
#include "Grading.h"

//forward declaration
class Student;
class Course;
class System;
class CourseList;
class StudentList;
class GradingList;

class System {
private:
    StudentList* all_students;
    CourseList* all_courses;
    GradingList* all_grading;
public:
    System(){
        this->all_students = new StudentList();
        this->all_courses = new CourseList();
    }

    void addStudent(string name, int id, string email) {
        all_students->addStudent(new Student(name, id, email));
    }

    void printStudents() {
        all_students->printStudents();
    }    

    void addCourse(string name, string instructor, int num_students) {
        this->all_courses->addCourse(new Course(name,instructor,num_students));
    }

    void printCourses() {
        all_courses->printCourses();
    }


    Student* getStudent(string name) {
        return all_students->getStudent(name);
    }

    Course* getCourse(string course_name) {
        return all_courses->getCourse(course_name);
    }

    void assign(Student* student, Course* course) {
        student->enrollCourse(course);
        course->enrollStudent(student);
        all_grading->addGrading(course, student);
    }
    void record(Course* course, Student* student, double score) {

    }
    void getScore(Course* course, Student* student) {
        vector<double> score = all_grading->getGrading(course, student);
        cout << "Grading of " << student->getName() << " in " << course->getCourseName() << ":\n";
        for (int i = 0; i < score.size(); i++) {
            cout << score[i] << ";";
        }
        cout << "\n";
    }
};

int main() {
    System system;
    
    Student* std;
    Course* course;


    // std = new Student();
    system.addStudent("John Doe",20,"johndoe@hcmut.edu.vn");


    system.addStudent("John Wick",21,"johnwick@hcmut.edu.vn");

    system.printStudents();


    system.addCourse("DSA","Tran Ngoc Bao Duy", 100);


    system.addCourse("LTNC","Le Thuan", 100);

    system.printCourses();


    std = system.getStudent("John Doe");
    course = system.getCourse("DSA");
    system.assign(std, course);
    cout << "\n";
    std->printCourse();
    system.record(course, std, 5.0);
    system.getScore(course, std);

    return 0;
}

