#include <iostream>
using namespace std;
template <typename T>
void SimSelSort(T myarray[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int minidx = i;//������СԪ�ص�λ��
		T tmp = myarray[i];
		for (int j = i + 1; j < length; j++)
		{
			if (myarray[minidx] > myarray[j])
			{
				minidx = j;
			}
		}
		if (minidx != i)
		{
			myarray[i] = myarray[minidx];
			myarray[minidx] = tmp;
		}
	}
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	SimSelSort(arr, length);
	cout << "��ѡ���������ս��Ϊ��";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}