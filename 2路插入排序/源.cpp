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
		else if (myarray[i] > pfzarray[tail])//大于尾巴
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