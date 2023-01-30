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