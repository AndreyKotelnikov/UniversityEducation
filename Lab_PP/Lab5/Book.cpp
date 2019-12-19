#include "other.h"
#include <tchar.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "Book.h"

//enum category { fantasy, history, scientific, children, art, other };
//struct book
//{
//	char name[41]; 
//	char author[41];
//	char categ[41];
//	size_t pages;
//	float price; 
//	short year;
//};

//static char category[41];

static char* categories[30] = { "fantasy", "history", "scientific", "children", "art", "other" };

void filling(book& b)
{
	size_t Ncat = 0;
	for (size_t i = 0; i < (sizeof(categories)/sizeof(char*)); i++)
	{
		if (categories[i] == nullptr) {
			Ncat = i; 
			break;
		}
	}
	if (Ncat == 0) { Ncat = (sizeof(categories) / sizeof(char*)); }
	printf("\n������� ���������� �� ����� �� ��������� �����:");
	printf("\n�������� ����� (15 ��������):\n");
	scanf("%15s", &b.name);
	fflush(stdin);
	printf("\n����� ����� (12 ��������):\n");
	scanf("%12s", &b.author);
	fflush(stdin);
	printf("\n��������� ����� (������� ���������� ����� ������ ���������):\n");
	for (size_t i = 0; i < Ncat; i++)
	{
		printf("'%d'-%s ", i+1, categories[i]);
		if (((i + 1) % 3) == 0) { printf("\n"); }
	}
	while (true)
	{
		int n, f = 1;
		scanf("%d", &n);
		fflush(stdin);
		for (size_t i = 0; i < Ncat; i++)
		{
			if ((i + 1) == n) { strcpy(b.categ, categories[i]); f = 0; break; }
		}
		if (f == 0) { break; }
		else { printf("\n������� �������� ��������! ���������� ��� ���:\n"); }
	}
	printf("\n��� ������� (�� 0 �� 3000):\n");
	while (true)
	{
		scanf("%d", &b.year);
		fflush(stdin);
		if ((b.year >= 0) && (b.year<=3000)) { break; }
		else { printf("\n������� �������� ��������! ���������� ��� ���:\n"); }
	}
	printf("\n���� ����� � ������ (������ 123,45):\n");
	while (true)
	{
		scanf("%f", &b.price);
		fflush(stdin);
		if (b.price >= 0) { break; }
		else { printf("\n������� �������� ��������! ���������� ��� ���:\n"); }
	}
	printf("\n���������� �������:\n");
	while (true)
	{
		scanf("%6d", &b.pages);
		fflush(stdin);
		if (b.year >= 0) { break; }
		else { printf("\n������� �������� ��������! ���������� ��� ���:\n"); }
	}
}

void title(void)
{
	printf("\n\n");
	printf("-------------------------------------------------------------------------------");
	printf("\n| %2s | %15s | %12s | %10s | %4s | %7s | %7s |", "�","������������", "�����", "���������", "���", "����", "���-��");
	printf("\n-------------------------------------------------------------------------------");
}

void display(const book& b, int namb)
{
	printf("\n| %2d | %15s | %12s | %10s | %4d | %7.2f | %7d |", namb, b.name, b.author, b.categ, b.year, b.price, b.pages);
}