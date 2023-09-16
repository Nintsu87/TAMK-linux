#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <sstream>

#define TRUE 1
using namespace std;


// i have few extra commented lines for better visual how the program works when run
int main(int argc, char *argv[]) {
	while (TRUE) {// create path char* with using string
		string user_input,
			path_s = "/bin/";
		cout << "Anna komento: ";
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, user_input);

		if(user_input == "") {
			return 0;
		} else {
			int helper = 0;

			// create args-vector so its usable with more than 2 command line arguments
			vector<const char*> args;
			istringstream iss(user_input);
			string token;
			while (iss >> token) {
				if (helper == 0) {
					path_s += token;
					args.push_back(path_s.c_str());
					helper++;
				} else {
					args.push_back(token.c_str());
				}
			}
			char* path = new char[path_s.length() + 1];
			strcpy(path, path_s.c_str());
			char* env[] = {NULL};
			pid_t c_pid = fork();

			if (c_pid < 0) { // if fork() fails
				cerr << "Fork failed." << endl;
				return 1;
			} else if (c_pid == 0) { // if no child is running
//				cout << "Child running.." << endl;
				// if execve() have problem, tell it
				if (execve(path, const_cast<char* const*>(args.data()), env) == -1) {
					perror("execve");
					return 1;
				}
			} else { // start parent
//				cout << "parent running.." << endl;
				int status;
				// wait untill child is done with its code
				waitpid(c_pid, &status, 0);
//				cout << "parent continues" << endl;
				// free memorys
				delete[] path;
			}
		}
	}
}
