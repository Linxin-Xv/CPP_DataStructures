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