typedef char Datatype;
typedef struct TreeNode {
	Datatype _data;
	struct TreeNode* _left;
	struct TreeNode* _right;
}Node;
// ���������
typedef struct BinaryTree{
	Node* _root;
}BinaryTree;

Node* createTree(Datatype* array, int* pi);

void inOrder(Node* root);

void destoryTree(Node** root);

int getLeafSize(Node* root);

int* getSize(Node* root);

Node* find(Node* root, Datatype data);


// �����ķǵݹ�
// ǰ�к���, ����ǵݹ�
void preOrderNor(Node* root);
void inOrderNor(Node* root);
void postOrderNor(Node* root);

void leverOrder(Node* root);
// �ж�һ����=���ǲ�����ȫ������
int isCompleteTree(Node* root);
