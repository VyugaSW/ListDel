#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//Сортировка по году
void SortingOnYear(Case* arr, int size,Case**pointCases) {
	Case* temp = arr;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (pointCases[j]->date.year > pointCases[j + 1]->date.year) {
				temp = pointCases[j];
				pointCases[j] = pointCases[j + 1];
				pointCases[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << "Номер дела - " << i + 1 << endl << "-----" << endl;
		cout << "Приоритет - " << arr[i].priority << endl;
		cout << arr[i].NameOfCase << "\n";
		cout << arr[i].description << "\n";
		cout << arr[i].date.day << "." << arr[i].date.month << "." << pointCases[i]->date.year << endl;
		cout << arr[i].date.hour << ":" << arr[i].date.minutes;
		cout << "\n--------------------\n\n";
	}
	delete[] temp;
}
//Сортировка по имени
void SortingOnName(Case* arr, int size, Case** pointCases) {
	Case* temp = arr;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(pointCases[j]->NameOfCase, pointCases[j + 1]->NameOfCase) > 0) {
				temp = pointCases[j];
				pointCases[j] = pointCases[j + 1];
				pointCases[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << "Номер дела - " << i + 1 << endl << "-----" << endl;
		cout << "Приоритет - " << arr[i].priority << endl;
		cout << pointCases[i]->NameOfCase << "\n";
		cout << arr[i].description << "\n";
		cout << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
		cout << arr[i].date.hour << ":" << arr[i].date.minutes;
		cout << "\n--------------------\n\n";
	}
	delete[] temp;
}
//Сортировка
void SortingOnPriority(Case* arr, int size, Case** pointCases) {
	Case* temp = arr;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (pointCases[j]->priority > pointCases[j + 1]->priority) {
				temp = pointCases[j];
				pointCases[j] = pointCases[j + 1];
				pointCases[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << "Номер дела - " << i + 1 << endl << "-----" << endl;
		cout << "Приоритет - " << pointCases[i]->priority << endl;
		cout << arr[i].NameOfCase << "\n";
		cout << arr[i].description << "\n";
		cout << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
		cout << arr[i].date.hour << ":" << arr[i].date.minutes;
		cout << "\n--------------------\n\n";
	}
	delete[] temp;
}