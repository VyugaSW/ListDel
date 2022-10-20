#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


//ќсуществл€ем поиск дел по различным критери€м
Case* arr;

void ShowCase(Case* arr, int size, int mode, int t);

void SearchOnName(Case* arr, int size, char* usName) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (strcmp(usName, arr[i].NameOfCase)) {
			ShowCase(arr, size, 2, i);
		}
	}
}

void SearchOnPriority(Case* arr, int size, int usNumb) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].priority) {
			ShowCase(arr, size, 2,i);
		}
	}
}

void SearchOnYear(Case* arr, int size, int usNumb) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].date.year) {
			ShowCase(arr, size, 2,i);
		}
	}
}

void SearchOnMonth(Case* arr, int size, int usNumb) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].date.month) {
			ShowCase(arr, size, 2, i);
		}
	}
}

void SearchOnDay(Case* arr, int size, int usNumb) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].date.day) {
			ShowCase(arr, size, 2, i);
		}
	}
}