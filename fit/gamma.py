from scipy.special import gamma, beta
import math

# density
def gammaDisdribution(x, alpha, lambda_):
	assert x >= 0
	return (lambda_ ** alpha) * (x ** (alpha - 1)) * (math.e ** (-lambda_ * x)) / gamma(alpha)

def sqr(x):
	return x * x

def transfer(cnt, length):
	cnt.sort()
	T = len(cnt)

	max_min = cnt[-1] - cnt[0]
	st = cnt[0]
	return list(map(lambda x: (x - st) / max_min * length, cnt[:-1]))

# return alpha, lambda of Gamma distribution
# length: range
def getGammaPrameter(cnt: list):
	T = len(cnt)

	sum1, sum2 = 0, 0
	for x in cnt:
		sum1 += x
		sum2 += sqr(x)

	e = sum1 / T
	var = sum2 / T - sqr(e)

	alpha = sqr(e) / var
	lambda_ = e / var

	return alpha, lambda_

filename = 'statistics/data_origin.txt'

def readData(filename):
	with open(filename, 'r') as f:
		f.readline()
		return list(map(int, f.read().strip().split('\n')))


def MSE(f, g):
	ret = 0
	for x, y in zip(f, g):
		ret += sqr(x - y)

	return ret / len(f)

if __name__ == "__main__":
	length = 100
	cnt = transfer(readData(filename), length)
	alpha, lambda_ = getGammaPrameter(cnt)

	print('alpha=', alpha, 'lambda=', lambda_)
	T = len(cnt)
	f = [0] * length
	for x in cnt:
		# print(x)
		f[int(x)] += 1 / T

	g = []
	for i in range(length):
		g.append(gammaDisdribution(i + 0.5, alpha, lambda_))

	print('MSE=', MSE(f, g))
