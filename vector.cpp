#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>
#include <regex>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::accumulate;
using std::setprecision;
using std::vector;

struct data {
    string name, surname;
    int* grades;
    int exam, grades_len = 0;
};

bool is_grade(string s);
bool check_name(string s);
bool check_select(string s);
void quick_sort(int array[], int first, int last);
double median(int* arr, int arr_length);
double average(int* arr, int arr_length);
int* input_grades(int& arr_length);
void input_data(vector<data>& arr);
void print(vector<data> arr, int s);

int main() {
    vector<data> arr;
    input_data(arr);
    cout << "Pagal ka norite skaiciuoti galutini bala?\n1. Vidurki\n2. Mediana\n";
    string select;
    while (true) {
        cin >> select;
        if(!check_select(select)) {
            cout << "Iveskite 1 arba 2" << endl;
        } else {
            int s = stoi(select);
            print(arr, s);
            break;
        }
    }
}

void quick_sort(int array[], int first, int last) {
    if (first < last) {
        // find pivot element that all smaller elements are on the left, greater on the right
        
        // select last element as pivot
        int pivot = array[last];

        // select first element as greater
        int i = first;

        // compare every element of array with pivot
        for (int j = first; j < last; j++) {
            // if element smaller than pivot is found, swap it with greater element
            if (array[j] <= pivot) {
                int tmp =  array[i];
                array[i] = array[j];
                array[j] = tmp;

                // select next element as greater
                i++;
            }
        }

        // swap pivot with greater element
        int tmp =  array[i];
        array[i] = array[last];
        array[last] = tmp;

        // quick sort left and right sides 
        quick_sort(array, first, i - 1);
        quick_sort(array, i + 1, last);
    }
}

bool is_grade(string s) {
    std::regex reg("[0-9]");
    if(std::regex_match(s, reg) || s == "10")
        return true;
    else
        return false;
}

int* input_grades(int& arr_length) {
    int* arr = new int[arr_length];
    cout << "Iveskite namu darbu rezultatus, norint baigti, iveskite 0: " << endl;
    string input = "";
    int number = 10;
    while(true) {
        cout << arr_length + 1 << " pazymys: ";
        if(cin >> input) {
            if(!is_grade(input)) {
                cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10" << endl;
            } else {
                number = stoi(input);
                if(number < 0 || number > 10) {
                    cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10" << endl;
                } else {
                    if(number == 0)
                        break;
                    int* tmp_arr = new int[arr_length + 1];
                    for(int i = 0; i < arr_length; i++) {
                        tmp_arr[i] = arr[i];
                    }
                    delete[] arr;
                    arr = tmp_arr;

                    arr[arr_length] = number;
                    arr_length++;
                }
            }
        }
    };
    
    return arr;
}

double median(int* arr, int arr_length) {
    quick_sort(arr, 0, arr_length-1);
    if(arr_length % 2 == 0) {
        return (arr[arr_length/2] + arr[(arr_length / 2) - 1]) / 2.0;
    } else  {
        return arr[arr_length/2];
    }
}

bool check_name(string s) {
    std::regex reg("^[A-Z][a-z]*$");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}

bool check_select(string s) {
    std::regex reg("[1-2]");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}

double average(int* arr, int arr_length) {
    if(arr_length > 0) {
        return accumulate(arr, arr + arr_length, 0.0) / arr_length;
    } else {
        return 0;
    }
}

void print(vector<data> arr, int s) {
    cout << endl;
    cout << left << setw(12) << "Vardas" 
        << left << setw(12) << " Pavarde";
    switch(s) {
        case 1:
            cout << left << setw(20) << " Galutinis (vid.)" << endl;
            break;
        case 2:
            cout << left << setw(20) << " Galutinis (med.)" << endl;
            break;
    }
    cout << std::string(44, '-') << endl;
    for(auto i:arr) {
        cout << left << setw(12) << i.name << " " 
            << left << setw(12) << i.surname << " ";
            switch(s) {
                case 1:
                    cout << left << setw(20) << setprecision(3) << 0.4 * average(i.grades, i.grades_len) + 0.6 * i.exam << endl;
                    break;
                case 2:
                    cout << left << setw(20) << setprecision(3) << 0.4 * median(i.grades, i.grades_len) + 0.6 * i.exam << endl;
                    break;
            }
    }
}

void input_data(vector<data>& arr) {
    bool add_data = true;
    int i = 0;
    while (add_data) {
        arr.push_back(data());

        cout << "Vardas: ";
        string name;
        while(true) {
            cin >> name;
            if(!check_name(name)) {
                cout << "Ar " << name << " tikrai yra mokinio vardas? (y/n): ";
                char confirm;
                cin >> confirm;
                if(confirm == 'y') {
                    arr[i].name = name;
                    break;
                } else {
                    cout << "Vardas: ";
                }
            } else {
                arr[i].name = name;
                break;
            }
        }
        cout << "Pavarde: ";
        string surname;
        while(true) {
            cin >> surname;
            if(!check_name(surname)) {
                cout << "Ar " << surname << " tikrai yra mokinio pavarde? (y/n): ";
                char confirm;
                cin >> confirm;
                if(confirm == 'y') {
                    arr[i].surname = surname;
                    break;
                } else {
                    cout << "Pavarde: ";
                }
            } else {
               arr[i].surname = surname;
                break;
            }
        }
        string exam;
        while(true) {
            cout << "Egzamino rezultatas: ";
            cin >> exam;
            if(!is_grade(exam)) {
                cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10" << endl;
            } else {
                int number = stoi(exam);
                if(number <=0 || number > 10) {
                    cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10" << endl;
                } else {
                    arr[i].exam = number;
                    break;
                }
            }
        }
        int grades_arr_length = 0;
        arr[i].grades = input_grades(grades_arr_length);
        arr[i].grades_len = grades_arr_length;
        i++;
        
        char add_more;
        cout << "Ar norite prideti dar vieno mokinio duomenis? (y/n): ";
        cin >> add_more;
        if(add_more != 'y') {
            add_data = false;
        }
    }
}