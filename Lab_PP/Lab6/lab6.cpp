/*************************************************************
	������������ ������� �5. ���������
//������������ ������ ��������
//�����
//����������
//���������� � �����
//������ �� �����
*************************************************************/
#include <tchar.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "Book.h"
#include "Sort.h"


#define	  stop __asm nop	

// �� ������! ���������� ���� � ���������. �� ������� ������ �� ������!

//�����: ��������� ������� ��� ����� � ������ int cmd; scanf() return cmd;
//while (c = menu())
//{
//
//}
//Book->book.h; book.cpp;
//������������ ������ ������.book - capacity(�����); ���������� N;
//����� ������ ����������->�� �2����� ����� ���� ���������;
//struct cart1 //���������
//{
//	Book *pb;
//	int Capacity, N
//}



int _tmain()
{
	setlocale(LC_ALL, "Russian");
	//����������� ��������� BOOK, ��������� � ���������� ������.
	//��� ����� ���������� ���������� � ���������� � ������� �����
	//book.h � book.cpp


	//���������:
	//1. ����� ����� � �������� ����� ������� �� ������ �����
	//2. ��� ������ ����� �������� ���������� �������. ���� �������
	//   �� ������ ��������, �� � ������� ������� �������, �������
	//   �) ������������ ������������ ��������� �����/������ - wprintf(), wscanf()
	//   �) ������� ������ ��� ����������� - wchar_t
	//   �) ���������� ��������� - setlocale(LC_CTYPE, ".866");


	//������� 1. ������� ����������.
	//���������� - ��� ������ �������� => ����� ����� ������ �������.
	//���������: ������ ������� �������� ������������� ���� ���������� ���� =>
	//����� ������ ���� ����� ������???

	cartoteca Cart = {0};
	// ��������� 6 ���� � ��������
	avtofilling(Cart);
	offsetfilling(Cart);
	


	//������������ ������ ����� ����������� �� ������ ������� ���������
	//������ �������� � ���������� => ����� ����� ����������� ���
	//������������: ��� ����� ��������� ��� ����� "����" (��������
	//��������� �������� � ��������������� ������� ������������), ��������:
	//����������� ���������� ��������� (1)
	//������ ����� ����� (2)
	//������� ������������(��) (3)
	//�������� ������� ���������� ��������� � ���� (4)
	//������� �� ����� ���������� � ��������� (5)
	//...
	//����� �� ��������� (...)
	typedef void(*pFmenu)(cartoteca& cart);
	pFmenu arFmenu[] = { displayCart, fillingCart, deleteCart, filerecord, fileread, sortCart };
	int c=1;
	while (c = menu())
	{
		arFmenu[c - 1](Cart);
	}

	//���������� ����������� ������� ������ ����������� ������ � ����������




	//���������: ��� ��������� �����/������ ����������� ������� fprintf � fscanf
	//(������������ ���� <cstdio>








	//****************************************************************
	//������� 2. ������������ ������������ ����������� �������� �������� ����
	//� ������������ ������� => �������� ������� (�������) ���������� �������
	//�� ������ �� ����� ���������.
	//���������: ������� - "�� ������ ���� ���������" ����� ������ � �������
	//������������.
	for (int i = 0; i < Cart.N; i++)
	{
		delete Cart.pb[i];
		Cart.pb[i] = nullptr;
	}
	delete[] Cart.pb;
	Cart.pb = nullptr;
	return 0;
}