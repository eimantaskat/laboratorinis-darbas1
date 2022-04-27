#include "../functions.hpp"

bool check_select3(const string s) {
    std::regex reg("[1-3]");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}

bool check_select2(const string s) {
    std::regex reg("[1-2]");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}

bool is_int(const string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}

bool is_grade(const string s) {
    std::regex reg("[0-9]");
    if(std::regex_match(s, reg) || s == "10")
        return true;
    else
        return false;
}

bool check_name(const string s) {
    std::regex reg("^[A-Z][a-z]*$");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}


void generate(int n, int nd) {
    std::mt19937 mt;
    mt.seed(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(0, 10);

    std::ofstream file(std::to_string(n) + "st_" + std::to_string(nd) + "nd.txt");

    file << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 0; i < nd; i++) {
        file << std::right << std::setw(5) << "ND" + std::to_string(i+1);
    }
    file << std::setw(6) << "Egz.\n";

    std::stringstream line;
    for (int i = 0; i < n; i++) {
        line << std::left << std::setw(20) << "Vardas" + std::to_string(i + 1) << std::setw(20) << "Pavarde" + std::to_string(i + 1);
        
        for (int i = 0; i <= nd; i++)
            line << std::right << std::setw(5) << dist(mt);

        if (i + 1 != n)
            line << "\n";

        if (i % 1000 == 0) {
            file << line.rdbuf();
            line.clear();
        }
    }

    file << line.rdbuf();
    file.close();
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

void read_data(list<Student>& arr, string filename) {
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
        list<string> header;
        while (buffer.peek() != '\n') {
            string data;
            buffer >> data;
            header.push_back(data);
        }

        // get homework count
        int homework_count = header.size() - 3;
        header.clear();

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

void read_data(deque<Student>& arr, string filename) {
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
        deque<string> header;
        while (buffer.peek() != '\n') {
            string data;
            buffer >> data;
            header.push_back(data);
        }

        // get homework count
        int homework_count = header.size() - 3;
        header.clear();

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


void write_students(const string filename, const vector<Student> arr) {
    // write student name, surname and final grade to stringstream
    std::stringstream line;
    for(auto student:arr)
        line << std::left << std::setw(20) << student.name() << std::setw(20) << student.surname() << std::setw(20) << student.finalGrade() << '\n';
    
    std::ofstream file (filename);

    // write header line
    file << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis balas" << std::endl;

    // write stringstream to file
    file << line.rdbuf();

    file.close();
}

void write_students(const string filename, const list<Student> arr) {
    // write student name, surname and final grade to stringstream
    std::stringstream line;
    for(auto student:arr)
        line << std::left << std::setw(20) << student.name() << std::setw(20) << student.surname() << std::setw(20) << student.finalGrade() << '\n';
    
    std::ofstream file (filename);

    // write header line
    file << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis balas" << std::endl;

    // write stringstream to file
    file << line.rdbuf();

    file.close();
}

void write_students(const string filename, const deque<Student> arr) {
    // write student name, surname and final grade to stringstream
    std::stringstream line;
    for(auto student:arr)
        line << std::left << std::setw(20) << student.name() << std::setw(20) << student.surname() << std::setw(20) << student.finalGrade() << '\n';
    
    std::ofstream file (filename);

    // write header line
    file << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis balas" << std::endl;

    // write stringstream to file
    file << line.rdbuf();

    file.close();
}

void input_grades(vector<int>& grades) {
    cout << "Iveskite namu darbu rezultatus, norint baigti, iveskite 0: " << "\n";
    string input;
    int number = 10;
    while(true) {
        // input and verify grade
        cout << grades.size() + 1 << " pazymys: ";
        if(cin >> input) {
            if(!is_grade(input)) {
                cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10" << "\n";
            } else {
                number = stoi(input);
                if(number < 0 || number > 10) {
                    cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10" << "\n";
                } else {
                    // if input is 0 break the loop 
                    // else add grade to an array
                    if(number == 0)
                        break;
                    grades.push_back(number);
                }
            }
        }
    };
}