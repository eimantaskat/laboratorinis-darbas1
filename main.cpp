#include "functions.h"

bool compareByName(const data &a, const data &b) {
    if (a.name != b.name)
        return a.name < b.name;
    else
        return a.surname < b.surname;
}

bool compareBySurname(const data &a, const data &b) {
    if (a.surname != b.surname)
        return a.surname < b.surname;
    else
        return a.name < b.name;
}

int main() {
    // input data
    vector<data> arr;
    string from_file;

    cout << "Ar norite nuskaityti duomenis is failo? (y/n): ";
    cin >> from_file;

    if (from_file == "y") {
        while (true) {
            // read from file
            cout << "Iveskite failo pavadinima su pletiniu: ";
            string filename;
            cin >> filename;

            read_data(arr, filename);
            if (arr.size() > 0) {
                cout << "Pagal ka norite rusiuoti studentus?\n1. Varda\n2. Pavarde\n";
                string select;

                while (true) {
                    cin >> select;
                    if(!check_select(select)) {
                        cout << "Iveskite 1 arba 2" << endl;
                    } else {
                        int s = stoi(select);
                        
                        // quick_sort(arr, 0, arr.size()-1);
                        switch (s) {
                        case 1:
                            std::sort(arr.begin(), arr.end(), compareByName);
                            break;
                        
                        case 2:
                            std::sort(arr.begin(), arr.end(), compareBySurname);
                            break;
                        }
                        
                        print(arr, 3);
                        break;
                    }
                }
                break;
            }
        }
    } else {
        // input manually
        input_data(arr);

        // ask user how to calculate final grade
        cout << "Pagal ka norite skaiciuoti galutini bala?\n1. Vidurki\n2. Mediana\n";
        string select;

        while (true) {
            cin >> select;

            if(!check_select(select)) {
                cout << "Iveskite 1 arba 2" << endl;
            } else {
                int s = stoi(select);
                // print data
                print(arr, s);
                break;
            }
        }
    }
}