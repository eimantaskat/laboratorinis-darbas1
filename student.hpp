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
        Student(std::istream& is);
        inline string name() const { return name__; }    // get'eriai, inline
        inline string surname() const { return surname__; }  // get'eriai, inline
        inline double exam() const { return exam_; }  // get'eriai, inline
        double finalGrade(double (*func) (vector<int>) = average) const;  // get'eriai
        void readStudent(std::istream&);  // set'eriai
};

void read_data(vector<Student>&, string);