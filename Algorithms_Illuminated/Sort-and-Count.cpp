#include<iostream>;

struct Num_and_Inv
{
	int *A;
	int inv;
};

int Merge_and_CountInv(int *L,int Llong,int *R,int Rlong,int *A,int sinv)
{
	int i = 0, j = 0, k = 0;
	
	while (i<Llong&&j<Rlong)
	{
		if (L[i] < R[j])
			A[k++] = L[i++];
		else
		{
			A[k++] = R[j++];
			sinv += Llong - i ;
		}
	}
	
	while (i<Llong)
		A[k++] = L[i++];
	while (j<Rlong)
		A[k++] = R[j++];
	
	return sinv;
}

int Sort_and_CountInv(int *A,int n)
{
	if (n < 2)
		return 0;

	int* L, * R, mid = n / 2;
	int linv=0, rinv=0, sinv=0;
	L = new int[mid];
	R = new int[n - mid];
	for (size_t i = 0; i < mid; i++)
		L[i] = A[i];
	for (size_t i = mid; i < n; i++)
		R[i - mid] = A[i];

	linv = Sort_and_CountInv(L, mid);
	rinv = Sort_and_CountInv(R, n - mid);
	sinv = Merge_and_CountInv(L,mid,R,n-mid,A,sinv);

	delete[]L;
	delete[]R;

	return linv + rinv + sinv;

}