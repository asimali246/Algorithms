#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;


//! ������ 64-������� �����
long long abs (long long n)
{
	return n < 0 ? -n : n;
}

unsigned long long abs (unsigned long long n)
{
	return n;
}

//! ���������� true, ���� n ������
template <class T>
bool even (const T & n)
{
	// return n % 2 == 0;
	return (n & 1) == 0;
}

//! ����� ����� �� 2
template <class T>
void bisect (T & n)
{
	// n /= 2;
	n >>= 1;
}

//! �������� ����� �� 2
template <class T>
void redouble (T & n)
{
	// n *= 2;
	n <<= 1;
}

//! ���������� true, ���� n - ������ ������� �������� �����
template <class T>
bool perfect_square (const T & n)
{
	T sq = (T) ceil (sqrt ((double)n));
	return sq*sq == n;
}

//! ��������� ������ �� �����, �������� ��� ����
template <class T>
T sq_root (const T & n)
{
	return (T) floor (sqrt ((double) n));
}

//! ���������� ���������� ��� � ����� (�.�. ����������� ���������� ���, �������� ����� ����������� ������ �����)
template <class T>
unsigned bits_in_number (T n)
{
	if (n == 0)
		return 1;
	unsigned result = 0;
	while (n)
	{
		bisect (n);
		++result;
	}
	return result;
}

//! ���������� �������� k-�� ���� ����� (���� ���������� � ����)
template <class T>
bool test_bit (const T & n, unsigned k)
{
	return (n & (T(1) << k)) != 0;
}

//! �������� a *= b (mod n)
template <class T>
void mulmod (T & a, T b, const T & n)
{
	// ������� ������, ������� ������ ��� ������� ����������
	a *= b;
	a %= n;
}

template <>
void mulmod (int & a, int b, const int & n)
{
	a = int( (((long long)a) * b) % n );
}

template <>
void mulmod (unsigned & a, unsigned b, const unsigned & n)
{
	a = unsigned( (((unsigned long long)a) * b) % n );
}

template <>
void mulmod (unsigned long long & a, unsigned long long b, const unsigned long long & n)
{
	// ������� ������, ���������� �� �������� ���������� ������������ � �����
	if (a >= n)
		a %= n;
	if (b >= n)
		b %= n;
	unsigned long long res = 0;
	while (b)
		if (!even (b))
		{
			res += a;
			while (res >= n)
				res -= n;
			--b;
		}
		else
		{
			redouble (a);
			while (a >= n)
				a -= n;
			bisect (b);
		}
	a = res;
}

template <>
void mulmod (long long & a, long long b, const long long & n)
{
	bool neg = false;
	if (a < 0)
	{
		neg = !neg;
		a = -a;
	}
	if (b < 0)
	{
		neg = !neg;
		b = -b;
	}
	unsigned long long aa = a;
	mulmod<unsigned long long> (aa, (unsigned long long)b, (unsigned long long)n);
	a = (long long)aa * (neg ? -1 : 1);
}


//! ��������� a^k (mod n). ���������� �������� ���������� � �������
template <class T, class T2>
T powmod (T a, T2 k, const T & n)
{
	T res = 1;
	while (k)
		if (!even (k))
		{
			mulmod (res, a, n);
			--k;
		}
		else
		{
			mulmod (a, a, n);
			bisect (k);
		}
	return res;
}

//! ��������� ����� n � ����� q*2^p
template <class T>
void transform_num (T n, T & p, T & q)
{
	T p_res = 0;
	while (even (n))
	{
		++p_res;
		bisect (n);
	}
	p = p_res;
	q = n;
}

//! �������� �������
template <class T, class T2>
T gcd (const T & a, const T2 & b)
{
	return (a == 0) ? b : gcd (b % a, a);
}

//! ��������� jacobi(a,b)
template <class T>
T jacobi (T a, T b)
{

#pragma warning (push)
#pragma warning (disable: 4146)

	if (a == 0)
		return 0;
	if (a == 1)
		return 1;
	
	if (a < 0)
		if ((b & 2) == 0)
			return jacobi (-a, b);
		else
			return - jacobi (-a, b);
	
	T e, a1;
	transform_num (a, e, a1);
	
	T s;
	if (even (e) || (b & 7) == 1 || (b & 7) == 7)
		s = 1;
	else
		s = -1;
	if ((b & 3) == 3 && (a1 & 3) == 3)
		s = -s;
	if (a1 == 1)
		return s;
	return s * jacobi (b % a1, a1);

#pragma warning (pop)

}

//! ��������� pi(b) ������ ������� �����. ���������� ������ �� ������ � �������� (� ������� ����� ��������� ������ �������, ��� ����) � � pi - pi(b)
template <class T, class T2>
const std::vector<T> & get_primes (const T & b, T2 & pi)
{

	static std::vector<T> primes;
	static T counted_b;

	// ���� ��������� ��� ��� �������� �����, ���������� ���, ����� ����������� �������
	if (counted_b >= b)
		pi = T2 (std::upper_bound (primes.begin(), primes.end(), b) - primes.begin());
	else
	{
	
		// ����� 2 ������������ ��������
		if (counted_b == 0)
		{
			primes.push_back (2);
			counted_b = 2;
		}

		// ������ ������������ ��� ��������, ���� �� ������ ������ ���������� �������
		T first = counted_b == 2 ? 3 : primes.back()+2;
		for (T cur=first; cur<=b; ++++cur)
		{
			bool cur_is_prime = true;
			for (std::vector<T>::const_iterator iter = primes.begin(), end = primes.end();
				iter != end; ++iter)
			{
				const T & div = *iter;
				if (div * div > cur)
					break;
				if (cur % div == 0)
				{
					cur_is_prime = false;
					break;
				}
			}
			if (cur_is_prime)
				primes.push_back (cur);
		}
		
		counted_b = b;
		pi = (T2) primes.size();

	}
	
	return primes;

}

//! ����������� �������� n �� ��������, ������������ ��� �������� �� m. ���������: 1 - ���� n ����� �������, p - ��� ��������� ��������, 0 - ���� ����������, �������� �� n ������� ��� ���
template <class T, class T2>
T2 prime_div_trivial (const T & n, T2 m)
{
	
	// ������� ��������� ����������� ������
	if (n == 2 || n == 3)
		return 1;
	if (n < 2)
		return 0;
	if (even (n))
		return 2;

	// ���������� ������� �� 3 �� m
	T2 pi;
	const vector<T2> & primes = get_primes (m, pi);

	// ����� �� ��� �������
	for (std::vector<T2>::const_iterator iter=primes.begin(), end=primes.end();
		iter!=end && *iter <= m; ++iter)
	{
		const T2 & div = *iter;
		if (div * div > n)
			break;
		else
			if (n % div == 0)
				return div;
	}
	
	if (n < m*m)
		return 1;
	return 0;

}

//! ��������� �������� �������-������ �������� n �� �������� �� ��������� b
template <class T, class T2>
bool miller_rabin (T n, T2 b)
{

	// ������� ��������� ����������� ������
	if (n == 2)
		return true;
	if (n < 2 || even (n))
		return false;

	// ���������, ��� n � b ������� ������ (����� ��� �������� � ������)
	// ���� ��� �� ������� ������, �� ���� n �� ������, ���� ����� ��������� b
	if (b < 2)
		b = 2;
	for (T g; (g = gcd (n, b)) != 1; ++b)
		if (n > g)
			return false;

	// ��������� n-1 = q*2^p
	T n_1 = n;
	--n_1;
	T p, q;
	transform_num (n_1, p, q);

	// ��������� b^q mod n, ���� ��� ����� 1 ��� n-1, �� n, ��������, �������
	T rem = powmod (T(b), q, n);
	if (rem == 1 || rem == n_1)
		return true;

	// ������ ��������� b^2q, b^4q, ... , b^((n-1)/2)
	// ���� �����-���� �� ��� ����� n-1, �� n, ��������, �������
	for (T i=1; i<p; i++)
	{
		mulmod (rem, rem, n);
		if (rem == n_1)
			return true;
	}

	return false;

}

//! ��������� �������� ������-��������� �������� n �� ��������. ������������ ��������� �������� ������ � ����������� ���������. �������� ������ � ��������� ������!!! ������ �������� unused �� ������������, �� ������ ���� ���
template <class T, class T2>
bool lucas_selfridge (const T & n, T2 unused)
{

	// ������� ��������� ����������� ������
	if (n == 2)
		return true;
	if (n < 2 || even (n))
		return false;

	// ���������, ��� n �� �������� ������ ���������, ����� �������� ���� ������
	if (perfect_square (n))
		return false;

	// �������� ���������: ������� ������ ����� d �����, ���:
	// jacobi(d,n)=-1 � ��� ����������� ���� { 5,-7,9,-11,13,... }
	T2 dd;
	for (T2 d_abs = 5, d_sign = 1; ; d_sign = -d_sign, ++++d_abs)
	{
		dd = d_abs * d_sign;
		T g = gcd (n, d_abs);
		if (1 < g && g < n)
			// ����� �������� - d_abs
			return false;
		if (jacobi (T(dd), n) == -1)
			break;
	}

	// ��������� ���������
	T2
		p = 1,
		q = (p*p - dd) / 4;
	
	// ��������� n+1 = d*2^s
	T n_1 = n;
	++n_1;
	T s, d;
	transform_num (n_1, s, d);

	// �������� ������
	T
		u = 1,
		v = p,
		u2m = 1,
		v2m = p,
		qm = q,
		qm2 = q*2,
		qkd = q;
	for (unsigned bit = 1, bits = bits_in_number(d); bit < bits; bit++)
	{
		mulmod (u2m, v2m, n);
		mulmod (v2m, v2m, n);
		while (v2m < qm2)
			v2m += n;
		v2m -= qm2;
		mulmod (qm, qm, n);
		qm2 = qm;
		redouble (qm2);
		if (test_bit (d, bit))
		{
			T t1, t2;
			t1 = u2m;
			mulmod (t1, v, n);
			t2 = v2m;
			mulmod (t2, u, n);
			
			T t3, t4;
			t3 = v2m;
			mulmod (t3, v, n);
			t4 = u2m;
			mulmod (t4, u, n);
			mulmod (t4, (T)dd, n);

			u = t1 + t2;
			if (!even (u))
				u += n;
			bisect (u);
			u %= n;

			v = t3 + t4;
			if (!even (v))
				v += n;
			bisect (v);
			v %= n;
			mulmod (qkd, qm, n);
		}
	}

	// ����� ������� (��� ������-�������)
	if (u == 0 || v == 0)
		return true;

	// ��������� ���������� �����
	T qkd2 = qkd;
	redouble (qkd2);
	for (T2 r = 1; r < s; ++r)
	{
		mulmod (v, v, n);
		v -= qkd2;
		if (v < 0) v += n;
		if (v < 0) v += n;
		if (v >= n) v -= n;
		if (v >= n) v -= n;
		if (v == 0)
			return true;
		if (r < s-1)
		{
			mulmod (qkd, qkd, n);
			qkd2 = qkd;
			redouble (qkd2);
		}
	}

	return false;

}

//! �������� �����-��������-��������-�������� (BPSW) �������� n �� ��������
template <class T>
bool baillie_pomerance_selfridge_wagstaff (T n)
{
	// ���������� ����������� �������� �� 1000
	int div = prime_div_trivial (n, 1000);
	if (div == 1)
		return true;
	if (div > 1)
		return false;

	// ���� �������-������ �� ��������� 2
	if (!miller_rabin (n, 2))
		return false;

	// ��������� ���� ������-���������
	return lucas_selfridge (n, 0);

}

//! �������� �����-��������-��������-�������� (BPSW) �������� n �� ��������
template <class T>
bool isprime (T n)
{
	return baillie_pomerance_selfridge_wagstaff (n);
}


// //////////////////////////////////////////////

#include <iostream>

int main()
{

	cout << "Enter any number -> ";
	long long num;
	cin >> num;
	cout << (isprime(num) ? "is prime" : "is composite") << endl;

	cin.get();
	cin.get();

	return 0;
}