#include <stdio.h>
#include <stdlib.h>

// 二叉链式结构(普通二叉树)的实现(的遍历)
// 插入和删除没法做 不像堆结点之间有要求 没有统一的操作
// 遍历方式有4种
// 前序/中序/后序 根据访问结点操作
// 前序  根~~一条边上所有结点的左子树~~再是右子树的左子树 再是...
// 中序  左子树~~根~~右子树 (要想访问根 先访问其左子树,再访问根,右子树的左子子树...
// 后序 左子树~~右子树~~根(要想访问根, 先访问左子树 左子树完了 再访问右子树,要想访问右子树 先访问其左子树 再右子树...

// 层序遍历 每一层都按照从左向右
// 一个前序 唯一确定一棵树的结果
/*中序+前序  唯一确定一棵树的结果
中序+后序  唯一确定一棵树的结果


*/

// 二叉树的前序遍历
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void preOrder(struct TreeNode* root, int* array, int* idx){


}
int getSize(struct TreeNode* root){

}
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* preorderTraversal(struct TreeNode* root, int* returnSize){

}

// 二叉树的中序遍历 (左 根 右)
void inOrder(struct TreeNode* root, int* array, int* idx){
	if (root){
		array[*idx] = root->val;
		++(*idx);
		inOrder(root->left, array, idx);
		inOrder(root->right, array, idx);
	}
	

}
int getSize(struct TreeNode* root){
	if (root){

	}
}
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* inorderTraversal(struct TreeNode* root, int* returnSize){

}

// 3. 判断二叉树中有无相同结点, 如果所有的结点值都相同, 返回1,



// 4. 翻转二叉树(左边结点到右边 所有结点变镜像)
void invert(struct TreeNode* root){
	if (root){
		//左右结点交换
		struct TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		// 翻转子树
		invert(root->left);
		invert(root->right);
	}
}
struct TreeNode* invertTree(struct TreeNode* root){
	invert(root);
	return root;
}

// 5. 检查两棵树是否相同(结构相同, 对应结点的值相同)
// 对每一个结点进行判断 值相同且结构相同 则相同
int isSameTree(struct TreeNode* p, struct TreeNode* q){
	// 同时走到空
	if (p == NULL && q = NULL)
		return 1;
	// 没有同时走到空
	if (p = NULL || q = NULL)
		return 0;
	// 只有当前位置相同且子树也完全相同时, 整棵树才相同(前序)
	return p->val == q->val // 两个数的根相同
	&& isSameTree(p->left, q->left)// 所有的左子树相同
	&& isSameTree(p->right, q->right);// 遨游的右子树也相同
}
// 对称二叉树
// 
int isSym(struct TreeNode* left, struct TreeNode* right){
	if (left == NULL && right == NULL)
		return 1;
	if (left == NULL || right == NULL)
		return 0;
	
	return left->val == right->val  // left, right 结点的值相同
	&& isSym(left->left, right->right) // left->left 和right->right 对称, 
	&& isSym(left->right, right->left);	// left->right和right->left 也对称
}
int 

// 判断一棵树是否包含另一棵树
// 从根开始判断: 有没有一个子结构和待判断的树完全相同
// 看左子树是否包含 再看右子树是否包含t
int isSubtree(struct TreeNode* s, struct TreeNode* t){
	// 任意一棵树都包含t
	if (t == NULL)
		return 1;
	// 空树不包含非空的树t
	if (s == NULL)
		return 0;
	// 首先判断s是否和t相同
	if (isSameTree(s, t))
		return 1;
	// 再判断s的子树是否和t相同
	return isSubtree(s->left, t)
		|| isSubtree(s->right, t);
	
}

// 平衡二叉树(每个结点的左右子树高度差不超过1)
// 获取高度
int getH(struct TreeNode* root){
	if (root == NULL)
	// 求左边子树的高度和右边子树的高度
	// 哪个高度大 给其高度加 1 = 树的高度
	int 
}
int  isBalance(struct TreeNode* root){

}

// 二叉树的创建
// 根据输入的先序遍历字符串 创建一个二叉树, 在对二叉树进行中序遍历, 输出中序遍历的结果,

