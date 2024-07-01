#pragma warning(disable : 4996)

#include<iostream>

#ifdef _WIN32
#include<direct.h>
#define CLEARSCR "cls"
#else
#include<unistd.h>
#define CLEARSCR "clear"
#endif

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"
#define BLUE "\033[34m"

#ifdef _WIN32
bool ok = 1;
#endif

using namespace std;

int main() {
	system(CLEARSCR);
	cout << BLUE << "DTerminal\n\n";
	char command[1001];
	while (strcmp(command, "exit") != 0) {
		cout << GREEN << "shell > " << WHITE;
		cin.getline(command, 1000);
		if (system(command)) {
			cout << '\n';
			continue;
		}
		else if (strncmp(command, "cd..", 4) == 0 && ok) {
			cout << RED << "Use 'cd ..' instead of 'cd..'\n" << WHITE;
		}
		else if (strncmp(command, "cd", 2) == 0)
			chdir(command + 3);

		cout << '\n';
	}
	return 0;
}