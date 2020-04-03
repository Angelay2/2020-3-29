//#include "heap.h"
//
///*
//堆:(TopK问题) 逻辑上为完全二叉树,物理上为顺序表结构 (主要按逻辑结构使用)
//	根结点是一个最值, 值大于/小于所有孙子结点的值, 并且每一个组数也满足此性质 为了快速获取最值
//	大堆/小堆根的值:  最大/最小
//	堆：逻辑上为完全二叉树， 物理上是顺序表的结构，主要关注逻辑结构， 按逻辑结构使用 最快找到最值
//	不一定下一层的所有结点值都要小于上一层的结点值, 只需要统一个叉的两个结点小于/大小他的根结点的
//	即可
//
//快速找到最值:
//	向上调整： 插入元素，O(logN)
//	向下调整： 建堆， 删除元素， O(logN)
//	删除元素： 交换， 尾删， 向下调整
//	插入元素： 尾插，向下调整，
//*/
//
///*
//建堆: 让数组中的元素的存储位置符合堆的层次结构 从堆 的最后一个非叶子结点开始进行向下调整,直到根结点结束调整
//	建大堆: swap(parent, child)
//	建小堆: 向下调整, 从最后一个非叶子结点开始调整 首先保证在结构满足小堆 与父结点比较后, 跟左右子结      构进行比较 看谁做根结点
//	在向下调整的过程中, 发生交换的子结构受影响, 其他不受影响
//*/
///*
//堆的使用场景:
//1. topK问题: 找K个最值
//	a. 找前K个最小的值 建含有K个元素的大堆 (先建好堆, 然后在用元素去和堆顶进行比较,如果比堆顶元素大, 则删除堆顶元素)
//	b. 找前K个最大的值 建含有K个元素的小堆 (先建好堆, 然后在用元素去和堆顶进行比较,如果比堆顶元素大, 则删除堆顶元素)
//	比较之后 删除堆顶元素 最后堆里留下的元素就是K个最值
//*/
//
//
//void heapInit(heap* hp, Type* arr, size_t size){
//// 用传入的arr给我结构体里的数组做个初始化, 这样的话后面的操作就不会改变原始数组, 只对堆里的本身数组做操作	
//	  // 若原始数组为返回值的话,, 可以对其数值进行改变 若不是就尽量不要改变其值
//	hp->_array = (Type*)malloc(sizeof(Type) * size);
//	memcpy(hp->_array, arr, sizeof(Type)*size);
//	// 由于已经存了数组的所有元素了 所以size不为0, size=capacity相当于初始化的状态
//	hp->_size = hp->_capacity = size;
//	
//	// 从最后一个非叶子结点开始向下调整
//	for (int i = (size - 2) / 2; i >= 0; --i){
//		// heapShiftDown(arr, size, i);
//		heapShiftDown(hp->_array, size, i);
//	}
//}
//
//// 交换函数
//void swap(Type* arr, int left, int right){
//	Type tmp = arr[left];
//	arr[left] = arr[right];
//	arr[right] = tmp;
//}
//
//// 向下调整(建堆和删除元素) O(logN)
//// 建大堆(child和parent只是位置(数组下标) 不代表值) 
//void heapShiftDown(Type* arr, int size, int parent){
//	// 计算孩子的位置, 
//	int child = 2 * parent + 1;
//	// 如果孩子存在 进行比较调整 (最坏情况是从parent一直调整到叶子结点)
//	while (child < size){
//		// 从两个孩子中选最大的 若左孩子小于右孩子的话,孩子位置交换, 就让父结点和右孩子节点进行比较
//		if (child + 1 < size && arr[child + 1] > arr[child])
//			++child;
//		// 如果父结点小于最大的孩子节点 则交换
//		if (arr[child] > arr[parent]) {
//			swap(arr, child, parent);
//			// 交换完毕之后, 老父亲要向下调整,孩子到父亲的下面
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		// 父亲节点大于所有的子孙结点 (大堆), 不需要调整
//		else{
//			break;
//		}
//	}
//}
//
//
//// 向上调整(插入时用): 从新插入的结点位置开始(叶子结点),进行调整
//// 调整结束: 待调整的位置小于父结点的值或者已经到根结点
//void heapShiftUp(Type* arr, int child){
//	int parent = (child - 1) / 2;
//	// 直到根结束
//	while (parent >= 0){ // while(child> > 0)
//		if (arr[child] > arr[parent]){
//			swap(arr, child, parent);
//			//继续向上调整
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//		// 已经调整完毕
//		else{
//			break;
//		}
//	}
//}
//
//// 要在堆里存放一个新的元素, 如果放在[0]的位置, 就要发生很大的变化,
//// 原始根结点变为现插入的头的子节点, 
//// 尾插高效, 不会破坏堆的原始结构, 涉及向上调整
//void heapPush(heap* hp, Type data){
//	// 检查容量
//	if (hp->_size == hp->_capacity){
//		hp->_capacity *= 2;
//		hp->_array = (Type*)realloc(hp->_array, sizeof(Type)* 2 * hp->_capacity);
//	}
//	// 尾插
//	hp->_array[hp->_size++] = data;
//	heapShiftUp(hp->_array, hp->_size - 1);
//}
//
//// 删除(交换 尾删 向下调整) 只能删除堆顶元素
//// 如果直接执行头删, 时间复杂度为O(N),效率低, 而且有可能破坏堆的结构
//// 正确删除方式:
//// 1. 把堆顶元素和最后一个叶子结点交换 (或者直接用最后一个叶子结点直接覆盖堆顶元素)
//// 2. 执行尾删
//// 3. 再把叶子结点向下调整到合适位置(向下调整的时间复杂度为log(N), 最坏情况遍历LogN个结点)
//void heapPop(heap* hp){
//	if (hp->_array > 0){
//		// 最后一个叶子和对堆顶元素 交换或覆盖
//		hp->_array[0] = hp->_array[hp->_size - 1];
//		//swap(hp->_array, 0, hp->_array[hp->_size - 1]);
//		// 尾删
//		hp->_size--;
//		// 从0位置开始向下调整
//		heapShiftDown(hp->_array, hp->_size, 0);
//	}
//}
//
//Type heapTop(heap* hp){
//	return hp->_array[0];
//}
//
//size_t heapSize(heap* hp){
//	return hp->_size;
//}
//
//int heapEmpty(heap* hp){
//	if (hp->_size == 0)
//		return 1;
//	return 0;
//}
