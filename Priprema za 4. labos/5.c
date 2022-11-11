#include <stdio.h>

int main() {
	int n;

	printf("Upisite broj redaka/stupaca matrice > ");
	
	scanf("%d", &n);

	int matrica[n][n];

	printf("Upisite %dx%d clanova > \n", n, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}

	int redak;

	printf("Upisite redni broj retka > ");

	scanf("%d", &redak);

	int stupac;

	printf("Upisite redni broj stupca > ");

	scanf("%d", &stupac);

	int suma = 0;

	// moramo izracunati sumu borjeva u redtku i u stupcu
	// te onda oduzeti element koji se nalazi na presjeku
	// tog retka i stupca jer smo ga dvaput zborjili u sumu

	// zbroj elemenata u retku
	for (int i = 0; i < n; i++) {
		suma = suma + matrica[redak][i];
	}

	// zbroj elemenata u stupcu
	for (int i = 0; i < n; i++) {
		suma = suma + matrica[i][stupac];
	}

	suma = suma - matrica[redak][stupac];

	printf("Suma brojeva koji se nalaze u retku %d i stupcu %d je %d.", redak, stupac, suma);

	return 0;
}