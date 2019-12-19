
//Прототипы используемых в данном задании функций:
double Sum(double a, double b);
double Sub(double a, double b);
double Mul(double a, double b);
double Div(double a, double b);
double Calc(double a, double b, double(*func)(double, double));
void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) );
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);
void SwapDouble(void* p1, void* p2);
int CmpDouble(void* p1, void* p2);
void SwapStr(void* p1, void* p2);
int CmpStr(void* p1, void* p2);
const char* GetString1();
const char* GetString2();
const char* GetString3();
const char* GetString4();
const char* GetString5();
const char* String_n(const char* (*StrF)(void));

