# 排序
## 基本概念
排序的目的就是为了让查找效率变得更高。
### 排序算法的稳定性
指的是关键字相同的元素之间在排序完成后相对位置不发生改变。  
1)不稳定算法
2)有些算法可以稳定，但通过微调代码也可以不稳定。
### 内部排序
在排序过程中，待排序的数据全部被载入在内存中；
### 外部排序
由于数据过多，导致待排序的数据只能部分载入在内存中，在排序过程中会有内存和磁盘之间的数据交换；（减少磁盘的读写次数）
### 两种基本操作：
比较、移动。
## 直接插入类排序
### 算法思想：
每次将一个记录按照其关键字的大小插入到已经排好的序列中，直至全部记录插入完毕。  
例如：
``` cpp
int arr[]={16,1,45,23,99,2,18,67,42,10};---{1,16,....}---{1,16,45,....}
---{1,16,23,45,.....}---{1,16,23,45,99}---{1,2,16,23,45,99}
---{1,2,16,18,23,45,99,....}---{1,2,16,18,23,42,45,99,...}
---{1,2,10,16,18,23,45,67,99}---{1,2,10,16,18,23,42,45,67,99}
```
#### 空间复杂度：$O(1)$。
#### 时间复杂度：最好情况：$O(n)$,最坏情况：$O(n^2)$，平均复杂度：$O(n^2)$。
#### 是一种稳定排序算法
#### 适合待排序数量比较少
实现代码：
``` cpp
#include<iostream>
using namespace std;
//直接插入排序
template <typename T>//T代表数组元素类型
void InsertSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	for (int i = 1; i < length; i++)//从第二个元素开始比较
	{
		if (myarray[i] < myarray[i - 1])
		{
			T temp = myarray[i];//暂存myarray[i],防止后续移动元素时值被覆盖掉
			int j;
			for (j = i - 1; j >= 0 && myarray[j] > temp; --j)//检查所有排好序的元素
			{
				myarray[j + 1] = myarray[j];//所有大于temp的元素都向后移动
			}//end for j
			myarray[j + 1] = temp;//赋值数据到插入位置
		}//end if
	}// end for i
	return;
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);//数组中元素个数等于数组大小除以单个元素大小
	InsertSort(arr, length);
	//输出排序结果
	cout << "直接插入排序结果为：";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
```
## 折半（二分）插入排序
### 是在已经排好序的序列（有序区）中，使用折半查找的方式去确定排序，类似于二分法。
### 减少了关键字的比较次数，但是没有减少数据的移动次数。时间复杂度依然是$O(n^2)$。
``` cpp
#include <iostream>
using namespace std;
//折半插入排序（从小到大）
template <typename T>
void HalfInsertSort(T myarray[],int length)
{
	if (length <= 1)
	{
		return;
	}
	for (int i = 1; i < length; i++)//从第二个元素（下标为1）开始比较
	{
		if (myarray[i] < myarray[i - 1])
		{
			T temp = myarray[i];//暂存myarray[i]的值，方式后续移动元素时将值覆盖
			//记录查找的左右区间范围
			int right = i - 1;
			int left = 0;
			while (left <= right)
			{
				//取中间元素
				int mid = (right - left) / 2 + left;
				if (myarray[mid] > temp)
				{
					//待排序的元素更小，将搜索区间缩小到左边的区域
					right = mid - 1;
				}
				else
				{
					//待排序的元素更小，将搜索区间缩小到左边的区域
					left = mid + 1;
				}
		    }//end while
			int j;
			for (j = i - 1; j >= right + 1; --j)
			{
				myarray[j + 1] = myarray[j];//所有大于temp的元素都向后移动
			}//end for j
			myarray[right + 1] = temp;
		}//end if
	}//end for i
	return;
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	HalfInsertSort(arr, length);
	cout << "折半插入排序结果为：";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
```

