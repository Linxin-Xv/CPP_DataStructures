#include <iostream>
using namespace std;
template <typename T>//T代表数据元素的类型
struct Node
{
	T data;//数据域，存放数据元素
	Node <T>* next;//指针域，指向下一个同类型的节点
};
//单链表的定义
template <typename T>
class LinkList
{
public:
	LinkList();//构造函数
	~LinkList();//析构函数
	bool ListInsert(int i, const T& e);//在第I个位置插入
	bool ListDelete(int i);//在第I个位置删除
	bool GetElem(int i, T& e);//获取第I个位置的元素
	int LocateElem(const T& e);//按元素查找其在单链表第一次出现的的位置
	void DisplayList();//输出单链表中的所有元素
	int ListLength();//输出单链表的长度
	bool Empty();//判断单链表是否为空
	void ReverseDataList();//翻转单链表数据
	void ReverseList();//翻转单链表
	bool InsertPriorNode(Node<T>* pcurr, const T& e);
	bool ListDelete();
	//在链表某个节点之前插入节点
private:
		Node<T>* m_head;//头指针（指向链表第一个节点的指针）
		int m_length;//单链表当前长度
};
//通过构造函数对单链表进行初始化
template <typename T>
LinkList<T>::LinkList()
{
	cout << "构造函数启动" << endl;
	m_head = new Node<T>;//先创建一个头结点
	m_head->next = nullptr;
	m_length = 0;//头结点不计入单链表的长度
	/*
	如果不带头结点的初始化
	m_head=nullptr;
	m_length=0;          
	*/
}
//单链表元素插入操作（在第i个位置插入指定元素e）
template <typename T>
bool LinkList<T>::ListInsert(int i, const T& e)
{
	//判断插入位置是否合法
	if (i<1 || i>(m_length+1))
	{
		cout << "元素插入位置不合法！" << endl;
		return false;
	}
	Node<T>* p_curr = m_head;
	//for循环用于找到第i-1个节点
	if (m_length == 0)
	{
		Node<T>* node = new Node<T>;//(1)
		node->data = e;//(2)
		node->next = nullptr;//让新节点连上后续节点
		p_curr->next = node;//让当前位置连上新节点
		cout << "插入位置为" << i << "成功在位置为" << i << "插入元素" << e << "!" << endl;
		m_length++;//实际表长加一
	}
	else
	{
		if (m_length >= i)
		{
			for (int j = 0; j < (i - 1); ++j)//j从0开始，表示p_curr一开始指向第0个节点
			{
				p_curr = p_curr->next;//一直找到需要插入的位置
				cout << "寻找到第" << j + 1 << "个节点" << endl;
				cout << "-------laoding-------" << endl;
			}
			Node<T>* node = new Node<T>;//(1)
			node->data = e;//(2)
			node->next = p_curr->next;//让新节点连上后续节点
			p_curr->next = node;//让当前位置连上新节点
			cout << "m_length=" << m_length << "插入位置为" << i << "成功在位置为" << i << "插入元素" << e << "!" << endl;
			m_length++;//实际表长加一
			cout << "-----插入后链表为-----" << endl;
			Node<T>* p_curr1 = m_head->next;
			for (int j = 1; j < m_length+1; ++j)//j从0开始，表示p_curr一开始指向第0个节点
			{

				cout << p_curr1->data << " ";
				p_curr1 = p_curr1->next;
			}
			cout << endl;
		}
		else
		{
			for (int j = 0; j < (i - 1); ++j)//j从0开始，表示p_curr一开始指向第0个节点
			{
				p_curr = p_curr->next;//一直找到需要插入的位置
				cout << "寻找到第" << j+1 << "个节点" << endl;
				cout << "-------laoding-------" << endl;
			}
			Node<T>* node = new Node<T>;//(1)
			node->data = e;//(2)
			node->next = nullptr;//让新节点连上空指针
			p_curr->next = node;//让当前位置连上新节点
			cout << "m_length=" << m_length << "插入位置为" << i << "成功在位置为" << i << "插入元素" << e << "!" << endl;
			m_length++;//实际表长加一
			cout << "-----插入后链表为-----" << endl;
			Node<T>* p_curr2 = m_head;
			Node<T>* p_curr1 = p_curr2->next;
			for (int j = 1; j < m_length+1; ++j)//j从0开始，表示p_curr一开始指向第0个节点
			{

				cout << p_curr1->data << " ";
				p_curr1 = p_curr1->next;
			}
			cout << endl;
		}
	}
}
//单链表元素插入操作（在第i个位置插入指定元素e）(不带头结点）
/* 
template <typename T>
bool LinkList<T>::ListInsert(int i,const T& e)
{
   //判断插入位置i是否合法
   if(i<1||i>(m_length+1))
   {
      cout<<"元素"<<e<<"插入位置"<<i<<"不合法"<<endl;
	  return false;
   }
   if(i==1)
   {
       Node<T>* node= new Node<T>;
	   node->data=e;
	   node->netx=m_head;
	   m_head=node;//头指针指向插入的第一个元素
	   cout<<"成功在位置为"<<i<<"处插入元素"<<e<<"!"<<endl;
	   m_length++;
	   return true;
   }
   else
   {
      Node<T>* p_curr=m_head;
      for(int j=0;j<(i-1);++j)
	  {
	      p_curr=p_curr->next;
	  }
	  Node<T>* node=new Node<T>;
	  node->data=e;
	  if((p_curr)!=nullptr)
	  {
	      node->next=p_curr->next;
	      p_curr->next=node;
	  }
	  else
	  {
	      node->next=nullptr;
	      p_curr->next=node;
	  }
   }

}
*/
//单链表扫描功能
template <typename T>
void LinkList<T>::DisplayList()
{
	Node<T>* p_curr = m_head->next;
	for (int j = 1; j < m_length+1; ++j)//j从0开始，表示p_curr一开始指向第0个节点
	{

		cout << p_curr->data << " ";
		p_curr = p_curr->next;
	}
	cout << endl;
}
template <typename T>
bool LinkList<T>::InsertPriorNode(Node<T>* pcurr, const T& e)
{
	//在节点pcurr之前插入新节点，新节点的数据域为e
	Node<T>* p_curr = new Node<T>;
	p_curr->data = e;
	p_curr->next = pcurr->next;
	pcurr->next = p_curr;
}
template <typename T>
bool LinkList<T>::ListDelete(int i)
{
	if (m_length < 1)
	{
		cout << "当前单链表为空，不能删除任何数据！" << endl;
		return false;
	}
	Node<T>* p_curr=m_head;
	if (i<1 || i>m_length)
	{
		cout << "删除位置不合法！" << endl;
		return false;
	}
	if (i >= 1 && i < m_length)
	{
		for (int j = 0; j < (i - 1); ++j)
		{
			p_curr = p_curr->next;
		}
		Node<T>* node;
		node = p_curr->next;
		p_curr->next = node->next;
		cout << "成功删除位置为" << i << "的元素" << node->data << "！" << endl;
		delete node;
		m_length--;//表长减一
		return true;
	}
	else
	{
		for (int j = 0; j < (i - 1); ++j)
		{
			p_curr = p_curr->next;
		}
		Node<T>* node;
		node = p_curr->next;
		p_curr->next = nullptr;
		cout << "成功删除位置为" << i << "的元素" << node->data << "！" << endl;
		delete node;
		m_length--;//表长减一
		return true;
	}
}
template <typename T>
bool LinkList<T>::GetElem(int i,  T& e)//获取第i个位置的元素值
{
	if (i<1 || i>m_length)
	{
		cout << "该位置不合法" << endl;
		return false;
	}
	Node<T>* p_curr = m_head;
	for (int j = 0; j < i; j++)
	{
		p_curr = p_curr->next;
	}
	e = p_curr->data;
	cout << "第" << i << "位元素的值为" << e << endl;
	return true;
}
template <typename T>
int LinkList<T>::LocateElem(const T& e)
{
	int k = 0;
	Node<T>* p_curr = m_head;
	for (int i = 0; i < m_length-1; i++)
	{
		p_curr = p_curr->next;
		if ((p_curr->data) == e)
		{
			++k;
			return k;
		}
		else
		{
			++k;
		}
	}
	if (((p_curr->next)->data) != e)
	{
		cout << "该单链表中不存在值为" << e << "的元素！" << endl;
		return 0;
	}
	else
	{
		return m_length;
	}
}
template <typename T>
int LinkList<T>::ListLength()
{
	return m_length;
}
template <typename T>
bool LinkList<T>::Empty()
{
	if(m_length==0)
	{ 
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
void LinkList<T>::ReverseDataList()//翻转单链表数据
{
	int k = m_length / 2;
	for (int i = 1; i <= k; i++)
	{
		Node<T>* p_currL = m_head;
		Node<T>* p_currR = m_head;
		for (int j = 1; j <= m_length - i; j++)
		{
			if (j <= i)
			{
				p_currL = p_currL->next;
			}
			p_currR = p_currR->next;
		}
		T a = p_currL->data;
		p_currL->data = p_currR->data;
		p_currL->data = a;
		p_currL = m_head;
		p_currR = m_head;
	}
}
template <typename T>
void LinkList<T>::ReverseList()
{
	if (m_length <= 1)
	{
		return;
	}
	Node<T>* pothersjd = m_head->next -> next;//指向第二个节点开始的后续节点
	m_head->next->next = nullptr;
	Node<T>* ptmp;
	while (pothersjd != nullptr)
	{
		ptmp = pothersjd;
		pothersjd = pothersjd->next;
		ptmp->next = m_head->next;
		m_head->next = ptmp;
	}
}
template <typename T>
LinkList<T>::~LinkList()//释放单链表中的元素
{
	Node<T>* pnode = m_head->next;
	Node<T>* ptmp;
	cout << "析构函数启动" << endl;
	while (pnode != nullptr)
	{
		ptmp = pnode;
		pnode = pnode->next;
		m_head->next = pnode;//可有可无
		delete ptmp;
	}
	delete m_head;//释放头结点
	cout << "--析构完成--nullptr" << endl;
}
template <typename T>
bool LinkList<T>::ListDelete()msvcp140d
{
	Node<T>* pnode = m_head->next;
	Node<T>* ptmp;
	while (pnode != nullptr)
	{
		ptmp = pnode;
		pnode = pnode->next;
		m_head->next = pnode;//可有可无
		delete ptmp;
	}
	delete m_head;//释放头结点
}
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//检测内存泄漏
	LinkList<int> slinkobj;
	slinkobj.ListInsert(1, 12);
	slinkobj.ListInsert(1, 24);
	slinkobj.ListInsert(3, 38);
	slinkobj.ListInsert(2, 139);
	slinkobj.ListInsert(3, 100);
	slinkobj.ListDelete(4);
	slinkobj.DisplayList();
	int k=0;
	slinkobj.GetElem(2, k);
	k=slinkobj.LocateElem(12);
	cout << k << endl;
	slinkobj.ReverseList();
	slinkobj.DisplayList();
	return 0;
}