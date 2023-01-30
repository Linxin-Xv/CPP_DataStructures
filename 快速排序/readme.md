# 交换类排序
## 冒泡排序（起泡排序）
### 大的数据不断往后移动，小的数据像气泡一样往上冒。
### 如果在一趟排序中没有发生值的交换了，冒泡排序就可以结束了。
### 空间复杂度$O(1)$,平均时间复杂度$O(n^2)$，最好时间复杂度$O(n)$。
### 冒泡排序是稳定算法。
``` cpp
#include <iostream>
using namespace std;
template <typename T>
void BobbleSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	//外层循环只控制排序的趟次
	for (int i = 0; i < length - 1; i++)
	{ 
		bool ismoved = false;//判断是否发生了移动
		//内层循环控制元素的大小比较和交换位置
		for (int j = 0; j < length - i - 1 ; j++)//每趟比较次数都会减少
		{
			if (myarray[j] > myarray[j + 1])//前面的数据如果比后面数据大
			{
				//交换位置
				T temp = myarray[j];
				myarray[j] = myarray[j + 1];
				myarray[j + 1] = temp;
				ismoved = true;
			}
		}//end for j
		//每走一趟显示一次结果
		cout << "第" << i + 1 << "趟冒泡排序的结果是：";
		for (int j = 0; j < length; j++)
		{
			cout << myarray[j] << " ";
		}
		cout << endl;
		if (ismoved == false)
		{
			break;
		}
		ismoved = false;
	}// end for i
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int brr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int length = sizeof(arr) / sizeof(arr[0]);
	BobbleSort(arr, length);
	cout << endl;
	int length1 = sizeof(brr) / sizeof(brr[0]);
	BobbleSort(brr, length1);
}
```
## 快速排序（qsort）是对冒泡排序的一种改进
### 任意一个元素作为枢轴（基准元素）。引入两个指针，low ,high。
``` cpp
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
```
### 快速排序效率分析
#### 时间复杂度=$O(n*递归调用深度)$。
#### 空间复杂度=$O(递归调用深度)$。
#### 递归调用深度:$[logn,n]$
#### 平均时间复杂度=$O(n*logn)$
#### 平均空间复杂度=$O(n*logn)$
### 快速排序是不稳定排序算法。