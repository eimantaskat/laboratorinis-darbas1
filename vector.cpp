#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>
#include <regex>
#include <vector>
#include <random>
#include <ctime>

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
    int* grades = new int[1];
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
    // input data
    vector<data> arr;
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

// functions to check if input is correct

bool is_grade(string s) {
    // if string contains characters from 0 to 9 or is equal to 10 return true
    std::regex reg("[0-9]");
    if(std::regex_match(s, reg) || s == "10")
        return true;
    else
        return false;
}

bool check_name(string s) {
    // if string starts with capital letter and contains only letters return true
    std::regex reg("^[A-Z][a-z]*$");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}

bool check_select(string s) {
    // if string is equal either to 1 or 2 return true
    std::regex reg("[1-2]");
    if(std::regex_match(s, reg))
        return true;
    else
        return false;
}


// sorting algorythm
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


// function to find median of an array
double median(int* arr, int arr_length) {
    // sort an array
    quick_sort(arr, 0, arr_length-1);
    // std::sort(&arr[0], &arr[arr_length-1]);

    // if array has even number of elements return average of middle elements
    // else return middle element
    if(arr_length % 2 == 0) {
        return (arr[arr_length/2] + arr[(arr_length / 2) - 1]) / 2.0;
    } else  {
        return arr[arr_length/2];
    }
}

// function to calculate the average of an array
double average(int* arr, int arr_length) {
    // if array is not empty
    // calculate the sum of elements and divide it by the length of an array
    if(arr_length > 0) {
        return accumulate(arr, arr + arr_length, 0.0) / arr_length;
    } else {
        return 0;
    }
}

// funtion to input homework grades
void input_grades(int*& arr, int& arr_length) {
    cout << "Iveskite namu darbu rezultatus, norint baigti, iveskite 0: " << endl;
    string input;
    int number = 10;
    while(true) {
        // input and verify grade
        cout << arr_length + 1 << " pazymys: ";
        if(cin >> input) {
            if(!is_grade(input)) {
                cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10" << endl;
            } else {
                number = stoi(input);
                if(number < 0 || number > 10) {
                    cout << "Pazymys turi buti sveikasis skaicius nuo 1 iki 10" << endl;
                } else {
                    // if input is 0 break the loop 
                    // else expand array
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
}

// function to input data
void input_data(vector<data>& arr) {
    bool add_data = true;
    int i = 0;
    while (add_data) {
        // add new element to an array
        arr.push_back(data());

        // input and verify name
        cout << "Vardas: ";
        string name;
        while(true) {
            cin >> name;
            if(!check_name(name)) {
                cout << "Ar " << name << " tikrai yra mokinio vardas? (y/n): ";
                char confirm;
                cin >> confirm;
                if(confirm == 'y' || confirm == 'Y') {
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

        // input and verify surname
        cout << "Pavarde: ";
        string surname;
        while(true) {
            cin >> surname;
            if(!check_name(surname)) {
                cout << "Ar " << surname << " tikrai yra mokinio pavarde? (y/n): ";
                char confirm;
                cin >> confirm;
                if(confirm == 'y' || confirm == 'Y') {
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

        char random;
        cout << "Ar norite sugeneruoti atsitiktinius balus uz namu darbus ir egzamina? (y/n): ";
        cin >> random;
        if(random == 'y' || random == 'Y') {
            // intitialise random number generator
            srand(time(NULL));
            // generate exam result
            arr[i].exam = 1 + rand() % 10;
            
            // ask how many grades to generate
            int n;
            cout << "Kiek norite sugeneruoti namu darbu pazymiu? ";
            while(!(cin >> n)) {
                cout << "Iveskite sveikaji skaiciu \n";
                cin.clear();
                cin.ignore(256, '\n');
            }
            
            // generate array of random grades
            arr[i].grades = new int [n];
            arr[i].grades_len = n;
            for(int j = 0; j < n; j++) {
                arr[i].grades[j] = 1 + rand() % 10;
            }
            

        } else {
            // input and verify exam result
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
            // input homework grades
            int grades_arr_length = 0;
            input_grades(arr[i].grades, grades_arr_length);
            arr[i].grades_len = grades_arr_length;
            i++;
        }

        // add more students or stop
        char add_more;
        cout << "Ar norite prideti dar vieno mokinio duomenis? (y/n): ";
        cin >> add_more;
        if(add_more != 'y' || add_more != 'Y') {
            add_data = false;
        }
    }
}

// function to print results
void print(vector<data> arr, int s) {
    // print header line
    cout << endl;
    cout << left << setw(12) << "Vardas" 
        << left << setw(12) << " Pavarde";
    // print based on s value
    switch(s) {
        case 1:
            cout << left << setw(20) << " Galutinis (vid.)" << endl;
            break;
        case 2:
            cout << left << setw(20) << " Galutinis (med.)" << endl;
            break;
    }
    // print a line of dashes
    cout << std::string(44, '-') << endl;
    // print all elements of an array
    for(auto i:arr) {
        cout << left << setw(12) << i.name << " " 
            << left << setw(12) << i.surname << " ";
            // calculate final grade using average or median based on s value
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