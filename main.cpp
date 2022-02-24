#include "functions.h"

int main() {
    // input data
    vector<data> arr;
    string from_file;
    cout << "Ar norite nuskaityti duomenis is failo? (y/n): ";
    cin >> from_file;
    if (from_file == "y") {
        // read from file
        cout << "Iveskite failo pavadinima su pletiniu: ";
        string filename;
        cin >> filename;
        read_data(arr, filename);
        quick_sort(arr, 0, arr.size()-1);
        print(arr, 3);
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