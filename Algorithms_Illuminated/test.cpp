#include<iostream>

int Rselect(int* A, int l, int r, int select);

int main()
{
	int A[6] = {1,3,5,2,4,6};
	int l = 0, r = 6;
	int n = 4;
	int select=(A, l,r,4);
	std::cout << select << std::endl;
	for(int var: A)
	{
		std::cout << var << " ";
	}
}