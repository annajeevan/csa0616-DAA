#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int freq[100];

    for (int i = 0; i < n; i++)
        cin >> freq[i];

    int dp[100][100] = {};

    for (int i = 0; i < n; i++)
        dp[i][i] = freq[i];

    for (int length = 2;
         length <= n;
         length++) {

        for (int i = 0;
             i + length <= n;
             i++) {

            int j = i + length - 1;

            int sum = 0;

            for (int k = i; k <= j; k++)
                sum += freq[k];

            dp[i][j] = 1000000000;

            for (int root = i;
                 root <= j;
                 root++) {

                int left = 0;
                int right = 0;

                if (root > i)
                    left = dp[i][root - 1];

                if (root < j)
                    right = dp[root + 1][j];

                dp[i][j] =
                    min(
                        dp[i][j],
                        left + right + sum
                    );
            }
        }
    }

    cout << "Optimal BST cost = "
         << dp[0][n - 1];

    return 0;
}
