#include "functions.hpp"

void split_two_new(list<Student> arr) {
    auto start = hrClock::now();
    // calculate final grade and split students
    list<Student> vargsiukai, kietiakai;
    for(auto student:arr) {
        if (student.finalGrade() < 5)
            vargsiukai.push_back(student);
        else
            kietiakai.push_back(student);
    }
    arr.clear();

    auto stop = hrClock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Studentu skirstymas i vargsiukus ir kietiakus uztruko: " << duration.count() * 1e-9 << "s\n";

    auto start5 = hrClock::now();

    kietiakai.sort(compareByName);
    vargsiukai.sort(compareByName);

    auto stop5 = hrClock::now();
    auto duration5 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop5 - start5);
    cout << "Studentu rusiavimas pagal vardus uztruko: " << duration5.count() * 1e-9 << " \n";
    
    start = hrClock::now();
    write_students("kietiakai.txt", kietiakai);
    kietiakai.clear();
    write_students("vargsiukai.txt", vargsiukai);
    vargsiukai.clear();
    stop = hrClock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Vargsiuku ir kietiaku rasymas i failus uztruko: " << duration.count() * 1e-9 << "s\n";
    // cout << "Studentai surusiuoti i falus kietiakai.txt ir vargsiukai.txt\n";
}

void split_one_new(list<Student> kietiakai) {
    auto start = hrClock::now();
    
    list<Student> vargsiukai;
    
    auto it = kietiakai.begin();
    while(it != kietiakai.end()) {
        if ((*it).finalGrade() < 5) {
            vargsiukai.push_back((*it));
            it = kietiakai.erase(it);
        } else
            it++;
    }

    auto stop = hrClock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Studentu skirstymas i vargsiukus ir kietiakus uztruko: " << duration.count() * 1e-9 << "s\n";

    auto start5 = hrClock::now();

    kietiakai.sort(compareByName);
    vargsiukai.sort(compareByName);

    auto stop5 = hrClock::now();
    auto duration5 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop5 - start5);
    cout << "Studentu rusiavimas pagal vardus uztruko: " << duration5.count() * 1e-9 << " \n";
    
    start = hrClock::now();
    write_students("kietiakai.txt", kietiakai);
    kietiakai.clear();
    write_students("vargsiukai.txt", vargsiukai);
    vargsiukai.clear();
    stop = hrClock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Vargsiuku ir kietiaku rasymas i failus uztruko: " << duration.count() * 1e-9 << "s\n";
    // cout << "Studentai surusiuoti i falus kietiakai.txt ir vargsiukai.txt\n";
}