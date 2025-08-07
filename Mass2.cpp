#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int *append_to_dynamic_array(int *Arr, int &logical_size, int &actual_size, int A) {
	int *new_arr = new int[actual_size];
	if (logical_size < actual_size) {
		logical_size += 1;
		Arr[logical_size - 1] = A;
		for (int i = 0; i < actual_size; i++) {
			new_arr[i] = Arr[i];
		}
		return new_arr;
	}
	else {
		actual_size *= 2;
		logical_size += 1;
		Arr[logical_size - 1] = A;
		for (int i = 0; i < actual_size; i++) {
			new_arr[i] = Arr[i];
		}
		return new_arr;
	}
	delete[]new_arr;
} 

void print_dynamic_array(int* ar, int &logical_size, int &actual_size) {
	
	for (int i = 0; i < actual_size; i++) {
		if (i < logical_size) {
			std::cout << ar[i] << "  ";
		}
		else  std::cout << " _ ";
	}
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "russian");
	int logical_size;
	int actual_size;
	int a;
	std::cout << "Введите фактический размер массива: ";
	std::cin >> actual_size;
	std::cout << std::endl;
	std::cout << "Введите логический размер массива: ";
	std::cin >> logical_size;
	std::cout << std::endl;
	int *arr = new int[logical_size];
	int** arrr = &arr;
	if (actual_size >= logical_size && actual_size != 0 && logical_size != 0) {
		for (int i = 0; i < logical_size; i++) {
			std::cout << "Введите arr[" << i << "]: ";
			std::cin >> arr[i];
			std::cout << std::endl;
		}
		std::cout << "Динамический массив: ";
		print_dynamic_array(arr, logical_size, actual_size);
			std::cout << std::endl;
		do {
			std::cout << "Введите элемент для добавления: ";
			std::cin >> a;
			std::cout << std::endl;
			if (a != 0) {
				*arrr = append_to_dynamic_array(arr, logical_size, actual_size, a);
				std::cout << "Динамический массив: ";
				print_dynamic_array(*arrr, logical_size, actual_size);
				std::cout << std::endl;
			}
       } while (a != 0);
	   std::cout << "Спасибо! Ваш массив: ";
	   print_dynamic_array(*arrr, logical_size, actual_size);
	   std::cout << std::endl;
	}
	else if (actual_size < logical_size && logical_size != 0) {
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
	}
	delete[]*arrr;
	return 0;
}


