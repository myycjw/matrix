#include<map>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 1e3 + 10;
#define ll long long
int i, j, k;
int n, m, q;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
map<ll, ll> mp[30];
int cmp(int a,int b) {
	return a > b;
}
int mx[maxn], dp[maxn][maxn], p[maxn][maxn], a[maxn];
void Print(int l, int r) {//递归输出
	if (l == r)
		cout << "A" << l;
	else {
		cout << "(";
		Print(l, p[l][r]);
		Print(p[l][r] + 1, r);
		cout << ")";
	}
}
int main() {
	memset(dp, 0, sizeof dp);
	memset(p, 0, sizeof p);
	cin >> n;
	cin >> mx[1] >> mx[2];
	for (i = 3; i <= n + 1; i++) {
		cin >> a[i] >> mx[i];
	}
	//动态规划
	for (int t = 1; t < n; t++) {
		for (i = 1; i <= n - t; i++) {
			j = i + t;
			int minn = inf;
			for (k = i; k <= j - 1; k++) {
				if ((dp[i][k] + dp[k + 1][j] + mx[i] * mx[k + 1] * mx[j + 1]) < minn) {
					minn = dp[i][k] + dp[k + 1][j] + mx[i] * mx[k + 1] * mx[j + 1];
					p[i][j] = k;
				}
			}
			dp[i][j] = minn;
		}
	}
	cout << dp[1][n] << endl;
	Print(1, n);
	return 0;
}
/*
3
10 100
100 5
5 50
*/
