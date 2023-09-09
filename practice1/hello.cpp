#include <iostream>
#include <string>
using namespace std;

int main (int argc, char* argv[]) {
	string name = "";
	if (argc == 1) {
		name = "stranger";
	} else {
		name = argv[1];
	}
	cout << "Hello, " << name << "!" << endl;
	return 0;

}
