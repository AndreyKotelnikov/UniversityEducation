#include "Sort.h"
#include "Book.h"
//Функции сортировки

void SortStruct(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*, int), int offset)
{
	int i;
	for (i = 1; i<nNumber; i++)
	for (int j = nNumber - 1; j >= i; j--)
	{
		char* pCurrent = pcFirst + j*size;
		char* pPrevious = pcFirst + (j - 1)*size;
		if ((*Compare)(pPrevious, pCurrent, offset) > 0)//требуется
			//переставить
			(*Swap)(pPrevious, pCurrent);
	}
	return;
}

void SwapPointBook(void* p1, void* p2)
{
	typedef book* T;
	T tmp = *reinterpret_cast<T*>(p1);
	*reinterpret_cast<T*>(p1) = *reinterpret_cast<T*>(p2);
	*reinterpret_cast<T*>(p2) = tmp;
}

int CmpNullptrUp(void* p1, void* p2, int offset)
{
	typedef book* T;
	int nResult = 0;
	if ((*reinterpret_cast<T*>(p1) == nullptr) && (*reinterpret_cast<T*>(p2) != nullptr)) { return 1; }
	return nResult;
}

int CmpStrBook(void* p1, void* p2, int offset)
{
	typedef book** T;
	char* ar1 = reinterpret_cast<char*>(*reinterpret_cast<T>(p1)) + offset;
	char* ar2 = reinterpret_cast<char*>(*reinterpret_cast<T>(p2)) + offset;
	int nResult = 0, i = 0;
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

int CmpIntBook(void* p1, void* p2, int offset)
{
	typedef book** T;
	
	;
	int nResult = *reinterpret_cast<int*>(reinterpret_cast<char*>(*reinterpret_cast<T>(p1)) + offset) - 
		*reinterpret_cast<int*>(reinterpret_cast<char*>(*reinterpret_cast<T>(p2)) + offset);
	return nResult;
}

int CmpDoubleBook(void* p1, void* p2, int offset)
{
	typedef book** T;
	int nResult = 0;
	if ((*reinterpret_cast<double*>(reinterpret_cast<char*>(*reinterpret_cast<T>(p1)) + offset) - 
		*reinterpret_cast<double*>(reinterpret_cast<char*>(*reinterpret_cast<T>(p2)) + offset)) > 0) { return 1; }
	else if ((*reinterpret_cast<double*>(reinterpret_cast<char*>(*reinterpret_cast<T>(p1)) + offset) -
		*reinterpret_cast<double*>(reinterpret_cast<char*>(*reinterpret_cast<T>(p2)) + offset)) < 0) { return -1; }
	return nResult;
}