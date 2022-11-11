#include <stdio.h>

int main() {
	int m;
	
	printf("Upisite velicinu polja m > ");

	scanf("%d", &m);

	printf("Upisite %d clanova polja m > ", m);

	int polje[m];

	for (int i = 0; i < m; i++) {
		scanf("%d", &polje[i]);
	}

	// trazimo pod-polje s maksimalnom sumom tako da
	// probamo poceti od svakog clana polja i probamo
	// zavrsiti sa svakim clanom nakon njega

	int pocetni_indeks = 0;
	int zavrsni_indeks = 0;
	int max = 0;
	int suma;

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			// sumu postavimo na 0 prije racunanja
			suma = 0;

			// za svaki pocetni indeks i te zavrsni indeks j
			// gledamo sumu izmedu tih elemenata i ako je veca
			// od max, ona postaje max, a i i j postaju pocetni
			// i zavrsni indeksi

			for (int k = i; k < j; k++) {
				suma = suma + polje[k];
			}

			if (suma > max) {
				max = suma;
				pocetni_indeks = i;
				zavrsni_indeks = j;
			}
		}
	}
	
	// kad smo nasli to pod polje ispisemo ga

	printf("Pronadjeno pod-polje:");

	for (int i = pocetni_indeks; i < zavrsni_indeks; i++) {
		printf(" %d", polje[i]);
	}

	printf("\nNajveca suma kontinuiranog pod-polja je: %d", max);

	return 0;
}