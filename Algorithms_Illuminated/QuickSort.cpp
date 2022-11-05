#include<iostream>
#include<random>

void swap(int &A, int &B)
{
	int temp = A;
	A = B;
	B = temp;
}

int Partition(int* A, int l, int r)
{	
	int i = l;
	int p = A[r - 1];

	for (size_t j = l; j < r; j++)
	{
		if (p > A[j])
			swap(A[i++], A[j]);
	}
	swap(A[i], A[r-1]);
	return i;
}

int random(int l, int r)
{
	std::default_random_engine seed;
	std::uniform_int_distribution<unsigned>u(l, r);
	return  u(seed);
}

void QuickSort(int *A,int l,int r)
{
	if (!(l<r))
		return;
	
	int rand = random(l, r-1);
	swap(A[r-1], A[rand]);

	int j = Partition(A, l, r);
	QuickSort(A, l, j - 1);
	QuickSort(A, j+1, r);
}
