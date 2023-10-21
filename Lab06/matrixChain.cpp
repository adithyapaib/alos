#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printOptimalOrder(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i + 1;
        return;
    }
    
    cout << "(";
    printOptimalOrder(s, i, s[i][j]);
    printOptimalOrder(s, s[i][j] + 1, j);
    cout << ")";
}

void findOptimalOrder(vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    
    cout << "Optimal Order: ";
    printOptimalOrder(s, 0, n - 1);
    cout << "\nMinimum Number of Multiplications: " << dp[0][n - 1] << endl;
}

int main() {
    vector<int> dimensions = {40, 20, 30, 10, 30};
    
    findOptimalOrder(dimensions);
    
    return 0;
}
