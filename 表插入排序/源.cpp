#include <iostream>
using namespace std;
//���������
//���þ�̬�����˼��
//��̬������Ԫ�صĶ���
template <typename T>
struct SLNode
{
	T data;//������
	int cur;//�α꣬���ڴ����һ���ڵ���±�
};
template <typename T>
void TableInsertSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	SLNode<T>* tbl = new SLNode<T>[length + 1];//newһ��length+1���ȵĿռ��ž�̬�ڵ㣬�׽ڵ���α�ָ����С���Ǹ�Ԫ��
	for (int i = 0; i < length; i++)
	{
		tbl[i + 1].data = myarray[i];//�����������׽ڵ㲻�������
		tbl[i].cur = 0;//��ʼ���α�����Ϊ0
	}
	tbl[0].cur = 1;//ͷ���һ��ʼָ���±�Ϊ1��λ��
	for (int i = 2; i < length + 1; i++)
	{
		int tmp = tbl[0].cur;
		int tmp_pre = 0;//ǰ��
		while (tmp != 0 && tbl[tmp].data < tbl[i].data)
		{
			tmp_pre = tmp;
			tmp = tbl[tmp].cur;
		}//end while
		tbl[i].cur = tbl[tmp_pre].cur;
		tbl[tmp_pre].cur = i;
	}//end for i
	int tmp = tbl[0].cur;
	int curidx = 0;
	while (tmp != 0)
	{
		myarray[curidx] = tbl[tmp].data;
		curidx++;
		tmp = tbl[tmp].cur;
	}// end while
	delete[] tbl;//�ͷſռ�
	return;
}
int main()
{
	int arr[] = { 16,1,45,23,99,2,18,67,42,10 };
	int length = sizeof(arr) / sizeof(arr[0]);
	TableInsertSort(arr, length);
	cout << "�����������Ϊ��";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}