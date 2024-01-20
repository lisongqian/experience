
# 树

![6lmcjx.jpg](./img/6lmcjx.jpg)

## 一个中心

树的遍历。

除了用递归实现树的前中后序遍历，还要掌握迭代遍历树。可以使用三色标记法，即：
- 用白色表示尚未访问
- 灰色表示尚未完全访问子节点
- 黑色表示子节点全部访问

树的遍历可以模仿上述思想：

- 颜色表示节点状态，新节点为白色，已访问的节点为灰色。
- 若遇到白色节点，将其标记为灰色，然后将右中左节点依次入栈（前序遍历）。
- 若遇到灰色节点，则将节点值输出。

### Morris 遍历

如果需要使用 $O(1)$ 空间遍历一棵二叉树，那么就要使用 Morris 遍历。

思路：
1. 初始化`root`节点为`curr`节点。
2. 若`curr`不为`NULL`，检查`curr`是否有左节点。
3. 若`curr`没有左节点，输出`curr`并且更新`curr`指向当前节点的右节点。
4. 否则，让`curr`成为左子树中最右侧节点的右节点。
5. 更新`curr`指向左节点。


## 三种题型

### 1. 搜索类
### 2. 构建类
### 3. 修改类

## 四个重要概念

### 1. 二叉搜索树
### 2. 完全二叉树
### 3. 路径
### 4. 距离

## 七个技巧

### 1. dfs(root)
### 2. 单双递归
### 3. 前后遍历
### 4. 虚拟节点
### 5. 边界
### 6. 参数扩展法
### 7. 返回元组/列表

## 题目推荐

1. [LCR 175. 计算二叉树的深度](https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/description/)
2. [LCR 153. 二叉树中和为目标值的路径](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/description/)
3. [0101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/description/)
4. [0226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/description/)
5. [543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/description/)
6. [662. 二叉树最大宽度](https://leetcode-cn.com/problems/maximum-width-of-binary-tree/description/)
7. [971. 翻转二叉树以匹配先序遍历](https://leetcode-cn.com/problems/flip-binary-tree-to-match-preorder-traversal/description/)
8. [987. 二叉树的垂序遍历](https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/description/)
9. [863. 二叉树中所有距离为 K 的结点](https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/description/)
10. [面试题 04.06. 后继者](https://leetcode-cn.com/problems/successor-lcci/description/)