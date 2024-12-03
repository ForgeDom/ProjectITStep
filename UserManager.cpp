#include "UserManager.h"
#include "Course.h"
#include <fstream>
#include <iostream>

using namespace std;

UserManager::UserManager(const string& file) : filename(file) {}

bool UserManager::register_user(const string& username, const string& password) {
    if (user_exists(username)) {
        cout << "���������� ��� ����!\n";
        return false;
    }

    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "������� ������� �� �����!\n";
        return false;
    }

    file << username << " " << password << "\n";
    file.close();
    cout << "���������� ������ �������������!\n";
    return true;
}

bool UserManager::login_user(const string& username, const string& password) {
    ifstream file(filename);
    if (!file) {
        cerr << "������� ������� �� �����!\n";
        return false;
    }

    string stored_username, stored_password;
    while (file >> stored_username >> stored_password) {
        if (stored_username == username && stored_password == password) {
            cout << "���� �������!\n";
            return true; 
        }
    }

    cout << "������� ���� ��� ������!\n";
    return false;
}

bool UserManager::user_exists(const string& username) {
    ifstream file(filename);
    if (!file) {
        cerr << "������� ������� �� �����!\n";
        return false;
    }

    string stored_username, stored_password;
    while (file >> stored_username >> stored_password) {
        if (stored_username == username) {
            return true; 
        }
    }

    return false; 
}

void UserManager::add_course(const string& course_name) {
    if (course_exists(course_name)) {
        cout << "���� � ����� ������ ��� ����!\n";
        return;
    }

    Course new_course(course_name);  
    courses.push_back(new_course);  
    cout << "���� " << course_name << " ������ ������!\n";

    ofstream file("courses.txt", ios::app);
    if (!file) {
        cerr << "�� ������� ������� ���� ��� ���������� �����!\n";
        return;
    }
    file << course_name << "\n";
    file.close();
}

void UserManager::view_courses() const {
    cout << "������� �����:\n";
    for (const auto& course : courses) {
        cout << course.course_name << "\n";
    }
}

Course* UserManager::get_courses(const string& course_name) {
    for (auto& course : courses) {
        if (course.course_name == course_name) {
            return &course;
        }
    }
    return nullptr; 
}

bool UserManager::course_exists(const string& course_name) const {
    for (const auto& course : courses) {
        if (course.course_name == course_name) {
            return true;
        }
    }
    return false;
}

vector<Course> UserManager::get_courses() const
{
    return vector<Course>();
}
