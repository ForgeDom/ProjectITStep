#include "Course.h"
#include "libs.h"

void Course::set_grade(const string& student_name, int grade) {
    if (student_grades.find(student_name) != student_grades.end()) {
        student_grades[student_name] = grade;
        cout << "������ ��� �������� " << student_name << " ������ ��������.\n";
    }
    else {
        cout << "������� �� ��������� �� ����.\n";
    }
}

void Course::view_grades() const {
    cout << "������ �� ���� " << course_name << ":\n";
    for (const auto& entry : student_grades) {
        cout << entry.first << ": " << entry.second << "\n";
    }
}

void Course::add_student(const string& student_name) {
    if (student_grades.find(student_name) == student_grades.end()) {
        student_grades[student_name] = 0; 
        cout << "�������� " << student_name << " ������ �� �����.\n";
    }
    else {
        cout << "������� ��� � �� ����.\n";
    }
}
void Course::remove_student(const string& student_name) {
    if (student_grades.find(student_name) != student_grades.end()) {
        student_grades.erase(student_name);
        cout << "�������� " << student_name << " ������ �������� � ����� " << course_name << ".\n";
    }
    else {
        cout << "�������� " << student_name << " �� �������� �� ���� " << course_name << ".\n";
    }
}

void Course::view_students() const {
    cout << "�������� �� ���� " << course_name << ":\n";
    for (const auto& entry : student_grades) {
        cout << entry.first << "\n";
    }
}
