#ifndef COURSE_MANAGER_H
#define COURSE_MANAGER_H
#include "Course.h"
#include "libs.h"

class CourseManager {
private:
    vector<Course> courses;
    string filename = "courses.txt";
    void load_courses();

public:
    CourseManager(const string& file) : filename(file) {
        load_courses();
    }
    void add_course(const string& name);  // Додати новий курс
    void save_courses();  // Зберегти курси у файл
    void view_courses() const;  // Переглянути всі курси
    Course* get_course(const string& name);  // Отримати курс по назві
    vector<Course> get_courses();
};

#endif
