#include <iostream>
using namespace std;
template <typename T>
void BobbleSort(T myarray[], int length)
{
	if (length <= 1)
	{
		return;
	}
	//���ѭ��ֻ����������˴�
	for (int i = 0; i < length - 1; i++)
	{ 
		bool ismoved = false;//�ж��Ƿ������ƶ�
		//�ڲ�ѭ������Ԫ�صĴ�С�ȽϺͽ���λ��
		for (int j = 0; j < length - i - 1 ; j++)//ÿ�˱Ƚϴ����������
		{
			if (myarray[j] > myarray[j + 1])//ǰ�����������Ⱥ������ݴ�
			{
				//����λ��
				T temp = myarray[j];
				myarray[j] = myarray[j + 1];
				myarray[j + 1] = temp;
				ismoved = true;
			}
		}//end for j
		//ÿ��һ����ʾһ�ν��
		cout << "��" << i + 1 << "��ð������Ľ���ǣ�";
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