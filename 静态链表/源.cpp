#include <iostream>
using namespace std;
#define MaxSize 201//静态链表的尺寸，可用数组下标为0-200
enum NODEUSE//枚举节点使用情况
{
	//这些枚举值都取负值
	e_NOUSE = -1,//未使用
	e_LAST = -2//最后一个节点
};
//静态链表中每个节点的定义
template <typename T>//T代表数据元素的类型
struct Node
{
	T data;//元素数据域
	int cur;//游标
};
//静态链表的定义
template <typename T>
class StaticLinkList
{
public:
	StaticLinkList();//构造函数
	~StaticLinkList();//析构函数
	int FindAnIdlePos();//找到一个空闲位置用于存放数据
	bool ListInsert(int i, const T& e);//在第i个位置插入指定元素e
	bool ListDelete(int i);//删除第i个位置元素
	bool GetElem(const T& e);//获得第i个位置的元素值
	int LocateElem(const T& e);//获得元素e第一次出现的位置
	void DisplayList();//扫描静态链表
	int ListLength();//获取静态链表的长度
	bool Empty();//判断静态链表是否为空
private:
	Node<T> m_data[MaxSize];//保存节点数据的数组
	int m_length;//保存数组长度
};
template <typename T>
StaticLinkList<T>::StaticLinkList()//通过构造函数对链表初始化
{
	for (int i = 1; i < MaxSize; i++)//从下标1开始的节点用于保存实际的数据，这些节点的cur有必要设置值，而头结点其实不用赋值。
	{
		m_data[i].cur = e_NOUSE;//标记这些节点都没有使用
	}
	m_length = 0;//长度为0
}
template <typename T>
StaticLinkList<T>::~StaticLinkList()
{

}
template <typename T>
int StaticLinkList<T>::FindAnIdlePos()//在m_data中找到一个空闲位置保存数据，若没找到则返回-1
{
	for (int i = 1; i < MaxSize; i++)
	{
		if (m_data[i].cur == e_NOUSE)
		{
			return i;
		}
	}
	return -1;
}
template <typename T>
bool StaticLinkList<T>::ListInsert(int i, const T& e)//在第i个位置插入指定元素e
{
	if (i<1 || i>(m_length + 1))
	{
		cout << "插入位置不合法！" << endl;
		return false;
	}
	int iIdx;
	if ((iIdx = FindAnIdlePos()) == -1)
	{
		cout << "链表已满！" << endl;
		return false;
	}
	if (i == 1)
	{
		if (m_length == 0)
		{
			m_data[iIdx].cur = e_LAST;//标注表尾
			m_data[iIdx].data = e;//传入数据域
			cout << "情况I" << endl;
		}
		else
		{
			m_data[iIdx].cur = m_data[0].cur;
			m_data[iIdx].data = e;
			cout << "情况II" << endl;
		}
		m_data[0].cur = iIdx;
		m_length++;
		cout << "插入位置不合法！" << endl;
		return true;
	}
	else
	{
		int prior = 0;//找到第i-1个节点的游标
		for (int j = 0; j < i - 1; j++)
		{
			prior = m_data[prior].cur;
		}
		m_data[iIdx].data = e;
		m_data[iIdx].cur =m_data[prior].cur;
		m_data[prior].cur = iIdx;
		/*Node<T> prior = m_data[0];
		for (int j = 0; j < i - 1; j++)
		{
			prior = m_data[prior.cur];
		}
		m_data[iIdx].cur = prior.cur;
		m_data[iIdx].data = e;
		prior.cur = iIdx;
		此处注释发生了我不明白原因的报错*/
		m_length++;
		cout << "情况III" << endl;
		cout << "插入位置不合法！" << endl;
		return true;
	}
}
template <typename T>
void StaticLinkList<T>::DisplayList()//输出静态链表中全部元素
{
	int p = 0;
	for (int i = 0; i < m_length; i++)
	{
		p = m_data[p].cur;
		cout << m_data[p].data << " ";
	}
	cout << endl;
}
template <typename T>
bool StaticLinkList<T>::GetElem(const T& e)
{
	if (m_length == 0)
	{
		cout << "空链表，查无此元素！" << endl;
		return false;
	}
	int count = 1;
	int p = m_data[0].cur;
	while (m_data[p].data != e)
	{
		p = m_data[p].cur;
		++count;
		if (count == m_length)
		{
			cout << "链表中没有此元素！" << endl;
			return false;
		}
	}
	cout << "链表中" << e << "元素的位置是第" << count << "位。" << endl;
	return true;
}
template <typename T>
int StaticLinkList<T>::LocateElem(const T& e)
{
	if (m_length == 0)
	{
		cout << "空链表，查无此元素！" << endl;
		return -1;
	}
	int count = 1;
	int p = m_data[0].cur;
	while (m_data[p].data != e)
	{
		p = m_data[p].cur;
		++count;
		if (count == m_length)
		{
			cout << "链表中没有此元素！" << endl;
			return -1;
		}
	}
	cout << "链表中" << e << "元素的位置是第" << count << "位。" << endl;
	return count;
}
template <typename T>
int StaticLinkList<T>::ListLength()
{
	return m_length;
}
template <typename T>
bool StaticLinkList<T>::Empty()
{
	if (m_length)
	{
		return false;
	}
	return true;
}
template <typename T>
bool StaticLinkList<T>::ListDelete(int i)
{
	int p = 0;
	if (i < 1 || i>m_length)
	{
		cout << "删除位置不合法！" << endl;
		return false;
	}
	if (i >= 1 || i <=  m_length)
	{
		for (int j = 0; j < i - 1; j++)
		{
			p = m_data[p].cur;
		}
		int coll = m_data[p].cur;
		m_data[p].cur = m_data[coll].cur;
		m_data[coll].cur = e_NOUSE;
		cout << "成功删除位置为" << i << "的元素" << m_data[coll].data << endl;
		m_length--;
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	StaticLinkList<int> obj;
	obj.ListInsert(1, 12);
	obj.ListInsert(1, 24);
	obj.ListInsert(3, 49);
	obj.ListInsert(2, 100);
	obj.ListInsert(5, 190);
	obj.ListInsert(4, 300);
	obj.DisplayList();
	obj.GetElem(1);
	obj.GetElem(100);
	obj.ListDelete(2);
	obj.DisplayList();
	obj.ListDelete(5);
	obj.DisplayList();
	obj.ListDelete(1);
	obj.DisplayList();
	obj.ListDelete(0);
	obj.DisplayList();
	return 0;
}