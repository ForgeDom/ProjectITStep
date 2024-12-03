#ifndef USER_MANAGER_H
#define USER_MANAGER_H
#include "Course.h"
#include "libs.h"

class UserManager {
private:
    string filename;  // Файл користувачів
    vector<Course> courses;  // Список курсів

public:
    UserManager(const string& file);

    // Реєстрація користувача
    bool register_user(const string& username, const string& password);

    // Вхід користувача
    bool login_user(const string& username, const string& password);

    // Перевірка наявності користувача
    bool user_exists(const string& username);

    // Додати курс
    void add_course(const string& course_name);

    // Переглянути курси
    void view_courses() const;
    Course* get_courses(const string& course_name);
    bool course_exists(const string& course_name) const;
    vector<Course> get_courses() const;
};
#endif // USER_MANAGER_H
