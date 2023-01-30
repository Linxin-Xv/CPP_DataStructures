#include <iostream>
#include <assert.h>
using namespace std;

//�ָ����һ�˿��������㷨��ʵ�ֺ���,��������λ���±�
template <typename T>
int Partition(T myarray[], int low, int high)
{
	static int icount = 0;
	icount++;
	cout << "����ǰPartition���ô����ǣ�" << icount << "��" << endl;
	//ѡȡ���ᣬ��Ԫ��
	T pivot = myarray[low];
	while (low < high)
	{
		//�ȴӸ�λ����
		while (low < high && myarray[high] >= pivot)
		{
			high--;
		}
		if (low == high)//�ҵ����ʵ�λ��
		{
			break;
		}
		if (low < high)
		{
			myarray[low] = myarray[high];
			myarray[high] = pivot;
		}
		//�ٴӵ�λ����
		while (low < high && myarray[low] <= pivot)
		{
			low++;
		}
		if (low == high)//�ҵ����ʵ�λ��
		{
			break;
		}
		if (low < high)
		{
			myarray[high] = myarray[low];
			myarray[low] = pivot;
		}
	}
	return low;
}
template <typename T>
void QuickSort(T myarray[], int low, int high, int length, int lvl = 1)
{
	//����
	assert(low < high);
	cout << "����ǰ��������ǣ�" << lvl << "�㡿";
	int pivotpos = Partition(myarray, low, high);//�ָ��
	//����м���
	cout << "low=" << low << "high=" << high << ";����λ��=" << pivotpos << "���˿��Ž��Ϊ��";
	for (int i = 0; i < length; i++)
	{
		cout << myarray[i] << " ";
	}
	cout << endl;
	if (low < pivotpos - 1)
	{
		QuickSort(myarray, low, pivotpos - 1, length, lvl + 1);
	}
	if (pivotpos + 1 < high)
	{
		QuickSort(myarray, pivotpos + 1, high, length, lvl + 1);
	}
	return;
}
template <typename T>
void QuickSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	int low = 0;//��λ��
	int high = length - 1;//��λ��
	QuickSort(myarray, low, high, length);//���غ���
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, length);
	cout << endl;
	cout << "�������������Ϊ��";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}