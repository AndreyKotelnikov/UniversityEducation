
struct book
{
	char name[41];
	char author[41];
	char categ[41];
	size_t pages;
	float price;
	short year;
};

void title(void);
void filling(book& b);
void display(const book& b, int namb);