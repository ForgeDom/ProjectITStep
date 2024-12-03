#ifndef CONSOLE_MENUS_H
#define CONSOLE_MENUS_H

#include "UserManager.h"

void clear_screen();
void admin_menu(UserManager& teachers_manager);
void add_teacher(const string& username, const string& password);
void view_teachers();
void delete_teacher(const string& teacher_username);
void teacher_menu(CourseManager& course_manager, UserManager& student_manager);
void student_menu(CourseManager& course_manager, UserManager& user_manager, const string& student_name);
void add_student(const string& username, const string& password);
void delete_student(const string& student_username);
void view_students();

#endif
