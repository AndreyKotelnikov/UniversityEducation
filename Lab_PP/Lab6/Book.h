#include <cstdio>
struct cartoteca
{
	struct	book **pb;
	int Capacity, N;
};

struct book
{
	char name[41];
	char author[41];
	char categ[41];
	int year;
	int pages;
	double price;
};

int menu(void);
void avtofilling(cartoteca& Cart);
void offsetfilling(cartoteca & Cart);
void title(void);
void filling(book& b);
void display(book& b, int namb);
void displayCart(cartoteca& cart);
void fillingCart(cartoteca& cart);
void deleteCart(cartoteca& cart);
void titleInFile(FILE* f);
void displayCartInFile(const cartoteca& cart, FILE* f);
void displayInFile(book& b, int namb, FILE* f);
void filerecord(cartoteca& cart);
void fileread(cartoteca& cart);
void displayCartOutFile(cartoteca& cart, FILE* f);
int displayOutFile(book& b, FILE* f);
void sortCart(cartoteca& cart);
