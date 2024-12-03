    #include "ConsoleMenus.h"
    #include "Course.h"
    #include "CourseManager.h"
    #include "admin.h"
    #include "libs.h"

    void clear_screen() {
        system("cls");
    }

    void add_student(const string& username, const string& password) {
        ofstream file("students.txt", ios::app);
        if (!file.is_open()) {
            cerr << "�� ������� ������� ���� students.txt ��� ������.\n";
            return;
        }
        file << username << " " << password << "\n";
        file.close();
        cout << "�������� " << username << " ������ ������.\n";
    }

    void delete_student(const string& student_username, CourseManager& course_manager) {

        ifstream file("students.txt");
        if (!file.is_open()) {
            cerr << "�� ������� ������� ���� students.txt.\n";
            return;
        }

        vector<pair<string, string>> students;
        string username, password;
        bool found = false;

        while (file >> username >> password) {
            if (username != student_username) {
                students.emplace_back(username, password);
            }
            else {
                found = true;
            }
        }
        file.close();

        if (!found) {
            cout << "�������� � ��'�� " << student_username << " �� ��������.\n";
            return;
        }

        ofstream outfile("students.txt", ios::trunc);
        for (const auto& student : students) {
            outfile << student.first << " " << student.second << "\n";
        }
        outfile.close();

        cout << "�������� " << student_username << " ������ �������� � �����.\n";

        // ��������� �������� � ��� �����
        for (auto& course : course_manager.get_courses()) {
            course.remove_student(student_username);  // ��������� �������� � ������� �����
        }
    }

     
  void view_students() {
        ifstream file("students.txt");
        if (!file.is_open()) {
            cerr << "�� ������� ������� ���� students.txt.\n";
            return;
        }

        string username, password;
        cout << "������ ��������:\n";
        while (file >> username >> password) {
            cout << "- " << username << "\n";
        }
        file.close();
  }

    void add_teacher(const string& username, const string& password) {
        ofstream file("teachers.txt", ios::app);
        if (!file.is_open()) {
            cerr << "�� ������� ������� ���� teachers.txt ��� ������.\n";
            return;
        }
        file << username << " " << password << "\n";
        file.close();
        cout << "��������� " << username << " ������ ������.\n";
    }

    void view_teachers() {
        ifstream file("teachers.txt");
        if (!file.is_open()) {
            cerr << "�� ������� ������� ���� teachers.txt.\n";
            return;
        }

        string username, password;
        cout << "������ ����������:\n";
        while (file >> username >> password) {
            cout << "��'�: " << username << " | ������: " << password << "\n";
        }
        file.close();
    }

    void delete_teacher(const string& teacher_username) {
        ifstream file("teachers.txt");
        if (!file.is_open()) {
            cerr << "�� ������� ������� ���� teachers.txt.\n";
            return;
        }

        vector<pair<string, string>> teachers;
        string username, password;
        bool found = false;

        while (file >> username >> password) {
            if (username != teacher_username) {
                teachers.emplace_back(username, password);
            }
            else {
                found = true;
            }
        }
        file.close();

        if (!found) {
            cout << "��������� � ��'�� " << teacher_username << " �� ��������.\n";
            return;
        }

        ofstream outfile("teachers.txt", ios::trunc);
        for (const auto& teacher : teachers) {
            outfile << teacher.first << " " << teacher.second << "\n";
        }
        outfile.close();

        cout << "�������� " << teacher_username << " ������ ���������.\n";
    }

    void admin_menu(UserManager& teachers_manager, CourseManager& course_manager) {
        clear_screen();
        while (true) {
            cout << "\n���� ������������:\n";
            cout << "1. ������ ���������\n";
            cout << "2. ����������� ����������\n";
            cout << "3. �������� ���������\n";
            cout << "4. ����������� ��������\n";  // ������
            cout << "5. �������� ��������\n";     // ������
            cout << "6. �����\n";
            cout << "��� ����: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                string username, password;
                cout << "������ ��'� ���������: ";
                cin >> username;
                cout << "������ ������ ��� ���������: ";
                cin >> password;
                add_teacher(username, password);
            }
            else if (choice == 2) {
                view_teachers();
            }
            else if (choice == 3) {
                string username;
                cout << "������ ��'� ���������, ����� ������� ��������: ";
                cin >> username;
                delete_teacher(username);
            }
            else if (choice == 4) {
                view_students(); // �������� ��������
            }
            else if (choice == 5) {
                string student_username;
                cout << "������ ��'� ��������, ����� ������� ��������: ";
                cin >> student_username;
                delete_student(student_username, course_manager); // ��������� ��������
            }
            else if (choice == 6) {
                cout << "����� � ���� ������������.\n";
                break;
            }
            else {
                cout << "������������ ����. ��������� �� ���.\n";
            }
            system("pause");
        }
    }


    void teacher_menu(CourseManager& course_manager, UserManager& student_manager) {
    while (true) {
        cout << "\n--- ���� ��������� ---\n";
        cout << "1. ������ ����\n";
        cout << "2. ����������� �����\n";
        cout << "3. ������ �������� �� �����\n";
        cout << "4. ����������� �������� �� ����\n";  // �������� ��������
        cout << "5. ���������� ������ ��������\n";
        cout << "6. �����\n";
        cout << "��� ����: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string course_name;
            cout << "������ ����� ������ �����: ";
            cin.ignore();
            getline(cin, course_name);
            course_manager.add_course(course_name);
        }
        else if (choice == 2) {
            course_manager.view_courses();
        }
        else if (choice == 3) {
            string course_name, student_name;
            cout << "������ ����� �����: ";
            cin.ignore();
            getline(cin, course_name);
            Course* course = course_manager.get_course(course_name);
            if (course) {
                cout << "������ ��'� ��������: ";
                getline(cin, student_name);
                course->add_student(student_name);
            }
            else {
                cout << "���� �� ��������.\n";
            }
        }
        else if (choice == 4) {
            string course_name;
            cout << "������ ����� �����: ";
            cin.ignore();
            getline(cin, course_name);
            Course* course = course_manager.get_course(course_name);
            if (course) {
                course->view_students();  // �������� ��������
            }
            else {
                cout << "���� �� ��������.\n";
            }
        }
        else if (choice == 5) {
            string course_name, student_name;
            int grade;
            cout << "������ ����� �����: ";
            cin.ignore();
            getline(cin, course_name);
            Course* course = course_manager.get_course(course_name);
            if (course) {
                cout << "������ ��'� ��������: ";
                getline(cin, student_name);
                cout << "������ ������: ";
                cin >> grade;
                course->set_grade(student_name, grade);
            }
            else {
                cout << "���� �� ��������.\n";
            }
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "������������ ����. ��������� �� ���.\n";
        }
    }
}


    void student_menu(CourseManager& course_manager,UserManager& user_manager, const string& student_name) {
        while (true) {
            cout << "\n--- ���� �������� ---\n";
            cout << "1. ����������� ������� �����\n";
            cout << "2. ����������� ������ �� �������\n";
            cout << "3. �����\n";
            cout << "��� ����: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                course_manager.view_courses();
            }
            else if (choice == 2) {
                cout << "���� ������:\n";
                const auto& courses = course_manager.get_courses();
                for (const auto& course : courses) {
                    auto it = course.student_grades.find(student_name);
                    if (it != course.student_grades.end()) {
                        cout << course.course_name << ": " << it->second << "\n";
                    }
                }
            }
            else if (choice == 3) {
                break;
            }
            else {
                cout << "������������ ����. ��������� �� ���.\n";
            }
        }
    }