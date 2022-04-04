#include "../functions.h"

void split(list<data> arr, double (*func)(vector<int>)) {
    auto start = std::chrono::high_resolution_clock::now();
    // calculate final grade and split students
    list<data> vargsiukai, kietiakai;
    for(auto student:arr) {
        student.final = 0.4 * func(student.grades) + 0.6 * student.exam;
        if (student.final < 5)
            vargsiukai.push_back(student);
        else
            kietiakai.push_back(student);

    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Studentu skirstymas i vargsiukus ir kietiakus uztruko: " << duration.count() * 1e-9 << "s\n";
    
    start = std::chrono::high_resolution_clock::now();
    write_students("kietiakai.txt", kietiakai);
    write_students("vargsiukai.txt", vargsiukai);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << "Vargsiuku ir kietiaku rasymas i failus uztruko: " << duration.count() * 1e-9 << "s\n";
    // cout << "Studentai surusiuoti i falus kietiakai.txt ir vargsiukai.txt\n";

    vargsiukai.clear();
    kietiakai.clear();
    arr.clear();
}