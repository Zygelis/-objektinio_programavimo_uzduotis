#include "my_lib.h"
#include "deklaravimai.h"

void ivedimas_is_file(vector<studentas> &grupe, char vm_pasirinkimas)
{
    std::ifstream duomenys("Studentai50.txt");

    if (!duomenys.is_open())
    {
        cout << "Neatsidare duomenys " << endl;
    }

    string pirma_eilute;
    getline(duomenys, pirma_eilute);
    cin.ignore();

    string eilute;
    while (getline(duomenys, eilute))
    { // kol nera pasiekta failo pabaiga skaitome po eilute
        studentas laikinas;

        if (eilute.empty() || std::all_of(eilute.begin(), eilute.end(), ::isspace))
        {
            continue;
        }

        std::istringstream iss(eilute); // pasiverciame eilute i srauta is kurio galima skaityti lengviau
        //
        iss >> laikinas.vardas >> laikinas.pavarde;

        int pazymiai;
        // Read scores
        while (iss >> pazymiai)
        { // kol yra skaiciu tol skaitome
            laikinas.paz.push_back(pazymiai);
        }
        // egzamino rezultatas yra paskutinis skaicius prie pazymiu
        laikinas.egz = laikinas.paz.back();
        laikinas.paz.pop_back(); // pasaliname egzamino rezultata is pazymiu vektoriaus
        // skaiciuojamas galutinis balas
        laikinas.rez = galutinio_balo_skaiciavimas(vm_pasirinkimas, laikinas);

        grupe.push_back(laikinas); // Add the student to the vector
    }

    duomenys.close();
}

studentas atsitiktinis_ivedimas()
{
    studentas laikinas;
    cout << "Iveskite varda ir pavarde:";
    cin >> laikinas.vardas >> laikinas.pavarde;

    cbelekeie AKAKAKAKAKAKAKAK
    int kiek_pazymiu;
    cin >> kiek_pazymiu;

    // sugeneruojami pazymiai
    laikinas.paz = random_skaicius(kiek_pazymiu);
    laikinas.egz = random_skaicius(1)[0];

    cout << "Sugeneruoti pazymiai: ";
    for (auto &a : laikinas.paz)
    {
        cout << a << " ";
    }
    cout << endl;

    cout << "Sugeneruotas egzamino rezultatas: " << laikinas.egz << endl;

    return laikinas;
}

studentas rankinis_ivedimas()
{
    studentas laikinas;

    cout << "Iveskite varda ir pavarde:";
    cin >> laikinas.vardas >> laikinas.pavarde;

    cout << "Iveskite pazymius viena po kito ir paspauskite Enter, kai baigsite. Arba iveskite 'baigti' kai baigsite pazymiu ivedima." << endl;
    string paz_tikrinimas;
    cin.ignore();
    while (true)
    {
        getline(cin, paz_tikrinimas);

        if (paz_tikrinimas == "baigti" || paz_tikrinimas.empty())
        {
            break;
        }

        try
        {
            int input = std::stoi(paz_tikrinimas);

            if (input < 0 || input > 10)
            {
                cout << "Neteisinga ivestis. Iveskite skaicius nuo 0 iki 10." << std::endl;
                continue;
            }
            laikinas.paz.push_back(input);
        }
        catch (const std::invalid_argument &)
        {
            cout << "Neteisinga ivestis. Iveskite naturalu skaiciu tarp 1 ir 10: " << std::endl;
        }
        catch (const std::out_of_range &)
        {
            cout << "Ivestas skaicius per didelis. Iveskite mazesni skaiciu." << std::endl;
        }
    }

    // ivedamas egzamino rezultatas
    while (true)
    {
        cout << "Iveskite egzamino rezultata: ";
        string egzrez_laikinas;
        cin >> egzrez_laikinas;

        try
        {
            int input = std::stoi(egzrez_laikinas);

            if (input < 1 || input > 10)
            {
                cout << "Egzamino rezultatas turi buti tarp 1 ir 10: " << endl;
            }
            else
            {
                laikinas.egz = input;
                break;
            }
        }
        catch (const std::invalid_argument &)
        {
            // jei ivestis yra ne skaicius, prasoma ivesti is naujo
            cout << "Neteisinga ivestis. Iveskite naturalu skaiciu tarp 1 ir 10: " << endl;
        }
        catch (const std::out_of_range &)
        {
            cout << "Ivestas skaicius per didelis. Iveskite mazesni skaiciu." << std::endl;
        }
    }

    // spausdinami ivesti pazymiai
    cout << "Ivedei pazymius: ";
    for (auto &a : laikinas.paz)
        cout << a << " ";
    cout << endl;

    cout << "Ivedei egzamina: " << laikinas.egz << endl;
    cin.ignore();

    return laikinas;
}
