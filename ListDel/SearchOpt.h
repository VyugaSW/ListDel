#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


//--������������ ����� ��� �� ��������� ���������

void ShowCase(Case* arr, int size);

void SearchOnName(Case* arr, int size, char* usName) {
	system("cls");
	cout << "���������� ����������: \n";
	for (int i = 0; i < size; i++) {
		if (strcmp(usName, arr[i].NameOfCase) == 0) {
			cout << "����� ���� - " << i + 1 << endl << "-----" << endl;
			cout << "��������� - " << arr[i].priority << endl;
			SetConsoleTextAttribute(console, 12);
			cout << arr[i].NameOfCase << "\n";
			SetConsoleTextAttribute(console, 15);
			cout << arr[i].description << "\n";
			cout << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
			cout << arr[i].date.hour << ":" << arr[i].date.minutes;
			cout << "\n--------------------\n\n";
		}
	}
}

void SearchOnPriority(Case* arr, int size, int usNumb) {
	system("cls");
	cout << "���������� ����������: \n";
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].priority) {
			cout << "����� ���� - " << i + 1 << endl << "-----" << endl;
			cout << "��������� - ";
			SetConsoleTextAttribute(console, 12);
			cout << arr[i].priority << endl;
			SetConsoleTextAttribute(console, 15);
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
	cout << "���������� ����������: \n";
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].date.year) {
			cout << "����� ���� - " << i + 1 << endl << "-----" << endl;
			cout << "��������� - " << arr[i].priority << endl;
			cout << arr[i].NameOfCase << "\n";
			cout << arr[i].description << "\n";
			cout << arr[i].date.day << "." << arr[i].date.month << ".";
			SetConsoleTextAttribute(console, 12);
			cout << arr[i].date.year << endl;
			SetConsoleTextAttribute(console, 15);
			cout << arr[i].date.hour << ":" << arr[i].date.minutes;
			cout << "\n--------------------\n\n";
		}
	}
}

void SearchOnMonth(Case* arr, int size, int usNumb) {
	system("cls");
	cout << "���������� ����������: \n";
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].date.month) {
			cout << "����� ���� - " << i + 1 << endl << "-----" << endl;
			cout << "��������� - " << arr[i].priority << endl;
			cout << arr[i].NameOfCase << "\n";
			cout << arr[i].description << "\n";
			cout << arr[i].date.day << ".";
			SetConsoleTextAttribute(console, 12);
			cout << arr[i].date.month;
			SetConsoleTextAttribute(console, 15);
			cout << "."  << arr[i].date.year << endl;
			cout << arr[i].date.hour << ":" << arr[i].date.minutes;
			cout << "\n--------------------\n\n";
		}
	}
}

void SearchOnDay(Case* arr, int size, int usNumb) {
	system("cls");
	cout << "���������� ����������: \n";
	for (int i = 0; i < size; i++) {
		if (usNumb == arr[i].date.day) {
			cout << "����� ���� - " << i + 1 << endl << "-----" << endl;
			cout << "��������� - " << arr[i].priority << endl;
			cout << arr[i].NameOfCase << "\n";
			cout << arr[i].description << "\n";
			SetConsoleTextAttribute(console, 12);
			cout << arr[i].date.day;
			SetConsoleTextAttribute(console, 15);
			cout << "." << arr[i].date.month << "." << arr[i].date.year << endl;
			cout << arr[i].date.hour << ":" << arr[i].date.minutes;
			cout << "\n--------------------\n\n";
		}
	}
}