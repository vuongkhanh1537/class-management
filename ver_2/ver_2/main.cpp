#include "System.h"

bool isNumber(string str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    System system;

    cout << "Welcome to Class Management System\n";
    cout << "How can I help you?\n";
    system.command();

    while (1) {
        string str_task;
        int task;
        cout << "> ";
        cin >> str_task;
        if (str_task == "help") {
            system.command();
            continue;
        }
        if (isNumber(str_task)) {
            task = stoi(str_task);
        } else {
            cout << "Syntax Error\n";
            continue;
        }
        if (task == 0) {break;}
        switch (task) {
            case 1: 
                system.addStudent();
                break;
            case 2:
                system.addCourse();
                break;
            case 3:
                system.assign();
                break;
            case 4:
                system.recordScore();
                break;
            case 5:
                system.getGPA();
                break;
            case 6:
                system.getStudentsInCourse();
                break;
            case 7:
                system.getCoursesInStudent();
                break;
            default:
                cout << "We don't have that choice\n";
                cout << "Use \"help\" to see all the commnad\n";
                break;
        }
    }
    
    cout << "See ya!\n";
    return 0;
}

