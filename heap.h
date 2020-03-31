#include <stdio.h>
#include <stdlib.h>

typedef int Type;
typedef struct heap{
	int* _array; // �����С
	size_t _size;// ����ָ��
	size_t _capacity; // ��������
}heap;

// ����һ��size��������Ϊ�յ�����
void heapInit(heap* hp);

// ����ͨ��һ���Ѿ����ڵ�����������, ����������鲻һ���Ƕѵ�һ������
void heapInit(heap* hp, Type* arr, size_t size);

// ����: Ҫ���µ����ĵ�����, �����С, ����������С(�����)
void heapShiftDown(Type* arr, size_t size, int parent);

