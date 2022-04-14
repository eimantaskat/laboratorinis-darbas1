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
    * **main.cpp**  
        main funkcija
    * **functions.cpp**  
        vidurkio, medianos skaičiavimo ir rezultatų spausdinimo funkcijos
    * **input.cpp**  
        duomenų įvedimo rankomis ir skaitymo iš failo funkcijos
    * **sorting.cpp**  
        duomenų rušiavimo funkcijos
    * **verification.cpp**  
        duomenų tikrinimo funkcijos  
      
    * **main.h**  
        *#include*, *using* sakiniai ir duomenų struktūra
    * **functions.h**  
        funkcijų aprašymai
* Naudojamas išimčių valdymas

# ***v0.4***
* Failų su atsitiktiniais studentų pažymiais generavimas
* Studentų padalinimas į du failus pagal galutinį balą:
    * *vargsiukai.txt* - jei galutinis balas mažesnis nei 5
    * *kietiakiai.txt* - jei galutinis balas didesnis arba lygus 5
* Sukurti du nauji *.cpp failai:
    * **main_functions.cpp**  
        funkcijos, kurios vykdo programą atsižvelgiant į vartotojo pasirinkimą
    * **output.cpp**  
        funkcijos, skirtos duomenų išvedimui

### Programos spartos analizė
| Įrašų kiekis | Failo generavimas, s | Duomenų nuskaitymas, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|
| 1,000 | 0.0018 | 0.0141 | 0 | 0.0025 | 0.0198 |
| 10,000 | 0.0104 | 0.0418 | 0.001 | 0.0126 | 0.0607 |
| 100,000 | 0.0965 | 0.3447 | 0.0095 | 0.1121 | 0.4855 |
| 1,000,000 | 0.9242 | 3.4384 | 0.0857 | 1.0876 | 4.7643 |
| 10,000,000 | 10.1074 | 34.0514 | 0.8886 | 10.2287 | 46.6012 |

*\* Programos testvaimas buvo atliktas naudojant g++ kompiliatorių (gcc version 8.1.0, x86_64-posix-seh-rev0)*  
*\* Rezultatai buvo apskaičiuoti naudojant 3 bandymų vidurkį*  
*\* Naudota sistema: i5-8300h, 16gb 2667 MHz CL19, Micron 1100 M.2 SATA 6Gb/s*  
*\* Programos veikimo laikas buvo pradėtas skaičiuoti sugeneravus duomenų failą*  
*\* Testuojant buvo generuojama 10 namų darbų pažymių*

# ***v0.5***
* Programa realizuota panaudojant *std::list* ir *std::deque* konteinerius

* Sukurtos naujos direktorijos:
    * **list_functions**  
        failai su funkcijomis, naudojančiomis *std::list* konteinerį
    * **deque_functions**  
        failai su funkcijomis, naudojančiomis *std::deque* konteinerį

### Programos spartos analizė
### ***std::vector***
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas pagal vardus, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s  |
|---|---|---|---|---|---|---|
| 1,000 | 0.0009943 | 0.0020066 | 0.000998 | 0 | 0.001999 | 0.009215 |
| 10,000 | 0.0089692 | 0.0240017 | 0.0030344 | 0.003975 | 0.0169999 | 0.0649667 |
| 100,000 | 0.0880324 | 0.187039 | 0.0439831 | 0.0379675 | 0.127418 | 0.504203 |
| 1,000,000 | 0.810035 | 1.788 | 0.515999 | 0.325003 | 1.199 | 4.781 |
| 10,000,000 | 8.02304 | 17.92 | 6.43395 | 3.526 | 11.731 | 48.821 |



### ***std::list***
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas pagal vardus, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s  |
|---|---|---|---|---|---|---|
| 1,000 | 0.001 | 0.0039905 | 0 | 0 | 0.0029898 | 0.0130003 |
| 10,000 | 0.0099987 | 0.022989 | 0.0010068 | 0.0039985 | 0.0174037 | 0.0674402 |
| 100,000 | 0.0850326 | 0.201986 | 0.012994 | 0.0370344 | 0.140998 | 0.527997 |
| 1,000,000 | 0.82202 | 1.95105 | 0.170032 | 0.341 | 1.34505 | 5.04403 |
| 10,000,000 | 7.99205 | 20.3931 | 2.10395 | 3.443 | 13.321 | 51.4901 |

### ***std::deque***

| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas pagal vardus, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s  |
|---|---|---|---|---|---|---|
| 1,000 | 0.0020384 | 0.0019991 | 0 | 0.0009999 | 0.005001 | 0.0130011 |
| 10,000 | 0.0109824 | 0.0200263 | 0.0030323 | 0.0039766 | 0.0179094 | 0.0651538 |
| 100,000 | 0.0860054 | 0.191026 | 0.0490018 | 0.0400378 | 0.138517 | 0.526471 |
| 1,000,000 | 0.811041 | 1.92003 | 0.67403 | 0.374002 | 1.383 | 5.328 |
| 10,000,000 | 8.06399 | 18.955 | 8.73404 | 3.802 | 13.276 | 54.387 |

*\* Naudota sistema: i5-8300h, 16gb 2667 MHz CL19, Samsung 970 Evo Plus NVMe SSD*  
*\* Programos testvaimas buvo atliktas naudojant g++ kompiliatorių (gcc version 8.1.0, x86_64-posix-seh-rev0)*  
*\* Naudotuose failuose buvo 10 namų darbų pažymių*  
*\* Galutinis failas buvo skaičiuojant naudojant vidurkį*

![1000](https://user-images.githubusercontent.com/80033246/163345669-e31bd136-ee3a-474c-befc-7cce5d4c7c51.png)
![10,000](https://user-images.githubusercontent.com/80033246/163345913-6def234b-f3d3-4384-a31c-e9fdee3a03a9.png)
![100,000](https://user-images.githubusercontent.com/80033246/163345979-e1ab4b1e-f9f6-4cba-983b-d0d1662921dc.png)
![1,000,000](https://user-images.githubusercontent.com/80033246/163346046-7b7aa110-62e3-482a-91f3-7a44e0a67e48.png)
![10,000,000](https://user-images.githubusercontent.com/80033246/163346056-938222b6-a02d-4d7a-acb7-a1501a9b5396.png)

# ***v1.0***

* Bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį

### Spartos analizė

### ***std::vector***
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas pagal vardus, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|---|
| 1,000 | 0.0010012 | 0.0020345 | 0.0010094 | 0 | 0.0039862 | 0.011524 |
| 10,000 | 0.0100004 | 0.0199993 | 0.0039996 | 0.0029759 | 0.0160085 | 0.0604955 |
| 100,000 | 0.0860277 | 0.185032 | 0.0409988 | 0.0310408 | 0.125682 | 0.490639 |
| 1,000,000 | 0.829033 | 1.851 | 0.543002 | 0.288052 | 1.239 | 4.881 |
| 10,000,000 | 8.089 | 18.16 | 6.46004 | 3.12697 | 11.6428 | 48.6848 |



### ***std::list***
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas pagal vardus, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|---|
| 1,000 | 0.0010015 | 0.0040036 | 0 | 0 | 0.0039915 | 0.014005 |
| 10,000 | 0.0110227 | 0.0230009 | 0.0020318 | 0.0030346 | 0.017998 | 0.0634439 |
| 100,000 | 0.0860004 | 0.203999 | 0.0139892 | 0.0320341 | 0.168029 | 0.533001 |
| 1,000,000 | 0.828032 | 1.98199 | 0.171996 | 0.29 | 1.47606 | 4.95501 |
| 10,000,000 | 7.99305 | 19.344 | 2.12404 | 2.895 | 14.089 | 48.393 |



### ***std::deque***
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas pagal vardus, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|---|
| 1,000 | 0.011994 | 0.0019929 | 0.0010157 | 0 | 0.0029863 | 0.0219931 |
| 10,000 | 0.0150071 | 0.0210023 | 0.0060106 | 0.003028 | 0.0160024 | 0.0686511 |
| 100,000 | 0.0869617 | 0.193996 | 0.0550439 | 0.0300138 | 0.141998 | 0.532711 |
| 1,000,000 | 0.833001 | 1.96003 | 0.657 | 0.292 | 1.306 | 5.213 |
| 10,000,000 | 8.22204 | 18.442 | 8.63304 | 2.803 | 12.721 | 52.367 |

*\* Programos testvaimas buvo atliktas naudojant g++ kompiliatorių (gcc version 8.1.0, x86_64-posix-seh-rev0)*  
*\* Rezultatai buvo apskaičiuoti naudojant 3 bandymų vidurkį*  
*\* Naudota sistema: i5-8300h, 16gb 2667 MHz CL19, Micron 1100 M.2 SATA 6Gb/s*  
*\* Programos veikimo laikas buvo pradėtas skaičiuoti sugeneravus duomenų failą*  
*\* Testuojant buvo generuojama 10 namų darbų pažymių*

![std::vector, 10,000,000](https://user-images.githubusercontent.com/80033246/163351482-f5e00c05-c123-4269-b14b-35688f746115.png)
![std::list, 10,000,000](https://user-images.githubusercontent.com/80033246/163351632-a3ef6e9d-6f62-4f0e-9eb6-2dcfe01e89a7.png)
![std::deque, 10,000,000](https://user-images.githubusercontent.com/80033246/163351641-8a80f254-18e7-4d93-b55a-926dd60632c0.png)
