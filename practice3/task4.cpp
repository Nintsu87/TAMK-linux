#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;


// i have few extra commented lines for better visual how the program works when run
int main(int argc, char *argv[]) {
	// create path char* with using string
	string path_string = "/bin/";
	path_string += argv[1];
	char* path = new char[path_string.length() + 1];
	strcpy(path, path_string.c_str());

	// create args-vector so its usable with more than 2 command line arguments
	vector<char*> args;
	args.push_back(path);
	for (int i = 2; i < argc; i++) {
		args.push_back(argv[i]);
	}

	char* env[] = {NULL};
	pid_t c_pid = fork();

	if (c_pid < 0) { // if fork() fails
		cerr << "Fork failed." << endl;
		return 1;
	} else if (c_pid == 0) { // if no child is running
//		cout << "Child running.." << endl;
		// if execve() have problem, tell it
		if (execve(path, args.data(), env) == -1) {
			perror("execve");
			return 1;
		}
		return 0;
	} else { // start parent
//		cout << "parent running.." << endl;
		int status;
		// wait untill child is done with its code
		waitpid(c_pid, &status, 0);
//		cout << "parent continues" << endl;
		// free memorys
		delete[] path;
		return 0;
	}
}
