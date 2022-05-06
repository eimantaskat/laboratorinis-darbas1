#include "person.hpp"

Person::Person(std::string name, std::string surname) {
    name__ = name;
    surname__ = surname;
}

// Person::Person(const Person &p) {
//     name__ = p.name();
//     surname__ = p.surname();
// }

// Person& Person::operator=(const Person& p) {
//     name__ = p.name();
//     surname__ = p.surname();
//     return *this;
// }

// bool Person::operator==(const Person& p) {
//     return (name__ == p.name() && surname__ == p.surname());
// }

// bool Person::operator!=(const Person& p) {
//     return !(name__ == p.name() && surname__ == p.surname());
// }

// std::ostream& operator<<(std::ostream& out, const Person& p) {
//     out << p.name__ << " " << p.surname__;
//     return out;
// }

// bool operator<(const Person& a, const Person& b) {
//     if (a.name__ != b.name__)
//         return a.name__ < b.name__;
//     else
//         return a.surname__ < b.surname__;
// }

// bool operator>(const Person& a, const Person& b) {
//     if (a.name__ != b.name__)
//         return a.name__ > b.name__;
//     else
//         return a.surname__ > b.surname__;
// }

// bool operator<=(const Person& a, const Person& b) {
//     if (a.name__ != b.name__)
//         return a.name__ <= b.name__;
//     else
//         return a.surname__ <= b.surname__;
// }

// bool operator>=(const Person& a, const Person& b) {
//     if (a.name__ != b.name__)
//         return a.name__ >= b.name__;
//     else
//         return a.surname__ >= b.surname__;
// }