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
	int *i = l, *j = r - 1, val = *(l + rand() % n);
	while (i <= j) {
		while (i <= j && this->cmp(*i, val))
			i++;
		while (i <= j && this->cmp(val, *j))
			j--;
		if (i > j)
			break;
		std::swap(*i, *j);
		i++;
		j--;
	}
	this->sort(l, j + 1);
	this->sort(i, r);
}

Simulator::Simulator(int n) : n(n)
{
	srand(time(NULL));
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
