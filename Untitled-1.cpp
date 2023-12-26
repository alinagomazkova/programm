#include <iostream>
#include <algorithm>
#include <climits>

// Определение структуры узла бинарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Рекурсивная функция для расчета максимальной суммы пути
int maxPathSumRecursive(TreeNode* root, int& maxSum) {
    // Если узла нет, то сумма пути равна 0
    if (root == nullptr) {
        return 0;
    }

    // Расчет максимальной суммы пути для левого поддерева
    int leftSum = std::max(0, maxPathSumRecursive(root->left, maxSum));

    // Расчет максимальной суммы пути для правого поддерева
    int rightSum = std::max(0, maxPathSumRecursive(root->right, maxSum));
    
    // Обновление максимальной суммы пути
    maxSum = std::max(maxSum, root->val + leftSum + rightSum);
    
    // Возвращаем максимальную сумму пути для данного узла
    return root->val + std::max(leftSum, rightSum);
}

// Функция для получения максимальной суммы пути в бинарном дереве
int maxPathSum(TreeNode* root) {
    // Инициализация максимальной суммы пути
    int maxSum = INT_MIN;

    // Вызов рекурсивной функции
    maxPathSumRecursive(root, maxSum);

    // Возвращаем максимальную сумму пути
    return maxSum;
}

// Пример использования функции
int main() {
    // Создание бинарного дерева
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Расчет максимальной суммы пути
    int maxSum = maxPathSum(root);

    // Вывод результата
    std::cout << "Максимальная сумма пути: " << maxSum << std::endl;

    return 0;
}