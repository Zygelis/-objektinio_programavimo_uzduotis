#include "my_lib.h"

studentas atsitiktinis_ivedimas()
{
    studentas laikinas;
    cout << "Iveskite varda ir pavarde:";
    cin >> laikinas.vardas >> laikinas.pavarde;

    cbelekeie AKAKAKAKAKAKAKAK
    int kiek_pazymiu;
    cin >> kiek_pazymiu;

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
