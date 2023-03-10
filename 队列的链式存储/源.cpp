#include <iostream>
using namespace std;
//带头结点的实现方式
//定义节点
template <typename T>
struct QueueNode
{
	T data;//数据域
	QueueNode<T>* next;//存放下一个节点的指针
};
template <typename T>
class LinkQueue
{
public:
	LinkQueue();//构造函数
	~LinkQueue();//析构函数
	bool EnQueue(const T& e);//入队函数
	bool DeQueue(T& e);//出队函数
	bool GetQueue(T& e);//获取队尾元素
	bool Empty();//判断是否为空队列
	int Queue();//返回队列长度
	void DisplayQueue();//扫描队列
	void ClearQueue();//清空队列
private:
	QueueNode<T>* m_front;//队首
	QueueNode<T>* m_rear;//队尾
	int m_size;//队列长度
	QueueNode<T>* m_head;//头节点
};
template <typename T>
LinkQueue<T>::LinkQueue()
{
	QueueNode<T>* m_head = new QueueNode<T>;//新建一个头结点
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
	}//释放队列
	delete m_head;//释放队首
}
template <typename T>
bool LinkQueue<T>::EnQueue(const T& e)
{
	QueueNode<T>* p = new QueueNode<T>;//为新的头结点分配空间
	p->data = e;//传入数据域
	if (m_size == 0)
	{
		m_rear = p;//将新节点的指针传入队尾
		m_front = p;//将新节点的指针传入队首
		m_size++;//队列长度增加
		return true;
	}
	if (m_size == 1)
	{
		m_rear = p;//将新节点的指针传入队头
		m_front->next = m_rear;//将m_rear设为m_front的后继节点
		m_size++;//队列长度增加
		return true;
	}
	else
	{
		QueueNode<T>* q = m_rear;//新建节点来接受队尾的值
		q->next = p;//将新节点插入在旧队尾的后面
		m_rear = p;//更新队尾
		m_size++;//队列长度增加
		return true;
	}
}
template <typename T>
bool LinkQueue<T>::DeQueue(T& e)
{
	if (m_size == 0)
	{
		cout << "空队列无法出队！" << endl;
		return false;
	}
	if (m_size == 1)
	{
		e = m_front->data;//获取队头数据
		QueueNode<T>* p = m_front;//获取队头指针
		delete p;//释放队尾
		m_rear = nullptr;
		m_front = nullptr;
		m_size--;//队列长度减少
		return true;
	}
	else
	{
		e = m_front->data;//获取队头数据
		QueueNode<T>* p = m_front;//获取队头指针
		m_front = p->next;//队头后移
		delete p;//释放队头
		m_size--;//队列长度减少
		return true;
	}
}
template <typename T>
bool LinkQueue<T>::GetQueue(T& e)
{
	if (m_size == 0)
	{
		cout << "空队列无法获取队尾元素！" << endl;
		return false;
	}
	else
	{
		e = m_front->data;//获取队尾数据
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
		cout << "空队列，无法扫描！" << endl;
	}
	else
	{
		QueueNode<T>* p = m_front;
		for (int i = 0; i < m_size; i++)
		{
			cout << p->data << " ";
			p = p->next;
		}//从头扫描队列
		cout << endl;//换行
	}
}
template <typename T>
void LinkQueue<T>::ClearQueue()
{
	T k;
	while (m_size > 0)
	{
		DeQueue(k);
	}//释放队列
	delete m_head;//释放队首
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