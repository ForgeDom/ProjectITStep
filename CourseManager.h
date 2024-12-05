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
    void add_course(const string& name);  
    void save_courses(); 
    void view_courses() const;  
    Course* get_course(const string& name); 
    vector<Course> get_courses();
};

#endif
