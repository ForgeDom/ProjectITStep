#include "Course.h"
#include "libs.h"

void Course::set_grade(const string& student_name, int grade) {
    if (student_grades.find(student_name) != student_grades.end()) {
        student_grades[student_name] = grade;
        cout << "Оцінка для студента " << student_name << " успішно оновлена.\n";
    }
    else {
        cout << "Студент не знайдений на курсі.\n";
    }
}

void Course::view_grades() const {
    cout << "Оцінки за курс " << course_name << ":\n";
    for (const auto& entry : student_grades) {
        cout << entry.first << ": " << entry.second << "\n";
    }
}

void Course::add_student(const string& student_name) {
    if (student_grades.find(student_name) == student_grades.end()) {
        student_grades[student_name] = 0;  // Початкова оцінка 0
        cout << "Студента " << student_name << " додано до курсу.\n";
    }
    else {
        cout << "Студент вже є на курсі.\n";
    }
}

void Course::view_students() const {
    cout << "Студенти на курсі " << course_name << ":\n";
    for (const auto& entry : student_grades) {
        cout << entry.first << "\n";
    }
}
