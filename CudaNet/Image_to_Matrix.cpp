#include <iostream>
#include <vector>
#include "CImg.h"
#include "Image_to_Matrix.h"
using namespace std;
using namespace cimg_library;

void namefunc(char lastname[], int number)// Number ����� ��������, ������� ����� �������. Lastname ��� �����, � ������� ������������� ����� 
{
	if (number < 10)// 1 ������� �����
	{
		lastname[0] = '0' + number;
		lastname[1] = '.';
		lastname[2] = 'b';
		lastname[3] = 'm';
		lastname[4] = 'p';
		lastname[5] = '\0';
	}
	if ((number < 99 || number == 99) && (number > 10 || number == 10))//2 ������� �����
	{
		int f1, f2;
		f1 = number / 10;
		f2 = number % 10;
		lastname[0] = '0' + f1;
		lastname[1] = '0' + f2;
		lastname[2] = '.';
		lastname[3] = 'b';
		lastname[4] = 'm';
		lastname[5] = 'p';
		lastname[6] = '\0';
	}
	if ((number < 999 || number == 999) && number > 99)//3 ������� �����
	{
		int f1, f2, f3;
		f1 = number / 100;
		f2 = (number / 10) % 10;
		f3 = number % 10;
		lastname[0] = '0' + f1;
		lastname[1] = '0' + f2;
		lastname[2] = '0' + f3;
		lastname[3] = '.';
		lastname[4] = 'b';
		lastname[5] = 'm';
		lastname[6] = 'p';
		lastname[7] = '\0';
	}
	if ((number < 9999 || number == 9999) && number > 999)//4 ������� �����
	{
		int f1, f2, f3, f4;
		f1 = number / 1000;
		f2 = (number / 100) % 10;
		f3 = (number / 10) % 10;
		f4 = number % 10;
		lastname[0] = '0' + f1;
		lastname[1] = '0' + f2;
		lastname[2] = '0' + f3;
		lastname[3] = '0' + f4;
		lastname[4] = '.';
		lastname[5] = 'b';
		lastname[6] = 'm';
		lastname[7] = 'p';
		lastname[8] = '\0';
	}
	if (number > 9999) //5 ������� �����
	{
		int f1, f2, f3, f4, f5;
		f1 = number / 10000;
		f2 = (number / 1000) % 10;
		f3 = (number / 100) % 10;
		f4 = (number / 10) % 10;
		f5 = number % 10;
		lastname[0] = '0' + f1;
		lastname[1] = '0' + f2;
		lastname[2] = '0' + f3;
		lastname[3] = '0' + f4;
		lastname[4] = '0' + f5;
		lastname[5] = '.';
		lastname[6] = 'b';
		lastname[7] = 'm';
		lastname[8] = 'p';
		lastname[9] = '\0';
	}
}
void matrix_fun(vector<vector<int>> &Matrix, int number_of_image)// ��������� �������� ��� ������� %number_of_image% � ���������� �������� ������� � %vector<vector<int>> Matrix%
{
	char lastname[10];
	namefunc(lastname, number_of_image);
	CImg<unsigned char> img(lastname);
	for (int i = 0; i < Matrix[0].size(); i++)
	{
		for (int k = 0; k < Matrix.size(); k++)
		{
			Matrix[i][k] = img(k, i, 0, 0);
		}
	}
}
void Console_out(vector<vector<int>> &Matrix, int number_of_image)
{
	--number_of_image;
	matrix_fun(Matrix, number_of_image);
	for (int j = 0; j < Matrix[0].size(); j++)
	{
		for (int k = 0; k < Matrix.size(); k++)
		{
			if (Matrix[j][k] == 0)
			{
				cout << "0";
			}
			else
			{
				cout << "@";
			}
		}
		cout << endl;
	}
	cout << "----------------------------" << endl;
}
void Cimg_out(vector<vector<int>> &Matrix, int number_of_image)
{
	--number_of_image;
	matrix_fun(Matrix, number_of_image);
	char lastname[10];
	namefunc(lastname, number_of_image);
	CImg<unsigned char> img(lastname);
	for (int j = 0; j < Matrix[0].size(); j++)
	{
		for (int k = 0; k < Matrix.size(); k++)
		{
			if (Matrix[j][k] == 0)
			{
				cout << "000";
			}
			else
			{
				cout << "|" << Matrix[j][k] << "|";
			}
		}
		cout << endl;
	}
	img.display(lastname);
}
void Console_out_of_range(vector<vector<int>> &Matrix, int iterator)// ������� ����������� � �������, ���� i<iterator
{
	for (int i = 0; i < iterator; i++)
	{
		matrix_fun(Matrix, i);
		for (int j = 0; j < Matrix[0].size(); j++)
		{
			for (int k = 0; k < Matrix.size(); k++)
			{
				if (Matrix[j][k] == 0)
				{
					cout << "0";
				}
				else
				{
					cout << "@";
				}
			}
			cout << endl;
		}
		cout << "----------------------------" << endl;
	}
}
void Cimg_out_of_range(vector<vector<int>> &Matrix, int iterator)
{
	for (int q = 0; q < iterator; q++)
	{
		matrix_fun(Matrix, q);
		char lastname[10];
		namefunc(lastname, q);
		CImg<unsigned char> img(lastname);
		for (int j = 0; j < Matrix[0].size(); j++)
		{
			for (int k = 0; k < Matrix.size(); k++)
			{
				if (Matrix[j][k] == 0)
				{
					cout << "000";
				}
				else
				{
					cout << Matrix[j][k];
				}
			}
			cout << endl;
		}
		img.display(lastname);
	}
}