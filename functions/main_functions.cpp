#include "../functions.h"

void data_input() {
    vector<data> arr;
    string from_file, select;
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

void data_generation() {
    int n, nd;
    string input;
    cout << "Kiek studentu duomenu norite sugeneruoti?\n";
    while (true) {
        cin >> input;
        if(is_int(input)) {
            n = stoi(input);
            break;
        } else {
            cout << "Iveskite sveikaji skaiciu\n";
        }
    }
    cout << "Kiek namu darbu pazymiu norite sugeneruoti?\n";
    while (true) {
        cin >> input;
        if(is_int(input)) {
                nd = stoi(input);
                break;
        } else {
            cout << "Iveskite sveikaji skaiciu\n";
        }
    }
    try {
        auto start = std::chrono::high_resolution_clock::now();
        generate(n, nd);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "Failo generavimas uztruko: " << duration.count() * 1e-9 << "s\n";
        cout << "Rezultatas issaugotas faile " << std::to_string(n) + "st_" + std::to_string(nd) + "nd.txt\n";
    } catch(...) {
        cout << "Ivyko klaida\n";
    }
}

void student_sorting() {
    vector<data> arr;
    while (true) {
        // read from file
        cout << "Iveskite failo pavadinima su pletiniu: ";
        string filename;
        cin >> filename;
        auto start = std::chrono::high_resolution_clock::now();
        read_data(arr, filename);

        // cout << "Pagal ka norite rusiuoti studentus?\n1. Varda\n2. Pavarde\n";

        // while (true) {
        //     string select;
        //     cin >> select;
        //     if(!check_select(select)) {
        //         cout << "Iveskite 1 arba 2" << endl;
        //     } else {
        //         int s = stoi(select);
                
        //         auto start = std::chrono::high_resolution_clock::now();
        //         switch (s) {
        //         case 1:
        //             std::sort(arr.begin(), arr.end(), compareByName);
        //             break;
                
        //         case 2:
        //             std::sort(arr.begin(), arr.end(), compareBySurname);
        //             break;
        //         }
        //         auto stop = std::chrono::high_resolution_clock::now();
        //         auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        //         cout << "Studentu rusiavimas pagal vardus uztruko: " << duration.count() * 1e-9 << " \n";
        //         break;
        //     }
        // }

        std::chrono::_V2::system_clock::time_point pause, cont;
        if (arr.size() > 0) {

            pause = std::chrono::high_resolution_clock::now();
            // ask user how to calculate final grade
            cout << "Pagal ka norite skaiciuoti galutini bala?\n1. Vidurki\n2. Mediana\n";
            string select;
            cont = std::chrono::high_resolution_clock::now();

            while (true) {
                cin >> select;

                if(!check_select(select)) {
                    cout << "Iveskite 1 arba 2" << endl;
                } else {
                    int s = stoi(select);
                    switch (s) {
                    case 1:
                        split(arr, &average);
                        break;
                    
                    case 2:
                        split(arr, &median);
                        break;
                    }
                    break;
                }
            }
            auto stop = std::chrono::high_resolution_clock::now();
            auto full_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            auto waiting_for_user = std::chrono::duration_cast<std::chrono::nanoseconds>(pause - cont);
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(full_duration - waiting_for_user);
            cout << "Programos veikimo laikas: " << duration.count() * 1e-9 << "\n";
            break;
        }

    }
}