#include "my_lib.h"

struct studentas {
    string vardas, pavarde;
    vector <int> paz;
    int egz;
    double rez;
};

struct studentas_list {
    string vardas, pavarde;
    list <int> paz;
    int egz;
    double rez;
};

// vector
void ivedimas_is_file(vector<studentas>& grupe, char vm_pasirinkimas, const string& duom_vard);
void rusiuojame_i_dvi_grupes(vector<studentas>& grupe, vector<studentas>& nuskriaustukai, std::vector<studentas>& galvočiai);
void issaugojam_duomenis(const vector<studentas>& studentai, const string& file_vard);
void duomenu_kurimas(int numLines);
void laiko_skaicuokle(int n_eil, int n, int rusiavimo_pasirinkimas);
double medianos_skaiciavimas(vector<int> vec);
double galutinio_balo_skaiciavimas(char vm_pasirinkimas, studentas& laikinas);
vector<int> random_skaicius(int n);
bool palyginimas_pagal_rezultata(const studentas& a, const studentas& b);
bool palyginimas_pagal_varda(const studentas &a, const studentas &b);
bool palyginimas_pagal_pavarde(const studentas &a, const studentas &b);
studentas rankinis_ivedimas();
studentas atsitiktinis_ivedimas();

// list
void ivedimas_is_file_list(std::list<studentas_list> &grupe, char vm_pasirinkimas, const string &duom_vard);
void rusiuojame_i_dvi_grupes_list(std::list<studentas_list>& grupe, std::list<studentas_list>& nuskriaustukai, std::list<studentas_list>& galvočiai);
void issaugojam_duomenis_list(const std::list<studentas_list>& studentai, const std::string& file_vard);
void duomenu_kurimas_list(int n_eiluciu);
void laiko_skaicuokle_list(int n_eil, int n, int rusiavimo_pasirinkimas);
double medianos_skaiciavimas_list(std::list<int> vektorius);
double galutinio_balo_skaiciavimas_list(char vm_pasirinkimas, studentas_list& laikinas);
list<int> random_skaicius_list(int n);
bool palyginimas_pagal_rezultata_list(const studentas_list& a, const studentas_list& b);
bool palyginimas_pagal_varda_list(const studentas_list &a, const studentas_list &b);
bool palyginimas_pagal_pavarde_list(const studentas_list &a, const studentas_list &b);
