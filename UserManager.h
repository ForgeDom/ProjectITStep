#ifndef USER_MANAGER_H
#define USER_MANAGER_H
#include "Course.h"
#include "libs.h"

class UserManager {
private:
    string filename;  // ���� ������������
    vector<Course> courses;  // ������ �����

public:
    UserManager(const string& file);

    // ��������� �����������
    bool register_user(const string& username, const string& password);

    // ���� �����������
    bool login_user(const string& username, const string& password);

    // �������� �������� �����������
    bool user_exists(const string& username);

    // ������ ����
    void add_course(const string& course_name);

    // ����������� �����
    void view_courses() const;
    Course* get_courses(const string& course_name);
    bool course_exists(const string& course_name) const;
    vector<Course> get_courses() const;
};
#endif // USER_MANAGER_H
