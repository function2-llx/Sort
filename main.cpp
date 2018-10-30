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
	fprintf(stderr, "\rprogres: 0/%d", T);
	for (int i = 1; i <= T; i++) {
		Simulator simulator(n);
		printf("%d\n", simulator.solve());
		fprintf(stderr, "\rprogres: %d/%d", i, T);
	}
	fprintf(stderr, "\n");
	return 0;
}
