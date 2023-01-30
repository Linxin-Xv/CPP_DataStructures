#include <iostream>
using namespace std;
//2·��������
template <typename T>
void TwoWayInsertSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	T* pfzarray = new T[length];//������������ռ�
	pfzarray[0] = myarray[0];//��ԭʼ����ռ�ĵ�һ��Ԫ�ط��븨������ռ�ĵ�һ��λ��
	int head = 0;//ͷָ��ָ���һ��λ��
	int tail = 0;//βָ��
	for (int i = 1; i < length; i++)
	{
		if (myarray[i] < pfzarray[head])//С��ͷ
		{
			head = (head - 1 + length) % length;
			pfzarray[head] = myarray[i];
		}
		else if (myarray[i] > pfzarray[tail])//����β��
		{
			tail = (tail + 1) % length;
			pfzarray[tail] = myarray[i];
		}
		else
		{
			//����Ҫ�ƶ�������
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
	delete[] pfzarray;//�ͷŸ����ռ�
	return;
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	TwoWayInsertSort(arr, length);
	cout << "2·����������Ϊ��";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}