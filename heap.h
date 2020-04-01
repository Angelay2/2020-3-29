#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Type;
typedef struct heap{
	int* _array; // �����С
	size_t _size;// ����ָ��
	size_t _capacity; // ��������
}heap;

// ����һ��size��������Ϊ�յ�����
// void heapInit(heap* hp);

// ����ͨ��һ���Ѿ����ڵ�����������, ����������鲻һ���Ƕѵ�һ������
void heapInit(heap* hp, Type* arr, size_t size);

// ����: Ҫ���µ����ĵ�����, �����С, ����������С(�����), size������ס���µ����Ľ���
void heapShiftDown(Type* arr, int size, int parent);

// ��Ҷ�ӽ��(child)��ʼ���ϵ���, 
void heapShiftUp(Type* arr, int child);

// Ҫɾ��Ԫ��ֻ��ɾ���Ѷ�Ԫ��, ����Ԫ�غܿ��ܻ��ƻ��ѵĽṹ Ҳ���м��ɵ�
void heapPush(heap* hp, Type data);

void heapPop(heap* hp);

Type heapTop(heap* hp);

size_t heapSize(heap* hp);

int heapEmpty(heap* hp);
