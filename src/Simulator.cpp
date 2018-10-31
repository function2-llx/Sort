#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "Simulator.h"

bool Simulator::cmp(int a, int b)
{
	cnt++;
	return a < b;
}

void Simulator::sort(int* l, int* r)
{
	int n = r - l;
	if (n <= 1)
		return;
    int step=1,upper;
    if (n>32){
        upper=9;
    }else{
        if (n>25){
            upper=3;
        }else{
            upper=1;
        }
    }
    int *rr=l+9;
    while (step<upper){
        for (int *i=l,*j=i+step,*k=j+step;k<rr;i=k+step,j=i+step,k=j+step){
            if (!cmp(*i,*j)){
                std::swap(*i,*j);
            }
            if (cmp(*i,*k)){
                if (cmp(*j,*k)){
                    std::swap(*i,*j);
                }else{
                    std::swap(*i,*k);
                }
            }
        }
        step*=3;
    }
    //int *pivot=l+rand()%(n/step)*step;
    //std::swap(*l,*pivot);
	int *i = l, *j = r - 1, val = *l;
	while (i < j) {
        while (i<j && !cmp(*j,val)){
            j--;
        }
        if (i<j){
            *(i++)=*j;
        }
        while (i<j && !cmp(val,*i)){
            i++;
        }
        if (i<j){
            *(j--)=*i;
        }
	}
    *i=val;
	this->sort(l, i);
	this->sort(i+1, r);
}

Simulator::Simulator(int n) : n(n)
{
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = rand();
}

Simulator::~Simulator()
{
	delete[] a;
}

int Simulator::solve()
{
	cnt = 0;
	this->sort(a, a + n);
	assert(this->check());
	return cnt;
}

bool Simulator::check() const
{
	for (int i = 1; i < n; i++)
		assert(a[i - 1] <= a[i]);

	return 1;
}
