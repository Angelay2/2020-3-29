#include "2tree.h"
#include "stack.h"

// 非递归遍历 相当于栈的入栈和出栈 
// 1. 访问即入栈, 入栈之后访问其左子树
// 2. 返回父结点即出栈 从而访问父结点的右子树

// 前序遍历(根 左 右)
// 访问完时, 栈里=0, cur 也等于0
// 从栈里弹出的结点意味着 该结点以及他的左子树已访问完, 需要访问其右子树, 
// 要访问其右子树 再将右节点入栈
// 1. 遍历当前结点的最左路径
// 2. 遍历最后访问的结点的右子树
void preOrderNor(Node* root){

}

// 当前结点先压栈, 不能访问, 
// 让左边访问完(走到NULL)后 再打印根结点, 后再右子树
void inOrderNor(Node* root){
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	while (cur || stackEmpty(&st) != 1){
		// 从当前根的位置, 一直访问完最左边的路径
		while (cur){
			// 先将当前结点压栈,访问左子树
			stackPush(&st, cur);
			cur = cur->_left;
		}
		// 获取栈顶元素
		top = stackTop(&st);
		stackPop(&st);
		// 打印当前结点
		printf("%c", top->_data);
		// 然后再访问右子树
		cur = cur->_right;
	}
}
void postOrderNor(Node* root){
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	while (cur || stackEmpty(&st) != 1){
		// 从当前根的位置, 一直访问完最左边的路径
		while (cur){

		}
}

void leverOrder(Node* root){

}

// 判断一个数=树是不是完全二叉树
int isCompleteTree(Node* root){

}