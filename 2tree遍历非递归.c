#include "2tree.h"
#include "stack.h"
#include "common.h"


// �ǵݹ���� �൱��ջ����ջ�ͳ�ջ 
// 1. ���ʼ���ջ, ��ջ֮�������������
// 2. ���ظ���㼴��ջ �Ӷ����ʸ�����������

// ǰ�����(�� �� ��)
// ������ʱ, ջ��=0, cur Ҳ����0
// ��ջ�ﵯ���Ľ����ζ�� �ý���Լ������������ѷ�����, ��Ҫ������������, 
// Ҫ������������ �ٽ��ҽڵ���ջ
// 1. ������ǰ��������·��
// 2. ���������ʵĽ���������
void preOrderNor(Node* root){
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	// ��ջ��һ��Ϊ��ʱ, ����ߵ�������������������,��ʱtop = root, ��ջ��, ջΪ��, Ȼ�����ջ��������������, ��cur��ΪNULL,����ѭ�� 
	// ��curΪNULL, ջҲΪ��ʱ, ������
	while (cur || stackEmpty(&st) != 1){
		// �ӵ�ǰ����λ��, һֱ����������ߵ�·��
		// curΪ��ʱ, ���·���ѷ�����, ȥ����丸���(������ջ) �����ҽڵ�,
		// ���ҽڵ㲻Ϊ��, ������Ϊ�µĸ���� ��ӡ ѹջ, ��ȥ����������ڵ�, ����ڵ�Ϊ��, ��ջ�����
		while (cur){
			// �ȴ�ӡ��ǰֵ(root)
			printf("%d ", cur->_data);
			// ѹջ��Ϊ�˺��ڳ�ջʱ�õ���������
			stackPush(&st, cur);
			cur = cur->_left;
		}

		// ��ȡջ��Ԫ�� ������֮��ɾ����
		top = stackTop(&st);
		stackPop(&st);

		// ����������
		cur = top->_right;
	}
}

// ��ǰ�����ѹջ, ���ܷ���, 
// ����߷�����(�ߵ�NULL)�� �ٴ�ӡ�����, ����������
void inOrderNor(Node* root){
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	while (cur || stackEmpty(&st) != 1){
		// �ӵ�ǰ����λ��, һֱ����������ߵ�·��
		while (cur){
			// �Ƚ���ǰ���ѹջ,����������
			stackPush(&st, cur);
			cur = cur->_left;
		}
		// ��ȡջ��Ԫ��
		top = stackTop(&st);
		stackPop(&st);
		// ��ӡ��ǰ���
		printf("%c", top->_data);
		// Ȼ���ٷ���������
		cur = cur->_right;
	}
}
void postOrderNor(Node* root){
	Node* cur, *top;
	Stack st;
	stackInit(&st, 10);
	cur = root;
	while (cur || stackEmpty(&st) != 1){
		// �ӵ�ǰ����λ��, һֱ����������ߵ�·��
		while (cur){

		}
}

void leverOrder(Node* root){

}

// �ж�һ����=���ǲ�����ȫ������
int isCompleteTree(Node* root){

}