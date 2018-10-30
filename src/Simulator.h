#pragma once

class Simulator {
	private:
		int *a, n;
		int cnt;
		bool cmp(int a, int b);
		void sort(int* l, int* r);
		bool check() const;

	public:
		Simulator(int n);
		~Simulator();

		int solve();
};
