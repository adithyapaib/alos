#include <iostream>
#include <vector>

using namespace std;

// Function to implement 0/1 Knapsack
void knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout<<"Max weight : "<<dp[n][W];

    // Display the items selected
    int kp[10] = {0};
    cout <<endl<< "0/1 Matrix: ";
    int i = n, j = W;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            kp[i-1] = 1;
            j -= wt[i - 1];
        }
        i--;
    }
    for(int i =0;i<n;i++)
        cout<<kp[i]<<" ";
    
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity: ";
    cin >> W;

    vector<int> wt(n), val(n);
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    knapsack(W, wt, val, n);

    return 0;
}