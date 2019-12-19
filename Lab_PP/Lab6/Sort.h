
//Объявление функций сортировки
void SortStruct(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*, int), int offset = 0);
void SwapPointBook(void* p1, void* p2);
int CmpNullptrUp(void* p1, void* p2, int offset = 0);
int CmpStrBook(void* p1, void* p2, int offset);
int CmpIntBook(void* p1, void* p2, int offset);
int CmpDoubleBook(void* p1, void* p2, int offset);
