#pragma once

class Simulator {
	public:
		int *a, n;
		int cnt;
		bool check() const;

	protected:
		bool cmp(int a, int b);
		virtual void sort(int* l, int* r);

	public:
		Simulator(int n);
		~Simulator();

		int solve();
};
