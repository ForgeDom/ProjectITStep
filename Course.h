#ifndef COURSE_H
#define COURSE_H

#include "libs.h"

class Course {
public:
    string course_name; 
    map<string, int> student_grades;  

    Course(const string& name) : course_name(name) {}

    void set_grade(const string& student_name, int grade);
    void view_grades() const;
    void add_student(const string& student_name);
    void remove_student(const string& student_name);
    void view_students() const;
    void save_to_file(const string& filename);
    void load_from_file(const string& filename);
};
#endif
