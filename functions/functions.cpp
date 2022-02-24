#include "../functions.h"

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