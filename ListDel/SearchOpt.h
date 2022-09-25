#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>



using namespace std;

void ShowCase(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size, int mode);
//Осуществляем поиск дел по различным критериям

void SearchOnName(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size, char* buff) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i < size; i++) {
		if (name[i] == buff)
		{
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << priority[i] << endl;
			cout << name[i] << "\n";
			cout << description[i] << "\n";
			cout << day[i] << "." << month[i] << "." << year[i] << endl;
			cout << hour[i] << ":" << minutes[i];
			cout << "\n--------------------\n\n";
		}
	}
}

void SearchOnPriority(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size, int numb) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i < size; i++) {
		if (priority[i] == numb) 
		{
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << priority[i] << endl;
			cout << name[i] << "\n";
			cout << description[i] << "\n";
			cout << day[i] << "." << month[i] << "." << year[i] << endl;
			cout << hour[i] << ":" << minutes[i];
			cout << "\n--------------------\n\n";
		}
	}
}

void SearchOnYear(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size, int numb) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i < size; i++) {
		if (year[i] == numb)
		{
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << priority[i] << endl;
			cout << name[i] << "\n";
			cout << description[i] << "\n";
			cout << day[i] << "." << month[i] << "." << year[i] << endl;
			cout << hour[i] << ":" << minutes[i];
			cout << "\n--------------------\n\n";
		}

	}
}

void SearchOnMonth(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size, int numb) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i < size; i++) {
		if (month[i] == numb)
		{
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << priority[i] << endl;
			cout << name[i] << "\n";
			cout << description[i] << "\n";
			cout << day[i] << "." << month[i] << "." << year[i] << endl;
			cout << hour[i] << ":" << minutes[i];
			cout << "\n--------------------\n\n";
		}

	}
}
void SearchOnDay(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size, int numb) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i < size; i++) {
		if (day[i] == numb)		
		{
			//ShowCase(name, description, priority, year, day, month, hour, minutes, i, 2);
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << priority[i] << endl;
			cout << name[i] << "\n";
			cout << description[i] << "\n";
			cout << day[i] << "." << month[i] << "." << year[i] << endl;
			cout << hour[i] << ":" << minutes[i];
			cout << "\n--------------------\n\n";
		}

	}
}