#pragma once

class Simulator {
	private:
		int *a, n;
		int cnt;
		bool cmp(int a, int b);
		void sort(int* l, int* r);

	public:
		Simulator(int n);
		~Simulator();

		int solve();
};
