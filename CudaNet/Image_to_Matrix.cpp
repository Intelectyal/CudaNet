#include <iostream>
#include "CImg.h"
#include "Image_to_Matrix.h"
using namespace std;
using namespace cimg_library;

void namefunc(char lastname[], int number)// Number номер картинки, которая будет открыта. Lastname имя файла, в которое записываеться число 
{
	if (number < 10)// 1 значное число
	{
		lastname[0] = '0' + number;
		lastname[1] = '.';
		lastname[2] = 'b';
		lastname[3] = 'm';
		lastname[4] = 'p';
		lastname[5] = '\0';
	}
	if ((number < 99 || number == 99) && (number > 10 || number == 10))//2 значное число
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
	if ((number < 999 || number == 999) && number > 99)//3 значное число
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
	if ((number < 9999 || number == 9999) && number > 999)//4 значное число
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
	if (number > 9999) //5 значное число
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
void imageMatrix(double Matrix[m_sizex][m_sizey], int number_of_image)// Открывает картинку под номером %number_of_image% и записывает значение пикселя в %vector<vector<int>> Matrix%
{
	char lastname[10];
	namefunc(lastname, number_of_image);
	CImg<unsigned char> img(lastname);
	for (int i = 0; i < m_sizey; i++)
	{
		for (int k = 0; k < m_sizex; k++)
		{
			Matrix[i][k] = img(k, i, 0, 0);
		}
	}
}
void Console_out(double Matrix[m_sizex][m_sizey], int number_of_image)
{
	--number_of_image;
	imageMatrix(Matrix, number_of_image);
	for (int j = 0; j < m_sizey; j++)
	{
		for (int k = 0; k < m_sizex; k++)
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
void Cimg_out(double Matrix[m_sizex][m_sizey], int number_of_image)
{
	--number_of_image;
	imageMatrix(Matrix, number_of_image);
	char lastname[10];
	namefunc(lastname, number_of_image);
	CImg<unsigned char> img(lastname);
	for (int j = 0; j < m_sizey; j++)
	{
		for (int k = 0; k < m_sizex; k++)
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
void Console_out_of_range(double Matrix[m_sizex][m_sizey], int iterator)// Выводит изображения в консоль, пока i<iterator
{
	for (int i = 0; i < iterator; i++)
	{
		imageMatrix(Matrix, i);
		for (int j = 0; j < m_sizey; j++)
		{
			for (int k = 0; k < m_sizex; k++)
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
void Cimg_out_of_range(double Matrix[m_sizex][m_sizey], int iterator)
{
	for (int q = 0; q < iterator; q++)
	{
		imageMatrix(Matrix, q);
		char lastname[10];
		namefunc(lastname, q);
		CImg<unsigned char> img(lastname);
		for (int j = 0; j < m_sizey; j++)
		{
			for (int k = 0; k < m_sizex; k++)
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