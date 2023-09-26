#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

constexpr auto Inf = numeric_limits<ll>::max();

int n;
vii mats;
vvl dp;

ll solve(int b, int e) {
	if (e - 1 == b) {
		return 0;
	}

	if (Inf == dp[b][e - 1]) {
		for (auto k = b; k + 1 < e; ++k) {
			dp[b][e - 1] = min(dp[b][e - 1],
				solve(b, k + 1) + solve(k + 1, e) + mats[b].first * mats[k].second * mats[e - 1].second);
		}
	}

	return dp[b][e - 1];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;

	mats = vii(n);
	for (auto&& [a, b] : mats) {
		cin >> a >> b;
	}

	dp = vvl(n, vl(n, Inf));

	cout << solve(0, n);

	return 0;
}