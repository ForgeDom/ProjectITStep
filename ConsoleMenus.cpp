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
            cerr << "Не вдалося відкрити файл students.txt для запису.\n";
            return;
        }
        file << username << " " << password << "\n";
        file.close();
        cout << "Студента " << username << " додано успішно.\n";
    }

    void delete_student(const string& student_username, CourseManager& course_manager) {

        ifstream file("students.txt");
        if (!file.is_open()) {
            cerr << "Не вдалося відкрити файл students.txt.\n";
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
            cout << "Студента з ім'ям " << student_username << " не знайдено.\n";
            return;
        }

        ofstream outfile("students.txt", ios::trunc);
        for (const auto& student : students) {
            outfile << student.first << " " << student.second << "\n";
        }
        outfile.close();

        cout << "Студента " << student_username << " успішно видалено з файлу.\n";

        // Видалення студента з усіх курсів
        for (auto& course : course_manager.get_courses()) {
            course.remove_student(student_username);  // Видалення студента з кожного курсу
        }
    }

     
  void view_students() {
        ifstream file("students.txt");
        if (!file.is_open()) {
            cerr << "Не вдалося відкрити файл students.txt.\n";
            return;
        }

        string username, password;
        cout << "Список студентів:\n";
        while (file >> username >> password) {
            cout << "- " << username << "\n";
        }
        file.close();
  }

    void add_teacher(const string& username, const string& password) {
        ofstream file("teachers.txt", ios::app);
        if (!file.is_open()) {
            cerr << "Не вдалося відкрити файл teachers.txt для запису.\n";
            return;
        }
        file << username << " " << password << "\n";
        file.close();
        cout << "Викладача " << username << " додано успішно.\n";
    }

    void view_teachers() {
        ifstream file("teachers.txt");
        if (!file.is_open()) {
            cerr << "Не вдалося відкрити файл teachers.txt.\n";
            return;
        }

        string username, password;
        cout << "Список викладачів:\n";
        while (file >> username >> password) {
            cout << "Ім'я: " << username << " | Пароль: " << password << "\n";
        }
        file.close();
    }

    void delete_teacher(const string& teacher_username) {
        ifstream file("teachers.txt");
        if (!file.is_open()) {
            cerr << "Не вдалося відкрити файл teachers.txt.\n";
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
            cout << "Викладача з ім'ям " << teacher_username << " не знайдено.\n";
            return;
        }

        ofstream outfile("teachers.txt", ios::trunc);
        for (const auto& teacher : teachers) {
            outfile << teacher.first << " " << teacher.second << "\n";
        }
        outfile.close();

        cout << "Викладач " << teacher_username << " успішно видалений.\n";
    }

    void admin_menu(UserManager& teachers_manager, CourseManager& course_manager) {
        clear_screen();
        while (true) {
            cout << "\nМеню адміністратора:\n";
            cout << "1. Додати викладача\n";
            cout << "2. Переглянути викладачів\n";
            cout << "3. Видалити викладача\n";
            cout << "4. Переглянути студентів\n";  // Додано
            cout << "5. Видалити студента\n";     // Додано
            cout << "6. Вийти\n";
            cout << "Ваш вибір: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                string username, password;
                cout << "Введіть ім'я викладача: ";
                cin >> username;
                cout << "Введіть пароль для викладача: ";
                cin >> password;
                add_teacher(username, password);
            }
            else if (choice == 2) {
                view_teachers();
            }
            else if (choice == 3) {
                string username;
                cout << "Введіть ім'я викладача, якого потрібно видалити: ";
                cin >> username;
                delete_teacher(username);
            }
            else if (choice == 4) {
                view_students(); // Перегляд студентів
            }
            else if (choice == 5) {
                string student_username;
                cout << "Введіть ім'я студента, якого потрібно видалити: ";
                cin >> student_username;
                delete_student(student_username, course_manager); // Видалення студента
            }
            else if (choice == 6) {
                cout << "Вихід з меню адміністратора.\n";
                break;
            }
            else {
                cout << "Неправильний вибір. Спробуйте ще раз.\n";
            }
            system("pause");
        }
    }


    void teacher_menu(CourseManager& course_manager, UserManager& student_manager) {
    while (true) {
        cout << "\n--- Меню Викладача ---\n";
        cout << "1. Додати курс\n";
        cout << "2. Переглянути курси\n";
        cout << "3. Додати студента до курсу\n";
        cout << "4. Переглянути студентів на курсі\n";  // Перегляд студентів
        cout << "5. Встановити оцінку студенту\n";
        cout << "6. Вийти\n";
        cout << "Ваш вибір: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string course_name;
            cout << "Введіть назву нового курсу: ";
            cin.ignore();
            getline(cin, course_name);
            course_manager.add_course(course_name);
        }
        else if (choice == 2) {
            course_manager.view_courses();
        }
        else if (choice == 3) {
            string course_name, student_name;
            cout << "Введіть назву курсу: ";
            cin.ignore();
            getline(cin, course_name);
            Course* course = course_manager.get_course(course_name);
            if (course) {
                cout << "Введіть ім'я студента: ";
                getline(cin, student_name);
                course->add_student(student_name);
            }
            else {
                cout << "Курс не знайдено.\n";
            }
        }
        else if (choice == 4) {
            string course_name;
            cout << "Введіть назву курсу: ";
            cin.ignore();
            getline(cin, course_name);
            Course* course = course_manager.get_course(course_name);
            if (course) {
                course->view_students();  // Перегляд студентів
            }
            else {
                cout << "Курс не знайдено.\n";
            }
        }
        else if (choice == 5) {
            string course_name, student_name;
            int grade;
            cout << "Введіть назву курсу: ";
            cin.ignore();
            getline(cin, course_name);
            Course* course = course_manager.get_course(course_name);
            if (course) {
                cout << "Введіть ім'я студента: ";
                getline(cin, student_name);
                cout << "Введіть оцінку: ";
                cin >> grade;
                course->set_grade(student_name, grade);
            }
            else {
                cout << "Курс не знайдено.\n";
            }
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    }
}


    void student_menu(CourseManager& course_manager,UserManager& user_manager, const string& student_name) {
        while (true) {
            cout << "\n--- Меню Студента ---\n";
            cout << "1. Переглянути доступні курси\n";
            cout << "2. Переглянути оцінки за курсами\n";
            cout << "3. Вийти\n";
            cout << "Ваш вибір: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                course_manager.view_courses();
            }
            else if (choice == 2) {
                cout << "Ваші оцінки:\n";
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
                cout << "Неправильний вибір. Спробуйте ще раз.\n";
            }
        }
    }