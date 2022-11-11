#include <stdio.h>
#define DULJINA_NIZA 150

// u zadatku je zadano da je niz sigurno manji od 150 znakova

int main() {
   char niz[DULJINA_NIZA];

   printf("Upisite znakovni niz > ");

   fgets(niz, DULJINA_NIZA, stdin);

   // u novi niz cemo upisivati clanove koji su slova
   // engleske abecede (od a do z i od A do Z) i
   // postavimo ga tako da su mu svi clanovi '\0'

   char novi_niz[DULJINA_NIZA] = {'\0'};

   int trenutni_indeks = 0;

   for (int i = 0; i < DULJINA_NIZA; i++) {
      // ako je trenutni znak '\0' znaci da smo dosli
      // do kraja stringa i trebamo izaci iz petlje
      if (niz[i] == '\0') {
         break;
      }

      // ako je znak slovo engleske abecede postavimo ga
      // na trenutni_indeks i trenutni_indeks povecamo za 1
      if (niz[i] >= 'A' && niz[i] <= 'Z') {
         novi_niz[trenutni_indeks] = niz[i];
         trenutni_indeks++;
      }
      if (niz[i] >= 'a' && niz[i] <= 'z') {
         novi_niz[trenutni_indeks] = niz[i];
         trenutni_indeks++;
      }
   }

   printf("Izlazni znakovni niz je : ");

   // ako je prvi clan novog niza '\0' znaci
   // da se radi o praznom stringu

   if (novi_niz[0] == '\0') {
      printf("prazan string");
   } else {
      printf("%s", novi_niz);
   }

   return 0;
}