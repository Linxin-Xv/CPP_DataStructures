#include <iostream>
using namespace std;
//ϣ������
template <typename T>
void ShellSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	//��ʾԭʼ����
	cout << "ԭʼ����Ϊ��";
	for (int i = 0; i < length; i++)
	{
		cout << myarray[i] << " ";
	}
	cout << endl;
	int Dim = length / 2;//����
	while (Dim >= 1)
	{
		//ÿһ�˶�ʹ��ֱ�Ӳ�������
		//��һ��whileѭ��i��(length/2)~(length-1)
		//�ڶ���i��(length/4)~(length-1)
		//������i��(length/8)~(length-1)
		//.............................
		//��n��i��(length/i^n)~(length-1)
		for (int i = Dim; i < length; ++i)//iֵÿ�θı�ᴦ��ͬ��������
		{ 
			if (myarray[i] < myarray[i - Dim])
			{
				T temp = myarray[i];
				int j;
				for (j = i - Dim; j >= 0 && myarray[j] > temp; j -= Dim)//���ǰ�������ź����Ԫ��
				{
					//���д���temp��Ԫ�ض�����ƶ�
					myarray[j + Dim] = myarray[j];
				}// end for j
				myarray[j + Dim] = temp;//�ҵ����ʵĲ���λ��
			}//end if
		}//end for i
		//ÿ��һ�˾���ʾһ��
		cout << "����ϣ�����������Ϊ��" << Dim << " ,������Ϊ��";
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
	cout << "ϣ��������Ϊ��";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}