typedef char Datatype;
typedef struct TreeNode {
	Datatype _data;
	struct TreeNode* _left;
	struct TreeNode* _right;
}Node;
// 二叉树结点
typedef struct BinaryTree{
	Node* _root;
}BinaryTree;

Node* createTree(Datatype* array, int* pi);

void inOrder(Node* root);

void destoryTree(Node** root);

int getLeafSize(Node* root);

int* getSize(Node* root);

Node* find(Node* root, Datatype data);


// 遍历的非递归
// 前中后序, 层序非递归
void preOrderNor(Node* root);
void inOrderNor(Node* root);
void postOrderNor(Node* root);

void leverOrder(Node* root);
// 判断一个数=树是不是完全二叉树
int isCompleteTree(Node* root);
