#include "other.h"
//#include <cstring>
#include <string.h>

///////////////////////////////////////////////////
double Sum(double a, double b) { return a + b; }
double Sub(double a, double b) { return a - b; }
double Mul(double a, double b) { return a * b; }
double Div(double a, double b) { return a / b; }

double Calc(double a, double b, double(*func)(double, double))
{
	return func(a, b);
}

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
	int i;
	for(i=1; i<nNumber; i++)
		for(int j=nNumber-1; j>=i; j--)
		{
			char* pCurrent = pcFirst+j*size;
			char* pPrevious = pcFirst+(j-1)*size;
			if((*Compare)( pPrevious, pCurrent ) > 0)//требуется
												//переставить
				(*Swap)( pPrevious, pCurrent );
		}
}

void SwapInt(void* p1, void* p2)
{
	typedef int T;
	int tmp = *static_cast<T*>(p1);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*reinterpret_cast<T*>(p1) = *reinterpret_cast<T*>(p2);
	*reinterpret_cast<T*>(p2) = tmp;
}

int CmpInt(void* p1, void* p2)
{
	typedef int T;
	T nResult = *reinterpret_cast<T*>(p1)-*reinterpret_cast<T*>(p2);
	return nResult;
}

void SwapDouble(void* p1, void* p2)
{
	typedef double T;
	T tmp = *reinterpret_cast<T*>(p1);
	*reinterpret_cast<T*>(p1) = *reinterpret_cast<T*>(p2);
	*reinterpret_cast<T*>(p2) = tmp;
}

 int CmpDouble(void* p1, void* p2)
{
	typedef double T;
	int nResult = 0;
	if ((*reinterpret_cast<T*>(p1)-*reinterpret_cast<T*>(p2)) > 0) { return 1; }
	else if ((*reinterpret_cast<T*>(p1)-*reinterpret_cast<T*>(p2)) < 0) { return -1; }
	return nResult;
}
 
 void SwapStr(void* p1, void* p2)
 {
	 typedef char* T;
	 T tmp = *reinterpret_cast<T*>(p1);
	 *reinterpret_cast<T*>(p1) = *reinterpret_cast<T*>(p2);
	 *reinterpret_cast<T*>(p2) = tmp;
 }

 int CmpStr(void* p1, void* p2)
 {
	 typedef char* T;
	 char* ar1 = *reinterpret_cast<T*>(p1);
	 char* ar2 = *reinterpret_cast<T*>(p2);
	 int nResult = 0, i = 0;
	// strcmp(ar1, ar2);


	 while ((ar1[i] != 0) && (ar2[i] != 0))
	 {
		 if (ar1[i] > ar2[i]) { nResult = 1; return nResult; }
		 else	{
			 if (ar1[i] < ar2[i]) { nResult = -1; return nResult; }
		 }
		 i++;
	 }
	 if ((ar1[i] == 0) && (ar2[i] != 0)) { nResult = -1; return nResult; }
	 else	{
		 if ((ar1[i] != 0) && (ar2[i] == 0)) { nResult = 1; return nResult; }
	 }
	 return nResult;
 }

 const char* GetString1(){ return "Func1"; }
 const char* GetString2(){ return "Func2"; }
 const char* GetString3(){ return "Func3"; }
 const char* GetString4(){ return "Func4"; }
 const char* GetString5(){ return "Func5"; }
 const char* String_n(const char* (*StrF)(void)) { return StrF(); };