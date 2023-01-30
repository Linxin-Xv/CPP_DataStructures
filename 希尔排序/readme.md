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
## 2路插入排序
### 用辅助数组来较少排序中的记录的移动次数。
### 时间复杂度仍然是$O(n^2)$。
### 空间复杂度是$O(n)$。
``` cpp
#include <iostream>
using namespace std;
//2路插入排序
template <typename T>
void TwoWayInsertSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	T* pfzarray = new T[length];//创建辅助数组空间
	pfzarray[0] = myarray[0];//将原始数组空间的第一个元素放入辅助数组空间的第一个位置
	int head = 0;//头指针指向第一个位置
	int tail = 0;//尾指针
	for (int i = 1; i < length; i++)
	{
		if (myarray[i] < pfzarray[head])//小于头
		{
			head = (head - 1 + length) % length;
			pfzarray[head] = myarray[i];
		}
		else if(myarray[i]>pfzarray[tail])//大于尾巴
		{
			tail = (tail + 1) % length;
			pfzarray[tail] = myarray[i];
		}
		else
		{
			//这里要移动数据了
			tail = (tail + 1) % length;
			pfzarray[tail] = pfzarray[tail - 1];
			int j;
			for (j = tail - 1; myarray[i] < pfzarray[(j - 1 + length) % length]; j = (j - 1 + length) % length)
			{
				pfzarray[j] = pfzarray[(j - 1 + length) % length];
			}//end for j
			pfzarray[j] = myarray[i];
		}
	}//end for i
	for (int i = 0; i < length; i++)
	{
		myarray[i] = pfzarray[head];
		head = (head + 1) % length;
	}
	delete[] pfzarray;//释放辅助空间
	return;
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	TwoWayInsertSort(arr, length);
	cout << "2路插入排序结果为：";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
```
## 表插入排序
### 利用静态链表的思想
### 时间复杂度仍然是$O(n^2)$
``` cpp
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
```
## 总结插入排序
### 最好时间复杂度是$O(n)$,平均时间复杂度都是$O(n^2)$，都是稳定排序算法。
## 希尔排序(Shell Sort)——缩小增量排序
### 先追求元素的部分有序，然后逐渐再追求元素的全局有序。
### 做法：先将整个待排序的记录序列（数组元素）分割成若干个子序列分别进行直接插入排序，等到整个序列中的记录基本有序时，再对所有记录进行一次直接插入排序。
### 多趟排序
``` cpp
#include <iostream>
using namespace std;
//希尔排序
template <typename T>
void ShellSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	//显示原始数据
	cout << "原始数据为：";
	for (int i = 0; i < length; i++)
	{
		cout << myarray[i] << " ";
	}
	cout << endl;
	int Dim = length / 2;//增量
	while (Dim >= 1)
	{
		//每一趟都使用直接插入排序
		//第一次while循环i是(length/2)~(length-1)
		//第二次i是(length/4)~(length-1)
		//第三次i是(length/8)~(length-1)
		//.............................
		//第n次i是(length/i^n)~(length-1)
		for (int i = Dim; i < length; ++i)//i值每次改变会处理不同的子序列
		{ 
			if (myarray[i] < myarray[i - Dim])
			{
				T temp = myarray[i];
				int j;
				for (j = i - Dim; j >= 0 && myarray[j] > temp; j -= Dim)//检查前面所有排好序的元素
				{
					//所有大于temp的元素都向后移动
					myarray[j + Dim] = myarray[j];
				}// end for j
				myarray[j + Dim] = temp;//找到合适的插入位置
			}//end if
		}//end for i
		//每走一趟就显示一趟
		cout << "本趟希尔排序的增量为：" << Dim << " ,排序结果为：";
		for (int i = 0; i < length; i++)
		{
			cout << myarray[i] << " ";
		}
		cout << endl;
		Dim /= 2;
	}// end while
	return;
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, length);
	cout << "希尔排序结果为：";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
```
