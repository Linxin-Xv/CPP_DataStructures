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