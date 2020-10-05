#include "Sort.h"
#include <iostream>

using namespace std;

int main()
{
	int a[] = { 4,7,9,2,3,6,9 };
	int temp[7] = { 0 };
	mergesort<int>(a, temp, 0, 6);
	for (int as : a) { cout << as << "\t"; }
	cout << endl;
}