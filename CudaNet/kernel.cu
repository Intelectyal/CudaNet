#include "kernel.h"
#include <stdio.h>
#include <cuda_runtime_api.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
#include "Image_to_Matrix.h"
using namespace std;

__global__ void same(double* dev_matrix1,double* dev_kernel,double*dev_matrix2)
{
	int idx = threadIdx.x;
	int idy = threadIdx.y;
	int idz = threadIdx.z;
}

 __host__ void same_conv(double Matrix[m_sizex][m_sizey],double Matrix2[m_sizex][m_sizey][sizez], double kernel[k_sizex][k_sizey][sizez])
{
	 double* matrixline=new double[m_sizex*m_sizey];//Выделяем память для входной матрицы,  одномерный массив 
	 double* kernelline=new double[k_sizex*k_sizey*sizez];//Выделяем память для  ядра, одномерный массив
	 for (int x = 0; x < m_sizex; x++)//Копируем матрицу размера 28*28 в одномерный массив на 28*28
	 {
		 for (int y = 0; y < m_sizey; y++)
		 {
			 matrixline[x * m_sizey + y] = Matrix[x][y];
		 }
	 }
	 for (int x = 0; x < k_sizex; x++)//Копируем ядро размером 5*5*20 в одномерный массив 5*5*20
	 {
		 for (int y = 0; y < k_sizey; y++)
		 {
			 for (int z = 0; z < sizez; z++)
			 {
				 kernelline[x * k_sizex *sizez +y* sizez + z] = kernel[x][y][z];
			 }
		 }
	 }

	 double* dev_matrix1;//указатель на память видеокарте матрица 1
	 double* dev_kernel;//указатель на память видеокарте  ядро
	 double* dev_matrix2;//указатель на память видеокарте  матрица 2
	 cudaMalloc((void**)&dev_matrix1, sizeof(double) * m_sizex*m_sizey);//Выделяем память для матрицы 1 на видеокарте
	 cudaMalloc((void**)&dev_kernel, sizeof(double) * k_sizex*k_sizey*sizez);//Выделяем память для ядра на видеокарте
	 cudaMalloc((void**)&dev_matrix2, sizeof(double) * m_sizex*m_sizey*sizez);//Выделяем память для матрицы 2 на видеокарте
	 cudaMemcpy(dev_matrix1, matrixline, sizeof(double) * m_sizex*m_sizey, cudaMemcpyHostToDevice);//Копируем данные в память видеокарты
	 cudaMemcpy(dev_kernel, kernelline, sizeof(double) * k_sizex*k_sizey*sizez, cudaMemcpyHostToDevice);//Копируем данные в память видеокарты

	
	 /* 28*28->32*32 боковые=0 */
}


