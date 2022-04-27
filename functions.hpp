#pragma once

#include "main.hpp"

bool check_select3(string);
bool check_select2(string);
bool is_int(string);
bool is_grade(string);

void generate_data();
void generate(int, int);
// void read_data(vector<Student>&, string);

void vector_student_sorting();
void list_student_sorting();
void deque_student_sorting();

void read_data(vector<Student>&, string);
void read_data(list<Student>&, string);
void read_data(deque<Student>&, string);
bool compareByName(const Student&, const Student&);
void write_students(const string, const vector<Student>);
void write_students(const string, const list<Student>);
void write_students(const string, const deque<Student>);
void split_two_new(vector<Student>);
void split_one_new(vector<Student>);
void split_two_new(list<Student>);
void split_one_new(list<Student>);
void split_two_new(deque<Student>);
void split_one_new(deque<Student>);