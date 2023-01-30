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