#include <iostream>
#include <queue>
#include <valarray>
#include "tree.h"

void printTree(TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->val << std::endl;
        printTree(root->left);
        printTree(root->right);
    }
}

TreeNode* init_tree(std::vector<int> data) {
    if (data.empty()) {
        return nullptr;
    }
    auto* root = new TreeNode(data[0]);
    int i = 1;
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        if (i >= data.size()) {
            break;
        }
        auto* curr = queue.front();
        queue.pop();
        if (curr->left == nullptr) {
            curr->left = new TreeNode(data[i++]);
            queue.push(curr->left);
        }
        if (curr->right == nullptr) {
            curr->right = new TreeNode(data[i++]);
            queue.push(curr->right);
        }
    }
    return root;
}

void morris(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            std::cout << curr->val << std::endl;
            curr = curr->right;
        }
        else {
            TreeNode* pre = curr->left;
            while (pre->right != nullptr && pre->right != curr) {
                pre = pre->right;
            }
            if (pre->right == curr) {
                pre->right = nullptr;
                curr = curr->right;
            }
            else {
                std::cout << curr->val << std::endl;
                pre->right = curr;
                curr = curr->left;
            }

        }
    }
}

void dfs(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->val << std::endl;
    dfs(root->left);
    dfs(root->right);
}

void bfs(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        auto* curr = queue.front();
        queue.pop();
        std::cout << curr->val << std::endl;
        if (curr->left != nullptr) {
            queue.push(curr->left);
        }
        if (curr->right != nullptr) {
            queue.push(curr->right);
        }
    }
}