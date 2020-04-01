//#include <stdio.h>
//#include <stdlib.h>
//
//// 二叉链式结构(普通二叉树)的实现(的遍历)
//// 插入和删除没法做 不像堆结点之间有要求 没有统一的操作
//// 遍历方式有4种
//// 前序/中序/后序 根据访问结点操作
//// 前序  根~~一条边上所有结点的左子树~~再是右子树的左子树 再是...
//// 中序  左子树~~根~~右子树 (要想访问根 先访问其左子树,再访问根,右子树的左子子树...
//// 后序 左子树~~右子树~~根(要想访问根, 先访问左子树 左子树完了 再访问右子树,要想访问右子树 先访问其左子树 再右子树...
//
//// 层序遍历 每一层都按照从左向右
//
///*中序+前序  唯一确定一棵树的结果
//中序+后序  唯一确定一棵树的结果
//
//
//*/
//
//// 二叉树的前序遍历
//* struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//};
//
//void preOrder(struct TreeNode* root, int* array, int* idx){
//
//
//}
//int getSize(struct TreeNode* root){
//
//}
///**
//* Note: The returned array must be malloced, assume caller calls free().
//*/
//int* preorderTraversal(struct TreeNode* root, int* returnSize){
//
//}
//
//// 二叉树的中序遍历 (左 根 右)
//void inOrder(struct TreeNode* root, int* array, int* idx){
//	if (root){
//		array[*idx] = root->val;
//		++(*idx);
//		inOrder(root->left, array, idx);
//		inOrder(root->right, array, idx);
//	}
//	
//
//}
//int getSize(struct TreeNode* root){
//
//}
///**
//* Note: The returned array must be malloced, assume caller calls free().
//*/
//int* inorderTraversal(struct TreeNode* root, int* returnSize){
//
//}
//
//// 判断二叉树中有无相同结点, 如果所有的结点值都相同, 返回1,
