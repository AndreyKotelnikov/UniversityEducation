#include "other.h"
#include <iostream>
#include <tchar.h>
#include <cstdio>
#include <cstdarg>

int x = 0;
int *ref = &x;
///////////////////////////////////////////////////
int IncByValue(int x) { x++; return x; }
void IncByPointer(int* x) { (*x)++; return; }
void IncByReference(int& x) { x++; return; }
void Swap(int* x, int* y) { int tmp; tmp = *x; *x = *y; *y = tmp; }
void Swap(int& x, int& y) { int tmp; tmp = x; x = y; y = tmp; }
int Min(int(*arr)[4], const size_t n)
{
	int min = **arr;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (min >(arr[i][j]))	{ min = arr[i][j]; }
		}
	}
	return min;
}
int Min(int **arr, const size_t n, const size_t m)
{
	int min = **arr;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (min >(arr[i][j]))	{ min = arr[i][j]; }
		}
	}
	return min;
}
int MyStrCmp(char* ar1, char* ar2)
{
	int s = 0, i = 0;
	while ((ar1[i] != 0) || (ar2[i] != 0))
	{
		if (ar1[i] > ar2[i]) { s = 1; return s; }
		else	{
			if (ar1[i] < ar2[i]) { s = -1; return s; }
		}
		i++;
	}
	//if ((ar1[i] == 0) && (ar2[i] != 0)) { s = -1; return s; }
	//else	{
	//	if ((ar1[i] != 0) && (ar2[i] == 0)) { s = 1; return s; }
	//}
	return s;
}
int DayOfYear(int d, int m, int Year, int(*arr)[12])
{
	int k = 0, s = 0;
	bool isLeapYear = 0;
	isLeapYear = (Year % 400 == 0) || (!(Year % 100 == 0) && (Year % 4 == 0));
	if (isLeapYear == 0) { k = 1; }
	for (size_t i = 0; i < m - 1; i++)
	{
		s += arr[k][i];
	}
	return (s + d);
}
void DayOfMonth(int n, int Year, int(*arr)[12], int& d, int& m)
{
	int k = 0, s = 0, i = 0;
	bool isLeapYear = 0;
	isLeapYear = (Year % 400 == 0) || (!(Year % 100 == 0) && (Year % 4 == 0));
	if (isLeapYear == 0) { k = 1; }
	while (n > s)
	{
		s += arr[k][i];
		i++;
	}
	m = i;
	d = n + arr[k][i - 1] - s;
	return;
}
void Addcmp(int*& p, int& n)
{
	int s = 0;
	printf("Введите число:\n");
	scanf("%d", &s);
	for (size_t i = 0; i < n; i++)
	{
		if (p[i] == s)
		{
			printf("\nТакое значение уже есть в элементе массива с индексом %d !\n\n", i);
			return;
		}
	}
	n++;
	int *tmp = new int[n];
//	memcpy(tmp, p, sizeof(int)*(n - 1));
	for (size_t i = 0; i < n-1; i++)
	{
		tmp[i] = p[i];
	}
	delete[] p;
	p = tmp;
	p[n - 1] = s;
	
	return;
}
void print(const int* p, const int& n)
{
	printf("печатаем итоговый массив размерностью %d:\n", n);
	for (size_t i = 0; i < n; i++)
	{
		printf("%d  ", p[i]);
	}
}
size_t sumrec(size_t n)
{
	if (n == 0) { return 0; }
	//size_t s = sumrec(n - 1);
	return (n + sumrec(n - 1));
}
void VarArgs(int n, ...)
{
	setlocale(LC_ALL, "Russian");
	int *p = &n;
	int s = 0;
	while (*p != 0){ s++; p++; }
	p = &n;
	printf("\nПечатаем %d чисел без последнего нуля:\n", s);
	while (*p != 0){ printf("%d  ", *p); p++; }
	return;
}
void VarArgsVa(int n, ...)
{
	setlocale(LC_ALL, "Russian");
	int i = n, s = 0;
	va_list p;
	va_start(p, n);
	while (i != 0){ s++; i = va_arg(p, int); }
	va_start(p, n);
	i = 1;
	printf("\nПечатаем %d чисел без последнего нуля:\n", s);
	while (i != 0){ printf("%d  ", *p); i = va_arg(p, int); }
	return;
}
int* MyMin(const int *p, const int n)
{
	int min = *p;
	const int* pm = p;
	for (int i = 0; i < n; i++)
	{
		if (min >(p[i]))	{ min = p[i]; pm = (p + i); }
	}
	return const_cast<int*>(pm);
}


//Подсказка-заготовка для задания 5а
//Без использования макросов
/*
void VarArgs(int arg1,...)
{
	int number = 0;	//счетчик элементов
	//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов




	//Печать числа элементов

}
*/


