# objektinio_programavimo_uzduotis

## Kaip naudotis

### Svarbiausia paleisti main.cpp:
- Per kodo editinimo programą.
- Per terminala `g++ main.cpp funkcijos.cpp ivestis.cpp -o v_pradine ` ir `./v_pradine`

## Struktūra
- main.cpp --> pagrindinis file.
- funkcijos.cpp --> įvairių funkcijų file.
- ivestis.cpp --> įvairių įvesties formų funkcijų file.
- my_lib.h --> library antraštinis file.
- deklaravimai.h --> deklaravimų antraštinis file.
- Studentai50.txt --> duomenys.

## Programos savybės

### Duomenų Įvedimas iš failo:
- Yra galimybė įvesti duomenis iš failo.

### Atsitiktinio Balų Generavimas:
- Vartotojai turi galimybę generuoti atsitiktinius namų darbų ir egzamino rezultatus studentams.

### Duomenų Įvedimas Ranka:
- Vartotojai gali patogiai įvesti studentų duomenis naudodami struktūruotą formatą, įskaitant studento vardą, pavardę, tarpinius namų darbų rezultatus ir egzamino rezultatą.

### Rezultato pateikimas:
- Įvedus duomenis, programa apskaičiuoja galutinį baląc ir lentelės formoje rezultatą pateikia ekrane. 
- Programa studentus gali surūšiuoti pagal vardą. 

### Skaičiavimo Galimybės:
- Programa palaiko tiek vidurkio, tiek medianos skaičiavimo metodus galutiniam balui apskaičiuoti.

### Dinaminis Namų Darbų Skaičius:
- Programa prisitaiko prie situacijų, kai namų darbų užduočių skaičius iš anksto nežinomas.
- Vartotojai gali nuspręsti, kada baigė įvesti visus namų darbų rezultatus, tiesiog paspaudę Enter arba "baigti", kaip tai yra prašoma.

### Duomenų Saugojimas:
- Programa naudoja vektorinius konteinerius (std::vector) duomenų saugojimui.
