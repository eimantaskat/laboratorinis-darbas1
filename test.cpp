#include "student.hpp"



int main() {
    vector<Student> v;
    read_data(v, "1000000st_10nd.txt");

    // for(auto stud:v)
    //     cout << stud.name() << " " << stud.surname() << " " << stud.finalGrade() << "\n";
    
    // string cont;
    // cout << "Koki konteineri norite naudoti?\n1 - std::vector\n2 - std::list\n3 - std::deque\n";
    // while(true) {
    //     cin >> cont;
    //     if (check_select3(cont)) {
    //         break;
    //     } else {
    //         cout << "Iveskite 1, 2 arba 3\n";
    //     }
    // }

    // string act;
    // cout << "Ka norite daryti?\n1 - ivesti duomeis\n2 - sugeneruoti duomenis\n3 - surusioti studentus i vargsiukus ir kietiakus\n";
    // while(true) {
    //     cin >> act;
    //     if (check_select3(act)) {
    //         break;
    //     } else {
    //         cout << "Iveskite 1, 2 arba 3\n";
    //     }
    // }

    // int container = std::stoi(cont);
    // int action = std::stoi(act);

    // switch(action) {
    //     case 1:
    //         // manual data input
    //         switch (container) {
    //             case 1:
    //                 // vector
    //                 break;
    //             case 2:
    //                 // list
    //                 break;
    //             case 3:
    //                 // deque
    //                 break;
    //         }
    //         break;
    //     case 2:
    //         // generate data
    //         generate_data();
    //         break;
    //     case 3:
    //         // read data from file, split into 2 files
    //         switch (container) {
    //             case 1:
    //                 // vector
    //                 vector_student_sorting();
    //                 break;
    //             case 2:
    //                 // list
    //                 break;
    //             case 3:
    //                 // deque
    //                 break;
    //         }
    //         break;
    // }
}