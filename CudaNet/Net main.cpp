#include <iostream>
#include <vector>
#include "Image_to_Matrix.h"
#include "kernel.h"
void kernelin(double kernel[k_sizex][k_sizey][sizez])
{
	for (int x = 0; x < k_sizex; x++)
	{
		for (int y = 0; y < k_sizey; y++)
		{
			for (int z = 0; z < sizez; z++)
			{
				kernel[x][y][z] = rand();
			}
		}
	}
}
void main()
{
	setlocale(LC_ALL, "Rus");
	double Matrix[m_sizex][m_sizey];
	double kernel[k_sizex][k_sizey][sizez];
	double Matrix2[m_sizex][m_sizey][sizez];
	imageMatrix(Matrix, 0);
	kernelin(kernel);
	same_conv(Matrix, Matrix2, kernel);
}