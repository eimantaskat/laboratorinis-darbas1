#include "functions.h"

int main() {
    // input data
    string select;
    cout << "Ka norite daryti?\n1 - ivesti duomeis\n2 - sugeneruoti duomenis\n3 - surusioti studentus i vargsiukus ir kietiakus\n";

    while (true) {
        cin >> select;
        if(!check_select1(select)) {
            cout << "Iveskite 1, 2 arba 3" << endl;
        } else {
            int s = stoi(select);

            switch (s) {
                case 1:
                    data_input();
                    break;
                
                case 2: {
                    data_generation();
                    break;
                }
                case 3: {
                    student_sorting();
                    break;
                }
            }
            break;
        }
    }
}