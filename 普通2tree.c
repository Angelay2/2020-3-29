#include <stdio.h>
#include <stdlib.h>

// 二叉链式结构(普通二叉树)的实现(的遍历)
// 插入和删除没法做 不像堆结点之间有要求 没有统一的操作
// 遍历方式有4种
// 前序/中序/后序 根据访问根结点操作(根访问的时机)
// 前序  根~~一条边上所有结点的左子树~~再是右子树的左子树 再是...
// 中序  左子树~~根~~右子树 (要想访问根 先访问其左子树,再访问根,右子树的左子子树...
// 后序 左子树~~右子树~~根(要想访问根, 先访问左子树 左子树完了 再访问右子树,要想访问右子树 先访问其左子树 再右子树...

// 层序遍历 每一层都按照从左向右
// 一个前序 唯一确定一棵树的结果
/*中序+前序  唯一确定一棵树的结果
中序+后序  唯一确定一棵树的结果


*/
// 每一个结点在遍历的时候都是root
// 1. 二叉树的前序遍历 (根 左 右
typedef struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}Node;

Node* createNode(int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = data;
	node->left = node->right = NULL;
	return node;
}
// idx (当前元素在数组中的位置)
void preOrder(struct TreeNode* root, int* array, int* idx){
	if (root){
	// 传索引指针是因为每次指的都是同一个位置 这三个这个位置的值在变而已 临时变量不能返回值
		array[*idx] = root->val;// 访问根的值
		++(*idx);
	// 若走到子树的左边没有任何东西 则返回到子树的根结点 再去走结点的右值 最终都要返回到父结点
		preOrder(root->left, array, idx);// 根左 后面的idx相当于一个数 不是地址 局部变量 数组下标
		preOrder(root->right, array, idx);// 根右
	}
}
int getSize(struct TreeNode* root){
	// 空树结点个数为0
	if (root == NULL)
		return 0;
	// 整棵树的结点个数 = 左子树的结点个数 + 右节点结点个数
	return getSize(root->left) + getSize(root->right) + 1;
}
// Note: The returned array must be malloced, assume caller calls free().```````````
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int num = getSize(root);
	*returnSize = num;
	int* ret = (int*)malloc(sizeof(int) * num);
	// 前序遍历
	int idx = 0;
	preOrder(root, ret, &idx);
	return ret;
}
int main1(){
	Node* node = createNode(1);
	node->right = createNode(2);
	node->right->left = createNode(3);

	int* array = (int*)malloc(sizeof(int) * 3);
	int idx = 0;
	preOrder(node, array, &idx);

	for (int i = 0; i < 3; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}

// 2. 二叉树的中序遍历 (左 根 右)
void inOrder(struct TreeNode* root, int* array, int* idx){
	if (root){
		inOrder(root->left, array, idx);
		array[*idx] = root->val;
		++(*idx);
		inOrder(root->right, array, idx);
	}
	

}
int getSize(struct TreeNode* root){
	if (root == NULL)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}

// Note: The returned array must be malloced, assume caller calls free().
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int num = getSize(root);
	*returnSize = num;
	int* ret = (int*)malloc(sizeof(int)* num);
	int idx = 0;
	inOrder(root, ret, &idx);
	return ret;
}

// 3. 判断二叉树中有无相同结点, 如果所有的结点值都相同, 返回1 (单值二叉树)
// 每一个值都和他的根值是一样的
// 前序遍历看是否为单值二叉树
int isVaild1(struct TreeNode* root, int val){
	// 如果是空树 
	if (root == NULL)
		return 1;
	// 如果不是空树, 则看根的值是否等于给定的val 若不等于 则false
	if (root->val != val)
		return 0;
	// 不是空树 且根的值等于val, 再去看左右子树的值是否等于val 若都等于 则最终为true
	return isVaild1(root->left, val) && isVaild1(root->right, val);
}
// 中序遍历看是否单值二叉树
int isVaild2(struct TreeNode* root, int val){
	if (root == NULL)
		return 1;
	return isVaild2(root->left, val) && root->val == val && isVaild2(root->right, val);
}
int isUnivalTree(struct TreeNode* root){
	// 前中后序遍历 看每一个值是否和根值相等
	if (root == NULL)
		return 1;
	return isVaild(root, root->val);
}

// 4. 求二叉树的最大深度(高度) 
// 求树的高度: max(左子树高度, 右子树高度) + 1
int maxDepth(struct TreeNode* root){
	// 空树/走到高度为0 子树后面没有了 就返回 
	if (root == NULL)
		return 0;
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	// 若左子树大 则返回左子树高度+1, 若右子树大 返回右子树高度+1
	return l > r ? l + 1 : r + 1;
}

// 5. 翻转二叉树(左边结点到右边 所有结点变镜像)
// 把左右孩子节点进行交换, 只交换地址就可以(指向节点的值进行交换)
// 先交换左右结点根的值, 再交换孩子结点的值
// 相当于执行以当前结点为根root的二叉树的翻转 先交换左右孩子节点 再执行左右子树的翻转 

void invert(struct TreeNode* root){
	if (root){
		//左右结点交换
		struct TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		// 翻转左右子树
		invert(root->left);
		invert(root->right);
	}
	// 空就不需要交换了
}
struct TreeNode* invertTree(struct TreeNode* root){
	// 调用函数,再返回根 因为根是没有交换的 不变的
	invert(root);
	return root;
}

// 6. 检查两棵树是否相同(结构相同, 对应结点的值相同)
// 拿到一个结点 先判断内容是否相同, 再判断其左右子树是否也是相同的  看相同位置的值是否相同
// 对每一个结点进行判断 值相同且结构相同 则相同
int isSameTree(struct TreeNode* p, struct TreeNode* q){
	// 同时走到空(叶子) 1. 本来是空树, 2, 上层结点相同, 下层结构也相同, 相同
	if (p == NULL && q == NULL)
		return 1;
	// 没有同时走到空,有一个走到空, 相当于一棵树的一个结点的左子树存在 而另一棵树的相同位置结点的左子树不存在
	if (p == NULL || q == NULL)
		return 0;

	// 只有当前位置结点相同且左右子树也完全相同时, 整棵树才相同(前序)返回1. 否返回0(不相同)
	return p->val == q->val // 两个树的根相同/结点相同
	&& isSameTree(p->left, q->left)// 左子树相同
	&& isSameTree(p->right, q->right);// 右子树也相同
}


// 7. 对称二叉树(自我镜像对称)
//  首先判断两个点 (当前这两个点), 接下来时下面的子树关系
int isSym(struct TreeNode* left, struct TreeNode* right){
	if (left == NULL && right == NULL)
		return 1;
	if (left == NULL || right == NULL)
		return 0;
	
	return left->val == right->val  // left, right 结点的值相同
	&& isSym(left->left, right->right) // left->left 和right->right 对称, 
	&& isSym(left->right, right->left);	// left->right和right->left 也对称
}
int isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return 1;
	if (isSym(root->left, root->right) == 1)
		return 1;
	return 0;
}

//8. 判断一棵树是否包含另一棵树
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

//9. 平衡二叉树(每个结点的左右子树高度差不超过1) 强调每个节点
// 获取高度  如果有一个结点左右子树高度差大于1 则整棵树不平衡 (不是只看根结点)
// 若一个结点的两子树平衡 则递归返回到该结点true
int getH(struct TreeNode* root){
	if (root == NULL)
		return 0;
	// 求左边子树的高度和右边子树的高度
	// 哪个高度大 给其高度加 1 = 树的高度
	int l = getH(root->left);
	int r = getH(root->right);

	return l > r ? l + 1 : r + 1;
}
int  isBalance(struct TreeNode* root){
	// 如果是空树 肯定高度平衡
	if (root == NULL)
		return 1;
	int l = getH(root->left);
	int r = getH(root->right);
	// 两数高度值差小于2 && 左边所有子树平衡 && 右边所有子树平衡 
	return abs(l - r) < 2 && isBalance(root->left) && isBalance(root->right);
}


