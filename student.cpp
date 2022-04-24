#include "student.hpp"

Student::Student(string name, string surname, vector<int> grades, int exam) {
    name__ = name;
    surname__ = surname;
    grades_ = grades;
    exam_ = exam; 
}

double Student::finalGrade(double (*func) (vector<int>)) const {
    return 0.4 * func(grades_) + 0.6 * exam_;
}

bool compareByName(const Student& a, const Student& b) {
    if (a.name() != b.name())
        return a.name() < b.name();
    else
        return a.surname() < b.surname();
}

void read_data(vector<Student>& arr, string filename) {
    try {
        auto start = std::chrono::high_resolution_clock::now();
        std::stringstream buffer;
        // open file
        std::ifstream file(filename);
        if (!file) {
            throw(1);
        }
        buffer << file.rdbuf();

        file.close();
        auto stop = hrClock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "Failo skaitymas uztruko: " << duration.count() * 1e-9 << "s\n";

        start = hrClock::now();
        int lines_count = 0;
        string line;
        while (getline(buffer, line)) {
            lines_count++;
        }

        if (lines_count == 0) {
            throw(3);
        }

        buffer.clear();
        buffer.seekg(0, std::ios::beg);

        // read file header
        vector<string> header;
        header.reserve(4);
        while (buffer.peek() != '\n') {
            string data;
            buffer >> data;
            header.push_back(data);
        }

        // get homework count
        int homework_count = header.size() - 3;
        header.clear();

        arr.reserve(lines_count - 1);
        // read data

        while (!buffer.eof()) {
            int i = 0, exam;
            string name, surname;
            vector<int> grades;
            buffer >> name >> surname;
            for (int j = 0; j < homework_count; j++) {
                grades.push_back(int());
                buffer >> grades[j];
            }
            buffer >> exam;
            arr.push_back(Student(name, surname, grades, exam));
            if (i > lines_count) {
                throw(2);
            }
            i++;
        }
        stop = hrClock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "Duomenu paruosimas programos naudojimui uztruko: " << duration.count() * 1e-9 << "s\n";
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