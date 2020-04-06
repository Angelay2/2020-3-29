#include <stdio.h>
#include <stdlib.h>
#include "2tree.h"
#pragma warning(disable:4996)
/*
	节点个数 - 1 = 边 = n - 1
	完全二叉树包含满二叉树
	每个节点最多有两个孩子, 树的度不大于2 ---> 二叉树
	只要节点编号和满二叉树对应不起来 那就不是完全二叉树
	n0: 度为0的结点(叶子）  边为0  
n1: 度为1的结点         边为1 = n1
n2: 度为2的结点         2条边 = 2*n2
 二叉树的结点个数:  n0+n1+n2 = n（节点个数）  ==>  边个数 = n1 + 2*n2 = n - 1(边的个数等于结点个数-1）
		边个数：	n1+2*n2 = n-1
上述两式子化简：	n0 = n2+1

二叉树：树的度 <= 2 （每一个结点的子树不超过2个）
满二叉树：除过叶子， 其他节点度都为2， 也是完全二叉树
满二叉树结点个数 = 2^h - 1
所有二叉树中的节点总数 <= 2^h - 1 (h表示数的高度 = log(n + 1), 如果是一般二叉树， 高度为log(n + 1)向下取整）
完全二叉树： 除过最后一层， 剩余的结构一定时满二叉树， 最后一层从左像右中间无间隔
一棵树的最大高度是：n (每层结点为1个）

完全二叉树节点编号可以对应树中的位置关系（数组存放）
节点位置关系：  child = 2*parent + 1/2,（左孩子加1. 右孩子加2）
				parent = (child -1）/2
所有的非叶子节点都是存放在叶子节点的前面， 
顺序表存储完全二叉树：节省空间， 父子结点关系明确， 快速定位（存储一般二叉树， 浪费空间）
链表存储一般二叉树（不是线性表，只是链式结构，每一个结点有两个指向）

n1: 1----> 节点个数为偶数
    0----> 节点个数为奇数
储存结构：
	顺序结构：完全二叉树（没有空间浪费）
	链式结构： 其他二叉树
	二叉链：两个孩子节点
	三叉链： 两个孩子指针 + 父亲指针
堆：根结点是一个全部最值，每个子树的根结点在其子树的范围内是一个最值
操作：建堆：让数组中的元素的存储位置复合对的层次结构 从堆的最后一个非叶子结点来时进行向下调整。

完全二叉树: 从第一层~~倒数第二层结点个数总和为奇数
	如果结点总数为奇数, 最后一个结点个数必为偶数 --> n1 = 0
	如果结点总数为偶数, 最后一个结点个数必为奇数 --> n1 = 1

*/

// 链接关系（有两为二叉， 有三为三叉）
// 二叉链 （data left right）
//struct Node{
//	Node* left;
//	Node* right;
//	Datatype data;
//};
//// 三叉链 （data left right parent）
//struct Node{
//	Node* left;
//	Node* right;
//	Node* parent;
//	Datatype data;
//};

//  二叉树的创建
// 根据输入的先序遍历字符串 创建一个二叉树, 再对二叉树进行中序遍历, 输出中序遍历的结果,
// 输入 输出 
// 前序 abc##de#g##f### 首先pi 指向a字符
// 参数有 数组array和位置的指针pi(保证全局拿到的为同一个i 要么传全局变量 要么传指针)
// 最终返回根结点


Node* createTree(Datatype* array, int* pi){
	// 这个位置的字符不等于'#' 就去建立结点
	if (array[*pi] != '#'){
		// 先创建根结点 先申请空间 再传数据
		Node* root = (Node*)malloc(sizeof(Node));
		root->_data = array[*pi]; // 让根的数据等于字符

		//把位置向后移动一个位置 建立下一个结点
		// 建立左子树 左边应等于createTree()这个函数返回的结点
		// 创建完根左边一系列的左结点(bc,直到c->left = '#'时, return NULL)后, 再进入下一个递归
		// 进而创建右节点 c的左右结点都为'#', 证明创建完毕, 返回c结点 证明b的左子树创建完毕 到右子树
		++(*pi);
		root->_left = createTree(array, pi);

		// 向后移动一个位置, 建立右子树
		++(*pi);
		root->_right = createTree(array, pi);

		// 建好之后返回根
		return root;
	}
	// 如果给的就是一个'#' 直接返回NULL
	else
		return NULL;
}
void inOrder(Node* root){
	if (root){
		inOrder(root->_left);// 左子树
		printf("%c ", root->_data);// 根
		inOrder(root->_right);// 右子树
	}
}
// 要改变指针的地址 就要传二级指针
void destoryTree(Node** root){
	if (*root){
		// 释放结点 先要做解引用 才能拿到指针的值
		Node* cur = *root;
		// 递归销毁左右子树
		destoryTree(&cur->_left);
		destoryTree(&cur->_right);
		free(cur);
		// 把根置空 防止指针变为野指针
		*root = NULL;
	}
}
// 传一级指针不行 最终left和right data 都为随机值,且root不为空, 依旧指向之前的空间, 指向没变前z+'/,NU7HY6GF之后会造成非法访问 因为空间已经还给系统了.
// 并没有改指针的值 应该把root的值变为NULL, 正确的是把空间释放了,也要把指针置NULL,
void destoryTree2(Node* root){
	if (root){
		// 释放结点
		Node* cur = root;
		// 递归销毁左右子树
		destoryTree2(cur->_left);
		destoryTree2(cur->_right);
		free(cur);
		// 把根置空 防止指针变为野指针
		root = NULL;
	}1;
}
// 求叶子结点个数
// 1. 不需要遍历, 等于左右子树 叶子和(类似前序的遍历)
int getLeafSize(Node* root){
	// 空树叶子为0
	if (root == NULL)
		return 0;
	// 只有一个结点的话 也为叶子
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	// 不是只有一个根结点的话 则叶子个数等于左右子树的叶子结点和
	return getLeafSize(root->_left) + getLeafSize(root->_right);
}

// 2. 遍历二叉树, 统计叶子结点
void getLeafSize2(Node* root, int* num){
	if (root){
		// 每走到一个叶子 个数+1,
		if (root->_left == NULL && root->_left == NULL){
			++(*num);
			return;
		}
		// 如果不是叶子 继续向下走, 从左树遍历到右树
		getLeafSize2(root->_left, num);
		getLeafSize2(root->_right, num);
	}
}
// 求第K层的结点个数
//  求左右子树第 k-1 层的结点个数和
int getKSize(Node* root, int k){
	if (root == NULL)
		return 0;
	// 第一层只有一个结点
	if (k == 1)
		return 1;
	return getKSize(root->_left, k - 1) + getKSize(root->_right, k - 1);
}
// 查找结点是否在二叉树中. 如果是, 返回结点指针 查不到 返回空,
// 遍历
Node* find(Node* root, Datatype data){
	Node* ret;
	// 任意一种遍历 每次和当前结点进行比较 
	if (root == NULL)
		return NULL;
	if (root->_data == data)
		return root;
	// 如果找到就直接返回, 不用再继续查找下去
	// 用ret 来保存找得到的地址,
	ret = find(root->_left, data);
	if (ret != NULL)
		return ret;
	ret = find(root->_right, data);
	if (ret != NULL)
		return ret;
	return NULL;
}

int main1(){
	char array[101] = "abc##de#g##f###";
	int idx = 0;
	int num = 0;
	Node* root = createTree(array, &idx);
	inOrder(root);
	printf("\n");

	
	printf("%d\n", getLeafSize(root));// 有3个叶子结点
	getLeafSize2(root, &num);
	printf("%d\n", num);// 有3个叶子结点

	destoryTree(&root);
	//destoryTree2(root);

	system("pause");
	return 0;
}
int main(){
	char str[] = {"abc##de#g##f###"};
	int i = 0;
	Node* ret;
	Node* root = createTree(str, &i);

	printf("%d\n", getKSize(root, 3));
	printf("%d\n", getKSize(root, 1));

	ret = find(root, 'g');
	ret = find(root, 'd');
	ret = find(root, 'b');

	system("pause");
	return 0;
}