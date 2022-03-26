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
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|
| 1,000 | 0 | 0 | 0 | 0.003991 | 0.007988 |
| 10,000 | 0.015621 | 0.015651 | 0.002032 | 0.024875 | 0.062536 |
| 100,000 | 0.074806 | 0.174583 | 0.008974 | 0.132533 | 0.413317 |
| 1,000,000 | 0.714639 | 1.76577 | 0.084773 | 1.20961 | 3.90779 |
| 10,000,000 | 7.10166 | 17.4659 | 0.874824 | 11.4619 | 38.396 |



### ***std::list***
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|
| 1,000 | 0 | 0.017723 | 0 | 0 | 0.033275 |
| 10,000 | 0.015583 | 0.015621 | 0 | 0.031199 | 0.062403 |
| 100,000 | 0.078038 | 0.187708 | 0.015621 | 0.161496 | 0.474089 |
| 1,000,000 | 0.741159 | 1.91418 | 0.17187 | 1.56129 | 4.68564 |
| 10,000,000 | 7.15479 | 19.1396 | 1.60161 | 16.0839 | 47.219 |

### ***std::deque***

| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|
| 1,000 | 0 | 0.015581 | 0 | 0.007142 | 0.023742 |
| 10,000 | 0.015611 | 0.015587 | 0 | 0.015620 | 0.046818 |
| 100,000 | 0.0779954 | 0.187456 | 0.015651 | 0.140561 | 0.452874 |
| 1,000,000 | 0.703468 | 1.8448 | 0.109346 | 1.35773 | 4.25 |
| 10,000,000 | 7.09527 | 18.5 | 1.04699 | 13.4185 | 42.4078 |

*\* Naudota sistema: i5-8300h, 16gb 2667 MHz CL19, Samsung 970 Evo Plus NVMe SSD*  
*\* Programos testvaimas buvo atliktas naudojant g++ kompiliatorių (gcc version 8.1.0, x86_64-posix-seh-rev0)*  
*\* Naudotuose failuose buvo 10 namų darbų pažymių*  
*\* Galutinis failas buvo skaičiuojant naudojant vidurkį*

![1,000 įrašų](http:/eimantas.ddns.net/images/op-charts/1000.png)