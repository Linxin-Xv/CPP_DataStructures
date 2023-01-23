#include <iostream>
using namespace std;
//��ͷ����ʵ�ַ�ʽ
//����ڵ�
template <typename T>
struct QueueNode
{
	T data;//������
	QueueNode<T>* next;//�����һ���ڵ��ָ��
};
template <typename T>
class LinkQueue
{
public:
	LinkQueue();//���캯��
	~LinkQueue();//��������
	bool EnQueue(const T& e);//��Ӻ���
	bool DeQueue(T& e);//���Ӻ���
	bool GetQueue(T& e);//��ȡ��βԪ��
	bool Empty();//�ж��Ƿ�Ϊ�ն���
	int Queue();//���ض��г���
	void DisplayQueue();//ɨ�����
	void ClearQueue();//��ն���
private:
	QueueNode<T>* m_front;//����
	QueueNode<T>* m_rear;//��β
	int m_size;//���г���
	QueueNode<T>* m_head;//ͷ�ڵ�
};
template <typename T>
LinkQueue<T>::LinkQueue()
{
	QueueNode<T>* m_head = new QueueNode<T>;//�½�һ��ͷ���
	m_front = nullptr;
	m_rear = nullptr;
	m_head->next = m_front;
	m_size = 0;
}
template <typename T>
LinkQueue<T>::~LinkQueue()
{
	T k;
	while (m_size > 0)
	{
		DeQueue(k);
	}//�ͷŶ���
	delete m_head;//�ͷŶ���
}
template <typename T>
bool LinkQueue<T>::EnQueue(const T& e)
{
	QueueNode<T>* p = new QueueNode<T>;//Ϊ�µ�ͷ������ռ�
	p->data = e;//����������
	if (m_size == 0)
	{
		m_rear = p;//���½ڵ��ָ�봫���β
		m_front = p;//���½ڵ��ָ�봫�����
		m_size++;//���г�������
		return true;
	}
	if (m_size == 1)
	{
		m_rear = p;//���½ڵ��ָ�봫���ͷ
		m_front->next = m_rear;//��m_rear��Ϊm_front�ĺ�̽ڵ�
		m_size++;//���г�������
		return true;
	}
	else
	{
		QueueNode<T>* q = m_rear;//�½��ڵ������ܶ�β��ֵ
		q->next = p;//���½ڵ�����ھɶ�β�ĺ���
		m_rear = p;//���¶�β
		m_size++;//���г�������
		return true;
	}
}
template <typename T>
bool LinkQueue<T>::DeQueue(T& e)
{
	if (m_size == 0)
	{
		cout << "�ն����޷����ӣ�" << endl;
		return false;
	}
	if (m_size == 1)
	{
		e = m_front->data;//��ȡ��ͷ����
		QueueNode<T>* p = m_front;//��ȡ��ͷָ��
		delete p;//�ͷŶ�β
		m_rear = nullptr;
		m_front = nullptr;
		m_size--;//���г��ȼ���
		return true;
	}
	else
	{
		e = m_front->data;//��ȡ��ͷ����
		QueueNode<T>* p = m_front;//��ȡ��ͷָ��
		m_front = p->next;//��ͷ����
		delete p;//�ͷŶ�ͷ
		m_size--;//���г��ȼ���
		return true;
	}
}
template <typename T>
bool LinkQueue<T>::GetQueue(T& e)
{
	if (m_size == 0)
	{
		cout << "�ն����޷���ȡ��βԪ�أ�" << endl;
		return false;
	}
	else
	{
		e = m_front->data;//��ȡ��β����
		return true;
	}
}
template <typename T>
bool LinkQueue<T>::Empty()
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
int LinkQueue<T>::Queue()
{
	return m_size;
}
template <typename T>
void LinkQueue<T>::DisplayQueue()
{
	if (m_size == 0)
	{
		cout << "�ն��У��޷�ɨ�裡" << endl;
	}
	else
	{
		QueueNode<T>* p = m_front;
		for (int i = 0; i < m_size; i++)
		{
			cout << p->data << " ";
			p = p->next;
		}//��ͷɨ�����
		cout << endl;//����
	}
}
template <typename T>
void LinkQueue<T>::ClearQueue()
{
	T k;
	while (m_size > 0)
	{
		DeQueue(k);
	}//�ͷŶ���
	delete m_head;//�ͷŶ���
}
int main()
{
	LinkQueue<int> obj;
	int k;
	obj.DisplayQueue();
	obj.DeQueue(k);
	obj.EnQueue(1);
	obj.EnQueue(2);
	obj.EnQueue(3);
	obj.EnQueue(4);
	obj.EnQueue(5);
	obj.DisplayQueue();
	obj.DeQueue(k);
	obj.DisplayQueue();
	obj.DeQueue(k);
	obj.DisplayQueue();
	obj.EnQueue(10);
	obj.DisplayQueue();
	return 0;
}