#include <iostream>
using namespace std;

int n;
int cost[12][12];
int dp[1 << 12][12];

int tsp(int mask, int pos) {

    if (mask == (1 << n) - 1)
        return cost[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = 1000000000;

    for (int city = 0; city < n; city++) {

        if ((mask & (1 << city)) == 0) {

            ans = min(
                ans,
                cost[pos][city] +
                tsp(mask | (1 << city), city)
            );
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    cout << "Minimum tour cost = "
         << tsp(1, 0);

    return 0;
}
