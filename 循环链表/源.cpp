#include <iostream>
using namespace std;
//˫������ÿ���ڵ�Ķ���
template <typename T>//T��������Ԫ�صĵ�����
struct DbNode
{
	T data;//�����򣬴������Ԫ��
	DbNode<T>* prior;//ǰ��ָ�룬ָ��ǰһ��ͬ���͵Ľڵ�
	DbNode<T>* next;//���ָ�룬ָ����һ��ͬ���͵Ľڵ�
};
template <typename T>
class DbLinkList
{
public:
	DbLinkList();//���캯��
	~DbLinkList();//��������
	bool ListInsert(int i, const T& e);//�ڵ�I��λ�ò���
	bool ListDelete(int i);//�ڵ�I��λ��ɾ��
	bool DeleteNode(DbNode<T>* p);//ɾ���ڵ�
	bool GetElem(int i, T& e);//��ȡ��I��λ�õ�Ԫ��
	int LocateElem(const T& e);//��Ԫ�ز������ڵ������һ�γ��ֵĵ�λ��
	void DisplayList();//����������е�����Ԫ��
	int ListLength();//���������ĳ���
	bool Empty();//�жϵ������Ƿ�Ϊ��
	void ReverseDataList();//��ת����������
	void ReverseList();//��ת������
	bool InsertPriorNode(DbNode<T>* pcurr, const T& e);
	bool ListDelete();
	//������ĳ���ڵ�֮ǰ����ڵ�
private:
	DbNode<T>* m_head;//ͷָ�루ָ�������һ���ڵ��ָ�룩
	int m_length;//������ǰ����
};
template <typename T>
DbLinkList<T>::DbLinkList()
{
	m_length = 0;//��¼������
	m_head = new DbNode<T>;//�½�һ��ͷ���
	m_head->next = nullptr;//ͷ���ĺ�̽ڵ㸳ֵΪ��ָ��
	m_head->prior = nullptr;//ͷ����ǰ���ڵ㸳ֵΪ��ָ��
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
		cout << "����λ�ò��Ϸ�������ʧ�ܣ�" << endl;
		return false;
	}
	if (m_length == 0)
	{
		DbNode<T>* pDbNode = new DbNode<T>;
		pDbNode->data = e;
		pDbNode->prior = m_head;
		pDbNode->next = nullptr;
		m_head->next = pDbNode;
		cout << "�ɹ���λ��" << i << "����Ԫ��" << e << endl;
		m_length++;
		return true;
	}
	if (i == m_length + 1)
	{
		DbNode<T>* pDbNode = new DbNode<T>;//�½��ڵ�
		DbNode<T>* p_curr = m_head;
		for (int j = 0; j < i - 1; j++)
		{
			p_curr = p_curr->next;
		}//�ҵ����һ���ڵ�
		pDbNode->data = e;//����������
		pDbNode->next = nullptr;//���һ���ڵ�ĺ�̸�ֵΪ��ָ��
		pDbNode->prior = p_curr;//���һ���ڵ��ǰ��ָ�븳ֵΪ֮ǰ��β���
		p_curr->next = pDbNode;//֮ǰ��β���ĺ��ָ�븳ֵΪ�µ�β���
		cout << "�ɹ���λ��" << i << "����Ԫ��" << e << endl;
		m_length++;
		return true;
	}
	if (i >= 1 && i <= m_length)
	{
		DbNode<T>* pDbNode = new DbNode<T>;//�½��ڵ�
		DbNode<T>* p_curr = m_head;
		for (int j = 0; j < i - 1; j++)
		{
			p_curr = p_curr->next;
		}//�ҵ���i-1���ڵ�
		pDbNode->data = e;//����������
		pDbNode->next = p_curr->next;//���Ӻ�̽ڵ�
		p_curr->next = pDbNode;//���º�̽ڵ�
		(p_curr->next)->prior = pDbNode;//����ǰ�����
		pDbNode->prior = p_curr;//����ǰ���ڵ�
		cout << "�ɹ���λ��" << i << "����Ԫ��" << e << endl;
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
	DbNode<T>* pDbNode = new DbNode<T>;//��ʼ���½ڵ�
	pDbNode->data = e;//���½ڵ��������ֵ
	DbNode<T>* p_curr = pcurr->prior;//�ҵ�����ڵ��ǰ���ڵ�
	pDbNode->next = pcurr;//���½ڵ����Ϻ�̽ڵ�
	pDbNode->prior = p_curr;//���½ڵ�����ǰ���ڵ�
	pcurr->prior = pDbNode;//���²���ڵ��ǰ���ڵ�
	p_curr->next = pDbNode;//���²���ڵ�ǰһ���ڵ�ĺ�̽ڵ�
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
		cout << "ɾ��λ�ò��Ϸ���" << endl;
		return false;
	}
	if (i == m_length)
	{
		for (int j = 0; j < i - 1; j++)
		{
			p_curr = p_curr->next;
		}
		DbNode<T>* p = p_curr->next;//�ҵ���iλ�Ľڵ�
		cout << "��ɾ��λ��Ϊ" << i << "�Ľڵ�," << "Ԫ��ֵΪ" << p->data << endl;
		delete p;//ɾ����iλ�Ľڵ�
		p_curr->next = nullptr;
		return true;
	}
	if (i >= 1 && i < m_length)
	{
		for (int j = 0; j < i - 1; j++)
		{
			p_curr = p_curr->next;
		}
		DbNode<T>* p = p_curr->next;//�ҵ���iλ�Ľڵ�
		DbNode<T>* q = p->next;//�ҵ���i+1λ�Ľڵ�
		cout << "��ɾ��λ��Ϊ" << i << "�Ľڵ�," << "Ԫ��ֵΪ" << p->data << endl;
		delete p;//ɾ����iλ�Ľڵ�
		p_curr->next = q;//���µ�i-1λ�ڵ�ĺ�̽ڵ�
		q->prior = p_curr;//���µ�i+1λ�ڵ��ǰ���ڵ�
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
	DbNode<T>* p_curr;//��ȡp�ڵ�
	DbNode<T>* p_currP;//��ȡp�ڵ��ǰ���ڵ�
	DbNode<T>* p_currN;//��ȡp�ڵ�ĺ�̽ڵ�
	p_currP = p->prior;//��ֵ
	p_curr = p;//��ֵ
	p_currN = p->next;//��ֵ
	p_currP->next = p_currN;//����p�ڵ��ǰ���ڵ�ĺ�̽ڵ�
	p_currN->prior = p_currP; //����p�ڵ�ĺ�̽ڵ��ǰ���ڵ�
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