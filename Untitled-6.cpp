#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    // Создаем двумерный массив dp
    std::vector<std::vector<int>> dp(3, std::vector<int>(n, 0));

    for (int i = 1; i <= 2; ++i) {
        int maxDiff = -prices[0];
        for (int j = 1; j < n; ++j) {
            dp[i][j] = std::max(dp[i][j - 1], prices[j] + maxDiff);
            maxDiff = std::max(maxDiff, dp[i - 1][j] - prices[j]);
        }
    }

    return dp[2][n - 1];
}

int main() {
    // Пример использования
    std::vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int result = maxProfit(prices);

    std::cout << "Максимальная прибыль: " << result << std::endl;

    return 0;
}