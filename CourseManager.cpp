#include "CourseManager.h"
#include "libs.h"

void CourseManager::load_courses() {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "�� ������� ������� ���� " << filename << ".\n";
        return;
    }

    string course_name;
    while (getline(file, course_name)) {
        courses.push_back(Course(course_name));
    }
    file.close();
}

void CourseManager::add_course(const string& name) {
    for (const auto& course : courses) {
        if (course.course_name == name) {
            cout << "���� � ����� ������ ��� ����!\n";
            return;
        }
    }
    courses.push_back(Course(name));
    save_courses();
    cout << "���� " << name << " ������ ������.\n";
}

void CourseManager::save_courses() {
    ofstream file(filename, ios::trunc);
    if (!file.is_open()) {
        cerr << "�� ������� ������� ���� " << filename << " ��� ������.\n";
        return;
    }

    for (const auto& course : courses) {
        file << course.course_name << "\n";
    }

    file.close();
}

void CourseManager::view_courses() const {
    if (courses.empty()) {
        cout << "���� ��������� �����.\n";
        return;
    }

    cout << "������� �����:\n";
    for (const auto& course : courses) {
        cout << "- " << course.course_name << "\n";
    }
}

vector<Course> CourseManager::get_courses() {
    return courses;
}

Course* CourseManager::get_course(const string& name) {
    for (auto& course : courses) {
        if (course.course_name == name) {
            return &course;
        }
    }
    return nullptr;
}
