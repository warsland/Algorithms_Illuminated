#include<iostream>
#include<random>

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int random(int l, int r)
{
	std::default_random_engine seed;
	std::uniform_int_distribution<unsigned>u(l, r - 1);
	return  u(seed);
}

int Partition(int* A, int l, int r)
{
	int p = A[r - 1];
	int i = l;
	for (int j = l; j < r; j++)
	{
		if (p > A[j])
			swap(A[i++], A[j]);
	}
	swap(A[i], A[r - 1]);
	return i;
}

int Rselect(int *A,int l,int r, int select)
{
	if (l == r)
		return A[r - l];
	int rand = random(l, r);
	swap(A[r-1], A[rand]);
	int j = Partition(A, l, r);
	if (select == j)
		return A[j];
	else if (select > j)
		return Rselect(A, j + 1, r, select - j);
	else
		return Rselect(A, l, j - 1, select);

}