#include <stdio.h>
#define DULJINA_NIZA 50

// u zadatku je zadano da je niz sigurno manji od 50 znakova

#define BROJ_ZNAKOVA 128

// znakovi se u C-u prikazuju ASCII kodom koji ima 128 znakova

int main() {
	char niz[DULJINA_NIZA];
	// u polje znakovi cemo zapisati koliko se puta svaki znak
	// pojavljuje u nizu, a na pocetku ga postavimo na 0
	int znakovi[BROJ_ZNAKOVA] = {0};

	printf("Unesite niz > ");

	fgets(niz, DULJINA_NIZA, stdin);

	for (int i = 0; i < DULJINA_NIZA; i++) {
		// ako je trenutni znak '\0' to znaci da smo dosli
		// do kraja niza znakova i trebamo izaci iz petlje
		if (niz[i] == '\0') {
			break;
		} else {
			// inace u polju znakovi na mjestu trenutnog znaka
			// povecamo broj za 1 jer smo nasli taj znak
			znakovi[(int) niz[i]]++;
		}
	}

	// trazimo znakove s maksimalnim brojem ponavljanja
	// pa varijablu max postavljamo na 0
	int max = 0;

	// u for petlji prolazimo kroz svaki clan polja znakovi
	for (int i = 0; i < BROJ_ZNAKOVA; i++) {
		// ako se znak pojavljuje vise puta od vrijednosti max
		// max postaje ta vrijednost
		if (znakovi[i] > max) {
			max = znakovi[i];
		}
	}

	// kada smo nasli maksimalni broj ponavljanja moramo
	// naci sve znakove koji se pojavljuju toliko puta
	// i njih cemo spremiti u novo polje max_znakovi u kojem cemo
	// na pocetku staviti znakove '\0' koji oznacavaju kraj niza znakova

	char max_znakovi[BROJ_ZNAKOVA] = {'\0'};

	// varijabla trenutni_indeks nam govori na kojem mjestu u polju
	// max_znakovi cemo dodati iduci znak ako se pojavljuje
	// maksimalni broj puta, a pocetku ga postavimo na 0

	int trenutni_indeks = 0;

	for (int i = 0; i < BROJ_ZNAKOVA; i++) {
		// ako smo nasli znak koji se pojavljuje maksimalni
		// broj puta, dodajemo ga na trenutni_indeks u polje
		// max_znakovi i trenutni_indeks povecamo za 1
		if (znakovi[i] == max) {
			max_znakovi[trenutni_indeks] = i;
			trenutni_indeks++;
		}
	}

	// ako je trenutni_indeks = 1, onda smo
	// u polje max_znakovi spremili samo 1 znak

	if (trenutni_indeks == 1) {
		// onda ispisujemo taj nulti element polja
		// max_znakovi i broj ponavlajnja max
		printf("Znak \"%c\" se ponavlja %d puta.", max_znakovi[0], max);
	} else {
		// inace moramo ispisati sve znakove koji se
		// ponavljaju maksimalni broj puta

		// prvi znak ne ispisujemo u for petlji
		// jer ispred njega ne ide zarez
		printf("Znakovi \"%c\"", max_znakovi[0]);
		// i zato pocinjemo od indeksa i = 1
		for (int i = 1; i < trenutni_indeks; i++) {
			printf(", \"%c\"", max_znakovi[i]);
		}
		printf(" se ponavljaju %d puta.", max);
	}

	return 0;
}