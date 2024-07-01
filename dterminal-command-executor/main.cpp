#pragma warning(disable : 4996)

#include<iostream>

#ifdef _WIN32
#include<direct.h>
#define CLEARSCR "cls"
bool ok = 1;
#else
#include<unistd.h>
#define CLEARSCR "clear"
bool ok = 0;
#endif

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define WHITE "\033[37m"
#define BLUE "\033[34m"

using namespace std;

int main() {
	system(CLEARSCR);
	cout << BLUE << "DTerminal ver 1.2\n\n";
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