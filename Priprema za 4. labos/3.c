#include <stdio.h>

int main() {
	int n;

	printf("Unesite n > ");
	
	scanf("%d", &n);

	int polje[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &polje[i][j]);
		}
	}

	// moramo izracunati sume po stupcima
	// i to cemo spremiti u polje

	int sume_stupaca[n];

	int suma;

	for (int i = 0; i < n; i++) {
		// na pocetku svakog ponavljanja sumu moramo postaviti na 0
		suma = 0;
		for (int j = 0; j < n; j++) {
			// buduci da zelimo sumu i-tog stupca
			// moramo gledati elemente svih j- stupaca
			suma = suma + polje[j][i];
		}
		sume_stupaca[i] = suma;
	}

	printf("Rezultat >");

	for (int i = 0; i < n - 1; i++) {
		// za prvih n - 1 stupaca trebamo ispisati
		printf(" %d", sume_stupaca[i] - sume_stupaca[i + 1]);
	}
	// a za zadnji stupac trebamo ispisati sumu tog - sumu prvog
	printf(" %d", sume_stupaca[n - 1] - sume_stupaca[0]);

	return 0;
}