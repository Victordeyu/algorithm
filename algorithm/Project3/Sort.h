#pragma once
#ifndef SORT_H
#define SORT_H
#define THRESHOLD 10

template<typename E>
void insertSort(E A[], int n);

template<typename E>
void mergesort(E A[], E temp[], int left, int right)
{
	if (left == right)return;

	int mid = (left + right) / 2;
	mergesort(A, temp, left, mid);
	mergesort(A, temp, mid + 1, right);
	for (int i = left; i <= right;i++)
	{
		temp[i] = A[i];
	}
	int i1 = left; int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++)
	{
		if (i1 == mid + 1)
			A[curr] = temp[i2++];
		else if (i2 > right)
			A[curr] = temp[i1++];
		else if (temp[i1] < temp[i2])
			A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
}

template<typename E>
void qmergesort(E A[], E temp[], int left, int right)
{
	if ((right - left) < THRESHOLD)
	{
		insertSort(&A[left], right - left + 1);
		return;
	}
	int mid = (left + right) / 2;
	mergesort(A, temp, left, mid);
	mergesort(A, temp, mid + 1, right);
	for (int i = left; i <= right; i++)
	{
		temp[i] = A[i];
	}
	int i1 = left; int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++)
	{
		if (i1 == mid + 1)
			A[curr] = temp[i2++];
		else if (i2 > right)
			A[curr] = temp[i1++];
		else if (temp[i1] < temp[i2])
			A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
}

#endif