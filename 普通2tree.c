#include <stdio.h>
#include <stdlib.h>

// ������ʽ�ṹ(��ͨ������)��ʵ��(�ı���)
// �����ɾ��û���� ����ѽ��֮����Ҫ�� û��ͳһ�Ĳ���
// ������ʽ��4��
// ǰ��/����/���� ���ݷ��ʸ�������(�����ʵ�ʱ��)
// ǰ��  ��~~һ���������н���������~~������������������ ����...
// ����  ������~~��~~������ (Ҫ����ʸ� �ȷ�����������,�ٷ��ʸ�,����������������...
// ���� ������~~������~~��(Ҫ����ʸ�, �ȷ��������� ���������� �ٷ���������,Ҫ����������� �ȷ����������� ��������...

// ������� ÿһ�㶼���մ�������
// һ��ǰ�� Ψһȷ��һ�����Ľ��
/*����+ǰ��  Ψһȷ��һ�����Ľ��
����+����  Ψһȷ��һ�����Ľ��


*/
// ÿһ������ڱ�����ʱ����root
// 1. ��������ǰ����� (�� �� ��
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
// idx (��ǰԪ���������е�λ��)
void preOrder(struct TreeNode* root, int* array, int* idx){
	if (root){
	// ������ָ������Ϊÿ��ָ�Ķ���ͬһ��λ�� ���������λ�õ�ֵ�ڱ���� ��ʱ�������ܷ���ֵ
		array[*idx] = root->val;// ���ʸ���ֵ
		++(*idx);
	// ���ߵ����������û���κζ��� �򷵻ص������ĸ���� ��ȥ�߽�����ֵ ���ն�Ҫ���ص������
		preOrder(root->left, array, idx);// ���� �����idx�൱��һ���� ���ǵ�ַ �ֲ����� �����±�
		preOrder(root->right, array, idx);// ����
	}
}
int getSize(struct TreeNode* root){
	// ����������Ϊ0
	if (root == NULL)
		return 0;
	// �������Ľ����� = �������Ľ����� + �ҽڵ������
	return getSize(root->left) + getSize(root->right) + 1;
}
// Note: The returned array must be malloced, assume caller calls free().```````````
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int num = getSize(root);
	*returnSize = num;
	int* ret = (int*)malloc(sizeof(int) * num);
	// ǰ�����
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

// 2. ��������������� (�� �� ��)
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

// 3. �ж϶�������������ͬ���, ������еĽ��ֵ����ͬ, ����1 (��ֵ������)
// ÿһ��ֵ�������ĸ�ֵ��һ����
// ǰ��������Ƿ�Ϊ��ֵ������
int isVaild1(struct TreeNode* root, int val){
	// ����ǿ��� 
	if (root == NULL)
		return 1;
	// ������ǿ���, �򿴸���ֵ�Ƿ���ڸ�����val �������� ��false
	if (root->val != val)
		return 0;
	// ���ǿ��� �Ҹ���ֵ����val, ��ȥ������������ֵ�Ƿ����val �������� ������Ϊtrue
	return isVaild1(root->left, val) && isVaild1(root->right, val);
}
// ����������Ƿ�ֵ������
int isVaild2(struct TreeNode* root, int val){
	if (root == NULL)
		return 1;
	return isVaild2(root->left, val) && root->val == val && isVaild2(root->right, val);
}
int isUnivalTree(struct TreeNode* root){
	// ǰ�к������ ��ÿһ��ֵ�Ƿ�͸�ֵ���
	if (root == NULL)
		return 1;
	return isVaild(root, root->val);
}

// 4. ���������������(�߶�) 
// �����ĸ߶�: max(�������߶�, �������߶�) + 1
int maxDepth(struct TreeNode* root){
	// ����/�ߵ��߶�Ϊ0 ��������û���� �ͷ��� 
	if (root == NULL)
		return 0;
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	// ���������� �򷵻��������߶�+1, ���������� �����������߶�+1
	return l > r ? l + 1 : r + 1;
}

// 5. ��ת������(��߽�㵽�ұ� ���н��侵��)
// �����Һ��ӽڵ���н���, ֻ������ַ�Ϳ���(ָ��ڵ��ֵ���н���)
// �Ƚ������ҽ�����ֵ, �ٽ������ӽ���ֵ
// �൱��ִ���Ե�ǰ���Ϊ��root�Ķ������ķ�ת �Ƚ������Һ��ӽڵ� ��ִ�����������ķ�ת 

void invert(struct TreeNode* root){
	if (root){
		//���ҽ�㽻��
		struct TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		// ��ת��������
		invert(root->left);
		invert(root->right);
	}
	// �վͲ���Ҫ������
}
struct TreeNode* invertTree(struct TreeNode* root){
	// ���ú���,�ٷ��ظ� ��Ϊ����û�н����� �����
	invert(root);
	return root;
}

// 6. ����������Ƿ���ͬ(�ṹ��ͬ, ��Ӧ����ֵ��ͬ)
// �õ�һ����� ���ж������Ƿ���ͬ, ���ж������������Ƿ�Ҳ����ͬ��  ����ͬλ�õ�ֵ�Ƿ���ͬ
// ��ÿһ���������ж� ֵ��ͬ�ҽṹ��ͬ ����ͬ
int isSameTree(struct TreeNode* p, struct TreeNode* q){
	// ͬʱ�ߵ���(Ҷ��) 1. �����ǿ���, 2, �ϲ�����ͬ, �²�ṹҲ��ͬ, ��ͬ
	if (p == NULL && q == NULL)
		return 1;
	// û��ͬʱ�ߵ���,��һ���ߵ���, �൱��һ������һ���������������� ����һ��������ͬλ�ý���������������
	if (p == NULL || q == NULL)
		return 0;

	// ֻ�е�ǰλ�ý����ͬ����������Ҳ��ȫ��ͬʱ, ����������ͬ(ǰ��)����1. �񷵻�0(����ͬ)
	return p->val == q->val // �������ĸ���ͬ/�����ͬ
	&& isSameTree(p->left, q->left)// ��������ͬ
	&& isSameTree(p->right, q->right);// ������Ҳ��ͬ
}


// 7. �Գƶ�����(���Ҿ���Գ�)
//  �����ж������� (��ǰ��������), ������ʱ�����������ϵ
int isSym(struct TreeNode* left, struct TreeNode* right){
	if (left == NULL && right == NULL)
		return 1;
	if (left == NULL || right == NULL)
		return 0;
	
	return left->val == right->val  // left, right ����ֵ��ͬ
	&& isSym(left->left, right->right) // left->left ��right->right �Գ�, 
	&& isSym(left->right, right->left);	// left->right��right->left Ҳ�Գ�
}
int isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return 1;
	if (isSym(root->left, root->right) == 1)
		return 1;
	return 0;
}

//8. �ж�һ�����Ƿ������һ����
// �Ӹ���ʼ�ж�: ��û��һ���ӽṹ�ʹ��жϵ�����ȫ��ͬ
// ���������Ƿ���� �ٿ��������Ƿ����t
int isSubtree(struct TreeNode* s, struct TreeNode* t){
	// ����һ����������t
	if (t == NULL)
		return 1;
	// �����������ǿյ���t
	if (s == NULL)
		return 0;
	// �����ж�s�Ƿ��t��ͬ
	if (isSameTree(s, t))
		return 1;
	// ���ж�s�������Ƿ��t��ͬ
	return isSubtree(s->left, t)
		|| isSubtree(s->right, t);
	
}

//9. ƽ�������(ÿ���������������߶Ȳ����1) ǿ��ÿ���ڵ�
// ��ȡ�߶�  �����һ��������������߶Ȳ����1 ����������ƽ�� (����ֻ�������)
// ��һ������������ƽ�� ��ݹ鷵�ص��ý��true
int getH(struct TreeNode* root){
	if (root == NULL)
		return 0;
	// ����������ĸ߶Ⱥ��ұ������ĸ߶�
	// �ĸ��߶ȴ� ����߶ȼ� 1 = ���ĸ߶�
	int l = getH(root->left);
	int r = getH(root->right);

	return l > r ? l + 1 : r + 1;
}
int  isBalance(struct TreeNode* root){
	// ����ǿ��� �϶��߶�ƽ��
	if (root == NULL)
		return 1;
	int l = getH(root->left);
	int r = getH(root->right);
	// �����߶�ֵ��С��2 && �����������ƽ�� && �ұ���������ƽ�� 
	return abs(l - r) < 2 && isBalance(root->left) && isBalance(root->right);
}


