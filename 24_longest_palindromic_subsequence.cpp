#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cin >> s;

    int n = s.length();

    int dp[1000][1000] = {};

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int length = 2;
         length <= n;
         length++) {

        for (int i = 0;
             i + length <= n;
             i++) {

            int j = i + length - 1;

            if (s[i] == s[j]) {

                if (length == 2)
                    dp[i][j] = 2;
                else
                    dp[i][j] =
                        dp[i + 1][j - 1] + 2;

            } else {

                dp[i][j] =
                    max(
                        dp[i + 1][j],
                        dp[i][j - 1]
                    );
            }
        }
    }

    cout << "Longest Palindromic Subsequence Length = "
         << dp[0][n - 1];

    return 0;
}
