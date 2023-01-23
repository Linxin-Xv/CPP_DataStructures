#include <iostream>
using namespace std;
#define MaxSize 201//��̬����ĳߴ磬���������±�Ϊ0-200
enum NODEUSE//ö�ٽڵ�ʹ�����
{
	//��Щö��ֵ��ȡ��ֵ
	e_NOUSE = -1,//δʹ��
	e_LAST = -2//���һ���ڵ�
};
//��̬������ÿ���ڵ�Ķ���
template <typename T>//T��������Ԫ�ص�����
struct Node
{
	T data;//Ԫ��������
	int cur;//�α�
};
//��̬����Ķ���
template <typename T>
class StaticLinkList
{
public:
	StaticLinkList();//���캯��
	~StaticLinkList();//��������
	int FindAnIdlePos();//�ҵ�һ������λ�����ڴ������
	bool ListInsert(int i, const T& e);//�ڵ�i��λ�ò���ָ��Ԫ��e
	bool ListDelete(int i);//ɾ����i��λ��Ԫ��
	bool GetElem(const T& e);//��õ�i��λ�õ�Ԫ��ֵ
	int LocateElem(const T& e);//���Ԫ��e��һ�γ��ֵ�λ��
	void DisplayList();//ɨ�農̬����
	int ListLength();//��ȡ��̬����ĳ���
	bool Empty();//�жϾ�̬�����Ƿ�Ϊ��
private:
	Node<T> m_data[MaxSize];//����ڵ����ݵ�����
	int m_length;//�������鳤��
};
template <typename T>
StaticLinkList<T>::StaticLinkList()//ͨ�����캯���������ʼ��
{
	for (int i = 1; i < MaxSize; i++)//���±�1��ʼ�Ľڵ����ڱ���ʵ�ʵ����ݣ���Щ�ڵ��cur�б�Ҫ����ֵ����ͷ�����ʵ���ø�ֵ��
	{
		m_data[i].cur = e_NOUSE;//�����Щ�ڵ㶼û��ʹ��
	}
	m_length = 0;//����Ϊ0
}
template <typename T>
StaticLinkList<T>::~StaticLinkList()
{

}
template <typename T>
int StaticLinkList<T>::FindAnIdlePos()//��m_data���ҵ�һ������λ�ñ������ݣ���û�ҵ��򷵻�-1
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
bool StaticLinkList<T>::ListInsert(int i, const T& e)//�ڵ�i��λ�ò���ָ��Ԫ��e
{
	if (i<1 || i>(m_length + 1))
	{
		cout << "����λ�ò��Ϸ���" << endl;
		return false;
	}
	int iIdx;
	if ((iIdx = FindAnIdlePos()) == -1)
	{
		cout << "����������" << endl;
		return false;
	}
	if (i == 1)
	{
		if (m_length == 0)
		{
			m_data[iIdx].cur = e_LAST;//��ע��β
			m_data[iIdx].data = e;//����������
			cout << "���I" << endl;
		}
		else
		{
			m_data[iIdx].cur = m_data[0].cur;
			m_data[iIdx].data = e;
			cout << "���II" << endl;
		}
		m_data[0].cur = iIdx;
		m_length++;
		cout << "����λ�ò��Ϸ���" << endl;
		return true;
	}
	else
	{
		int prior = 0;//�ҵ���i-1���ڵ���α�
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
		�˴�ע�ͷ������Ҳ�����ԭ��ı���*/
		m_length++;
		cout << "���III" << endl;
		cout << "����λ�ò��Ϸ���" << endl;
		return true;
	}
}
template <typename T>
void StaticLinkList<T>::DisplayList()//�����̬������ȫ��Ԫ��
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
		cout << "���������޴�Ԫ�أ�" << endl;
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
			cout << "������û�д�Ԫ�أ�" << endl;
			return false;
		}
	}
	cout << "������" << e << "Ԫ�ص�λ���ǵ�" << count << "λ��" << endl;
	return true;
}
template <typename T>
int StaticLinkList<T>::LocateElem(const T& e)
{
	if (m_length == 0)
	{
		cout << "���������޴�Ԫ�أ�" << endl;
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
			cout << "������û�д�Ԫ�أ�" << endl;
			return -1;
		}
	}
	cout << "������" << e << "Ԫ�ص�λ���ǵ�" << count << "λ��" << endl;
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
		cout << "ɾ��λ�ò��Ϸ���" << endl;
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
		cout << "�ɹ�ɾ��λ��Ϊ" << i << "��Ԫ��" << m_data[coll].data << endl;
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