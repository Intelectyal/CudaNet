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
	 double* matrixline=new double[m_sizex*m_sizey];//�������� ������ ��� ������� �������,  ���������� ������ 
	 double* kernelline=new double[k_sizex*k_sizey*sizez];//�������� ������ ���  ����, ���������� ������
	 for (int x = 0; x < m_sizex; x++)//�������� ������� ������� 28*28 � ���������� ������ �� 28*28
	 {
		 for (int y = 0; y < m_sizey; y++)
		 {
			 matrixline[x * m_sizey + y] = Matrix[x][y];
		 }
	 }
	 for (int x = 0; x < k_sizex; x++)//�������� ���� �������� 5*5*20 � ���������� ������ 5*5*20
	 {
		 for (int y = 0; y < k_sizey; y++)
		 {
			 for (int z = 0; z < sizez; z++)
			 {
				 kernelline[x * k_sizex *sizez +y* sizez + z] = kernel[x][y][z];
			 }
		 }
	 }

	 double* dev_matrix1;//��������� �� ������ ���������� ������� 1
	 double* dev_kernel;//��������� �� ������ ����������  ����
	 double* dev_matrix2;//��������� �� ������ ����������  ������� 2
	 cudaMalloc((void**)&dev_matrix1, sizeof(double) * m_sizex*m_sizey);//�������� ������ ��� ������� 1 �� ����������
	 cudaMalloc((void**)&dev_kernel, sizeof(double) * k_sizex*k_sizey*sizez);//�������� ������ ��� ���� �� ����������
	 cudaMalloc((void**)&dev_matrix2, sizeof(double) * m_sizex*m_sizey*sizez);//�������� ������ ��� ������� 2 �� ����������
	 cudaMemcpy(dev_matrix1, matrixline, sizeof(double) * m_sizex*m_sizey, cudaMemcpyHostToDevice);//�������� ������ � ������ ����������
	 cudaMemcpy(dev_kernel, kernelline, sizeof(double) * k_sizex*k_sizey*sizez, cudaMemcpyHostToDevice);//�������� ������ � ������ ����������

	
	 /* 28*28->32*32 �������=0 */
}


