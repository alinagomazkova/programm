#include <iostream>
#include <algorithm>
#include <climits>

// ����������� ��������� ���� ��������� ������
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ����������� ������� ��� ������� ������������ ����� ����
int maxPathSumRecursive(TreeNode* root, int& maxSum) {
    // ���� ���� ���, �� ����� ���� ����� 0
    if (root == nullptr) {
        return 0;
    }

    // ������ ������������ ����� ���� ��� ������ ���������
    int leftSum = std::max(0, maxPathSumRecursive(root->left, maxSum));

    // ������ ������������ ����� ���� ��� ������� ���������
    int rightSum = std::max(0, maxPathSumRecursive(root->right, maxSum));
    
    // ���������� ������������ ����� ����
    maxSum = std::max(maxSum, root->val + leftSum + rightSum);
    
    // ���������� ������������ ����� ���� ��� ������� ����
    return root->val + std::max(leftSum, rightSum);
}

// ������� ��� ��������� ������������ ����� ���� � �������� ������
int maxPathSum(TreeNode* root) {
    // ������������� ������������ ����� ����
    int maxSum = INT_MIN;

    // ����� ����������� �������
    maxPathSumRecursive(root, maxSum);

    // ���������� ������������ ����� ����
    return maxSum;
}

// ������ ������������� �������
int main() {
    // �������� ��������� ������
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // ������ ������������ ����� ����
    int maxSum = maxPathSum(root);

    // ����� ����������
    std::cout << "������������ ����� ����: " << maxSum << std::endl;

    return 0;
}