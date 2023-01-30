#include <iostream>
using namespace std;
//�۰�������򣨴�С����
template <typename T>
void HalfInsertSort(T myarray[],int length)
{
	if (length <= 1)
	{
		return;
	}
	for (int i = 1; i < length; i++)//�ӵڶ���Ԫ�أ��±�Ϊ1����ʼ�Ƚ�
	{
		if (myarray[i] < myarray[i - 1])
		{
			T temp = myarray[i];//�ݴ�myarray[i]��ֵ����ʽ�����ƶ�Ԫ��ʱ��ֵ����
			//��¼���ҵ��������䷶Χ
			int right = i - 1;
			int left = 0;
			while (left <= right)
			{
				//ȡ�м�Ԫ��
				int mid = (right - left) / 2 + left;
				if (myarray[mid] > temp)
				{
					//�������Ԫ�ظ�С��������������С����ߵ�����
					right = mid - 1;
				}
				else
				{
					//�������Ԫ�ظ�С��������������С����ߵ�����
					left = mid + 1;
				}
		    }//end while
			int j;
			for (j = i - 1; j >= right + 1; --j)
			{
				myarray[j + 1] = myarray[j];//���д���temp��Ԫ�ض�����ƶ�
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
	cout << "�۰����������Ϊ��";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}