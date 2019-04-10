#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
using namespace std;
#define IOS                      \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0)
#define mt(a, b) memset(a, b, sizeof(a));
#define pb push_back
#define pob pop_back
#define mid (l + r) >> 1
#define lson rt << 1
#define rson rt << 1 | 1
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
	codeforce 1139 C
	���鼯
	˼·���ȼ������е�����n��k�η���Ȼ���ڼ�ȥ�����������ģ�
	�������еĺ�·�ߵĵ�����ɵĿ飬Ȼ����㲻��������������
	�����к�·�߿�ĵ��������k�η��ĺͣ����ڼ�ȥ��ɫ��ĸ���
	ͬʱ���⻹�漰���˿����ݵ�֪ʶ
*/

ll mod = 1e9 + 7;
int const maxn = 1e5 + 5;
int p[maxn], shu[maxn];
int vis[maxn], isred[maxn];

int findx(int x)
{
	if (p[x] != x)
		return p[x] = findx(p[x]);
	return x;
}

void unit(int u, int v)
{
	int uu = findx(u);
	int vv = findx(v);
	p[uu] = vv;
}
//����������
ll qpow(int n, int k)
{
	if (k == 0)
		return 1;
	ll res = 1;
	while (k)
	{
		if (k & 1) // ���k������
		{
			res *= n;
			res %= mod;
		}
		n *= n;
		k >>= 1;
	}
	return res; 
}

ull pow4(int n, int k)
{
	ull res = 1;
	while (k--)
	{
		res *= n;
		res %= mod;
	}
	return res;
}

int main()
{
	IOS;
	int n, k;
	mt(vis, 0);
	mt(isred, 0);
	mt(shu, 0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (!w)
		{
			isred[u] = 1;
			isred[v] = 1;
			unit(u, v);
		}
	}
	ull sum = pow4(n, k);
	for (int i = 1; i <= n; i++)
	{
		shu[findx(i)]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[findx(i)]) continue;
		if (!isred[i])
		{
			sum--;
			vis[i] = 1;
			continue;
		}
		ull cnt = pow4(shu[findx(i)], k);
		sum -= cnt;
		sum = (sum + mod) % mod;
		vis[findx(i)] = 1;
	}
	cout << (sum + mod) % mod << "\n";
	return 0;
}