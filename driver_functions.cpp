#include "functions.hpp"

void generate_data() {
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
        auto start_generation = hrClock::now();
        generate(n, nd);
        auto stop_generation = hrClock::now();
        auto generation_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_generation - start_generation);
        cout << "Failo generavimas uztruko: " << generation_duration.count() * 1e-9 << "s\n";
        cout << "Rezultatas issaugotas faile " << std::to_string(n) + "st_" + std::to_string(nd) + "nd.txt\n";
    } catch(...) {
        cout << "Ivyko klaida\n";
    }
}

void vector_student_sorting() {
    vector<Student> stud;

    cout << "Kaip norite rusioti studentus?\n1. I du naujus konteinerius\n2. I viena nauja konteineri\n";
    string select;
    while (true) {
        cin >> select;

        if (check_select2(select))
            break;
        else
            cout << "Iveskite 1 arba 2\n";
    }

    while (true) {
        // read from file
        cout << "Iveskite failo pavadinima su pletiniu: ";
        string filename;
        cin >> filename;
        auto start = hrClock::now();

        read_data(stud, filename);

        if (stud.size() > 0) {
            int s = stoi(select);
            switch (s) {
                case 1:
                    split_two_new(stud);
                    break;

                case 2:
                    split_one_new(stud);
                    break;
            }
            auto stop = hrClock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            cout << "Programos veikimo laikas: " << duration.count() * 1e-9 << "\n";
            break;
        }
    }
}

void list_student_sorting() {
    list<Student> stud;

    cout << "Kaip norite rusioti studentus?\n1. I du naujus konteinerius\n2. I viena nauja konteineri\n";
    string select;
    while (true) {
        cin >> select;

        if (check_select2(select))
            break;
        else
            cout << "Iveskite 1 arba 2\n";
    }

    while (true) {
        // read from file
        cout << "Iveskite failo pavadinima su pletiniu: ";
        string filename;
        cin >> filename;
        auto start = hrClock::now();

        read_data(stud, filename);

        if (stud.size() > 0) {
            int s = stoi(select);
            switch (s) {
                case 1:
                    split_two_new(stud);
                    break;

                case 2:
                    split_one_new(stud);
                    break;
            }
            auto stop = hrClock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            cout << "Programos veikimo laikas: " << duration.count() * 1e-9 << "\n";
            break;
        }
    }
}

void deque_student_sorting() {
    deque<Student> stud;

    cout << "Kaip norite rusioti studentus?\n1. I du naujus konteinerius\n2. I viena nauja konteineri\n";
    string select;
    while (true) {
        cin >> select;

        if (check_select2(select))
            break;
        else
            cout << "Iveskite 1 arba 2\n";
    }

    while (true) {
        // read from file
        cout << "Iveskite failo pavadinima su pletiniu: ";
        string filename;
        cin >> filename;
        auto start = hrClock::now();

        read_data(stud, filename);

        if (stud.size() > 0) {
            int s = stoi(select);
            switch (s) {
                case 1:
                    split_two_new(stud);
                    break;

                case 2:
                    split_one_new(stud);
                    break;
            }
            auto stop = hrClock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            cout << "Programos veikimo laikas: " << duration.count() * 1e-9 << "\n";
            break;
        }
    }
}