#include <stdio.h>
#include <stdlib.h>
#include "2tree.h"
#pragma warning(disable:4996)
/*
	�ڵ���� - 1 = �� = n - 1
	��ȫ������������������
	ÿ���ڵ��������������, ���ĶȲ�����2 ---> ������
	ֻҪ�ڵ��ź�����������Ӧ������ �ǾͲ�����ȫ������
	n0: ��Ϊ0�Ľ��(Ҷ�ӣ�  ��Ϊ0  
n1: ��Ϊ1�Ľ��         ��Ϊ1 = n1
n2: ��Ϊ2�Ľ��         2���� = 2*n2
 �������Ľ�����:  n0+n1+n2 = n���ڵ������  ==>  �߸��� = n1 + 2*n2 = n - 1(�ߵĸ������ڽ�����-1��
		�߸�����	n1+2*n2 = n-1
������ʽ�ӻ���	n0 = n2+1

�����������Ķ� <= 2 ��ÿһ����������������2����
��������������Ҷ�ӣ� �����ڵ�ȶ�Ϊ2�� Ҳ����ȫ������
�������������� = 2^h - 1
���ж������еĽڵ����� <= 2^h - 1 (h��ʾ���ĸ߶� = log(n + 1), �����һ��������� �߶�Ϊlog(n + 1)����ȡ����
��ȫ�������� �������һ�㣬 ʣ��Ľṹһ��ʱ���������� ���һ����������м��޼��
һ���������߶��ǣ�n (ÿ����Ϊ1����

��ȫ�������ڵ��ſ��Զ�Ӧ���е�λ�ù�ϵ�������ţ�
�ڵ�λ�ù�ϵ��  child = 2*parent + 1/2,�����Ӽ�1. �Һ��Ӽ�2��
				parent = (child -1��/2
���еķ�Ҷ�ӽڵ㶼�Ǵ����Ҷ�ӽڵ��ǰ�棬 
˳���洢��ȫ����������ʡ�ռ䣬 ���ӽ���ϵ��ȷ�� ���ٶ�λ���洢һ��������� �˷ѿռ䣩
����洢һ����������������Ա�ֻ����ʽ�ṹ��ÿһ�����������ָ��

n1: 1----> �ڵ����Ϊż��
    0----> �ڵ����Ϊ����
����ṹ��
	˳��ṹ����ȫ��������û�пռ��˷ѣ�
	��ʽ�ṹ�� ����������
	���������������ӽڵ�
	�������� ��������ָ�� + ����ָ��
�ѣ��������һ��ȫ����ֵ��ÿ�������ĸ�������������ķ�Χ����һ����ֵ
���������ѣ��������е�Ԫ�صĴ洢λ�ø��϶ԵĲ�νṹ �Ӷѵ����һ����Ҷ�ӽ����ʱ�������µ�����

��ȫ������: �ӵ�һ��~~�����ڶ���������ܺ�Ϊ����
	����������Ϊ����, ���һ����������Ϊż�� --> n1 = 0
	����������Ϊż��, ���һ����������Ϊ���� --> n1 = 1

*/

// ���ӹ�ϵ������Ϊ���棬 ����Ϊ���棩
// ������ ��data left right��
//struct Node{
//	Node* left;
//	Node* right;
//	Datatype data;
//};
//// ������ ��data left right parent��
//struct Node{
//	Node* left;
//	Node* right;
//	Node* parent;
//	Datatype data;
//};

//  �������Ĵ���
// �����������������ַ��� ����һ��������, �ٶԶ����������������, �����������Ľ��,
// ���� ��� 
// ǰ�� abc##de#g##f### ����pi ָ��a�ַ�
// ������ ����array��λ�õ�ָ��pi(��֤ȫ���õ���Ϊͬһ��i Ҫô��ȫ�ֱ��� Ҫô��ָ��)
// ���շ��ظ����


Node* createTree(Datatype* array, int* pi){
	// ���λ�õ��ַ�������'#' ��ȥ�������
	if (array[*pi] != '#'){
		// �ȴ�������� ������ռ� �ٴ�����
		Node* root = (Node*)malloc(sizeof(Node));
		root->_data = array[*pi]; // �ø������ݵ����ַ�

		//��λ������ƶ�һ��λ�� ������һ�����
		// ���������� ���Ӧ����createTree()����������صĽ��
		// ����������һϵ�е�����(bc,ֱ��c->left = '#'ʱ, return NULL)��, �ٽ�����һ���ݹ�
		// ���������ҽڵ� c�����ҽ�㶼Ϊ'#', ֤���������, ����c��� ֤��b��������������� ��������
		++(*pi);
		root->_left = createTree(array, pi);

		// ����ƶ�һ��λ��, ����������
		++(*pi);
		root->_right = createTree(array, pi);

		// ����֮�󷵻ظ�
		return root;
	}
	// ������ľ���һ��'#' ֱ�ӷ���NULL
	else
		return NULL;
}
void inOrder(Node* root){
	if (root){
		inOrder(root->_left);// ������
		printf("%c ", root->_data);// ��
		inOrder(root->_right);// ������
	}
}
// Ҫ�ı�ָ��ĵ�ַ ��Ҫ������ָ��
void destoryTree(Node** root){
	if (*root){
		// �ͷŽ�� ��Ҫ�������� �����õ�ָ���ֵ
		Node* cur = *root;
		// �ݹ�������������
		destoryTree(&cur->_left);
		destoryTree(&cur->_right);
		free(cur);
		// �Ѹ��ÿ� ��ָֹ���ΪҰָ��
		*root = NULL;
	}
}
// ��һ��ָ�벻�� ����left��right data ��Ϊ���ֵ,��root��Ϊ��, ����ָ��֮ǰ�Ŀռ�, ָ��û��ǰz+'/,NU7HY6GF֮�����ɷǷ����� ��Ϊ�ռ��Ѿ�����ϵͳ��.
// ��û�и�ָ���ֵ Ӧ�ð�root��ֵ��ΪNULL, ��ȷ���ǰѿռ��ͷ���,ҲҪ��ָ����NULL,
void destoryTree2(Node* root){
	if (root){
		// �ͷŽ��
		Node* cur = root;
		// �ݹ�������������
		destoryTree2(cur->_left);
		destoryTree2(cur->_right);
		free(cur);
		// �Ѹ��ÿ� ��ָֹ���ΪҰָ��
		root = NULL;
	}1;
}
// ��Ҷ�ӽ�����
// 1. ����Ҫ����, ������������ Ҷ�Ӻ�(����ǰ��ı���)
int getLeafSize(Node* root){
	// ����Ҷ��Ϊ0
	if (root == NULL)
		return 0;
	// ֻ��һ�����Ļ� ҲΪҶ��
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	// ����ֻ��һ�������Ļ� ��Ҷ�Ӹ�����������������Ҷ�ӽ���
	return getLeafSize(root->_left) + getLeafSize(root->_right);
}

// 2. ����������, ͳ��Ҷ�ӽ��
void getLeafSize2(Node* root, int* num){
	if (root){
		// ÿ�ߵ�һ��Ҷ�� ����+1,
		if (root->_left == NULL && root->_left == NULL){
			++(*num);
			return;
		}
		// �������Ҷ�� ����������, ����������������
		getLeafSize2(root->_left, num);
		getLeafSize2(root->_right, num);
	}
}
// ���K��Ľ�����
//  ������������ k-1 ��Ľ�������
int getKSize(Node* root, int k){
	if (root == NULL)
		return 0;
	// ��һ��ֻ��һ�����
	if (k == 1)
		return 1;
	return getKSize(root->_left, k - 1) + getKSize(root->_right, k - 1);
}
// ���ҽ���Ƿ��ڶ�������. �����, ���ؽ��ָ�� �鲻�� ���ؿ�,
// ����
Node* find(Node* root, Datatype data){
	Node* ret;
	// ����һ�ֱ��� ÿ�κ͵�ǰ�����бȽ� 
	if (root == NULL)
		return NULL;
	if (root->_data == data)
		return root;
	// ����ҵ���ֱ�ӷ���, �����ټ���������ȥ
	// ��ret �������ҵõ��ĵ�ַ,
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

	
	printf("%d\n", getLeafSize(root));// ��3��Ҷ�ӽ��
	getLeafSize2(root, &num);
	printf("%d\n", num);// ��3��Ҷ�ӽ��

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