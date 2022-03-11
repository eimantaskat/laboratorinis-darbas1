#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "main.h"

bool is_grade(string);
bool check_name(string);
bool check_select(string);
void quick_sort(vector<int>& array, int first, int last);
void quick_sort(vector<data>& array, int first, int last);
double median(vector<int> arr);
double average(vector<int> arr);
void input_grades(vector<int>& grades);
void input_data(vector<data>& arr);
void print(vector<data> arr, int s);
void generate(int, int);
void read_data(vector<data>& arr, string filename);
bool compareByName(const data&, const data&);
bool compareBySurname(const data&, const data&);
bool is_int(string);

#endif