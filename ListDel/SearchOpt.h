#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
// Ќе могу в данном заголовке никак сослатьс€ из главна€ файла на массив структур, поэтому, пока оно не работает
// 
//ќсуществл€ем поиск дел по различным критери€м
struct Case {
	char* NameOfCase = new char[256];
	char* description = new char[256];
	int priority;
	struct {
		int year;
		int month;
		int day;
		int hour;
		int minutes;
	} date;
};

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