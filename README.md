# laboratorinis-darbas
# ***v0.1***
Faile ***array.cpp*** programa sukurta naudojant *C masyvą*, faile ***vector.cpp*** naudojant *std::vector* tipo konteinerį

### Duomenų įvedimas
---
#### *Studento duomenų įvedimas*
**Paleidus programą, naudotojo yra paprašoma įvesti studento duomenis:**
* vardą,
* pavardę,
* egzamino įvertinimą,
* namų darbų įvertinimus

**Visi įvesti duomenys yra patikrinami:**
* Vardas ir pavardė turi prasidėti didžiąja raide ir būti sudaryti tik iš raidžių. Jei įvestas tekstas neatitinka šių reikalavimų, naudotojo yra paprašomas patvirtinimas, kad įvestas varda/pavardė yra teisingi
* Egzamino ir namų darbų įvertinimai turi būti sveikieji skaičiai nuo 1 iki 10. Jei įvestas tekstas neatitinka šių reikalavimų, įvertinimą paprašoma įvesti iš naujo

##### *Atsitiktinių balų generavimas*
Įvedus studento vardą ir pavardę, programa paklausia ar naudotojas nori sugeneruoti atsitiktinius balus. Jei jis nenori, pereinama prie rankinio duomenų įvedimo, jei nori, programa sugeneruoja egzamino balą, paklausia, kiek namų darbų pažymių sugeneruoti ir juos sugeneruoja

##### *Namų darbų įvertinimų įvedimas*  
Naudotojas gali įvesti neribotą kiekį namų darbų pažymių. Norit baigti namų darbų įvertinimų įrašymą, reikia įvesti **0**

#### *Kitų studentų duomenų įvedimas*
Įvedus visus vieno studento duomenis programa paklausia ar naudotojas nori įvesti dar vieno mokinio duomenis. Jei jis pasirenka įvesti, studentų duomenų masyvas yra padidinamas ir kartojama duomenų įvedimo procedūra. Jei naudotojas nebenori įvesti daugiau duomenų, pereinama prie galutinio balo skaičiavimo.

### Galutinio balo skaičiavimas
---
Įvedus visų studentų duomenis, programa paklausia, pagal ką norima skaičiuoti galutinį balą: pagal namų darbų *medianą* ar *vidurkį*

##### Masyvo medianos radimas
Studento namų darbų įvertinimų masyvas yra surikuojamas naudojant **Quicksort** algoritmą. Šis rikiavimo algoritmas yra vienas greičiausių, todėl programa gali labai greitai surikuoti didelius duomenų masyvus. Pavyzdžiui, ***10,000,000*** pažymių masyvą **Quicksort** surikiavo per **9s**, kai **Bubble sort** per tą patį laiką surikavo tik ***26,000*** pažymių masyvą.  
Surikiavus masyvą, patikrinama, ar elementų skaičius yra lyginis. Jei jis lyginis yra gražinamas vidurinių elementų vidurkis, jei nelyginis - vidurinis elementas.

##### Masyvo vidurkio skaičiavimas
Yra sudedami visi studento namų darbų masyvo elementai naudojant *std::accumulate* funkciją iš *\<numeric>* bibliotekos. Įvertinimų suma yra padalijama iš elementų skaičiaus.

### Duomenų išvedimas
---
**Duomenys yra pateikiami tokioje lentelėje:**  
Vardas &emsp; Pavarde &emsp; Galutinis (vid.)  
\--------------------------------------------  
Arvydas &emsp; Sabonis &emsp;&ensp; 7.7  
Rimas &emsp;&emsp;  Kurtinaitis &nbsp;  7.4

# ***v0.2***
Panaikinta programos realizacija su masyvais, **vector.cpp** pervadintas į **main.cpp**
### Duomenų įvedimas
---
Duomenis įvesti galima iš failo. Įjungus programą, naudotojo yra paklausiama, ar jis nori duomenis įvesti pats, ar nuskaityti iš failo. Pasirinkus nuskaitymą iš failo, yra paprašoma įvesti duomenų failo pavadinimą su plėtiniu, pvz.: *kursiokai.txt*

#### Duomenų failo strukrūra
* Pirmoji eilutė turi būti antraštė, kurioje turi būti užrašyta vardas, pavardė, **n** namų darbų skaičius ir egzaminas.
    ```
        Vardas    Pavardė    ND1  ND2  ... NDn Egzaminas
    ```
    **Pvz.:**
    ```
        Vardas    Pavarde    ND1  ND2  ND3  ND4  ND5  ND6  ND7  Egz.
    ```
* Kitose eilutėse gali būti neribotas kiekis studentų duomenų

### Duomenų išvedimas
**Nuskaičius duomenis iš failo, jie yra pateikiami tokioje lentelėje:**  
Vardas &emsp; Pavarde &emsp; Galutinis (vid.) &ensp; Galutinis (med.)  
\------------------------------------------------------------  
Arvydas &nbsp; Sabonis &emsp; &emsp; &nbsp; 7.7 &emsp; &emsp; &emsp; &emsp; &emsp; 7.5  
Rimas &emsp;&nbsp; Kurtinaitis &emsp; &nbsp;&nbsp; 7.4 &emsp; &emsp; &emsp; &emsp; &emsp; 7.8

Studentai yra surūšiuoti abėcėlės tvarka

# ***v0.3***
* Programa padalinta penkis *.cpp ir du *.h failus
* Naudojamas išimčių valdymas