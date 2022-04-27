#pragma once

#include <string>
#include <vector>
#include <numeric>

#include "average.hpp"

class Student {
    private:
        std::string name__;
        std::string surname__;
        double exam_;
        std::vector<int> grades_;
    public:
        Student() : exam_(0) { }  // default konstruktorius
        Student(std::string name, std::string surname, std::vector<int> grades, int exam);
        inline std::string name() const { return name__; }
        inline std::string surname() const { return surname__; }
        inline double exam() const { return exam_; }
        inline void setName(std::string name) { name__ = name; }
        inline void setSurame(std::string surname) { surname__ = surname; }
        inline void setGrades(std::vector<int> grades) { grades_ = grades; }
        inline void setName(int exam) { exam_ = exam; }
        double finalGrade(double (*func) (std::vector<int>) = average) const;
};