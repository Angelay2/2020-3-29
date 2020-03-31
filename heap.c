#include "heap.h"

/*
堆: 根结点是一个最值, 值大于/小于所有孙子结点的值, 并且每一个组数也满足此性质
大堆/小堆根的值:  最大/最小
堆：逻辑上为完全二叉树， 物理上是顺序表的结构，主要关注逻辑结构， 按逻辑结构使用 最快找到最值
不一定下一层的所有结点值都要小于上一层的结点值, 只需要统一个叉的两个结点小于/大小他的根结点的值即可

向上调整： 插入元素，O(logN)
向下调整： 建堆， 删除元素， O(logN)
删除元素： 交换， 尾删， 向下调整
插入元素： 尾插，向下调整，
*/

/*
建堆:
	建大堆: swap(parent, child)
	建小堆: 向下调整, 从最后一个非叶子结点开始调整 首先保证在结构满足小堆 与父结点比较后, 跟左右子结      构进行比较 看谁做根结点
	在向下调整的过程中, 发生交换的子结构受影响, 其他不受影响
*/

void heapInit(heap* hp, Type* arr, size_t size);

// 交换函数
void swap(Type* arr, int left, int right){
	Type tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

// 建大堆
void heapShiftDown(Type* arr, size_t size, int parent){
	// 计算孩子的位置, 
	int child = 2 * parent + 1;
	// 如果孩子存在 进行比较调整 (最坏情况是从parent一直调整到叶子结点)
	while (child){
		// 从两个孩子中选最大的 若左孩子小于右孩子的话, 就让父结点和右孩子节点进行比较
		if (child + 1 < size && arr[child + 1] > arr[child])
			++child;
		// 如果父结点小于最大的孩子节点 则交换
		if (arr[child] > arr[parent]) {
			swap(arr, child, parent);
			// 交换完毕之后, 老父亲要向下调整,
			parent = child;
			child = 2 * parent + 1;
		}
		// 父亲节点大于所有的子孙结点 (大堆), 不需要调整
		else{
			break;
		}
	}
}
