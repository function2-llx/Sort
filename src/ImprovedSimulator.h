#include "Simulator.h"

class ImprovedSimulator : public Simulator{
	public:
		ImprovedSimulator(int n);
		void sort(int *l, int *r) override;
};