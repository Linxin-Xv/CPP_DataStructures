#include <iostream>
using namespace std;
#define INT_MAX_MY 2147483647 //整型能够存储的最大数值，作为标记使用
template<typename T>
void TreeSelSort(T myarray[], int length)
{
	//ceil是向上取整
	int treelvl = (int)ceil(log(length)) / log(2) + 1;//完全二叉树高度
	int nodecount = (int)pow(2, treelvl) - 1;//满二叉树的节点个数
	int nodecount2 = (int)pow(2, treelvl - 1) - 1;//treelvl-1的满二叉树最多节点个数
	int* pidx = new int[nodecount];//保存节点下标的内存
	for (int i = 0; i < length; i++)
	{
		pidx[nodecount2 + i] = i;
	}
	//给多余的叶子结点赋值
	for (int i = nodecount2 + length; i < nodecount; i++)
	{
		pidx[i] = INT_MAX_MY;
	}
	int tmpnode = nodecount;
	int tmpnode2 = nodecount2;
	//现在给非叶子节点赋值
    //第一趟要赋值，还要节点比较
	while (tmpnode2 != 0)
	{
		for (int i = tmpnode2; i < tmpnode; i += 2)
		{
			if (pidx[i] != INT_MAX_MY && pidx[i + 1] != INT_MAX_MY)
			{
				if (myarray[pidx[i]] <= myarray[pidx[i + 1]])
				{
					pidx[(i + 1) / 2 - 1] = pidx[i];
				}
				else
				{
					pidx[(i + 1) / 2 - 1] = pidx[i + 1];
				}
			}
			else if (pidx[i] != INT_MAX_MY)
			{
				pidx[(i + 1) / 2 - 1] = pidx[i];
			}
			else
			{
				pidx[(i + 1) / 2 - 1] = pidx[i + 1];
			}
		}
		tmpnode = tmpnode2;
		tmpnode2 = (tmpnode2 - 1) / 2;
	}
	T* ptmparray = new T[length];//临时保存排好序的数组
	for (int i = 0; i < length; i++)
	{
		ptmparray[i] = myarray[pidx[0]];//将当前最小值赋值给临时保存
		int leftidx = 0;
		for (int j = 1; j < treelvl; j++)
		{
			if (pidx[2 * leftidx + 1] == pidx[leftidx])
			{
				leftidx = 2 * leftidx + 1;
			}
			else
			{
				leftidx = 2 * leftidx + 2;
			}
		}
		pidx[leftidx] = INT_MAX_MY;
		while (leftidx)
		{
			leftidx = (leftidx + 1) / 2 - 1;
			if (pidx[2 * leftidx + 1] != INT_MAX_MY && pidx[2 * leftidx + 2] != INT_MAX_MY)
			{
				if (myarray[pidx[2 * leftidx + 1]] <= myarray[pidx[2 * leftidx + 2]])
				{
					pidx[leftidx] = pidx[2 * leftidx + 1];
				}
				else
				{
					pidx[leftidx] = pidx[2 * leftidx + 2];
				}
			}
			else if (pidx[2 * leftidx + 1] != INT_MAX_MY)
			{
				pidx[leftidx] = pidx[2 * leftidx + 1];
			}
			else
			{
				pidx[leftidx] = pidx[2 * leftidx + 2];
			}
		}
	}
	//把数据拷贝回数组
	for (int i = 0; i < length; i++)
	{
		myarray[i] = ptmparray[i];
	}
	delete[] ptmparray;
	delete[] pidx;
	return;
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	TreeSelSort(arr, length);
	cout << "树形选择排序最终结果为：";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}