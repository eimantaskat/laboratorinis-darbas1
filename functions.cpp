#include "functions.hpp"
#include "student.hpp"

double median(vector<int> grades) {
    std::sort(grades.begin(), grades.end());

    if(grades.size() % 2 == 0) {
        return (grades[grades.size()/2] + grades[(grades.size() / 2) - 1]) / 2.0;
    } else  {
        return grades[grades.size()/2];
    }
}

double average(vector<int> arr) {
    if(arr.size() > 0) {
        return std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
    } else {
        return 0;
    }
}

bool check_select3(string s) {
    std::regex reg("[1-3]");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}

bool check_select2(string s) {
    std::regex reg("[1-2]");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}

bool is_int(string s) {
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}

bool is_grade(string s) {
    std::regex reg("[0-9]");
    if(std::regex_match(s, reg) || s == "10")
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