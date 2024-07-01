#pragma warning(disable : 4996)

#include<iostream>

#ifdef _WIN32
#include<direct.h>
#else
#include<unistd.h>
#endif

#ifdef _WIN32
bool ok = 1;
#endif

using namespace std;

int main() {
	cout << "DTerminal\n\n";
	char command[1001];
	while (strcmp(command, "exit") != 0) {
		cout << "shell > ";
		cin.getline(command, 1000);
		if (system(command)) {
			cout << '\n';
			continue;
		}
		else if (strncmp(command, "cd..", 4) == 1 && ok) {
			cout << "Use 'cd ..' instead of 'cd..'\n";
		}
		else if (strncmp(command, "cd", 2) == 1)
			chdir(command + 3);

		cout << '\n';
	}
	return 0;
}