#include <cstdio>
#include "src/Simulator.h"

int main(int argc, char const *argv[])
{
	Simulator simulator(10);
	printf("%d\n", simulator.solve());
	return 0;
}
