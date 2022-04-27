#include "student.hpp"

Student::Student(std::string name, std::string surname, std::vector<int> grades, int exam) {
    name__ = name;
    surname__ = surname;
    grades_ = grades;
    exam_ = exam; 
}

double Student::finalGrade(double (*func) (std::vector<int>)) const {
    return 0.4 * func(grades_) + 0.6 * exam_;
}

bool compareByName(const Student& a, const Student& b) {
    if (a.name() != b.name())
        return a.name() < b.name();
    else
        return a.surname() < b.surname();
}

bool compareBySurname(const Student& a, const Student& b) {
    if (a.surname() != b.surname())
        return a.surname() < b.surname();
    else
        return a.name() < b.name();
}