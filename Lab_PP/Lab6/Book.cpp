
#include <tchar.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "Book.h"
#include "Sort.h"


//struct cartoteca
//{
//	book *pb;
//	int Capacity, N;
//}; 

//struct book
//{
//	char name[41];
//char author[41];
//char categ[41];
//int pages;
//int year;
//double price;
//};

static char* categories[30] = { "fantasy", "history", "scientific", "children", "art", "other" };
static char* menuitem[] = { "�����", "���������� ���������", "������ ����� �����", "������� ������������(��) �����", "�������� � ����", "������� �� �����", "���������� �� ����" };
static char* sortFields[] = { "���", "�����", "���������", "���", "���-�� �������", "����" };
static int offsetbook[6];

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
			if ((i + 1) == n) { strcpy_s(b.categ, categories[i]); f = 0; break; }
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
	printf("\n���������� �������:\n");
	while (true)
	{
		scanf("%6d", &b.pages);
		fflush(stdin);
		if (b.year >= 0) { break; }
		else { printf("\n������� �������� ��������! ���������� ��� ���:\n"); }
	}
	printf("\n���� ����� � ������ (������ 123,45):\n");
	while (true)
	{
		scanf("%lf", &b.price);
		fflush(stdin);
		if (b.price >= 0) { break; }
		else { printf("\n������� �������� ��������! ���������� ��� ���:\n"); }
	}
	return;
}

void title(void)
{
	printf("\n\n");
	printf("-------------------------------------------------------------------------------");
	printf("\n| %2s | %15s | %12s | %10s | %4s | %7s | %7s |", "�", "������������", "�����", "���������", "���", "���-��", "����");
	printf("\n-------------------------------------------------------------------------------");
	return;
}

void display(book& b, int namb)
{
	printf("\n| %2d | %15s | %12s | %10s | %4d | %7d | %7.2lf |", namb, b.name, b.author, b.categ, b.year, b.pages, b.price);
	return;
}

int menu(void)
{
	size_t NMenuItems = sizeof(menuitem) / sizeof(char*);
	printf("\n\n������� ����� ��������:\n");
	for (size_t i = 0; i < NMenuItems; i++)
	{
		printf("'%d'-%s ", i, menuitem[i]);
		if (((i + 1) % 3) == 0) { printf("\n"); }
	}
	int res = 0;
	printf("\n");
	while (true)
	{
		int n, f = 1;
		scanf("%d", &n);
		fflush(stdin);
		for (size_t i = 0; i < NMenuItems; i++)
		{
			if (i == n) { res = i; f = 0; break; }
		}
		if (f == 0) { break; }
		else { printf("\n������� �������� ��������! ���������� ��� ���:\n"); }
	}
	return res;
}

void displayCart(cartoteca& cart)
{
	printf("\n\n������� ���������� ���������:");
	title();
	for (int i = 0; i < cart.N; i++)
	{
		display(*cart.pb[i], i + 1);
	}
	return;
}

void fillingCart(cartoteca& cart)
{
	printf("\n\n���������� ����� ����� � ���������:\n");
	if (cart.Capacity > cart.N)
	{
		cart.pb[cart.N] = new book;
		filling(*cart.pb[cart.N]); 
		cart.N++;
	}
	else
	{
		if (cart.Capacity == cart.N)
		{
			cart.Capacity++;
			book** pbtmp = new book*[cart.Capacity];
			for (size_t i = 0; i < cart.Capacity - 1; i++)
			{
				pbtmp[i] = cart.pb[i];
			}
			delete[] cart.pb;
			cart.pb = pbtmp;
			cart.pb[cart.N] = new book;
			filling(*cart.pb[cart.N]);
			cart.N++;
		}
		else{ printf("\n\nfillingCart: ������ � ��������� ������� ���������� �� �����!\n\n"); }
	} 
	return;
}
//void fillingCart(cartoteca& cart)
//{
//	printf("\n\n���������� ����� ����� � ���������:\n");
//	
//	
//		if (cart.Capacity == cart.N)
//		{ //������� Resize;
//			cart.Capacity++;
//			book** pbtmp = new book*[cart.Capacity];
//			for (size_t i = 0; i < cart.Capacity - 1; i++)
//			{
//				pbtmp[i] = cart.pb[i];
//			}
//			delete[] cart.pb;
//			cart.pb = pbtmp;
//			
//		}
//		cart.pb[cart.N] = new book;
//		filling(*cart.pb[cart.N]);
//		cart.N++;
//	//	else{ printf("\n\nfillingCart: ������ � ��������� ������� ���������� �� �����!\n\n"); }
//	
//	return;
//}


void deleteCart(cartoteca& cart)
{
	if (cart.N == 0) { printf("\n\n������� ������! �� �� ������ ������� �����!\n"); return; }
//	printf("\n\n������� ������ ���� ��� �������� ����� ������ \n��� '0' ��� �������� � ����:\n");
	int f = 0;
	printf("\n\n������� ����� �����\n��� '0' ��� �������� � ����:\n");
	//while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0) { return; }
		if ((n >= 1) && (n <= cart.N))
		{
			if (cart.pb[n - 1] == nullptr) { printf("\n\n�� ��� ������� ����� � ������� %d! �������� ������ ����� �����:\n", n); }
			delete cart.pb[n - 1];
			cart.pb[n - 1] = nullptr;
			f++;
		}
		else { printf("\n������� �������� ��������! ���������� ��� ���:\n"); fflush(stdin); }
	}
	fflush(stdin);

	//�������� �� �������������� �����
	SortStruct(reinterpret_cast<char*>(cart.pb), cart.N, sizeof(cart.pb[0]), SwapPointBook, CmpNullptrUp);
	cart.N = cart.N - f;
	switch (f)
	{
	case 0:
		printf("\n\n�� �� ������� �� ����� �����, � �������� �� �������� ���-�� ���� ����� %d\n", cart.N); break;
	case 1 :
		printf("\n\n�� ������� %d �����, ������ � �������� ���-�� ���� ����� %d\n", f, cart.N); break;
	case 2:
	case 3:
	case 4:
		printf("\n\n�� ������� %d �����, ������ � �������� ���-�� ���� ����� %d\n", f, cart.N); break;
	default:
		printf("\n\n�� ������� %d ����, ������ � �������� ���-�� ���� ����� %d\n", f, cart.N); break;
	}
	return;
}

void avtofilling(cartoteca& Cart)
{
	Cart.pb = new book*[6];
	Cart.Capacity = 6;
	Cart.N = 0;
	for (size_t i = 0; i < 6; i++)
	{
		Cart.pb[i] = new book;
		Cart.N++;
	}
	
	//����������� ���������� 6 ����
	strcpy_s(Cart.pb[0]->name, "Adrenalin");
	strcpy_s(Cart.pb[0]->author, "Sergeev");
	strcpy_s(Cart.pb[0]->categ, "scientific");
	Cart.pb[0]->year = 2015;
	Cart.pb[0]->price = 4000.00l;
	Cart.pb[0]->pages = 700;

	strcpy_s(Cart.pb[1]->name, "Vershina");
	strcpy_s(Cart.pb[1]->author, "Orlov");
	strcpy_s(Cart.pb[1]->categ, "history");
	Cart.pb[1]->year = 2005;
	Cart.pb[1]->price = 400.50l;
	Cart.pb[1]->pages = 1700;

	strcpy_s(Cart.pb[2]->name, "Yabloko");
	strcpy_s(Cart.pb[2]->author, "Zuev");
	strcpy_s(Cart.pb[2]->categ, "children");
	Cart.pb[2]->year = 2000;
	Cart.pb[2]->price = 500.70l;
	Cart.pb[2]->pages = 300;

	strcpy_s(Cart.pb[3]->name, "Korolevstvo");
	strcpy_s(Cart.pb[3]->author, "Fokin");
	strcpy_s(Cart.pb[3]->categ, "fantasy");
	Cart.pb[3]->year = 1000;
	Cart.pb[3]->price = 5500.70l;
	Cart.pb[3]->pages = 1300;

	strcpy_s(Cart.pb[4]->name, "Igra");
	strcpy_s(Cart.pb[4]->author, "Gogolev");
	strcpy_s(Cart.pb[4]->categ, "art");
	Cart.pb[4]->year = 2011;
	Cart.pb[4]->price = 470.75l;
	Cart.pb[4]->pages = 450;

	strcpy_s(Cart.pb[5]->name, "Amargedon");
	strcpy_s(Cart.pb[5]->author, "Serafim");
	strcpy_s(Cart.pb[5]->categ, "other");
	Cart.pb[5]->year = 2015;
	Cart.pb[5]->price = 3470.75l;
	Cart.pb[5]->pages = 750;

	return;
}

void offsetfilling(cartoteca & Cart)
{
	offsetbook[0] = 0;
	offsetbook[1] = reinterpret_cast<char*>(&Cart.pb[0]->author) - reinterpret_cast<char*>(&Cart.pb[0]->name);
	offsetbook[2] = reinterpret_cast<char*>(&Cart.pb[0]->categ) - reinterpret_cast<char*>(&Cart.pb[0]->name);
	offsetbook[3] = reinterpret_cast<char*>(&Cart.pb[0]->year) - reinterpret_cast<char*>(&Cart.pb[0]->name);
	offsetbook[4] = reinterpret_cast<char*>(&Cart.pb[0]->pages) - reinterpret_cast<char*>(&Cart.pb[0]->name);
	offsetbook[5] = reinterpret_cast<char*>(&Cart.pb[0]->price) - reinterpret_cast<char*>(&Cart.pb[0]->name);
}

void filerecord(cartoteca& cart)
{
	FILE* f = fopen("cartoteca.txt", "w");
	if (f)
	{
		displayCartInFile(cart, f);
	}
	else
	{
		printf("\n\n�� ������� ������� ���� \"cartoteca.txt\"! \n��������� ��� ������� � ���������� �������!\n\n"); return;
	}
	fclose(f);
	printf("\n\n������� ���������� ��������� �������� � ���� \"cartoteca.txt\"\n\n");
	return;
}

void titleInFile(FILE* f)
{
	fprintf(f, "\n\n");
	fprintf(f, "-------------------------------------------------------------------------------");
	fprintf(f, "\n| %2s | %15s | %12s | %10s | %4s | %7s | %7s |", "�", "������������", "�����", "���������", "���", "���-��", "����");
	fprintf(f, "\n-------------------------------------------------------------------------------");
	return;
}

void displayCartInFile( const cartoteca& cart, FILE* f)
{
	fprintf(f, "\n\n������� ���������� ���������:");
	titleInFile(f);
	for (int i = 0; i < cart.N; i++)
	{
		displayInFile(*cart.pb[i], i + 1, f);
	}
	return;
}

void displayInFile(book& b, int namb, FILE* f)
{
	fprintf(f, "\n| %2d | %15s | %12s | %10s | %4d | %7d | %7.2lf |", namb, b.name, b.author, b.categ, b.year, b.pages, b.price);
	return;
}

void fileread(cartoteca& cart)
{
	FILE* f = fopen("cartoteca.txt", "r");
	if (f)
	{
		int n = 0;
		while (n < cart.N)
		{
			delete cart.pb[n];
			cart.pb[n] = nullptr;
			n++;
		}
		cart.N = 0;
		displayCartOutFile(cart, f);
	}
	else
	{
		printf("\n\n�� ������� ������� ���� \"cartoteca.txt\"! \n��������� ��� ������� � ���������� �������!\n\n"); return;
	}
	fclose(f);
	printf("\n\nC��������� �� ����� \"cartoteca.txt\" ������� ������������� � ���������\n");
	printf("���������� ����������� ���� � ��������� �����: %d\n\n", cart.N);
	return;
}

void displayCartOutFile(cartoteca& cart, FILE* f)
{
	int flug = 1;
	while (flug != -1)
	{
		if (cart.Capacity > cart.N)
		{
			cart.pb[cart.N] = new book;
			flug = displayOutFile(*cart.pb[cart.N], f); cart.N++;
		}
		else
		{
			if (cart.Capacity = cart.N)
			{
				cart.Capacity++;
				book** pbtmp = new book*[cart.Capacity];
				for (size_t i = 0; i < cart.Capacity - 1; i++)
				{
					pbtmp[i] = cart.pb[i];
				}
				delete[] cart.pb;
				cart.pb = pbtmp;
				cart.pb[cart.N] = new book;
				flug = displayOutFile(*cart.pb[cart.N], f);
				cart.N++;
			}
			else{ printf("\n\ndisplayCartOutFile: ������ � ��������� ������� ���������� �� �����!\n\n"); }
		}
	}
	return;
}

int displayOutFile(book& b, FILE* f)
{
	static int namb = -1;
	int n;
	char str[200] = {0};
	while (true)
	{
		if (namb == -1) { fscanf(f, "%s", str); }
		if ((str[0] == '1') && (namb == -1)) { namb = 0; }
		if (namb >= 0)
			{
			fscanf(f, " | %15s | %12s | %10s | %4d | %7d | %lf |", &b.name, &b.author, &b.categ, &b.year, &b.pages, &b.price);
			namb++;
			fscanf(f, "%s", str);
			fscanf(f, "%s", str);
			if (feof(f)) { return -1; }
			return namb;
			}	
	}
	return -1;
}

void sortCart(cartoteca& cart)
{
	printf("\n���� ��� ����������(������� ���������� ����� ������� ����):\n");
	for (size_t i = 0; i < sizeof(sortFields)/sizeof(char*); i++)
	{
		printf("'%d'-%s ", i + 1, sortFields[i]);
		if (((i + 1) % 3) == 0) { printf("\n"); }
	}
	int n;
	while (true)
	{
		int f = 1;
		scanf("%d", &n);
		fflush(stdin);
		for (size_t i = 0; i < sizeof(sortFields) / sizeof(char*); i++)
		{
			if ((i + 1) == n) { f = 0; break; }
		}
		if (f == 0) { break; }
		else { printf("\n������� �������� ��������! ���������� ��� ���:\n"); }
	}
	if (n < 4)
	{
		SortStruct(reinterpret_cast<char*>(cart.pb), cart.N, sizeof(cart.pb[0]), SwapPointBook, CmpStrBook, offsetbook[n - 1]);
	}
	else
	{
		if ((n >= 4) && (n < 6))
		{
			SortStruct(reinterpret_cast<char*>(cart.pb), cart.N, sizeof(cart.pb[0]), SwapPointBook, CmpIntBook, offsetbook[n - 1]);
		}
		else
		{
			if (n == 6)
			{
				SortStruct(reinterpret_cast<char*>(cart.pb), cart.N, sizeof(cart.pb[0]), SwapPointBook, CmpDoubleBook, offsetbook[n - 1]);
			}
		}
	}
	printf("\n��������� ���� ������������� �� ���� \"%s\"\n", sortFields[n - 1]);
	return;
}

