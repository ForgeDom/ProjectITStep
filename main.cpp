#include "UserManager.h"
#include "ConsoleMenus.h"
#include "CourseManager.h"
#include "libs.h"

using namespace std;

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    UserManager admins_manager("admins.txt");  
    UserManager teachers_manager("teachers.txt"); 
    UserManager students_manager("students.txt");
    CourseManager course_manager("courses.txt");

    if (!admins_manager.user_exists("admin")) {
        cout << "��������� ������������...\n";
        admins_manager.register_user("admin", "admin123");
    }

    while (true) {
        clear_screen();  
        cout << "\n--- ������� ���� ---\n";
        cout << "1. ���� �� �����������\n";
        cout << "2. ���� �� ��������\n";
        cout << "3. ���� �� �������\n";
        cout << "4. ��������� �� �������\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        int choice;
        cin >> choice;

        string username, password;
        if (choice == 0) break;

        switch (choice) {
        case 1:
            cout << "������ ����: ";
            cin >> username;
            cout << "������ ������: ";
            cin >> password;
            if (admins_manager.login_user(username, password)) {
                admin_menu(teachers_manager, course_manager);  
            }
            break;
        case 2:
            cout << "������ ����: ";
            cin >> username;
            cout << "������ ������: ";
            cin >> password;
            if (teachers_manager.login_user(username, password)) {
                teacher_menu(course_manager, students_manager);  
            }
            break;
        case 3:
            cout << "������ ����: ";
            cin >> username;
            cout << "������ ������: ";
            cin >> password;
            if (students_manager.login_user(username, password)) {
                student_menu(course_manager, students_manager, username); 
            }
            break;
        case 4:
            cout << "������ ��'� �����������: ";
            cin >> username;
            cout << "������ ������: ";
            cin >> password;
            students_manager.register_user(username, password); 
            break;
        default:
            cout << "������� ����!\n";
            break;
        }
    }

    cout << "�������� ���������.\n";
    return 0;
}
