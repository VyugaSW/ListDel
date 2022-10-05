#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
// Не могу в данном заголовке никак сослаться из главная файла на массив структур, поэтому, пока оно не работает
// 
//Осуществляем поиск дел по различным критериям
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

void SearchOnName(Case* arr, int size, char* usNumb) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].NameOfCase) {
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << arr[i].priority << endl;
			cout << arr[i].NameOfCase << "\n";
			cout << arr[i].description << "\n";
			cout << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
			cout << arr[i].date.hour << ":" << arr[i].date.minutes;
			cout << "\n--------------------\n\n";
		}
	}
}

void SearchOnPriority(Case* arr, int size, int usNumb) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].priority) {
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << arr[i].priority << endl;
			cout << arr[i].NameOfCase << "\n";
			cout << arr[i].description << "\n";
			cout << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
			cout << arr[i].date.hour << ":" << arr[i].date.minutes;
			cout << "\n--------------------\n\n";
		}
	}
}

void SearchOnYear(Case* arr, int size, int usNumb) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].date.year) {
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << arr[i].priority << endl;
			cout << arr[i].NameOfCase << "\n";
			cout << arr[i].description << "\n";
			cout << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
			cout << arr[i].date.hour << ":" << arr[i].date.minutes;
			cout << "\n--------------------\n\n";
		}
	}
}

void SearchOnMonth(Case* arr, int size, int usNumb) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].date.month) {
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << arr[i].priority << endl;
			cout << arr[i].NameOfCase << "\n";
			cout << arr[i].description << "\n";
			cout << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
			cout << arr[i].date.hour << ":" << arr[i].date.minutes;
			cout << "\n--------------------\n\n";
		}
	}
}

void SearchOnDay(Case* arr, int size, int usNumb) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].date.day) {
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << arr[i].priority << endl;
			cout << arr[i].NameOfCase << "\n";
			cout << arr[i].description << "\n";
			cout << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
			cout << arr[i].date.hour << ":" << arr[i].date.minutes;
			cout << "\n--------------------\n\n";
		}
	}
}