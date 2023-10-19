#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
	// sain size = 2095226 koulun linuxilla ssh kautta kerran, mutta luku
	// muuttuu core dumbiksi ajoittain, joten otin 2miljoonaa varmuuden vuoksi
	bool silent = false;
	const int size = 2000000;
	int list[size];

	// luo list-arrayn jokaiseen alkioon alkion indeksin mukaisen numeron
	for (int i = 0; i < size; i++) {
		list[i] = i;
	}

	// tarkistaa, onko argc:ssa jotain ja varmistaa, onko se "-s" jotta coutin saa hiljennettyä
	for (int i = 1; i < argc; ++i) {
		if (string(argv[i]) == "-s") {
			silent = true;
			break;
		}
	}
	// tulostaa 100 viimeistä alkioo, jos ei ole hiljennetty
	if (!silent) {
		for (int i = (size-100); i < size; i++) {
			cout << list[i] << endl;
		}
	}
	return 0;
}
