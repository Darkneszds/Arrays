#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int number = 0; cout << "Введите число: "; cin >> number; cout << hex << number;
}