
#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <limits>


//Модуль для функций поиска
#include "SearchOpt.h"

using namespace std;

// Программа будет функционировать и хранить данные в массиве, и вся работа это лишь
// изменение массивов.
// Каждый массив на каждую единицу дела(имя, описание, дата, приоритет).
// Первое дело - 0-ой индекс в каждом массиве, второе - 1-ый индекс и т.д.

void FillArrs(char* name[], char* descriprion[], int* priority,int * year, int* day,  int* month, int* hour, int* minutes, int size); //Добавление
void MassRedact(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size, int user); //Редактирование
void ShowCase(char * name[], char * description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size, int mode); //Отображение
void SearchCase(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size); // Поиск дела
void SortingCases(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size);
int main(){

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 0;
	//Создаём двумерный массивы char названия
	char** name = new char*[size];
	for (int i = 0; i < size; i++) {
		name[i] = new char[256];                      //Двумерный массивы char, а не string,
	}                                                 //так как последний абсолютная скверна и с ней я не буду работать
	//Создаём двумерный массивы char описания  
	char** description = new char*[size];
	for (int i = 0; i < size; i++) {
		description[i] = new char[256];
	}
	//Приоритет
	int* priority = new int[size];
	//Дата
	int* day = new int[size];
	int* month = new int[size];
	int* year = new int[size];
	int* hour = new int[size];
	int* minutes = new int[size];

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
		cout << size;
		cin >> user_chose;

		//Выбор опции

		switch (user_chose) {
		case 1:

			size++;
			FillArrs(name, description,priority, year, day, month, hour, minutes, size);
			break;

		case 2:

			break;

		case 3:

			system("cls");
			cout << "Какое дело отредактировать?\n";
			cout << "\tНомера дел\n";
			for (int i = 0; i < size; i++) {
				cout << "-  " <<  i + 1 << endl;
			}
			cin >> user_chose;
			MassRedact(name, description,priority, year, day, month, hour, minutes, size, user_chose);
			break;

		case 4:
			SearchCase(name, description, priority,  year,  day, month, hour, minutes, size);
			break;
		case 5:

			ShowCase(name, description,priority, year, day, month, hour, minutes, size,1);
			cout << "Вернуться к списку дел (1 - да)?\n";
			cin >> user_chose;
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
void ShowCase(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size, int mode) {
	
	system("cls");	
	// mode 1 отвечает за отображение дел по порядку
	if (mode == 1) {
		for (int i = 0; i < size; i++) {
			cout << "Номер дела - " << i + 1 << endl << endl;
			cout << "Приоритет - " << priority[i] << endl;
			cout << name[i] << "\n";
			cout << description[i] << "\n";
			cout << day[i] << "." << month[i] << "." << year[i] << endl;
			cout << hour[i] << ":" << minutes[i];
			cout << "\n--------------------\n\n";
		}
	}
	                        //ВРЕМЕННО НЕ РАБОТАЕТ\\

	// mode 2 или же else, в ответственности за отображение дела поштучно (функция поиска)
	// индекс size, так как он будет отвечать за индекс дела (чтобы не создавать новых переменных)
	else {
		cout << "Номер дела - " << size + 1 << endl << endl;
		cout << "Приоритет - " << priority[size] << endl;
		cout << name[size] << "\n";
		cout << description[size] << "\n";
		cout << day[size] << "." << month[size] << "." << year[size] << endl;
		cout << hour[size] << ":" << minutes[size];
		cout << "\n--------------------\n\n";
	}
}
// Возможность пользователя редактировать дело, т.е. массивы
void MassRedact(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size, int user) {
	system("cls");
	char* buff = new char[256]; //Хранить строку пользователя

	cout << "Что необходимо отредактировать?\n";
	cout << "Имя - 1\n" << "Приоритет - 2\n" << "Описание - 3\n" <<
		"Дату - 4\n" << "Всё дело - 5\n";

	int user_chose;
	cin >> user_chose;

	switch (user_chose) {
	case 1:

		cout << "Введите новое имя:\n";		
		gets_s(buff, 256);
		name[user - 1] = buff;
		delete[] buff;
		break;

	case 2:

		cout << "Введите новый приоритет:\n";
		cin >> priority[user - 1];
		break;

	case 3:

		cout << "Введите новое описание:\n";
		gets_s(buff, 256);
		description[user - 1] = buff;
		delete[] buff;
		break;		

	case 4:

		cout << "Введите новую дату (день, месяц, год, час, минута):\n";
		cin >> day[user - 1];
		cin >> month[user - 1];
		cin >> year[user - 1];
		cin >> hour[user - 1];
		cin >> minutes[user - 1];
		break;

	case 5:

		FillArrs(name, description, priority, year, day, month, hour, minutes, user);
		break;
	}
}
//Добавление дела
void FillArrs(char* name[], char* description[], int * priority, int * year, int * day, int *month, int * hour, int * minutes, int size) {
	system("cls");
	char* buff = new char[256]{"If you see this, you cheated"}; //Хранить строку пользователя
	cout << "Введите имя дела:\n";
	cin.ignore(256, '\n');    //Очищаем поток ввода, чтобы паршивая строка ввода char ниже работала
	gets_s(buff,256);
	name[size - 1] = buff;

	cout << "Введите описание дела:\n";
	gets_s(buff, 256);
	description[size - 1] = buff;
	cout << "Введите приоритет дела (1 - самое важное, ... 5 - самое неважное): \n";
	cin >> priority[size - 1];

	cout << "Введите дату (день, месяц, год, час, минута): \n";
	cin >> day[size - 1];
	cin >> month[size - 1];
	cin >> year[size - 1];
	cin >> hour[size - 1];
	cin >> minutes[size - 1];
	
	delete[] buff;
}

//Поиск дел
void SearchCase(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size) {
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

	cin >> user_chose;

	switch (user_chose) {
	case 1:
		gets_s(buff, 256);
		SearchOnName(name, description, priority, year,  day, month,  hour, minutes, size, buff);
		delete[] buff;
		break;
	case 2:
		cout << "Приоритет:\n";
		cin >> alltemp;
		SearchOnPriority(name, description, priority, year, day, month, hour, minutes, size, alltemp);
		cout << "Продолжить?(1 - да)\n";
		cin >> user_chose;
		break;
	case 3:
		cout << "Год:\n";
		cin >> alltemp;
		SearchOnYear(name, description, priority, year, day, month, hour, minutes, size, alltemp);
		cout << "Продолжить?(1 - да)\n";
		cin >> user_chose;
		break;
	case 4:
		cout << "Месяц:\n";
		cin >> alltemp;
		SearchOnMonth(name, description, priority, year, day, month, hour, minutes, size, alltemp);
		cout << "Продолжить?(1 - да)\n";
		cin >> user_chose;
		break;
	case 5:
		cout << "День:\n";
		cin >> alltemp;
		SearchOnDay(name, description, priority, year, day, month, hour, minutes, size, alltemp);
		cout << "Продолжить?(1 - да)\n";
		cin >> user_chose;
		break;
	}
}

void SortingCases(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size) {

}