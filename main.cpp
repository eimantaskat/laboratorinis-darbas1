#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>
#include <regex>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>

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
    int exam;
    vector<int> grades;
};

bool is_grade(string s);
bool check_name(string s);
bool check_select(string s);
void quick_sort(vector<int>& array, int first, int last);
void quick_sort(vector<data>& array, int first, int last);
double median(vector<int> arr);
double average(vector<int> arr);
void input_grades(vector<int>& grades);
void input_data(vector<data>& arr);
void print(vector<data> arr, int s);
void read_data(vector<data>& arr, string filename);


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


// sorting algorythms
// sort grades
void quick_sort(vector<int>& array, int first, int last) {
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

// sort students
void quick_sort(vector<data>& array, int first, int last) {
    if (first < last) {
        // find pivot element that all smaller elements are on the left, greater on the right
        
        // select last element as pivot
        string pivot = array[last].name + array[last].surname;

        // select first element as greater
        int i = first;

        // compare every element of array with pivot
        for (int j = first; j < last; j++) {
            // if element smaller than pivot is found, swap it with greater element
            if (array[j].name+array[j].surname <= pivot) {
                data tmp =  array[i];
                array[i] = array[j];
                array[j] = tmp;

                // select next element as greater
                i++;
            }
        }

        // swap pivot with greater element
        data tmp =  array[i];
        array[i] = array[last];
        array[last] = tmp;

        // quick sort left and right sides 
        quick_sort(array, first, i - 1);
        quick_sort(array, i + 1, last);
    }
}


// function to find median of an array
double median(vector<int> arr) {
    // sort an array
    quick_sort(arr, 0, arr.size()-1);
    // std::sort(&arr[0], &arr[arr_length-1]);

    // if array has even number of elements return average of middle elements
    // else return middle element
    if(arr.size() % 2 == 0) {
        return (arr[arr.size()/2] + arr[(arr.size() / 2) - 1]) / 2.0;
    } else  {
        return arr[arr.size()/2];
    }
}

// function to calculate the average of an array
double average(vector<int> arr) {
    // if array is not empty
    // calculate the sum of elements and divide it by the length of an array
    if(arr.size() > 0) {
        return accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
    } else {
        return 0;
    }
}

// funtion to input homework grades
void input_grades(vector<int>& grades) {
    cout << "Iveskite namu darbu rezultatus, norint baigti, iveskite 0: " << endl;
    string input;
    int number = 10;
    while(true) {
        // input and verify grade
        cout << grades.size() + 1 << " pazymys: ";
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
                    grades.push_back(number);
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

        // input and verify surname
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

        char random;
        cout << "Ar norite sugeneruoti atsitiktinius balus uz namu darbus ir egzamina? (y/n): ";
        cin >> random;
        if(random == 'y') {
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
            for(int j = 0; j < n; j++) {
                arr[i].grades.push_back(1 + rand() % 10);
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
            input_grades(arr[i].grades);
        }
        i++;
        // add more students or stop
        char add_more;
        cout << "Ar norite prideti dar vieno mokinio duomenis? (y/n): ";
        cin >> add_more;
        if(add_more != 'y') {
            add_data = false;
        }
    }
}

// function to print results
void print(vector<data> arr, int s) {
    // print header line
    cout << endl;
    cout << left << setw(15) << "Vardas" 
        << left << setw(15) << " Pavarde";
    // print based on s value
    switch(s) {
        case 1:
            cout << left << setw(15) << " Galutinis (vid.)" << endl;
            cout << std::string(45, '-') << endl;
            break;
        case 2:
            cout << left << setw(15) << " Galutinis (med.)" << endl;
            cout << std::string(45, '-') << endl;
            break;
        case 3:
            cout << left << setw(15) << " Galutinis (vid.)" << left << setw(15) << " Galutinis (med.)" << endl;
            cout << std::string(60, '-') << endl;
            break;
    }
    // print all elements of an array
    for(auto i:arr) {
        cout << left << setw(15) << i.name << " " 
            << left << setw(15) << i.surname << " ";
            // calculate final grade using average or median based on s value
            switch(s) {
                case 1:
                    cout << left << setw(20) << setprecision(3) << 0.4 * average(i.grades) + 0.6 * i.exam << endl;
                    break;
                case 2:
                    cout << left << setw(20) << setprecision(3) << 0.4 * median(i.grades) + 0.6 * i.exam << endl;
                    break;
                case 3:
                    cout << left << setw(20) << setprecision(3) << 0.4 * average(i.grades) + 0.6 * i.exam 
                        << left << setw(20) << setprecision(3) << 0.4 * median(i.grades) + 0.6 * i.exam << endl;
                    break;
            }
    }
}

void read_data(vector<data>& arr, string filename) {
    // open file
    std::ifstream file;
    file.open(filename);
    // read file header
    vector<string> header;
    header.reserve(4);
    while (file.peek() != '\n') {
        string data;
        file >> data;
        header.push_back(data);
    }

    // get homework count
    int homework_count = header.size() - 3;
    header.clear();

    // read data
    data temp;
    int i = 0;
    while (!file.eof()) {
        arr.push_back(data());
        file >> arr[i].name >> arr[i].surname;
        for (int j = 0; j < homework_count; j++) {
            arr[i].grades.push_back(int());
            file >> arr[i].grades[j];
        }
        file >> arr[i].exam;
        i++;
    }
    
    // close file
    file.close();
}