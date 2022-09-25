#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;



void SortingOnName(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size) {

}

void SortingOnYear(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size) {
	int* SortYear = new int[size]; //ћассив, который мы будем сортировать
	SortYear = year;
	int temp;
	    for (int i = 0; i < size; i++) {
	        for (int j = size - 1; j > i; j--) {
	            if (SortYear[j - 1] > SortYear[j]) {
	                temp = SortYear[j - 1];
					SortYear[j - 1] = SortYear[j];
					SortYear[j] = temp;
	            }
	        }
	    }

}

void SortingOnPriority(char* name[], char* description[], int* priority, int* year, int* day, int* month, int* hour, int* minutes, int size) {

}