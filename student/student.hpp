#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <iostream>

#include "average.hpp"

class Student {
    private:
        std::string name__;
        std::string surname__;
        int exam_;
        std::vector<int> grades_;
    public:
        Student() : exam_(0) {} // default constructor
        Student(std::string name, std::string surname, std::vector<int> grades, int exam); // constructor
        ~Student() {} // destructor
        Student(const Student& stud); // copy constructor
        Student& operator=(const Student& stud); // copy assignment operator
        bool operator==(const Student& stud); // is equal to operator
        bool operator!=(const Student& stud); // not equal to operator
        inline std::string name() const { return name__; }
        inline std::string surname() const { return surname__; }
        inline int exam() const { return exam_; }
        inline std::vector<int> grades() const { return grades_; }
        inline void setName(std::string name) { name__ = name; }
        inline void setSurame(std::string surname) { surname__ = surname; }
        inline void setGrades(std::vector<int> grades) { grades_ = grades; }
        inline void setExam(int exam) { exam_ = exam; }
        double finalGrade(double (*func) (std::vector<int>) = average) const;
        friend std::ostream& operator<<(std::ostream& out, const Student& stud); 
};