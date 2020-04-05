typedef int Datatype;
typedef struct TreeNode {
	Datatype _data;
	struct TreeNode* _left;
	struct TreeNode* _right;
}Node;
// ¶þ²æÊ÷½áµã
typedef struct BinaryTree{
	Node* _root;
}BinaryTree;

Node* createTree(Datatype* array, int* pi);

Node* destoryTree(Node** root);

int getLeafSize(Node* root);

int* getSize(Node* root);

Node* find(Node* root, Datatype data);

void inOrder(Node* root);