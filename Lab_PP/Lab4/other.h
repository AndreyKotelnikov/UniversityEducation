//Прототипы используемых в данном задании функций:
extern int *ref;
int IncByValue(int srs);
void IncByPointer(int* srs);
void IncByReference(int& srs);
void Swap(int* srs1, int* srs2);
void Swap(int& srs1, int& srs2);
int Min(int(*arr)[4], size_t NamberOfStrings);
int Min(int **arr, const size_t NamberOfStrings, const size_t NamberOfColums);
int MyStrCmp(char* ar1, char* ar2);
int DayOfYear(int d, int m, int Year, int(*arr)[12]);
void DayOfMonth(int DayOfYear, int Year, int(*arr)[12], int& d, int& m);
void Addcmp(int*& p, int& n);
void print(const int* p, const int& n);
size_t sumrec(size_t n);
void VarArgs(int first, ...);
void VarArgsVa(int n, ...);
int* MyMin(const int *p, const int n);
