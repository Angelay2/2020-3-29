#include <stdio.h>
#include <stdlib.h>

typedef int Type;
typedef struct heap{
	int* _array; // 数组大小
	size_t _size;// 数组指针
	size_t _capacity; // 数组容量
}heap;

// 创建一个size和容量都为空的数组
void heapInit(heap* hp);

// 可以通过一个已经存在的数组来创建, 给的这个数组不一定是堆的一个排列
void heapInit(heap* hp, Type* arr, size_t size);

// 参数: 要向下调整的的数组, 数组大小, 调整的起点大小(父结点)
void heapShiftDown(Type* arr, size_t size, int parent);

