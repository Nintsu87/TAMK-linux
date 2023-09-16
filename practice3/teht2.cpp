#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
	char* path = "/bin/ls";
	char* args[] = {path, NULL};
	char* env[] = {NULL};
	// taman ohjelman ajon sijaan ajaa execven pakottaman ohjelman
	if (execve(path, args, env) == -1) {
		perror("execve");
		return 1;
	}
	return 0;
}
