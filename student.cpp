#include "student.hpp"

Student::Student(std::istream& is) {
    readStudent(is);  
}

double Student::finalGrade(double (*func) (vector<int>)) const {
    return 0.4 * func(grades_) + 0.6 * exam_;
}

void Student::readStudent(std::istream& is) {
    is >> name__ >> surname__;
    string grade;
    while (!is.eof()) {
        is >> grade;
        if(!is_grade(grade))
            throw(1);
        int g = std::stoi(grade);
        grades_.push_back(g);
    }
    if (grades_.size() > 0) {
        exam_ = *(grades_.end() - 1);
        grades_.pop_back();
    }
}

bool compareByName(const Student& a, const Student& b) {
    if (a.name() != b.name())
        return a.name() < b.name();
    else
        return a.surname() < b.surname();
}

void read_data(vector<Student>& arr, string filename) {
    try {
        auto start_reading = hrClock::now();

        std::stringstream buffer, ln;
        std::fstream file(filename);
        if (!file) {
            throw(1);
        }
        buffer << file.rdbuf();
        file.close();

        auto stop_reading = hrClock::now();
        auto reading_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_reading - start_reading);
        cout << "Failo skaitymas uztruko: " << reading_duration.count() * 1e-9 << "s\n";

        auto start_processing = hrClock::now();
        
        string line;
        std::getline(buffer, line);
        if(buffer.tellg() < 0)
            throw(3);
        while(std::getline(buffer, line)) {
            ln << line;
            try {
                Student stud(ln);
                arr.push_back(stud);
            } catch (int err) {
                throw(2);
            }
            ln.clear();
        }

        auto stop_processing = hrClock::now();
        auto processing_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_processing - start_processing);
        cout << "Duomenu paruosimas programos naudojimui uztruko: " << processing_duration.count() * 1e-9 << "s\n";
    }
    catch (int err) {
        switch (err) {
        case 1:
            cout << "Failas neegzistuoja\n";
            break;
        case 2:
            arr.clear();
            cout << "Faile yra klaida\n";
            break;
        case 3:
            cout << "Failas yra tuscias\n";
            break;
        }
    }
}