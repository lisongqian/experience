//
// Created by lisongqian on 2024/1/18.
//

#ifndef EXPERIENCE_TREE_H
#define EXPERIENCE_TREE_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* init_tree(std::vector<int> data);
void printTree(TreeNode* root);
void morris(TreeNode* root);

#endif //EXPERIENCE_TREE_H
