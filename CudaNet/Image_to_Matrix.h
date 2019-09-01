#pragma once
#include "kernel.h"
void imageMatrix(double Matrix[m_sizex][m_sizey], int final_number);
void namefunc(char lastname[], int number);
void Console_out(double Matrix[m_sizex][m_sizey], int number_of_image);
void Cimg_out(double Matrix[m_sizex][m_sizey], int number_of_image);
void Console_out_of_range(double Matrix[m_sizex][m_sizey], int iterator);
void Cimg_out_of_range(double Matrix[m_sizex][m_sizey], int iterator);