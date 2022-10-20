#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <limits>
#include <conio.h>



using namespace std;


//Структура, хранящая параметры дела
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

//Рукотворный заголовок
#include "SearchOpt.h"

void FillArrs(Case* arr, int size); //Добавление
void MassRedact(Case* arr, int usNumb); //Редактирование
void ShowCase(Case* arr, int size, int mode, int t); //Отображение
void SearchCase(Case* arr, int size); // Поиск дела
void SortingCases(); //Сортировка дел

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 0;
	int z; //Считывание нажатия клавиш

	Case* arr = new Case[size];  //Массив структур

	int user_chose; //Переменная выбора
	bool flag = true; //Не даёт программе оставовиться
	//Непосредственно сам цикл, т.е. меню приложения и весь функционал
	while (flag) {

		system("cls");

		cout << "\t\tСПИСОК ДЕЛ\n\n";
		cout << "--Выберите опцию:\n";
		cout << "1 - Добавить дело\n";
		cout << "2 - Удалить дело\n";
		cout << "3 - Редактировать дело\n";
		cout << "4 - Поиск дела\n";
		cout << "5 - Отображение дел\n";
		cout << "6 - Сортировка дел\n\n";
		cin >> user_chose;

		//Выбор опции

		switch (user_chose) {
		case 1:
			size++;
			FillArrs(arr, size);
			break;
		case 2:

			break;

		case 3:
			system("cls");
			cout << "Какое дело отредактировать?\n";
			cout << "\tНомера дел\n";

			for (int i = 0; i < size; i++) {
				cout << "-  " << i + 1 << endl;
			}

			cin >> user_chose;
			MassRedact(arr, user_chose);
			break;
		case 4:
			SearchCase(arr, size);
			break;
		case 5:
			ShowCase(arr, size, 1,0);
			cout << "Для продолжения нажмите любую клавишу\n";
			z = _getch();
			break;
		case 6:
			break;
		default:
			cout << "Не пользуйся программой";
			break;
		}
	}

}

//Выводит все дела
void ShowCase(Case* arr, int size, int mode, int t) { //int t - для mode 2
	// mode 1 отвечает за отображение дел по порядку
	if (mode == 1) {
		for (int i = 0; i < size; i++) {
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << arr[i].priority << endl;
			cout << arr[i].NameOfCase << "\n";
			cout << arr[i].description << "\n";
			cout << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
			cout << arr[i].date.hour << ":" << arr[i].date.minutes;
			cout << "\n--------------------\n\n";
		}
	}

	// mode 2 или же else, в ответственности за отображение дела поштучно (функция поиска)
	else if (mode == 2) {
		cout << "Номер дела - " << t+1 << endl << endl;
		cout << "Приоритет - " << arr[t].priority << endl;
		cout << arr[t].NameOfCase << "\n";
		cout << arr[t].description << "\n";
		cout << arr[t].date.day << "." << arr[t].date.month << "." << arr[t].date.year << endl;
		cout << arr[t].date.hour << ":" << arr[t].date.minutes;
		cout << "\n--------------------\n\n";
	}
}

// Возможность пользователя редактировать дело, т.е. массивы
void MassRedact(Case* arr, int usNumb) {
	system("cls");
	char* buff = new char[256]; //Хранить строку пользователя

	cout << "Что необходимо отредактировать?\n";
	cout << "Имя - 1\n" << "Приоритет - 2\n" << "Описание - 3\n" <<
		"Дату - 4\n" << "Всё дело - 5\n";

	int user_chose;
	cin >> user_chose;
	switch (user_chose) {
	case 1:
		cin.ignore(256, '\n');
		cout << "Введите новое имя:\n";
		gets_s(buff, 256);
		arr[usNumb - 1].NameOfCase;
		break;
	case 2:
		cout << "Введите новый приоритет:\n"; \
			arr[usNumb - 1].priority;
		break;

	case 3:
		cin.ignore(256, '\n');
		cout << "Введите новое описание:\n";
		gets_s(buff, 256);
		arr[usNumb - 1].description;
		break;
	case 4:
		cout << "Введите новую дату (Год, месяц, день, час, минута):\n";
		cin >> arr[usNumb - 1].date.year;
		cin >> arr[usNumb - 1].date.month;
		cin >> arr[usNumb - 1].date.day;
		cin >> arr[usNumb - 1].date.hour;
		cin >> arr[usNumb - 1].date.minutes;
		break;
	case 5:
		FillArrs(arr, usNumb);
		break;
	}
}

//Добавление дела
void FillArrs(Case* arr, int size) {
	system("cls");
	char* buff = new char[256]{ "If you see this, you cheated" }; //Хранить строку пользователя
	char* buff2 = new char[256]{ "If you see this, you cheated" }; //Пока что через два буфера

	cout << "Введите имя дела:\n";
	cin.ignore(256, '\n');    //Очищаем поток ввода
	gets_s(buff, 256);
	arr[size - 1].NameOfCase = buff;

	cout << "Введите описание дела:\n";
	gets_s(buff2, 256);
	arr[size - 1].description = buff2;

	cout << "Введите приоритет дела (1 - самое важное, ... 5 - самое неважное): \n";
	cin >> arr[size - 1].priority;

	cout << "Введите дату (год, месяц, день, час, минута): \n";
	cin >> arr[size - 1].date.year;
	cin >> arr[size - 1].date.month;
	cin >> arr[size - 1].date.day;
	cin >> arr[size - 1].date.hour;
	cin >> arr[size - 1].date.minutes;
}


void SearchCase(Case* arr, int size) {
	
	system("cls");
	int z; // Считывание нажатия клавиши
	int user_chose; //Выбор пользователя
	int alltemp; //Переменная для поисков
	char* buff = new char[256]; //Хранить строку пользователя
	cout << "Поиск дела по:\n";
	cout << "1 - Имени\n";
	cout << "2 - Приоритету\n";
	cout << "3 - Году\n";
	cout << "4 - Месяцу\n";
	cout << "5 - Дню\n";

	cin >> user_chose;

	switch (user_chose) {
	case 1:
		cin.ignore(256, '\n'); // Очистка потока ввода
		cout << "Введите искомое имя:\n";
		gets_s(buff, 256);
		SearchOnName(arr,size,buff);
		cout << "Для продолжения нажмите любую клавишу\n";
		z = _getch();
		break;
	case 2:
		cout << "Приоритет:\n";
		cin >> alltemp;
		SearchOnPriority(arr, size, alltemp);
		cout << "Для продолжения нажмите любую клавишу\n";
		z = _getch();
		break;
	case 3:
		cout << "Год:\n";
		cin >> alltemp;
		SearchOnYear(arr, size, alltemp);
		cout << "Для продолжения нажмите любую клавишу\n";
		z = _getch();
		break;
	case 4:
		cout << "Месяц:\n";
		cin >> alltemp;
		SearchOnMonth(arr, size, alltemp);
		cout << "Для продолжения нажмите любую клавишу\n";
		z = _getch();
		break;
	case 5:
		cout << "День:\n";
		cin >> alltemp;
		SearchOnDay(arr, size, alltemp);
		cout << "Для продолжения нажмите любую клавишу\n";
		z = _getch();
		break;
	}
}

//Сортировка дел
void SortingCases() {
	cout << "Сортировка дел по: \n";
	cout << "1 - Имени\n";
	cout << "2 - Году\n";
	cout << "3 - Приоритету\n";
	int user_chose;
	cin >> user_chose;
	char* buff = new char[256]; //Хранить строку пользователя
	switch (user_chose) {
	case 1:
		cin.ignore(256, '\n'); // Очистка потока ввода
		gets_s(buff, 256);
		break;
	case 2:

		break;
	case 3:

		break;
	}

}