#include <stdio.h>
#include <stdlib.h>

// ������ʽ�ṹ(��ͨ������)��ʵ��(�ı���)
// �����ɾ��û���� ����ѽ��֮����Ҫ�� û��ͳһ�Ĳ���
// ������ʽ��4��
// ǰ��/����/���� ���ݷ��ʽ�����
// ǰ��  ��~~һ���������н���������~~������������������ ����...
// ����  ������~~��~~������ (Ҫ����ʸ� �ȷ�����������,�ٷ��ʸ�,����������������...
// ���� ������~~������~~��(Ҫ����ʸ�, �ȷ��������� ���������� �ٷ���������,Ҫ����������� �ȷ����������� ��������...

// ������� ÿһ�㶼���մ�������
// һ��ǰ�� Ψһȷ��һ�����Ľ��
/*����+ǰ��  Ψһȷ��һ�����Ľ��
����+����  Ψһȷ��һ�����Ľ��


*/

// ��������ǰ�����
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

// ��������������� (�� �� ��)
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

// 3. �ж϶�������������ͬ���, ������еĽ��ֵ����ͬ, ����1,



// 4. ��ת������(��߽�㵽�ұ� ���н��侵��)
void invert(struct TreeNode* root){
	if (root){
		//���ҽ�㽻��
		struct TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		// ��ת����
		invert(root->left);
		invert(root->right);
	}
}
struct TreeNode* invertTree(struct TreeNode* root){
	invert(root);
	return root;
}

// 5. ����������Ƿ���ͬ(�ṹ��ͬ, ��Ӧ����ֵ��ͬ)
// ��ÿһ���������ж� ֵ��ͬ�ҽṹ��ͬ ����ͬ
int isSameTree(struct TreeNode* p, struct TreeNode* q){
	// ͬʱ�ߵ���
	if (p == NULL && q = NULL)
		return 1;
	// û��ͬʱ�ߵ���
	if (p = NULL || q = NULL)
		return 0;
	// ֻ�е�ǰλ����ͬ������Ҳ��ȫ��ͬʱ, ����������ͬ(ǰ��)
	return p->val == q->val // �������ĸ���ͬ
	&& isSameTree(p->left, q->left)// ���е���������ͬ
	&& isSameTree(p->right, q->right);// ���ε�������Ҳ��ͬ
}
// �Գƶ�����
// 
int isSym(struct TreeNode* left, struct TreeNode* right){
	if (left == NULL && right == NULL)
		return 1;
	if (left == NULL || right == NULL)
		return 0;
	
	return left->val == right->val  // left, right ����ֵ��ͬ
	&& isSym(left->left, right->right) // left->left ��right->right �Գ�, 
	&& isSym(left->right, right->left);	// left->right��right->left Ҳ�Գ�
}
int 

// �ж�һ�����Ƿ������һ����
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

// ƽ�������(ÿ���������������߶Ȳ����1)
// ��ȡ�߶�
int getH(struct TreeNode* root){
	if (root == NULL)
	// ����������ĸ߶Ⱥ��ұ������ĸ߶�
	// �ĸ��߶ȴ� ����߶ȼ� 1 = ���ĸ߶�
	int 
}
int  isBalance(struct TreeNode* root){

}

// �������Ĵ���
// �����������������ַ��� ����һ��������, �ڶԶ����������������, �����������Ľ��,

