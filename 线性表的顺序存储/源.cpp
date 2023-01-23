#include <iostream>
using namespace std;
template <typename T>//T��������Ԫ�ص�����
struct Node
{
	T data;//�����򣬴������Ԫ��
	Node <T>* next;//ָ����ָ����һ��ͬ���͵Ľڵ�
};
//������Ķ���
template <typename T>
class LinkList
{
public:
	LinkList();//���캯��
	~LinkList();//��������
	bool ListInsert(int i, const T& e);//�ڵ�I��λ�ò���
	bool ListDelete(int i);//�ڵ�I��λ��ɾ��
	bool GetElem(int i, T& e);//��ȡ��I��λ�õ�Ԫ��
	int LocateElem(const T& e);//��Ԫ�ز������ڵ������һ�γ��ֵĵ�λ��
	void DisplayList();//����������е�����Ԫ��
	int ListLength();//���������ĳ���
	bool Empty();//�жϵ������Ƿ�Ϊ��
	void ReverseDataList();//��ת����������
	void ReverseList();//��ת������
	bool InsertPriorNode(Node<T>* pcurr, const T& e);
	bool ListDelete();
	//������ĳ���ڵ�֮ǰ����ڵ�
private:
		Node<T>* m_head;//ͷָ�루ָ�������һ���ڵ��ָ�룩
		int m_length;//������ǰ����
};
//ͨ�����캯���Ե�������г�ʼ��
template <typename T>
LinkList<T>::LinkList()
{
	cout << "���캯������" << endl;
	m_head = new Node<T>;//�ȴ���һ��ͷ���
	m_head->next = nullptr;
	m_length = 0;//ͷ��㲻���뵥����ĳ���
	/*
	�������ͷ���ĳ�ʼ��
	m_head=nullptr;
	m_length=0;          
	*/
}
//������Ԫ�ز���������ڵ�i��λ�ò���ָ��Ԫ��e��
template <typename T>
bool LinkList<T>::ListInsert(int i, const T& e)
{
	//�жϲ���λ���Ƿ�Ϸ�
	if (i<1 || i>(m_length+1))
	{
		cout << "Ԫ�ز���λ�ò��Ϸ���" << endl;
		return false;
	}
	Node<T>* p_curr = m_head;
	//forѭ�������ҵ���i-1���ڵ�
	if (m_length == 0)
	{
		Node<T>* node = new Node<T>;//(1)
		node->data = e;//(2)
		node->next = nullptr;//���½ڵ����Ϻ����ڵ�
		p_curr->next = node;//�õ�ǰλ�������½ڵ�
		cout << "����λ��Ϊ" << i << "�ɹ���λ��Ϊ" << i << "����Ԫ��" << e << "!" << endl;
		m_length++;//ʵ�ʱ���һ
	}
	else
	{
		if (m_length >= i)
		{
			for (int j = 0; j < (i - 1); ++j)//j��0��ʼ����ʾp_currһ��ʼָ���0���ڵ�
			{
				p_curr = p_curr->next;//һֱ�ҵ���Ҫ�����λ��
				cout << "Ѱ�ҵ���" << j + 1 << "���ڵ�" << endl;
				cout << "-------laoding-------" << endl;
			}
			Node<T>* node = new Node<T>;//(1)
			node->data = e;//(2)
			node->next = p_curr->next;//���½ڵ����Ϻ����ڵ�
			p_curr->next = node;//�õ�ǰλ�������½ڵ�
			cout << "m_length=" << m_length << "����λ��Ϊ" << i << "�ɹ���λ��Ϊ" << i << "����Ԫ��" << e << "!" << endl;
			m_length++;//ʵ�ʱ���һ
			cout << "-----���������Ϊ-----" << endl;
			Node<T>* p_curr1 = m_head->next;
			for (int j = 1; j < m_length+1; ++j)//j��0��ʼ����ʾp_currһ��ʼָ���0���ڵ�
			{

				cout << p_curr1->data << " ";
				p_curr1 = p_curr1->next;
			}
			cout << endl;
		}
		else
		{
			for (int j = 0; j < (i - 1); ++j)//j��0��ʼ����ʾp_currһ��ʼָ���0���ڵ�
			{
				p_curr = p_curr->next;//һֱ�ҵ���Ҫ�����λ��
				cout << "Ѱ�ҵ���" << j+1 << "���ڵ�" << endl;
				cout << "-------laoding-------" << endl;
			}
			Node<T>* node = new Node<T>;//(1)
			node->data = e;//(2)
			node->next = nullptr;//���½ڵ����Ͽ�ָ��
			p_curr->next = node;//�õ�ǰλ�������½ڵ�
			cout << "m_length=" << m_length << "����λ��Ϊ" << i << "�ɹ���λ��Ϊ" << i << "����Ԫ��" << e << "!" << endl;
			m_length++;//ʵ�ʱ���һ
			cout << "-----���������Ϊ-----" << endl;
			Node<T>* p_curr2 = m_head;
			Node<T>* p_curr1 = p_curr2->next;
			for (int j = 1; j < m_length+1; ++j)//j��0��ʼ����ʾp_currһ��ʼָ���0���ڵ�
			{

				cout << p_curr1->data << " ";
				p_curr1 = p_curr1->next;
			}
			cout << endl;
		}
	}
}
//������Ԫ�ز���������ڵ�i��λ�ò���ָ��Ԫ��e��(����ͷ��㣩
/* 
template <typename T>
bool LinkList<T>::ListInsert(int i,const T& e)
{
   //�жϲ���λ��i�Ƿ�Ϸ�
   if(i<1||i>(m_length+1))
   {
      cout<<"Ԫ��"<<e<<"����λ��"<<i<<"���Ϸ�"<<endl;
	  return false;
   }
   if(i==1)
   {
       Node<T>* node= new Node<T>;
	   node->data=e;
	   node->netx=m_head;
	   m_head=node;//ͷָ��ָ�����ĵ�һ��Ԫ��
	   cout<<"�ɹ���λ��Ϊ"<<i<<"������Ԫ��"<<e<<"!"<<endl;
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
//������ɨ�蹦��
template <typename T>
void LinkList<T>::DisplayList()
{
	Node<T>* p_curr = m_head->next;
	for (int j = 1; j < m_length+1; ++j)//j��0��ʼ����ʾp_currһ��ʼָ���0���ڵ�
	{

		cout << p_curr->data << " ";
		p_curr = p_curr->next;
	}
	cout << endl;
}
template <typename T>
bool LinkList<T>::InsertPriorNode(Node<T>* pcurr, const T& e)
{
	//�ڽڵ�pcurr֮ǰ�����½ڵ㣬�½ڵ��������Ϊe
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
		cout << "��ǰ������Ϊ�գ�����ɾ���κ����ݣ�" << endl;
		return false;
	}
	Node<T>* p_curr=m_head;
	if (i<1 || i>m_length)
	{
		cout << "ɾ��λ�ò��Ϸ���" << endl;
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
		cout << "�ɹ�ɾ��λ��Ϊ" << i << "��Ԫ��" << node->data << "��" << endl;
		delete node;
		m_length--;//����һ
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
		cout << "�ɹ�ɾ��λ��Ϊ" << i << "��Ԫ��" << node->data << "��" << endl;
		delete node;
		m_length--;//����һ
		return true;
	}
}
template <typename T>
bool LinkList<T>::GetElem(int i,  T& e)//��ȡ��i��λ�õ�Ԫ��ֵ
{
	if (i<1 || i>m_length)
	{
		cout << "��λ�ò��Ϸ�" << endl;
		return false;
	}
	Node<T>* p_curr = m_head;
	for (int j = 0; j < i; j++)
	{
		p_curr = p_curr->next;
	}
	e = p_curr->data;
	cout << "��" << i << "λԪ�ص�ֵΪ" << e << endl;
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
		cout << "�õ������в�����ֵΪ" << e << "��Ԫ�أ�" << endl;
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
void LinkList<T>::ReverseDataList()//��ת����������
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
	Node<T>* pothersjd = m_head->next -> next;//ָ��ڶ����ڵ㿪ʼ�ĺ����ڵ�
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
LinkList<T>::~LinkList()//�ͷŵ������е�Ԫ��
{
	Node<T>* pnode = m_head->next;
	Node<T>* ptmp;
	cout << "������������" << endl;
	while (pnode != nullptr)
	{
		ptmp = pnode;
		pnode = pnode->next;
		m_head->next = pnode;//���п���
		delete ptmp;
	}
	delete m_head;//�ͷ�ͷ���
	cout << "--�������--nullptr" << endl;
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
		m_head->next = pnode;//���п���
		delete ptmp;
	}
	delete m_head;//�ͷ�ͷ���
}
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//����ڴ�й©
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