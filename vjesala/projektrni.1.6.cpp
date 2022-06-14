#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<fstream>


using namespace std;

fstream file;

int igra(char* abeceda, char* kopija_abecede, int kraj, int br, int duljina, int* pogodeno, char* odgovor, int zastavica) {
    while (!kraj) {
        // Ispisuje se rijec tako da umjesto slova koja nisu pogodena pisemo -
        cout << "Rijec glasi:";
        for (int j = 0; j < duljina; ++j) {
            cout << pogodeno[j];

            // if (pogodeno[j]) {
                 //cout << odgovor[j];
            // }
            // else {
            //     cout<<"-";
            // }
        }
        cout << "\n";

        // Igrac pogada
        char pokusaj;
        int slovo;
        cout << "Slovo? ";
        fflush(stdout);
        cin >> pokusaj;
        if (pokusaj == '!') {
            cout << "Spremanje igre!" << endl;
            file.open("staraigra.bin", ios::binary | ios::out);
            file.write((char*)&odgovor, sizeof(odgovor));
            file.write((char*)&pogodeno, sizeof(pogodeno));
            file.close();
            cout << "Igra spremljena!" << endl;
            return 0;
        }
        for (int i = 0; i < 22; i++) {
            if (toupper(pokusaj) == abeceda[i])
                slovo = i;
        }
        if (kopija_abecede[slovo] == '-' && pokusaj != '?')
            cout << "Ovo slovo vec je iskoristeno. Pokusajte ponovo.\n";

        else {

            kopija_abecede[slovo] = '-';

            system("cls");

            //crtamo naslov
            cout << "***********************\n";
            cout << "                             __                              \n";
            cout << " ||  ||   //\\      \\   ||\\   ||  //__| ||\\    /||   //\\\\   ||\\   ||\n";
            cout << " ||  ||  //  \\  ||   \\  ||\\\\  || ||   __  ||\\\\  //||  //  \\\\  ||\\\\  ||\n";
            cout << " ||  || ||    || || \\\\ || ||  |_| || \\\\// || ||_|| || \\\\ ||\n";
            cout << " ||--|| ||----|| ||  \\\\|| ||    || ||      || ||----|| ||  \\\\||\n";
            cout << " ||  || ||    || ||   \\||  \\|||||| ||      || ||    || ||   \\||\n";
            cout << "\n";
            cout << "***********************\n\n";


            if (pokusaj == '?') {
                cout << "Dostupna slova: ";
                for (int i = 0; i < 22; i++) {
                    if (kopija_abecede[i] != '-')
                        cout << abeceda[i] << " ";
                }
                cout << endl;
            }

            // U polju pogodeno, oznacavamo jedinicom sve pojave slova koje je igrac unio i smanjujemo broj pokusaja ako nije pogodio ni jedno slovo
            for (int k = 0; k < duljina; ++k) {
                if (odgovor[k] == pokusaj) {
                    pogodeno[k] = 1;
                    zastavica = 1;
                }
            }

            if (zastavica == 0) {
                if (pokusaj != '?' && pokusaj != '!') {
                    br--;
                }

                switch (br)
                {
                case 0:
                    kraj = 1;
                    cout << "Izgubili ste";
                    cout << "\n";
                    break;
                case 1:
                    cout << "Broj pokusaja: 1\n";
                    break;
                case 2:
                    cout << "Broj pokusaja: 2\n";
                    break;
                case 3:
                    cout << "Broj pokusaja: 3\n";
                    break;
                case 4:
                    cout << "Broj pokusaja: 4\n";
                    break;
                case 5:
                    cout << "Broj pokusaja: 5\n";
                    break;

                }

            }
            else
                cout << "\n";


            cout << "\n";

            switch (br)
            {
            case 0:
                cout << "  ___\n";
                cout << "  |/   | \n";
                cout << "  |    O \n";
                cout << "  |   \\|/\n";
                cout << "  |    | \n";
                cout << "  |   / \\\n";
                cout << "_|____\n\n";
                break;
            case 1:
                cout << "  ___\n";
                cout << "  |/   | \n";
                cout << "  |    O \n";
                cout << "  |   \\|/\n";
                cout << "  |    | \n";
                cout << "  |   /\n";
                cout << "_|____\n\n";
                break;
            case 2:
                cout << "  ___\n";
                cout << "  |/   | \n";
                cout << "  |    O \n";
                cout << "  |   \\|/\n";
                cout << "  |    | \n";
                cout << "  |\n";
                cout << "_|____\n\n";
                break;
            case 3:
                cout << "  ___\n";
                cout << "  |/   | \n";
                cout << "  |    O \n";
                cout << "  |   \\|\n";
                cout << "  |    | \n";
                cout << "  |\n";
                cout << "_|____\n\n";
                break;
            case 4:
                cout << "  ___\n";
                cout << "  |/   | \n";
                cout << "  |    O \n";
                cout << "  |    |\n";
                cout << "  |    |\n";
                cout << "  |\n";
                cout << "_|____\n\n";
                break;
            case 5:
                cout << "  ___\n";
                cout << "  |/   | \n";
                cout << "  |    O \n";
                cout << "  |\n";
                cout << "  |\n";
                cout << "  |\n";
                cout << "_|____\n\n";
                break;
            case 6:
                cout << "  ___\n";
                cout << "  |/\n";
                cout << "  |\n";
                cout << "  |\n";
                cout << "  |\n";
                cout << "  |\n";
                cout << "_|____\n\n";
                break;

            }





            zastavica = 0;

            // Odredujemo je li igrac pobijedio
            if (br != 0) {
                kraj = 1;
                for (int m = 0; m < duljina; ++m) {
                    if (!pogodeno[m]) {
                        kraj = 0;
                        break;
                    }
                }
            }

        }

    }
    return 0;
}

int main() {


    cout << "***********************\n";
    cout << "                             __                              \n";
    cout << " ||  ||   //\\\\   ||\\   ||  //__| ||\\    /||   //\\\\   ||\\   ||\n";
    cout << " ||  ||  //  \\\\  ||\\\\  || ||   __  ||\\\\  //||  //  \\\\  ||\\\\  ||\n";
    cout << " ||_|| ||_|| || \\\\ || ||  |_| || \\\\// || ||_|| || \\\\ ||\n";
    cout << " ||--|| ||----|| ||  \\\\|| ||    || ||      || ||----|| ||  \\\\||\n";
    cout << " ||  || ||    || ||   \\||  \\|||||| ||      || ||    || ||   \\||\n";
    cout << "\n";
    cout << "***********************\n\n";

    cout << "\n";
    cout << "\n";
    cout << "  ___\n";
    cout << "  |/\n";
    cout << "  |\n";
    cout << "  |\n";
    cout << "  |\n";
    cout << "  |\n";
    cout << "_|____\n\n";


    // ucitavanje rijeci
    char odgovor[128];
    char abeceda[22] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Z' };
    char kopija_abecede[22] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Z' };
    int br = 6, zastavica = 0;
    int kraj = 0; // varijabla koja nam govori kada je igra gotova (kao zastavica)

    cout << "Zelite li ucitati staru igru [y/n]";
    char izbor;
    cin >> izbor;
    if (toupper(izbor) == 'Y') {
        system("cls");
        cout << "Ucitavanje igre!" << endl;
        file.open("staraigra.bin", ios::binary | ios::in);
        if (file.fail()) {
            cout << "Greska pri otvaranju staraigra.bin. Datoteka ne postoji ili je krivo napisana!\n";
            return 0;
        }
        //file.read((char*)&kopija_abecede, sizeof(kopija_abecede));
        //file.read((char*)&br, sizeof(br));
        file.read((char*)&odgovor, sizeof(odgovor));
        int duljina = 128;
        int* pogodeno = new int[duljina];
        file.read((char*)&pogodeno, sizeof(pogodeno));
        file.close();
        cout << "Igra ucitana!" << endl;
        for (int i = 0; i < duljina; i++) {
            cout << odgovor[i];
        }
        cout << "\n";
        for (int i = 0; i < duljina; i++) {
            cout << pogodeno[i];
        }
        cout << "\n";
        return 0;
        igra(abeceda, kopija_abecede, kraj, br, duljina, pogodeno, odgovor, zastavica);
    }
    else {
        cout << "Unesi rijec za pogadanje:";
        fflush(stdout);
        cin >> odgovor;
        system("cls"); 
        int duljina = strlen(odgovor);
        int* pogodeno = new int[duljina];
        for (int i = 0; i < duljina; ++i) {
            pogodeno[i] = 0;
        }
        igra(abeceda, kopija_abecede, kraj, br, duljina, pogodeno, odgovor, zastavica);
    }


    // Svaki prolazak kroz petlju predstavlja jedan krug pogadanja


// Ovdje je bio stari kod

    // pobjednicka poruka
    if (br != 0)
        cout << "Pobjeda! Odgovor je:\n" << odgovor;

    return 0;
}