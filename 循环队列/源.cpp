#include <iostream>
using namespace std;
#define MaxSize 10//���������10
template <typename T>
class SeqQueue
{
public:
	SeqQueue();//���캯��
	~SeqQueue();//��������
	bool EnSeqQueue(const T& e);//����У��������ݣ�
	bool DeSeqQueue(T& e);//������
	bool GetHead(T& e);//��ȡ��ͷԪ��
	void ClearQueue();//���������
	void DisplayQueue();//ɨ�����
	int Queue();//���ض��г���
	bool IsEmpty();//�ж϶����Ƿ�Ϊ��
	bool IsFull();//�ж϶����Ƿ�����
private:
	T* m_data;//�ٽ���˳������е�Ԫ��
	int m_size;//���г���
	int m_front;//��ͷָ�루�����±꣩������ɾ����һ�ˣ�������в�Ϊ�գ���ָ�����ͷԪ��
	int m_rear;//��βָ�루�����±꣩����������һ�ˣ�������в�Ϊ�գ���ָ�����βԪ�ص���һ��Ԫ��
};
//ͨ�����캯�����Զ��г�ʼ��
template <typename T>
SeqQueue<T>::SeqQueue()
{
	m_data = new T[MaxSize];
	//�ն���Լ��m_front��m_rear��Ϊ0
	m_front = 0;
	m_rear = 0;
	m_size = 0;
}
//ͨ�������������Զ����ͷ�
template <typename T>
SeqQueue<T>::~SeqQueue()
{
	delete[] m_data;
}
template <typename T>
bool SeqQueue<T>::EnSeqQueue(const T& e)//����в���
{
	if (IsFull() == true)
	{
		cout << "˳����������������ٽ�������в����ˣ�" << endl;
		return false;
	}
	m_data[m_rear] = e;//�����ݴ����β
	m_rear = (m_rear + 1) % MaxSize;//��βָ��+1����ȡ����
	m_size++;
	return true;
}
template <typename T>
bool SeqQueue<T>::DeSeqQueue(T& e)
{
	if (IsEmpty() == true)
	{
		cout << "�ն����޷����г����в���!" << endl;
		return false;
	}
	e = m_data[m_front];
	m_front = (m_front + 1) % MaxSize;
	m_size--;
	return true;
}
template <typename T>
bool SeqQueue<T>::GetHead(T& e)
{
	if (IsEmpty() == true)
	{
		cout << "�ն����޷���ȡ��ͷ!" << endl;
		return false;
	}
	e = m_data[m_front];
	return true;
}
template <typename T>
bool SeqQueue<T>::IsEmpty()
{
	if (m_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
bool SeqQueue<T>::IsFull()
{
	if (m_size == MaxSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
int SeqQueue<T>::Queue()
{
	return m_size;
}
template <typename T>
void SeqQueue<T>::ClearQueue()
{
	m_rear = 0;
	m_front = 0;
}
template <typename T>
void SeqQueue<T>::DisplayQueue()
{
	if (Queue() == 0)
	{
		cout << "�ն��У�" << endl;
	}
	else
	{
		for (int i = m_front; i !=m_rear; )
		{
			cout << m_data[i] << " ";
			i = (i + 1) % MaxSize;
		}
		cout << endl;
	}
}
int main()
{
	SeqQueue<int> obj;
	obj.DisplayQueue();
	obj.EnSeqQueue(1);
	obj.EnSeqQueue(2);
	obj.EnSeqQueue(3);
	obj.EnSeqQueue(4);
	obj.EnSeqQueue(5);
	obj.DisplayQueue();
	int k;
	obj.DeSeqQueue(k);
	obj.DisplayQueue();
	obj.DeSeqQueue(k);
	obj.DisplayQueue();
	obj.EnSeqQueue(1);
	obj.EnSeqQueue(2);
	obj.EnSeqQueue(15);
	obj.EnSeqQueue(46);
	obj.EnSeqQueue(120);
	obj.EnSeqQueue(1111);
	obj.DisplayQueue();
	for (int i = 0; i <= 8; i++)
	{
		obj.DeSeqQueue(k);
		obj.DisplayQueue();
	}
	return 0;
}