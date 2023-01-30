#include <iostream>
using namespace std;
//表插入排序
//利用静态链表的思想
//静态链表中元素的定义
template <typename T>
struct SLNode
{
	T data;//数据域
	int cur;//游标，用于存放下一个节点的下标
};
template <typename T>
void TableInsertSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	SLNode<T>* tbl = new SLNode<T>[length + 1];//new一个length+1长度的空间存放静态节点，首节点的游标指向最小的那个元素
	for (int i = 0; i < length; i++)
	{
		tbl[i + 1].data = myarray[i];//传入数据域，首节点不存放数据
		tbl[i].cur = 0;//初始化游标设置为0
	}
	tbl[0].cur = 1;//头结点一开始指向下标为1的位置
	for (int i = 2; i < length + 1; i++)
	{
		int tmp = tbl[0].cur;
		int tmp_pre = 0;//前驱
		while (tmp != 0 && tbl[tmp].data < tbl[i].data)
		{
			tmp_pre = tmp;
			tmp = tbl[tmp].cur;
		}//end while
		tbl[i].cur = tbl[tmp_pre].cur;
		tbl[tmp_pre].cur = i;
	}//end for i
	int tmp = tbl[0].cur;
	int curidx = 0;
	while (tmp != 0)
	{
		myarray[curidx] = tbl[tmp].data;
		curidx++;
		tmp = tbl[tmp].cur;
	}// end while
	delete[] tbl;//释放空间
	return;
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	TableInsertSort(arr, length);
	cout << "表插入排序结果为：";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}