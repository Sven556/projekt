#include <stdio.h>
#include <string.h>

int main() {
  // učitavanje riječi
  char odgovor[128];
  char abeceda[22]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Z'};
  int br=10, zastavica=0;

  printf("Unesi rijec za pogadanje: ");
  fflush(stdout);
  scanf(" %s", odgovor);

  // Postavi pomocno polje - pogodeno[i] je 1 ako
  // je znak odgovor[i] pogoden.
  // Ovo polje inicijaliziramo na 0 jer na pocetku nista nije pogodeno.
  int N = strlen(odgovor); //N= duljina odgovora
  int pogodeno[N];
  for (int i=0; i < N; ++i) {
    pogodeno[i] = 0;
  }

  // Svaki prolazak kroz petlju predstavlja jedan krug pogadanja
  int kraj = 0; // varijabla koja nam govori kada je igra gotova (kao zastavica)
  while (!kraj) {
    // Ispisuje se riječ tako da umjesto slova koja nisu pogodena pisemo -
    printf("Rijec glasi: ");
    for(int j=0; j < N; ++j) {
      if (pogodeno[j]) {
        printf("%c", odgovor[j]);
        zastavica=1;
      }
      else {
        printf("-");
      }
    }
    printf("\n");

    // Igrac pogada
    char pokusaj;
    printf("Slovo? ");
    fflush(stdout);
    scanf(" %c", &pokusaj);


    for(int i=0;i<22;i++){
            if(toupper(pokusaj)==abeceda[i])
                abeceda[i]='-';
        }

    if(pokusaj=='?'){
        printf("Dostupna slova: ");
        for(int i=0;i<22;i++){
            if(abeceda[i]!='-')
                printf("%c ", abeceda[i]);
        }
        printf("\n");
    }

    // U polju pogodeno, oznacavamo jedinicom sve pojave slova koje je igrac unio i smanjujemo broj pokusaja ako nije pogodio ni jedno slovo
    for(int k=0; k < N; ++k) {
      if (odgovor[k] == pokusaj) {
        pogodeno[k] = 1;
        zastavica=1;
      }
      if(zastavica=0){
        br--;
        printf("\n%d", br);

        switch (br)
        {
        case 0:
            kraj=1;
            printf("Izgubili ste");
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;

        }

      }

    }

    zastavica=0;

    // Određujemo je li igrac pobijedio
    kraj = 1;
    for(int m = 0; m < N; ++m) {
      if (!pogodeno[m]) {
        kraj= 0;
        break;
      }
    }


  }

  // Print victory message!
  if(br!=0)
    printf("Pobjeda! Odgovor je \"%s\".\n", odgovor);

  return 0;
}
