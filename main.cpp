#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;
void sampleStudents(), searchStudent(), addStudent(), displayStudent(), viewStudents();

struct Student {
    string name;
    string id;
    bool submissions[5]; // W1 to W5 
    //w2
};

vector<Student> students;

int main() {
    sampleStudents();
    int choice;

    do {
        system("cls");
        cout << "\n--- Assignment Submission System ---\n";
        cout << "1. Searsch Student\n";
        cout << "2. Add Student\n";
        cout << "3. Students list\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: searchStudent(); break;
            case 2: addStudent(); break;
            case 3: viewStudents(); break;
            case 4: system("cls"); cout << "Exiting...\n"; sleep(2); return 0; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 4);

    return 0;
}

void viewStudents() {
    system("cls");
    cout << "\n--- Students List ---\n";
    for (const auto& s : students) {
        cout << "Name: " << s.name << ", ID: " << s.id << endl;
    }
    cout << "\nPress any key to return to menu...";
    getch();
}

void displayStudent(const Student& s) {
    system("cls");
    cout << "\nStudent\n";
    cout << "Name: " << s.name << endl;
    cout << "ID: " << s.id << endl;
    for (int i = 0; i < 5; i++) {
        cout << "W" << (i+1) << " " << (s.submissions[i] ? "Y" : "X") << endl;
    }

    cout << "\nPress any key to return to menu...";
    getch();
}

void searchStudent() {
    system("cls");
    string query;
    cout << "\nEnter student name or ID to search: ";
    cin >> query;

    for (const auto& s : students) {
        if (s.name == query || s.id == query) {
            displayStudent(s);
            return;
        }
    }
    cout << "Student not found.\n";
}

void addStudent() {
    system("cls");
    Student s;
    cout << "\nEnter student name: ";
    cin >> s.name;
    cout << "Enter student ID: ";
    cin >> s.id;

    for (int i = 0; i < 5; i++) {
        char submit;
        cout << "Did the student submit W" << (i+1) << "? (y/n): ";
        cin >> submit;
        s.submissions[i] = (submit == 'y' || submit == 'Y');
    }

    students.push_back(s);
    cout << "Student added successfully.\n";
}

void sampleStudents() {
    system("cls");
    Student s1 = {"Louie", "000", {1,1,1,1,1}};
    Student s2 = {"Anna", "001", {1,0,1,1,0}};
    Student s3 = {"Mark", "002", {0,0,1,0,1}};
    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);
}
