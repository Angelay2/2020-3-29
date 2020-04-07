#include "2tree.h"
#include "stack.h"
#include "common.h"


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
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	// 当栈第一次为空时, 根左边的所有子树都访问完了,此时top = root, 出栈后, 栈为空, 然后根据栈顶访问其右子树, 但cur不为NULL,继续循环 
	// 当cur为NULL, 栈也为空时, 访问完
	while (cur || stackEmpty(&st) != 1){
		// 从当前根的位置, 一直访问完最左边的路径
		// cur为空时, 左边路径已访问完, 去获得其父结点(父结点出栈) 访问右节点,
		// 若右节点不为空, 将其作为新的父结点 打印 压栈, 再去访问他的左节点, 若左节点为空, 出栈父结点
		while (cur){
			// 先打印当前值(root)
			printf("%d ", cur->_data);
			// 压栈是为了后期出栈时拿到其右子树
			stackPush(&st, cur);
			cur = cur->_left;
		}

		// 获取栈顶元素 访问完之后删除掉
		top = stackTop(&st);
		stackPop(&st);

		// 访问右子树
		cur = top->_right;
	}
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