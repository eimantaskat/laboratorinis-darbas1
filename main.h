#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>
#include <regex>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::accumulate;
using std::setprecision;
using std::vector;

struct data {
    string name, surname;
    int exam;
    vector<int> grades;
};

#endif