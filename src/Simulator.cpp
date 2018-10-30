#include <ctime>
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
		while (i <= j && cmp(*i, val))
			i++;
		while (i <= j && cmp(val, *j))
			j--;
		std::swap(*i, *j);
		i++;
		j--;
	}
	sort(l, j + 1);
	sort(i, r);
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
	sort(a, a + n);
	return cnt;
}

