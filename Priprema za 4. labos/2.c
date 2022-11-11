#include <stdio.h>
#define DULJINA_NIZA 200

// u zadatku je zadano da je niz sigurno manji od 200 znakova

int main() {
	char niz[DULJINA_NIZA];
	
	printf("Upisite znakovni niz > ");

	fgets(niz, DULJINA_NIZA, stdin);

	char obrnuti_niz[DULJINA_NIZA];

	// trebamo izracunati broj znakova
	// u prvom nizu prije '\0' ili neki
   // znak koji nije izmedu 32 i 126 jer
   // je tako zadano u zadatku

	int broj_znakova = 0;

	for (int i = 0; i < DULJINA_NIZA; i++) {
		if (niz[i] == '\0' || niz[i] > 126 || niz[i] < 32) {
			break;
		} else {
			broj_znakova++;
		}
	}

	for (int i = 0; i < broj_znakova; i++) {
		// buduci da obrcemo pocetni niz element koji
		// je u njemu bio na mjestu i sada ce biti na
		// na mjestu broj_znakova - 1 - i;

		// ali moramo provjeriti je li taj znak malo
		// slovo i ako je pretvoriti ga u veliko
		if (niz[i] >= 'a' && niz[i] <= 'z') {
			niz[i] = niz[i] + ('A' - 'a');
		}

		obrnuti_niz[broj_znakova - 1 - i] = niz[i]; 
	}

	// znak na mjestu broj_znakova u obrnutom nizu moramo
	// postaviti na '\0' d aoznačimo da tu niz prestaje
	obrnuti_niz[broj_znakova] = '\0';

	printf("Obrnuti niz: %s", obrnuti_niz);

	return 0;
}