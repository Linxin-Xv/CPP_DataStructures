#include<iostream>
using namespace std;
//ֱ�Ӳ�������
template <typename T>//T��������Ԫ������
void InsertSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	for (int i = 1; i < length; i++)//�ӵڶ���Ԫ�ؿ�ʼ�Ƚ�
	{
		if (myarray[i] < myarray[i - 1])
		{
			T temp = myarray[i];//�ݴ�myarray[i],��ֹ�����ƶ�Ԫ��ʱֵ�����ǵ�
			int j;
			for (j = i - 1; j >= 0 && myarray[j] > temp; --j)//��������ź����Ԫ��
			{
				myarray[j + 1] = myarray[j];//���д���temp��Ԫ�ض�����ƶ�
			}//end for j
			myarray[j + 1] = temp;//��ֵ���ݵ�����λ��
		}//end if
	}// end for i
	return;
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);//������Ԫ�ظ������������С���Ե���Ԫ�ش�С
	InsertSort(arr, length);
	//���������
	cout << "ֱ�Ӳ���������Ϊ��";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}