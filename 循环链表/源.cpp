#include <iostream>
using namespace std;
//双链表中每个节点的定义
template <typename T>//T代表数据元素的的类型
struct DbNode
{
	T data;//数据域，存放数据元素
	DbNode<T>* prior;//前驱指针，指向前一个同类型的节点
	DbNode<T>* next;//后继指针，指向下一个同类型的节点
};
template <typename T>
class DbLinkList
{
public:
	DbLinkList();//构造函数
	~DbLinkList();//析构函数
	bool ListInsert(int i, const T& e);//在第I个位置插入
	bool ListDelete(int i);//在第I个位置删除
	bool DeleteNode(DbNode<T>* p);//删除节点
	bool GetElem(int i, T& e);//获取第I个位置的元素
	int LocateElem(const T& e);//按元素查找其在单链表第一次出现的的位置
	void DisplayList();//输出单链表中的所有元素
	int ListLength();//输出单链表的长度
	bool Empty();//判断单链表是否为空
	void ReverseDataList();//翻转单链表数据
	void ReverseList();//翻转单链表
	bool InsertPriorNode(DbNode<T>* pcurr, const T& e);
	bool ListDelete();
	//在链表某个节点之前插入节点
private:
	DbNode<T>* m_head;//头指针（指向链表第一个节点的指针）
	int m_length;//单链表当前长度
};
template <typename T>
DbLinkList<T>::DbLinkList()
{
	m_length = 0;//记录链表长度
	m_head = new DbNode<T>;//新建一个头结点
	m_head->next = nullptr;//头结点的后继节点赋值为空指针
	m_head->prior = nullptr;//头结点的前驱节点赋值为空指针
}
template <typename T>
DbLinkList<T>::~DbLinkList()
{

}
template <typename T>
bool DbLinkList<T>::ListInsert(int i, const T& e)
{
	if (i<1 || i>(m_length + 1))
	{
		cout << "插入位置不合法！插入失败！" << endl;
		return false;
	}
	if (m_length == 0)
	{
		DbNode<T>* pDbNode = new DbNode<T>;
		pDbNode->data = e;
		pDbNode->prior = m_head;
		pDbNode->next = nullptr;
		m_head->next = pDbNode;
		cout << "成功在位置" << i << "插入元素" << e << endl;
		m_length++;
		return true;
	}
	if (i == m_length + 1)
	{
		DbNode<T>* pDbNode = new DbNode<T>;//新建节点
		DbNode<T>* p_curr = m_head;
		for (int j = 0; j < i - 1; j++)
		{
			p_curr = p_curr->next;
		}//找到最后一个节点
		pDbNode->data = e;//传入数据域
		pDbNode->next = nullptr;//最后一个节点的后继赋值为空指针
		pDbNode->prior = p_curr;//最后一个节点的前驱指针赋值为之前的尾结点
		p_curr->next = pDbNode;//之前的尾结点的后继指针赋值为新的尾结点
		cout << "成功在位置" << i << "插入元素" << e << endl;
		m_length++;
		return true;
	}
	if (i >= 1 && i <= m_length)
	{
		DbNode<T>* pDbNode = new DbNode<T>;//新建节点
		DbNode<T>* p_curr = m_head;
		for (int j = 0; j < i - 1; j++)
		{
			p_curr = p_curr->next;
		}//找到第i-1个节点
		pDbNode->data = e;//传入数据域
		pDbNode->next = p_curr->next;//连接后继节点
		p_curr->next = pDbNode;//更新后继节点
		(p_curr->next)->prior = pDbNode;//更新前驱结点
		pDbNode->prior = p_curr;//连接前驱节点
		cout << "成功在位置" << i << "插入元素" << e << endl;
		m_length++;
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
bool DbLinkList<T>::InsertPriorNode(DbNode<T>* pcurr, const T& e)
{
	DbNode<T>* pDbNode = new DbNode<T>;//初始化新节点
	pDbNode->data = e;//给新节点的数据域赋值
	DbNode<T>* p_curr = pcurr->prior;//找到插入节点的前驱节点
	pDbNode->next = pcurr;//将新节点链上后继节点
	pDbNode->prior = p_curr;//将新节点链上前驱节点
	pcurr->prior = pDbNode;//更新插入节点的前驱节点
	p_curr->next = pDbNode;//更新插入节点前一个节点的后继节点
	return true;
}
template <typename T>
void DbLinkList<T>::DisplayList()
{
	DbNode<T>* p_curr = m_head->next;
	while (p_curr != nullptr)
	{
		cout << p_curr->data << " ";
		p_curr = p_curr->next;
	}
}
template <typename T>
bool DbLinkList<T>::ListDelete(int i)
{
	DbNode<T>* p_curr = m_head;
	if (i<1 || i>m_length)
	{
		cout << "删除位置不合法！" << endl;
		return false;
	}
	if (i == m_length)
	{
		for (int j = 0; j < i - 1; j++)
		{
			p_curr = p_curr->next;
		}
		DbNode<T>* p = p_curr->next;//找到第i位的节点
		cout << "已删除位置为" << i << "的节点," << "元素值为" << p->data << endl;
		delete p;//删除第i位的节点
		p_curr->next = nullptr;
		return true;
	}
	if (i >= 1 && i < m_length)
	{
		for (int j = 0; j < i - 1; j++)
		{
			p_curr = p_curr->next;
		}
		DbNode<T>* p = p_curr->next;//找到第i位的节点
		DbNode<T>* q = p->next;//找到第i+1位的节点
		cout << "已删除位置为" << i << "的节点," << "元素值为" << p->data << endl;
		delete p;//删除第i位的节点
		p_curr->next = q;//更新第i-1位节点的后继节点
		q->prior = p_curr;//更新第i+1位节点的前驱节点
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
bool DbLinkList<T>::DeleteNode(DbNode<T>* p)
{
	DbNode<T>* p_curr;//获取p节点
	DbNode<T>* p_currP;//获取p节点的前驱节点
	DbNode<T>* p_currN;//获取p节点的后继节点
	p_currP = p->prior;//赋值
	p_curr = p;//赋值
	p_currN = p->next;//赋值
	p_currP->next = p_currN;//更新p节点的前驱节点的后继节点
	p_currN->prior = p_currP; //更新p节点的后继节点的前驱节点
	return true;
}
int main()
{
	DbLinkList<int> obj;
	obj.ListInsert(1, 12);
	obj.ListInsert(1, 24);
	obj.ListInsert(3, 48);
	obj.ListInsert(2, 100);
	obj.ListDelete(2);
	obj.DisplayList();
	return 0;
}