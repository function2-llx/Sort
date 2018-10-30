extern int cnt;

bool cmp(int a, int b)
{
	cnt++;
	return a < b;
}