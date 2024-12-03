#ifndef ADMIN_H
#define ADMIN_H

#include <string>

// Додає викладача
void add_teacher(const string& username, const string& password);

// Переглядає список викладачів
void view_teachers();

// Видаляє викладача
void delete_teacher(const string& teacher_username);

// Меню адміністратора
void admin_menu();

#endif // ADMIN_H
