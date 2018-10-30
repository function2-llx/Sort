#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "src/Simulator.h"

int main(int argc, char const *argv[])
{
	int n, T;
	scanf("%d%d", &n, &T);
	printf("%d %d\n", n, T);
	srand(time(NULL));
	while (T--) {
		Simulator simulator(n);
		printf("%d\n", simulator.solve());
	}
	return 0;
}
