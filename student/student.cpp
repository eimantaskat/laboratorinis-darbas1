#include "student.hpp"

Student::Student(std::string name, std::string surname, std::vector<int> grades, int exam) {
    name__ = name;
    surname__ = surname;
    grades_ = grades;
    exam_ = exam; 
}

Student::Student(const Student &stud) {
    name__ = stud.name();
    surname__ = stud.surname();
    grades_ = stud.grades();
    exam_ = stud.exam();
}

Student& Student::operator=(const Student& stud) {
    name__ = stud.name();
    surname__ = stud.surname();
    grades_ = stud.grades();
    exam_ = stud.exam();
    return *this;
}

bool Student::operator==(const Student& stud) {
    return (name__ == stud.name() && surname__ == stud.surname() && grades_ == stud.grades() && exam_ == stud.exam());
}

bool Student::operator!=(const Student& stud) {
    return !(name__ == stud.name() && surname__ == stud.surname() && grades_ == stud.grades() && exam_ == stud.exam());
}

std::ostream& operator<<(std::ostream& out, const Student& stud) {
    out << stud.name__ << " " << stud.surname__ << " ";
    for (int grade:stud.grades_)
        out << grade << " ";
    out << stud.exam_;
    return out;
}

double Student::finalGrade(double (*func) (std::vector<int>)) const {
    return 0.4 * func(grades_) + 0.6 * exam_;
}

bool operator<(const Student& a, const Student& b) {
    if (a.name__ != b.name__)
        return a.name__ < b.name__;
    else
        return a.surname__ < b.surname__;
}

bool operator>(const Student& a, const Student& b) {
    if (a.name__ != b.name__)
        return a.name__ > b.name__;
    else
        return a.surname__ > b.surname__;
}

bool operator<=(const Student& a, const Student& b) {
    if (a.name__ != b.name__)
        return a.name__ <= b.name__;
    else
        return a.surname__ <= b.surname__;
}

bool operator>=(const Student& a, const Student& b) {
    if (a.name__ != b.name__)
        return a.name__ >= b.name__;
    else
        return a.surname__ >= b.surname__;
}

bool compareBySurname(const Student& a, const Student& b) {
    if (a.surname() != b.surname())
        return a.surname() < b.surname();
    else
        return a.name() < b.name();
}