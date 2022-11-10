#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <limits>
#include <conio.h>


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
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
#include "SortingCases.h"
Case* DeleteArr(Case* arr, int& size, int index);//Удаление
void FillArrs(Case* arr, int size); //Добавление
void MassRedact(Case* arr, int usNumb); //Редактирование
void ShowCase(Case* arr, int size); //Отображение
void SearchCase(Case* arr, int size); // Поиск дела
void SortingCases(Case** q, int size, Case* arr); //Сортировка дел
Case* UpdateArr(Case* arr, int& size); //Увеличение массива (добавление дела)

int main() {
	SetConsoleTextAttribute(console, 15);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 0;

	Case* arr = new Case[size];  //Массив структур
	Case** pointCases = new Case * [size]; //Массив указателей
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
		cout << "6 - Сортировка дел\n";
		cout << "(Клавиши NumPad)\n\n";
		user_chose = _getch();
		//Выбор опции

		switch (user_chose) {
		case 49: //1
			system("cls");
			cout << "\tДля отмены нажмите \"Esc\", для продолжение \"Space\"\n\n";
			user_chose = _getch();
			if (user_chose == 27)
				break;
			arr = UpdateArr(arr, size);
			FillArrs(arr, size);
			break;
		case 50: //2
			system("cls");
			cout << "Какое дело отредактировать?\n";
			cout << "\tНомера дел\n";
			for (int i = 0; i < size; i++) {
				cout << "-  " << i + 1 << endl;
			}
			cout << "(Вернуться в меню - \"Esc\")\n";
			user_chose = _getch();
			if (user_chose == 27)
				break;
			else
				user_chose -= 48; //NumPad 1 = 49, NumPad 2 = 50, => отняв 48, получаем чистое число (номер дела)
			arr = DeleteArr(arr, size,user_chose);
			break;
		case 51: //3
			system("cls");
			cout << "Какое дело удалить?\n";
			cout << "\tНомера дел\n";
			for (int i = 0; i < size; i++) {
				cout << "-  " << i + 1 << endl;
			}
			cout << "(Вернуться в меню - \"Esc\")\n";
			user_chose = _getch();
			if (user_chose == 27)
				break;
			else
				user_chose -= 48; //NumPad 1 = 49, NumPad 2 = 50, => отняв 48, получаем чистое число (номер дела)
			MassRedact(arr, user_chose);
			break;
		case 52: //4
			system("cls");
			SearchCase(arr, size);
			break;
		case 53: //5
			system("cls");
			ShowCase(arr, size);
			cout << "Для продолжения нажмите любую клавишу\n";
			_getch();
			break;
		case 54: //6
			SortingCases(pointCases,size,arr);
			break;
		default:
			cout << "ОШИБКА!";
			Sleep(1800);
			break;
		}
	}

}
//Увеличение размера массива
Case * UpdateArr(Case* arr, int &size) {
	size++;
	//Создаём новый массив
	Case* newArr = new Case[size];
	//Копируем старый массив в новый
	for (int i = 0; i < size - 1; i++) {
		strcpy_s(newArr[i].NameOfCase, 256, arr[i].NameOfCase);
		strcpy_s(newArr[i].description, 256, arr[i].description);
		newArr[i].priority = arr[i].priority;
		newArr[i].date.day = arr[i].date.day;
		newArr[i].date.month = arr[i].date.month;
		newArr[i].date.year = arr[i].date.year;
		newArr[i].date.hour = arr[i].date.hour;
		newArr[i].date.minutes = arr[i].date.minutes;
	}
	delete[] arr; //Удаляем старый
	return newArr;
}

//Выводит все дела
void ShowCase(Case* arr, int size) { 
	for (int i = 0; i < size; i++) {
		cout << "Номер дела - " << i + 1 << endl << "-----" << endl;
		cout << "Приоритет - " << arr[i].priority << endl;
		cout << arr[i].NameOfCase << "\n";
		cout << arr[i].description << "\n";
		cout << arr[i].date.day << "." << arr[i].date.month << "." << arr[i].date.year << endl;
		cout << arr[i].date.hour << ":" << arr[i].date.minutes;
		cout << "\n--------------------\n\n";
	}

}

// Возможность пользователя редактировать дело, т.е. массивы
void MassRedact(Case* arr, int usNumb) {
	system("cls");
	char* buff = new char[256]; //Хранить строку пользователя
	char* buff2 = new char[256];
	cout << "Что необходимо отредактировать?\n";
	cout << "Имя - 1\n" << "Приоритет - 2\n" << "Описание - 3\n" <<
		"Дату - 4\n" << "Всё дело - 5\n";

	int user_chose;
	user_chose = _getch();
	cout << endl;
	switch (user_chose) {
	case 49:
		cin.ignore(256, '\n');
		cout << "Введите новое имя:\n";
		gets_s(buff, 256);
		arr[usNumb - 1].NameOfCase = buff;
		break;
	case 50:
		cout << "Введите новый приоритет:\n";
		cin >> arr[usNumb - 1].priority;
		break;

	case 51:
		cin.ignore(256, '\n');
		cout << "Введите новое описание:\n";
		gets_s(buff2, 256);
		arr[usNumb - 1].description = buff2;
		break;
	case 52:
		cout << "Введите новую дату (Год, месяц, день, час, минута):\n";
		cin >> arr[usNumb - 1].date.year;
		cin >> arr[usNumb - 1].date.month;
		cin >> arr[usNumb - 1].date.day;
		cin >> arr[usNumb - 1].date.hour;
		cin >> arr[usNumb - 1].date.minutes;
		break;
	case 53:
		FillArrs(arr, usNumb);
		break;

	}
}

//Добавление дела
void FillArrs(Case* arr, int size) {
	system("cls");
	
	cout << "Введите имя дела:\n";
	if (size > 1)
		cin.ignore(256, '\n');

	try {
		gets_s(arr[size - 1].NameOfCase, 256);
		throw(arr[size - 1]);
	}
	catch (...) {
		cout << "Ошибка!\n";
		cout << "Попробуйте снова!\n";
	}
	

	cout << "Введите описание дела:\n";
	gets_s(arr[size - 1].description, 256);



	cout << "Введите приоритет дела (1 - самое важное, ... 5 - самое неважное): \n";
	cin >> arr[size - 1].priority;

	cout << "Введите дату (год, месяц, день, час, минута): \n";
	cin >> arr[size - 1].date.year;
	cin >> arr[size - 1].date.month;
	cin >> arr[size - 1].date.day;
	cin >> arr[size - 1].date.hour;
	cin >> arr[size - 1].date.minutes;
}

//Поиск дел
void SearchCase(Case* arr, int size) {
	
	system("cls");
	int user_chose; //Выбор пользователя
	int alltemp; //Переменная для поисков
	char* buff = new char[256]; //Хранить строку пользователя
	cout << "Поиск дела по:\n";
	cout << "1 - Имени\n";
	cout << "2 - Приоритету\n";
	cout << "3 - Году\n";
	cout << "4 - Месяцу\n";
	cout << "5 - Дню\n";
	cout << "(Вернуться в меню - \"Esc\")\n";

	user_chose = _getch();

	switch (user_chose) {
	case 49:
		cout << "Введите искомое имя:\n";
		gets_s(buff, 256);
		SearchOnName(arr,size,buff);
		cout << "Для продолжения нажмите любую клавишу\n";
		_getch();
		break;
	case 50:
		cout << "Приоритет:\n";
		cin >> alltemp;
		SearchOnPriority(arr, size, alltemp);
		cout << "Для продолжения нажмите любую клавишу\n";
		_getch();
		break;
	case 51:
		cout << "Год:\n";
		cin >> alltemp;
		SearchOnYear(arr, size, alltemp);
		cout << "Для продолжения нажмите любую клавишу\n";
		_getch();
		break;
	case 52:
		cout << "Месяц:\n";
		cin >> alltemp;
		SearchOnMonth(arr, size, alltemp);
		cout << "Для продолжения нажмите любую клавишу\n";
		_getch();
		break;
	case 53:
		cout << "День:\n";
		cin >> alltemp;
		SearchOnDay(arr, size, alltemp);
		cout << "Для продолжения нажмите любую клавишу\n";
		_getch();
		break;
	case 27:
		break;
	default:
		cout << "ОШИБКА!";
		Sleep(1800);
		SearchCase(arr, size);
		break;
	}
}

//Удаление дела
Case* DeleteArr(Case* arr, int& size, int index) {
	size--;
	Case* newArr = new Case[size];
	for (int i = 0, k = 0; i < size + 1; i++) {
		if (index - 1 == i)
			continue;
		else {
			strcpy_s(newArr[k].NameOfCase, 256, arr[i].NameOfCase);
			strcpy_s(newArr[k].description, 256, arr[i].description);
			newArr[k].priority = arr[i].priority;
			newArr[k].date.day = arr[i].date.day;
			newArr[k].date.month = arr[i].date.month;
			newArr[k].date.year = arr[i].date.year;
			newArr[k].date.hour = arr[i].date.hour;
			newArr[k].date.minutes = arr[i].date.minutes;
			k++;
		}
	}
	delete[] arr;
	return newArr;
}



//Сортировка дел
void SortingCases(Case** pointCases, int size, Case* arr) {
	system("cls");
	for (int i = 0; i < size; i++) {
		pointCases[i] = &arr[i];
	}
	cin.ignore(256, '\n');
	cout << "Сортировка дел по: \n";
	cout << "1 - Имени\n";
	cout << "2 - Году\n";
	cout << "3 - Приоритету\n";
	cout << "(Для возврата в меню - \"Esc\")\n";
	int user_chose;
	user_chose = _getch();
	switch (user_chose) {
	case 49:
		system("cls");
		SortingOnName(arr, size, pointCases);
		cout << "Для продолжения нажмите любую клавишу\n";
		_getch();
		break;
	case 50:
		system("cls");
		SortingOnYear(arr, size, pointCases);
		cout << "Для продолжения нажмите любую клавишу\n";
		_getch();
		break;
	case 51:
		system("cls");
		SortingOnPriority(arr, size, pointCases);
		cout << "Для продолжения нажмите любую клавишу\n";
		_getch();
		break;
	case 27:
		break;
	default:
		cout << "\n\tОШИБКА!\n";
		Sleep(1000);
		SortingCases(pointCases, size, arr);
	}
}