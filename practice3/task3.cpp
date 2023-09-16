#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


using namespace std;

int main() {
	char* path = "/bin/ls";
	char* args[] = {path, NULL};
	char* env[] = {NULL};

	pid_t c_pid = fork();

	if (c_pid < 0) {
		cerr << "Fork failed." << endl;
		return 1;
	} else if (c_pid == 0) {
		cout << "Child running.." << endl;
		if (execve(path, args, env) == -1) {
			perror("execve");
			return 1;
		}
		return 0;
	} else {
		cout << "parent running.." << endl;
		int status;
		waitpid(c_pid, &status, 0);
		cout << "parent continues" << endl;
		return 0;
	}
}
