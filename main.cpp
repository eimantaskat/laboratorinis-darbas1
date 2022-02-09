#include <iostream>
#include <iomanip>
#include <numeric>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::accumulate;
using std::setprecision;

struct data {
    string name, surname;
    int* grades;
    int exam, grades_len = 0;
};

data* input_data(int& arr_length);
int* input_grades(int& arr_length);

double average(int* arr, int arr_length) {
    return accumulate(arr, arr + arr_length, 0.0) / arr_length;
}



void print(data* arr, int arr_length) {
    cout << endl;
    cout << left << setw(12) << "Vardas" 
        << left << setw(12) << " Pavarde"
        << left << setw(12) << " Galutinis (vid.)" << endl;
    cout << "-----------------------------------------------------" << endl;
    // cout << setw(20) << setfill('-') << "" << endl;
    for(int i = 0; i < arr_length; i++) {
        cout << left << setw(12) << arr[i].name << " " 
            << left << setw(12) << arr[i].surname << " " 
            << left << setw(12) << setprecision(2) << 0.4 * average(arr[i].grades, arr[i].grades_len) + 0.6 * arr[i].exam << endl;
    }
}

int main() {
    int arr_length = 0;
    data* arr = input_data(arr_length);
    print(arr, arr_length);
    // for(int i = 0; i < arr_length; i++) {
    //     cout << endl << endl << arr[i].name << " " << arr[i].surname << " " << endl;
    //     for(int j = 0; j < arr[i].grades_len; j++) {
    //         cout << arr[i].grades[j] << " ";
    //     }
    //     cout << endl << arr[i].exam << endl;
    // }
}


 

int* input_grades(int& arr_length) {
    int* arr = new int[arr_length];
    cout << "Iveskite namu darbu rezultatus atskiriant tarpu: ";
    do {
        int input;
        if(cin >> input) {
            int* tmp_arr = new int[arr_length + 1];
            for(int i = 0; i < arr_length; i++) {
                tmp_arr[i] = arr[i];
            }
            delete[] arr;
            arr = tmp_arr;

            arr[arr_length] = input;
            arr_length++;
        }
    } while (cin && cin.peek() != '\n' ) ;
    return arr;
}

data* input_data(int& arr_length) {
    data* arr = new data[arr_length];
    bool add_data = true;
    while (add_data) {
        data* tmp_arr = new data[arr_length + 1];
        for(int i = 0; i < arr_length; i++) {
            tmp_arr[i] = arr[i];
        }
        delete[] arr;
        arr = tmp_arr;

        cout << "Vardas: ";
        cin >> arr[arr_length].name;
        cout << "Pavarde: ";
        cin >> arr[arr_length].surname;
        cout << "Egzamino rezultatas: ";
        cin >> arr[arr_length].exam;
        int grades_arr_length = 0;
        arr[arr_length].grades = input_grades(grades_arr_length);
        arr[arr_length].grades_len = grades_arr_length;
        arr_length++;
        
        char add_more;
        cout << "Ar norite prideti dar vieno mokinio duomenis? (y/n): ";
        cin >> add_more;
        if(add_more != 'y') {
            add_data = false;
        }
    }
    return arr;
}