#include <iostream>
using namespace std;
#define MaxSize 10//最大容量是10
template <typename T>
class SeqQueue
{
public:
	SeqQueue();//构造函数
	~SeqQueue();//析构函数
	bool EnSeqQueue(const T& e);//入队列（增加数据）
	bool DeSeqQueue(T& e);//出队列
	bool GetHead(T& e);//获取队头元素
	void ClearQueue();//将队列清空
	void DisplayQueue();//扫描队列
	int Queue();//返回队列长度
	bool IsEmpty();//判断队列是否为空
	bool IsFull();//判断队列是否已满
private:
	T* m_data;//促进方顺序队列中的元素
	int m_size;//队列长度
	int m_front;//对头指针（数组下标），允许删除的一端，如果队列不为空，则指向队列头元素
	int m_rear;//对尾指针（数组下标），允许插入的一端，如果队列不为空，则指向队列尾元素的下一个元素
};
//通过构造函数来对队列初始化
template <typename T>
SeqQueue<T>::SeqQueue()
{
	m_data = new T[MaxSize];
	//空队列约定m_front和m_rear都为0
	m_front = 0;
	m_rear = 0;
	m_size = 0;
}
//通过析构函数来对队列释放
template <typename T>
SeqQueue<T>::~SeqQueue()
{
	delete[] m_data;
}
template <typename T>
bool SeqQueue<T>::EnSeqQueue(const T& e)//入队列操作
{
	if (IsFull() == true)
	{
		cout << "顺序队列已满，不能再进行入队列操作了！" << endl;
		return false;
	}
	m_data[m_rear] = e;//将数据传入队尾
	m_rear = (m_rear + 1) % MaxSize;//队尾指针+1并且取余数
	m_size++;
	return true;
}
template <typename T>
bool SeqQueue<T>::DeSeqQueue(T& e)
{
	if (IsEmpty() == true)
	{
		cout << "空队列无法进行出队列操作!" << endl;
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
		cout << "空队列无法获取队头!" << endl;
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
		cout << "空队列！" << endl;
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