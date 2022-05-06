#pragma once

#include <string>
#include <iostream>

class Person {
    protected:
        std::string name__;
        std::string surname__;

        Person() : name__(""), surname__("") {}
        Person(std::string name, std::string surname);
        
    public:
        inline std::string name() const { return name__; }
        inline std::string surname() const { return surname__; }

        inline void setName(std::string name) { name__ = name; }
        inline void setSurame(std::string surname) { surname__ = surname; }
};