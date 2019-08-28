#include <iostream>
#include <vector>
#include "Image_to_Matrix.h"
#include "kernel.h"
using namespace std;
void some()
{
	int h = 28, l = 28, number = 16;
	vector<vector<int>> Matrix(h, vector<int>(l));
	Cimg_out(Matrix, 1);
	setlocale(LC_ALL, "Rus");
}
