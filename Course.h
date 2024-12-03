#ifndef COURSE_H
#define COURSE_H

#include "libs.h"

class Course {
public:
    string course_name;  // Назва курсу
    map<string, int> student_grades;  // Список студентів та їхні оцінки

    Course(const string& name) : course_name(name) {}

    void set_grade(const string& student_name, int grade);
    void view_grades() const;
    void add_student(const string& student_name);
    void view_students() const;
};
#endif
