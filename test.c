#include "heap.h"

void test(){
	heap hp;
	int arr[] = { 1, 10, 3, 5, 7, 2, 54, 145, 56, 23 };
	heapInit(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	heapPush(&hp, 200);
}
void test2(){
	heap hp;
	int arr[] = { 1, 10, 3, 5, 7, 2, 54, 145, 56, 23 };
	heapInit(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	heapPush(&hp, 20000);
	heapPush(&hp, 18960);
	heapPush(&hp, 345);
	heapPush(&hp, 64);
	heapPush(&hp, 34554);
	heapPush(&hp, 670);
	while (heapEmpty(&hp) != 1){
		printf("%d\n", heapTop(&hp));
		heapPop(&hp);
	}
}
int main(){
	//test();
	test2();
	system("pause");
	return 0;
}