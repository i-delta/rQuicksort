/*
 * Random quick sort algorithm
 * Author: ywjia
 * 2014-10-21
 */

#include<stdio.h>
#include<stdlib.h>

/* random  generator */

static unsigned random_index(unsigned int min, unsigned int max){
	unsigned int range = max - min;
	unsigned int buckets =(RAND_MAX) / range;
	unsigned int limit = buckets * range;
	int r;
	do{
		r = random();

	}while(r >= limit);

	return min + r/buckets;
}


static void exchange(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

static int partion(int a[], int p, int r){
	int x = a[r];			// the pivot
	int i = p - 1;
	int j;

	for(j = p; j < r; j++)
	{
		if( a[j] < x){
			i = i + 1;
			exchange(&(a[i]), &(a[j]));
		}
	}
	exchange(&a[i+1], &(a[r]));
	return i+1;
}

int random_partion(int a[], int p, int r){
	int i = random_index(p, r);
	exchange(&a[i], &a[r]);
	return partion(a, p, r);
}
void qSort(int a[], int p, int r){
	int q;
	if(p < r)
	{
		q = random_partion(a, p, r);
		qSort(a, p, q-1);
		qSort(a, q+1, r);
	}
}
