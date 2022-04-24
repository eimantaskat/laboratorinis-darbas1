#pragma once

#include "functions.hpp"

class Student {
    private:
        string name__;
        string surname__;
        double exam_;
        vector<int> grades_;
    public:
        Student() : exam_(0) { }  // default konstruktorius
        Student(string name, string surname, vector<int> grades, int exam);
        inline string name() const { return name__; }
        inline string surname() const { return surname__; }
        inline double exam() const { return exam_; }
        inline void setName(string name) { name__ = name; }
        inline void setSurame(string surname) { surname__ = surname; }
        inline void setGrades(vector<int> grades) { grades_ = grades; }
        inline void setName(int exam) { exam_ = exam; }
        double finalGrade(double (*func) (vector<int>) = average) const;
};

void read_data(vector<Student>&, string);