#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <iomanip>

#include "../person/person.hpp"
#include "average.hpp"

class Student : public Person {
    private:
        int exam_;
        std::vector<int> grades_;
    public:
        Student() : exam_(0) {} // default constructor
        Student(std::string name, std::string surname, std::vector<int> grades, int exam) : Person(name, surname), grades_(grades), exam_(exam) {}
        ~Student() { grades_.clear(); } // destructor
        Student(const Student& stud); // copy constructor

        Student& operator=(const Student& stud); // copy assignment operator
        friend std::ostream& operator<<(std::ostream& out, const Student& stud); // insertion operator

        bool operator==(const Student& stud);
        bool operator!=(const Student& stud);

        inline std::string name() const { return name__; }
        inline std::string surname() const { return surname__; }
        inline int exam() const { return exam_; }
        inline std::vector<int> grades() const { return grades_; }

        inline void setGrades(std::vector<int> grades) { grades_ = grades; }
        inline void setExam(int exam) { exam_ = exam; }

        double finalGrade(double (*func) (std::vector<int>) = average) const;
};