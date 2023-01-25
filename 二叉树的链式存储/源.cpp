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
enum ECCHILDSIGN//�ڵ���
{
	E_Root,//����
	E_ChildLeft,//����
	E_ChildRight//�Һ���
};
//����ÿ���ڵ�Ķ���
template <typename T>//T�������ݵ�����
struct BinaryTreeNode
{
	T data;//������
	BinaryTreeNode* leftChild;//���ӽڵ�ָ��
	BinaryTreeNode* rightChild;//�Һ��ӽڵ�ָ��
	//BinaryTreeNode* parent;//���ڵ�ָ�룬������Ҫ��������
};
//�������Ķ���
template <typename T>
class BinaryTree
{
public:
	BinaryTree();//���캯��
	~BinaryTree();//��������
	//����һ�����ڵ�
	BinaryTreeNode<T>* CreateNode(BinaryTreeNode<T>* parent, ECCHILDSIGN pointsign, const T& e);
	//�ͷ�һ�����ڵ�
	void RleaseNode(BinaryTreeNode<T>* pnode);
	//������չ��������ǰ���������������һ�ö�����
	void CreateBiTreeAccordPT(char* pstr); 
	void preOrder();//ǰ�����
	void inOrder();//�������
	void postOrder();//�������
	void levelOrder();//�������
private:
	BinaryTreeNode<T>* root;//�����ڵ��ָ��
	//������չ��������ǰ��������д����������ĵݹ麯��
	void CreateBiTreeAccordPTRecu(BinaryTreeNode<T>*& tnode,char* &pstr);//��������Ϊ���ã�ȷ���ݹ�����жԲ����ĸı��Ӱ�쵽����ֵ
	void preOrder(BinaryTreeNode<T>* tNode);//ǰ�����
	void inOrder(BinaryTreeNode<T>* tNode);//�������
	void postOrder(BinaryTreeNode<T>* tNode);//�������
	void levelOrder(BinaryTreeNode<T>* tNode);//�������
};
//���캯��
template<typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;//����Ϊ����
}
//��������
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	RleaseNode(root);//�Ӹ���ʼ�ͷŽڵ�
}
//�ͷŶ������ڵ�
template <typename T>
void BinaryTree<T>::RleaseNode(BinaryTreeNode<T>* pnode)
{
	if (pnode != nullptr)
	{
		RleaseNode(pnode->leftChild);//�ͷ���������
		RleaseNode(pnode->rightChild);//�ͷ������Һ���
	}
	delete pnode;
}
//����һ�����ڵ�
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::CreateNode(BinaryTreeNode<T>* parentnode, ECCHILDSIGN pointsign, const T& e)
{
	//���½ڵ㴴������
	BinaryTreeNode<T>* tmpnode = new BinaryTreeNode<T>;
	tmpnode->data = e;//���½ڵ㴫������
	tmpnode->leftChild = nullptr;
	tmpnode->rightChild = nullptr;
	//���½ڵ������ȷ��λ��
	if (pointsign == E_Root)//�������������ڵ�
	{
		root = tmpnode;
	}
	if (pointsign == E_ChildLeft)//������������
	{
		parentnode->leftChild = tmpnode;
	}
	else if (pointsign == E_ChildRight)//���������Һ��ӽڵ�
	{
		parentnode->rightChild = tmpnode;
	}
	return tmpnode;
}
//������չ��������ǰ���������������һ�ö�����
template <typename T>
void BinaryTree<T>::CreateBiTreeAccordPT(char* pstr)
{
	CreateBiTreeAccordPTRecu(root, pstr);
}
//������չ��������ǰ��������д����������ĵݹ麯��
template <typename T>
void BinaryTree<T>::CreateBiTreeAccordPTRecu(BinaryTreeNode<T>*& tnode, char*& pstr)//��������Ϊ���ã�ȷ���ݹ�
{
	//ABD###C#B##
	if (*pstr == '#')
	{
		tnode = nullptr;
	}
	else
	{
		//������
		tnode = new BinaryTreeNode<T>;//�����½ڵ�
		tnode->data = *pstr;
		CreateBiTreeAccordPTRecu(tnode->leftChild, ++pstr);//����������
		CreateBiTreeAccordPTRecu(tnode->rightChild, ++pstr);//����������
	}
}
//ǰ�����������
//������
template <typename T>
void BinaryTree<T>::preOrder()
{
	preOrder(root);
}
template <typename T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* tNode)
{
	if (tNode != nullptr)//���ǿն�����
	{
		cout << tNode->data << " ";//����ڵ��������ֵ
		preOrder(tNode->leftChild);//�ݹ鷽ʽǰ�����������
		preOrder(tNode->rightChild);//�ݹ鷽ʽǰ�����������
	}
}
//�������������
//�����
template <typename T>
void BinaryTree<T>::inOrder()
{
	inOrder(root);
}
template <typename T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* tNode)
{
	if (tNode != nullptr)//���ǿն�����
	{
		inOrder(tNode->leftChild);//�ݹ鷽ʽ�������������
		cout << tNode->data << " ";//����ڵ��������
		inOrder(tNode->rightChild);//�ݹ鷽ʽ�������������
	}
}
//�������������
//���Ҹ�
template <typename T>
void BinaryTree<T>::postOrder()
{
	postOrder(root);
}
template <typename T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* tNode)
{
	if (tNode != nullptr)//���ǿն�����
	{
		postOrder(tNode->leftChild);//�ݹ鷽ʽ�������������
		postOrder(tNode->rightChild);//�ݹ鷽ʽ�������������
		cout << tNode->data << " ";//����ڵ��������
	}
}
//�������������
template <typename T>
void BinaryTree<T>::levelOrder()
{
	levelOrder(root);
}
template <typename T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* tNode)
{
	if (tNode != nullptr)//���������ǿ�
	{
		BinaryTreeNode<T>* tmpnode;
		LinkQueue<BinaryTreeNode<T>* > lnobj;//ע�����Ԫ�������ǽڵ�ָ������
		lnobj.EnQueue(tNode);//�ȰѸ��ڵ�ָ�����
		while (!lnobj.Empty())//ѭ���ж϶����Ƿ�Ϊ��
		{
			lnobj.DeQueue(tmpnode);//������
			cout << (char)tmpnode->data << " ";
			if (tmpnode->leftChild != nullptr)
			{
				lnobj.EnQueue(tmpnode->leftChild);//�������
			}
			if (tmpnode->rightChild != nullptr)
			{
				lnobj.EnQueue(tmpnode->rightChild);//�Һ������
			}
		}//end while
	}// end if
}
int main()
{
	BinaryTree<int> mytree;//����������
	BinaryTreeNode<int>* rootpoint = mytree.CreateNode(nullptr, E_Root, 'A');//�������ڵ�A
	BinaryTreeNode<int>* subpoint = mytree.CreateNode(rootpoint, E_ChildLeft, 'B');//�������ڵ�����ӽڵ�B
	subpoint = mytree.CreateNode(subpoint, E_ChildLeft, 'D');//����B�����ӽڵ�D
    subpoint = mytree.CreateNode(rootpoint, E_ChildRight, 'C');//�������ڵ�����ӽڵ�C
	subpoint = mytree.CreateNode(subpoint, E_ChildRight, 'E');//����C�����ӽڵ�E
	BinaryTree<char> mytree2;//����������
	mytree2.CreateBiTreeAccordPT((char*)"ABD###C#E##");//������չ��������ǰ��������д���������
	cout << "ǰ���������Ϊ��";
	mytree2.preOrder();
	cout << endl;
	cout << "�����������Ϊ��";
	mytree2.inOrder();
	cout << endl;
	cout << "�����������Ϊ��";
	mytree2.postOrder();
	cout << endl;
	cout << "�����������Ϊ��";
	mytree2.levelOrder();
	cout << endl;
	return 0;
}