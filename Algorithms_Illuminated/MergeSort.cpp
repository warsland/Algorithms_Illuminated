#include<iostream>

void Merge(int* A, int* front, int mid, int* behind, int n)
{
	int i = 0, j = 0, k = 0;
	while (i < mid && j < n)
	{
		if (front[i] < behind[j])
			A[k++] = front[i++];
		else
			A[k++] = behind[j++];
	}
	while (i < mid)
		A[k++] = front[i++];
	while (j < n)
		A[k++] = behind[j++];
}

void MergeSort(int *A, int n)
{
	if (n < 2)
		return;
	int *front,*behind,mid = n / 2;
	front = new int[mid];
	behind = new int[n-mid];
	for (size_t i = 0; i < mid; i++)
		front[i] = A[i];
	for (size_t i = mid; i < n; i++)
		behind[i-mid] = A[i];

	MergeSort(front, mid);
	MergeSort(behind, n - mid);
	Merge(A, front, mid, behind, n - mid);

	delete[]front;
	delete[]behind;
}