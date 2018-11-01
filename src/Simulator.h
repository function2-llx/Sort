#pragma once

class Simulator {
	private:
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
