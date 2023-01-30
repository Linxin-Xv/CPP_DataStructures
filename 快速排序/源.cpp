#include <iostream>
#include <assert.h>
using namespace std;

//分割函数：一趟快速排序算法的实现函数,返回枢轴位置下标
template <typename T>
int Partition(T myarray[], int low, int high)
{
	static int icount = 0;
	icount++;
	cout << "【当前Partition调用次数是：" << icount << "】" << endl;
	//选取枢轴，首元素
	T pivot = myarray[low];
	while (low < high)
	{
		//先从高位置来
		while (low < high && myarray[high] >= pivot)
		{
			high--;
		}
		if (low == high)//找到合适的位置
		{
			break;
		}
		if (low < high)
		{
			myarray[low] = myarray[high];
			myarray[high] = pivot;
		}
		//再从低位置来
		while (low < high && myarray[low] <= pivot)
		{
			low++;
		}
		if (low == high)//找到合适的位置
		{
			break;
		}
		if (low < high)
		{
			myarray[high] = myarray[low];
			myarray[low] = pivot;
		}
	}
	return low;
}
template <typename T>
void QuickSort(T myarray[], int low, int high, int length, int lvl = 1)
{
	//断言
	assert(low < high);
	cout << "【当前调用深度是：" << lvl << "层】";
	int pivotpos = Partition(myarray, low, high);//分割函数
	//输出中间结果
	cout << "low=" << low << "high=" << high << ";枢轴位置=" << pivotpos << "本趟快排结果为：";
	for (int i = 0; i < length; i++)
	{
		cout << myarray[i] << " ";
	}
	cout << endl;
	if (low < pivotpos - 1)
	{
		QuickSort(myarray, low, pivotpos - 1, length, lvl + 1);
	}
	if (pivotpos + 1 < high)
	{
		QuickSort(myarray, pivotpos + 1, high, length, lvl + 1);
	}
	return;
}
template <typename T>
void QuickSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	int low = 0;//低位置
	int high = length - 1;//高位置
	QuickSort(myarray, low, high, length);//重载函数
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, length);
	cout << endl;
	cout << "快速排序最后结果为：";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}