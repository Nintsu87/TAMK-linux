#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	ifstream file;

	file.open("nofile.txt");

	if (file) {
		cout << "\"nofile.txt\" could be opened." << endl;
		file.close();
	} else {
		cerr << "Can't open \"nofile.txt\": " << strerror(errno) << endl;
		perror("open");
	}
	return 0;
}
