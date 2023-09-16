#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	cout << "Komentoriviargumentteja: " << argc - 1 << endl;
	cout << "Ja ne ovat: " << endl;
	for (int i = 1; i < argc; i++) {
		cout << argv[i] << endl;
	}


	return 0;
}
