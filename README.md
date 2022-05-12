# laboratorinis-darbas

## Įdiegimo instrukcija

### Programos instaliavimas
1. Atsisiųskite programos [setup.exe](https://github.com/eimantaskat/laboratorinis-darbas1/releases/download/v2.0/setup.exe) arba [Setup.msi](https://github.com/eimantaskat/laboratorinis-darbas1/releases/download/v2.0/Setup.msi) failą
2. Paleiskite atsisiųstą failą, spauskite *Next*  
![image](https://user-images.githubusercontent.com/80033246/168071378-eff73e7c-3e5e-45c3-b490-88dcf00c01ac.png)
3. Pasirinkite, kur norite instaliuoti programą, spauskite *Next*    
![image](https://user-images.githubusercontent.com/80033246/168071584-77b010f7-b517-4cdc-b4c9-185166311d46.png)
4. Spauskite *Next*  
![image](https://user-images.githubusercontent.com/80033246/168071801-ca0b29ee-20f1-4d5a-a265-c1d91f38cbf0.png)
5. Atsiradusiame lange spauskite *Yes*
6. Programa instaliuota  
![image](https://user-images.githubusercontent.com/80033246/168072013-e3861bd9-651e-43f3-a2f1-b9c5142b7dee.png)
---
### *Portable* versijos naudojimas
1. Atsisiųskite [Laboratorinis-darbas.exe](https://github.com/eimantaskat/laboratorinis-darbas1/releases/download/v2.0/Laboratorinis-darbas.exe) failą
2. Paleiskite atsisiųstą failą
---
### Programos sukompiliavimas
1. Atsisiųskite programos kodą paspaudę [čia](https://github.com/eimantaskat/laboratorinis-darbas1/archive/refs/heads/v2.0.zip) arba su komanda
```console
$ git clone https://github.com/eimantaskat/laboratorinis-darbas1.git
```
2. Sukompiliuokite programą
```console
$ make
```
arba  
```
$ g++ -o <pavadinimas> main.cpp container_functions/*.cpp functions/*.cpp student/*.cpp person/*.cpp -O3
```
3. Paleiskite programos *<pavadinimas>.exe* failą
---
## Naudojimosi instrukcija
1. Palieskite programos ***.exe** failą
2. Sekite instrukcijas ekrane
---

# ***v2.0***
* Sugeneruota projekto dokumentacija naudojant [*Doxygen*](https://www.doxygen.nl/manual/index.html)
* Sukurti **Unit Testai** 5 funkcijoms naudojant *Google Test* framework'ą
* Sukurtas įdiegimo failas

# ***v1.5***
* sukurta abstrakčioji bazinė žmogaus klasė (**person**)
* studento klasė (**student**) padaryta žmogaus (**person**) išvestinė klasė

# ***v1.2***

* realizuota *rule of three* - (sukurtas destruktorius, *copy* konstuktorius, *copy assignment* operatorius)  
* realizuoti operatoriai:
    * ==
    * !=
    * <
    * \>
    * <=
    * \>=
    * <<

# ***v1.1***
* Studentų duomenų struktūra (*stuct*) pakeista į klasę (*class*)
* Pertvarkyta programos failų struktūra

## Programos spartos analizė

### Naudojant O3 flag'ą
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų rikiavimas pagal vardus, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|---|
| 1,000,000 | 0.711048 | 2.00103 | 0.355985 | 1.45004 | 1.238 | 5.886 |
| 10,000,000 | 7.00603 | 20.206 | 3.508 | 14.733 | 11.091 | 57.61 |


### Naudojant O2 flag'ą
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų rikiavimas pagal vardus, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|---|
| 1,000,000 | 0.728998 | 1.997 | 0.348 | 1.549 | 1.19169 | 5.9377 |
| 10,000,000 | 7.09 | 20.813 | 3.54303 | 16.837 | 11.2531 | 60.672 |

### Naudojant O1 flag'ą
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų rikiavimas pagal vardus, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|---|
| 1,000,000 | 0.720049 | 2.022 | 0.347999 | 1.51003 | 1.22679 | 5.94884 |
| 10,000,000 | 7.08302 | 20.342 | 3.48103 | 16.112 | 11.5792 | 59.7072 |

### Be optimizacijos flag'o
| Įrašų kiekis | Duomenų nuskaitymas, s | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų rikiavimas pagal vardus, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|---|
| 1,000,000 | 0.725985 | 3.15202 | 1.20499 | 4.949 | 1.677 | 11.909 |
| 10,000,000 | 7.00703 | 32.461 | 12.123 | 49.3172 | 15.74 | 118.563 |

*\* Programos testvaimas buvo atliktas naudojant g++ kompiliatorių (gcc version 8.1.0, x86_64-posix-seh-rev0)*  
*\* Naudota sistema: i5-8300h, 16gb 2667 MHz CL19, Micron 1100 M.2 SATA 6Gb/s*  
*\* Programos veikimo laikas buvo pradėtas skaičiuoti sugeneravus duomenų failą*  
*\* Testuojant buvo naudojami failai su 10 namų darbų pažymių*  
*\* Testavimui buvo naudojamas **std::vector** tipo konterineris*  
*\* Testuojant studentai buvo skirtomi panaudojant **vieną** naują konteinerį*  
*\* Testuojant buvo naudojama klasė (**class**)*

### ***class*** ir ***struct*** spartos palyginimas
![1,000,000](https://user-images.githubusercontent.com/80033246/165742100-c160d3d4-2e4e-454d-b128-7a1ee68f006c.png)
![10,000,000](https://user-images.githubusercontent.com/80033246/165742116-a3cb9cca-8335-4996-b965-eb3f7e353264.png)

### Skirtingų optimizacijos lygių palyginimas
![1,000,000](https://user-images.githubusercontent.com/80033246/165748086-8febe38b-e4fc-4f97-a236-06414263f604.png)
![10,000,000](https://user-images.githubusercontent.com/80033246/165748097-8a2f163c-4bf3-4ffc-b0e1-964c59160108.png)
