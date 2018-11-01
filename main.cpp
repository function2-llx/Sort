#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <string>
#include "src/Simulator.h"
#include "src/ImprovedSimulator.h"

const char ORIGIN_OUTPUT[] = "statistics/data_origin.txt";
const char IMPROVED_OUTPUT[] = "statistics/data_improved.txt";

inline bool isImproved(int argc, char const *argv[])
{
	return argc > 1;
}

int main(int argc, char const *argv[])
{
	bool isImproved = ::isImproved(argc, argv);
	if (isImproved)
		freopen(IMPROVED_OUTPUT, "w", stdout);
	else
		freopen(ORIGIN_OUTPUT, "w", stdout);
	int n, T;
	scanf("%d%d", &n, &T);
	printf("%d %d\n", n, T);
	srand(time(NULL));
	fprintf(stderr, "\rprogres: 0/%d", T);
	for (int i = 1; i <= T; i++) {
		Simulator *simulator = isImproved ? new ImprovedSimulator(n) : new Simulator(n);
		printf("%d\n", simulator->solve());
		fprintf(stderr, "\rprogres: %d/%d", i, T);
	}
	fprintf(stderr, "\n");
	return 0;
}
