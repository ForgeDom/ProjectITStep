#ifndef ADMIN_H
#define ADMIN_H

#include <string>

// ���� ���������
void add_teacher(const string& username, const string& password);

// ��������� ������ ����������
void view_teachers();

// ������� ���������
void delete_teacher(const string& teacher_username);

// ���� ������������
void admin_menu();

#endif // ADMIN_H
