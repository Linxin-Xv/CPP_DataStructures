#include <iostream>
using namespace std;
/*ջʵ������*/
//��ʽջ��ÿ���ڵ�Ķ���
template <typename T>
struct StackNode
{
	T data;//������
	StackNode<T>* next;//ָ�����һ��ͬ���͵Ľڵ�
};
//��ʽջ�Ķ���
template <typename T>
class LinkStack
{
public:
	LinkStack();//���캯��
	~LinkStack();//��������
	bool Push(const T& e);//��ջ����
	bool Pop(T& e);//��ջ����
	bool GetTop(T& e);//��ȡջ��Ԫ��
	void DisplayLinkStack();//ɨ�������ʽջ
	bool Empty();//�ж���ʽջ�Ƿ�Ϊ��ջ
	int ListLength();//������ʽջ����
private:
	int m_length;//ջ����
	StackNode<T>* m_top;//ջ����ַ(ָ�룩
};
template <typename T>
LinkStack<T>::LinkStack()
{
	int m_length = 0;//��ʼ��ջ�ĳ���Ϊ0
	m_top = nullptr;//ջ��ָ��Ϊ��ָ��
}
template <typename T>
LinkStack<T>::~LinkStack()//��������
{
	T k;
	while (m_length > 0)
	{
		Pop(k);//���ϳ�ջֱ����ʽջ�ĳ���Ϊ�����������
	}
}
template <typename T>
bool LinkStack<T>::Push(const T& e)
{
	if (m_length == 0)//����ǿ�ջ
	{
		StackNode<T>* p = new StackNode<T>;//Ϊջ��Ԫ�ط����ڴ�
		p->data = e;//��ջ��Ԫ�ش�����
		m_top = p;//��p�ĵ�ַ����ջ��
		m_top->next = nullptr;//��ջ��ָ���nextָ���ָ��
		m_length++;//��ʽջ�ĳ�������
		return true;
	}
	else
	{
		StackNode<T>* p = new StackNode<T>;//Ϊջ��Ԫ�ط����ڴ�
		p->data = e;//��ջ��Ԫ�ش�����
		StackNode<T>* q = m_top;//��ȡԭ��ջ��Ԫ�صĵ�ַ
		m_top = p;//��p�ĵ�ַ����ջ��
		m_top->next = q;//��ջ��ָ���nextָ��ԭ�ȵ�ջ��
		m_length++;//��ʽջ�ĳ�������
		return true;
	}
}
template <typename T>
bool LinkStack<T>::Pop(T& e)
{
	if (m_length == 0)
	{
		cout << "����ʽջΪ��ջ���޷���ջ��" << endl;
		return false;
	}
	else
	{
		e = m_top->data;//��ջ�������ݴ���e
		StackNode<T>* p = m_top;
		m_top = m_top->next;//ջ��Ԫ��ָ��ջ��Ԫ�ص���һλ
		delete p;//�ͷ�ԭ��ջ��Ԫ�صĿռ�
		m_length--;//��ʽջ�ĳ��ȼ���
		return true;
	}
}
template <typename T>
bool LinkStack<T>::GetTop(T& e)
{
	if (m_length == 0)
	{
		cout << "����ʽջΪ��ջ����ȡջ��Ԫ������ʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		e = m_top->data;//��ջ�������ݴ���e
		return true;
	}
}
template <typename T>
void LinkStack<T>::DisplayLinkStack()
{
	if (m_length == 0)
	{
		cout << "����ʽջΪ��ջ��" << endl;
	}
	else
	{
		StackNode<T>* p = m_top;
		for (int i = 0; i < m_length; i++)
		{
			cout << p->data << " ";//���p��data
			p = p->next;
		}
		cout << endl;//�����������
	}
}
template <typename T>
int LinkStack<T>::ListLength()
{
	return m_length;
}
template <typename T>
bool LinkStack<T>::Empty()
{
	if (m_length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*����ʵ������*/
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
enum  ECCHILDSIGN//�ڵ���
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
//Ϊʵ�ֶ������ķǵݹ������������µ���ģ��
template <typename T>
struct BTNode_extra
{
	BinaryTreeNode<T>* point;
	int pointSign;
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
	//��������ڵ����
	int getSize();
	//��������߶�
	int getHeight();
	//����ĳ���ڵ㣨����������Ľڵ������ͬ��
	BinaryTreeNode<T>* SearchElem(const T& e);
	//����ĳ���ڵ�ĸ��ڵ�
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* tSonNode);
	//���Ŀ���
	void CopyTree(BinaryTree<T>* targettree);
	//�ǵݹ鷽ʽǰ�����������
	void preOrder_noRecu();
	//�ǵݹ鷽ʽ�������������
	void inOrder_noRecu();
	//�ǵݹ鷽ʽ�������������
	void postOrder_noRecu();
	//����ǰ��������������������������
	void CreateBTreeAccordPI(char *pP_T,char *pI_T);
	//���ݺ���������������������������
	void CreateBTreeAccordPO(char* pP_T, char* pI_T);
private:
	BinaryTreeNode<T>* root;//�����ڵ��ָ��
	//������չ��������ǰ��������д����������ĵݹ麯��
	void CreateBiTreeAccordPTRecu(BinaryTreeNode<T>*& tnode,char* &pstr);//��������Ϊ���ã�ȷ���ݹ�����жԲ����ĸı��Ӱ�쵽����ֵ
	void preOrder(BinaryTreeNode<T>* tNode);//ǰ�����
	void inOrder(BinaryTreeNode<T>* tNode);//�������
	void postOrder(BinaryTreeNode<T>* tNode);//�������
	void levelOrder(BinaryTreeNode<T>* tNode);//�������
	//��������ڵ����
	int getSize(BinaryTreeNode<T>* tNode);//Ҳ�����ñ����������ķ�ʽ��ڵ����
	//��������߶�
	int getHeight(BinaryTreeNode<T>* tNode);
	//����ĳ���ڵ㣨����������Ľڵ������ͬ��
	BinaryTreeNode<T>* SearchElem(BinaryTreeNode<T>* tNode, const T& e);
	//���Ŀ���
	void CopyTree(BinaryTreeNode<T>* tSouce, BinaryTreeNode<T>*& tTarget);//ע��ڶ���������������
	//�ǵݹ鷽ʽǰ�����������
	void preOrder_noRecu(BinaryTreeNode<T>* tNode);
	//�ǵݹ鷽ʽ�������������
	void inOrder_noRecu(BinaryTreeNode<T>* tNode);
	//�ǵݹ鷽ʽ�������������
	void postOrder_noRecu(BinaryTreeNode<T>* tNode);
	//����ǰ��������������������������
	void CreateBTreeAccordPI(BinaryTreeNode<T>* &tNode, char* pP_T, char* pI_T, int n);
	//���ݺ���������������������������
	void CreateBTreeAccordPO(BinaryTreeNode<T>*& tNode, char* pP_T, char* pI_T, int n);
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
//��������ڵ����
template <typename T>
int BinaryTree<T>::getSize()
{
	return getSize(root);
}
//��������ڵ����
template <typename T>
int BinaryTree<T>::getSize(BinaryTreeNode<T>* tNode)
{
	if (tNode == nullptr)
	{
		return 0;
	}
	return getSize(tNode->leftChild) + getSize(tNode->rightChild) + 1;//�������ڵ���������������ڵ�����ټ�������
}
//��������߶�
template <typename T>
int BinaryTree<T>::getHeight()
{
	return getHeight(root);
}
template <typename T>
int BinaryTree<T>::getHeight(BinaryTreeNode<T>* tNode)
{
	if (tNode == nullptr)
	{
		return 0;
	}
	int lheight = getHeight(tNode->leftChild);//�������߶�
	int rheight = getHeight(tNode->rightChild);//�������߶�
	if (lheight > rheight)
	{
		return lheight + 1;
	}
	return rheight + 1;
}
//����ĳ���ڵ㣨����������Ľڵ������ͬ��
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::SearchElem(const T& e)
{
	return SearchElem(root, e);
}
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::SearchElem(BinaryTreeNode<T>* tNode, const T& e)
{

	if (tNode != nullptr)//���������ǿ�
	{
		BinaryTreeNode<T>* tmpnode;
		LinkQueue<BinaryTreeNode<T>* > lnobj;//ע�����Ԫ�������ǽڵ�ָ������
		lnobj.EnQueue(tNode);//�ȰѸ��ڵ�ָ�����
		while (!lnobj.Empty())//ѭ���ж϶����Ƿ�Ϊ��
		{
			lnobj.DeQueue(tmpnode);//������
			if (tmpnode->data == e)
			{
				return tmpnode;
			}
			if (tmpnode->leftChild != nullptr)
			{
				lnobj.EnQueue(tmpnode->leftChild);//�������
			}
			if (tmpnode->rightChild != nullptr)
			{
				lnobj.EnQueue(tmpnode->rightChild);//�Һ������
			}
		}//end while
		return nullptr;
	}// end if
}
//����ĳ���ڵ�ĸ��ڵ�
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::GetParent(BinaryTreeNode<T>* tSonNode)
{
	if (tSonNode == nullptr)
	{
		return nullptr;
	}
	BinaryTreeNode<T>* tmpnode;
	LinkQueue<BinaryTreeNode<T>* > lnobj;//ע�����Ԫ�������ǽڵ�ָ������
	lnobj.EnQueue(root);//�ȰѸ��ڵ�ָ�����
	while (!lnobj.Empty())//ѭ���ж϶����Ƿ�Ϊ��
	{
		lnobj.DeQueue(tmpnode);//������
		if (tmpnode->leftChild == tSonNode|| tmpnode->rightChild == tSonNode)
		{
			return tmpnode;
		}
		if (tmpnode->leftChild != nullptr)
		{
			lnobj.EnQueue(tmpnode->leftChild);//�������
		}
		if (tmpnode->rightChild != nullptr)
		{
			lnobj.EnQueue(tmpnode->rightChild);//�Һ������
		}
	}//end while
	return nullptr;
}
//���Ŀ���
template <typename T>
void BinaryTree<T>::CopyTree(BinaryTree<T>* targetTree)
{
	CopyTree(root, targetTree->root);
}
template <typename T>
void BinaryTree<T>::CopyTree(BinaryTreeNode<T>* tSouce, BinaryTreeNode<T>*& tTarget)//ע��ڶ���������������
{
	if (tSouce == nullptr)
	{
		tTarget = nullptr;
	}
	else
	{
		tTarget = new BinaryTreeNode<T>;
		tTarget->data = tSouce->data;
		CopyTree(tSouce->leftChild, tTarget->leftChild);//������������
		CopyTree(tSouce->rightChild, tTarget->rightChild);//������������
	}
}
//�ǵݹ鷽ʽʵ��ǰ�����
template <typename T>
void BinaryTree<T>::preOrder_noRecu()
{
	preOrder_noRecu(root);
}
template <typename T>
void BinaryTree<T>::preOrder_noRecu(BinaryTreeNode<T>* tNode)
{
	if (tNode == nullptr)
	{
		return;
	}
	LinkStack<BinaryTreeNode<T>*> obj;
	BinaryTreeNode<T>* k;
	obj.Push(tNode);//���ڵ���ջ
	while (!obj.Empty())//���ջ��Ϊ����ѭ������Ĳ��裬ֱ��ջΪ��
	{
		obj.Pop(k);//ջ��Ԫ�س�ջ
		cout << k->data << " ";//�����ʣ���ʾ�ڵ�ֵ�����Ԫ��
		if (k->rightChild != nullptr)//�����������ʵ�Ԫ�����ӽڵ㲻Ϊ�գ���������ӽڵ���ջ
		{
			obj.Push(k->rightChild);
		}
		if (k->leftChild != nullptr)//�����������ʵ�Ԫ�����ӽڵ㲻Ϊ�գ���������ӽڵ���ջ
		{
			obj.Push(k->leftChild);
		}
	}//end while
} 
//�ǵݹ鷽ʽʵ���������
template <typename T>
void BinaryTree<T>::inOrder_noRecu()
{
	inOrder_noRecu(root);
}
template <typename T>
void BinaryTree<T>::inOrder_noRecu(BinaryTreeNode<T>* tNode)
{
	if (tNode == nullptr)
	{
		return;
	}
	LinkStack<BinaryTreeNode<T>*> obj;
	BinaryTreeNode<T>* k;
	obj.Push(tNode);//���ڵ���ջ
	while (!obj.Empty())//���ջ��Ϊ����ѭ������Ĳ��裬ֱ��ջΪ��
	{
		while (tNode->leftChild != nullptr)
		{
			obj.Push(tNode->leftChild);//����ǰ�ڵ�����ӽڵ���ջ
			tNode = tNode->leftChild;//����ǰ�ڵ�����ӽڵ����±��Ϊ��ǰ�ڵ㣻
		}
		obj.Pop(k);//ջ��Ԫ�س�ջ
		cout << k->data << " ";//����ջ��Ԫ��
		if(k->rightChild != nullptr)//�����ǰ�ڵ�����ӽڵ㲻Ϊ�գ�����Լ����ҽڵ��趨Ϊ��ǰ�ڵ㣬������ջ��
		{
			tNode = k->rightChild;//���ոճ�ջ��Ԫ�ص��ҽڵ���Ϊ��ǰ�ڵ�
			obj.Push(tNode);//����ǰ�ڵ���ջ
		}
	}
}
//�ǵݹ鷽ʽʵ���������
template <typename T>
void BinaryTree<T>::postOrder_noRecu()
{
	postOrder_noRecu(root);
}
template <typename T>
void BinaryTree<T>::postOrder_noRecu(BinaryTreeNode<T>* tNode)
{
	if (tNode == nullptr)
	{
		return;
	}
	LinkStack< BTNode_extra<T> > obj;
	BTNode_extra<T> ext_tmpnode;
	do 
	{
		while (tNode != nullptr)
		{
			ext_tmpnode.point = tNode;
			ext_tmpnode.pointSign = 1;//����ȴ���ýڵ������
			obj.Push(ext_tmpnode);
			tNode = tNode->leftChild;
		}//ѭ��2
		while (!obj.Empty())
		{
			obj.Pop(ext_tmpnode);//��ջ
			if (ext_tmpnode.pointSign == 1)
			{
				ext_tmpnode.pointSign = 0;//��Ǹýڵ�Ϊ�Һ���
				obj.Push(ext_tmpnode);//������ջ
				tNode = ext_tmpnode.point->rightChild;
				break;//��ֹwhileѭ��
			}
			else
			{
				cout << ext_tmpnode.point->data << " ";
			}

		}//ѭ��3
	} while (!obj.Empty());//ѭ��1
}
template <typename T>
void BinaryTree<T>::CreateBTreeAccordPI(char *pP_T,char *pI_T)
{
	CreateBTreeAccordPI(root, pP_T, pI_T, strlen(pP_T));
}
template <typename T>
void BinaryTree<T>::CreateBTreeAccordPI(BinaryTreeNode<T>* &tNode,char* pP_T, char* pI_T, int n)
{
	if (n == 0)
	{
		tNode = nullptr;
	}
	else
	{
		//(1)����������������Ҹ�ǰ������и�������ǰ��ġ�
		int tmpindex = 0;
		while (pP_T[0] != pI_T[tmpindex])
		{
			tmpindex++;
		}
		tNode = new BinaryTreeNode<T>;//�������ڵ�
		tNode->data = pI_T[tmpindex];
		//��2����������
		CreateBTreeAccordPI(
			tNode->leftChild,//��������
			pP_T + 1,//�ҵ�ǰ�����������������ʼ�ڵ��λ�ã����������˸��ڵ�
			pI_T,//�ҵ��������������������ʼ�ڵ��λ��
			tmpindex //���ӵĽڵ����
		);
		//(3)�����Һ���
		CreateBTreeAccordPI(
			tNode->rightChild,//�����Һ���
			pP_T + tmpindex + 1,//�ҵ�ǰ�����������������ʼ�ڵ��λ�ã����������˸��ڵ�
			pI_T + tmpindex + 1,//�ҵ��������������������ʼ�ڵ��λ��
			n - tmpindex - 1 //���ӵĽڵ����
		);
	}
}
//ͨ������������кͺ��������������ԭ������
template <typename T>
void BinaryTree<T>::CreateBTreeAccordPO(char* pI_T, char* pPost_T)
{
	CreateBTreeAccordPO(root, pI_T, pPost_T, strlen(pPost_T));
}
template <typename T>
void BinaryTree<T>::CreateBTreeAccordPO(BinaryTreeNode<T>*& tNode, char* pI_T, char* pPost_T, int n)
{
	if (n == 0)
	{
		tNode = nullptr;
	}
	else
	{
		int tmpindex = 0;//�±�
		while (pPost_T[n - 1] != pI_T[tmpindex])
		{
			tmpindex++;
		}//�ҵ���������е�����
		tNode = new BinaryTreeNode<T>;//�����½ڵ�
		tNode->data = pI_T[tmpindex];
		//��������
		CreateBTreeAccordPO(
			tNode->leftChild,//��������
		    pI_T,//�����������
			pPost_T,//�����������
			tmpindex//���ӽڵ�����
		);
		//�����Һ���
		CreateBTreeAccordPO(
			tNode->rightChild,//�����Һ���
			pI_T+tmpindex+1,//�ҵ������������������ʼ�ڵ�λ��
			pPost_T+tmpindex,//�ҵ������������������ʼ�ڵ�λ��
			n-tmpindex-1//�Һ��ӽڵ�����
		);
	}
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
	cout << "�������Ľڵ����Ϊ��" << mytree2.getSize() << endl;
	cout << "�������ĸ߶�Ϊ��" << mytree2.getHeight() << endl;
	//����ĳ�ڵ�
	char val = 'E';
	BinaryTreeNode<char>* p = mytree2.SearchElem(val);
	if (p != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val << "�Ľڵ㣡" << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val << "�Ľڵ㣡" << endl;
	}
	BinaryTreeNode<char>* parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val << "�Ľڵ�ĸ��ڵ㣡" << parp->data << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val << "�Ľڵ㣡" << endl;
	}
	char val1 = 'A';
	p = mytree2.SearchElem(val1);
	if (p != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val1 << "�Ľڵ㣡" << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val1 << "�Ľڵ㣡" << endl;
	}
	parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val1 << "�Ľڵ�ĸ��ڵ㣡" << parp->data << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val1 << "�Ľڵ�ĸ��ڵ㣡" << endl;
	}
	char val2 = 'B';
	p = mytree2.SearchElem(val2);
	if (p != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val2 << "�Ľڵ㣡" << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val2 << "�Ľڵ㣡" << endl;
	}
	parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val2 << "�Ľڵ�ĸ��ڵ㣡" << parp->data << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val2 << "�Ľڵ�ĸ��ڵ㣡" << endl;
	}
	char val3 = 'C';
	p = mytree2.SearchElem(val3);
	if (p != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val3 << "�Ľڵ㣡" << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val3 << "�Ľڵ㣡" << endl;
	}
	parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val3 << "�Ľڵ�ĸ��ڵ㣡" << parp->data << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val3 << "�Ľڵ�ĸ��ڵ㣡" << endl;
	}
	char val4 = 'D';
	p = mytree2.SearchElem(val4);
	if (p != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val4 << "�Ľڵ㣡" << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val4 << "�Ľڵ㣡" << endl;
	}
	parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val4 << "�Ľڵ�ĸ��ڵ㣡" << parp->data << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val4 << "�Ľڵ�ĸ��ڵ㣡" << endl;
	}
	char val5 = 'K';
	p = mytree2.SearchElem(val5);
	if (p != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val5 << "�Ľڵ㣡" << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val5 << "�Ľڵ㣡" << endl;
	}
	parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "�ҵ���ֵΪ" << val5 << "�Ľڵ�ĸ��ڵ㣡" << parp->data << endl;
	}
	else
	{
		cout << "û���ҵ�ֵΪ" << val5 << "�Ľڵ�ĸ��ڵ㣡" << endl;
	}
	//�������Ŀ���
	cout << "---------�������Ŀ���----------" << endl;
	BinaryTree<char> mytree3;
	mytree2.CopyTree(&mytree3);
	mytree3.levelOrder();
	cout << endl;
	//���Էǵݹ�ǰ�����
	cout << "---------���Էǵݹ�ǰ�����----------" << endl;
	mytree2.preOrder_noRecu();
	cout << endl;
	cout << "---------���Էǵݹ��������----------" << endl;
	mytree2.inOrder_noRecu();
	cout << endl;
	cout << "---------���Էǵݹ�������----------" << endl;
	mytree2.postOrder_noRecu();
	cout << endl;
	BinaryTree<char> mytree4;//����������
	mytree4.CreateBTreeAccordPI((char*)"ABDCE", (char*)"DBACE");
	cout << "---------���Էǵݹ�ǰ������¶�����1----------" << endl;
	mytree4.preOrder_noRecu();
	cout << endl;
	cout << "---------���Էǵݹ���������¶�����1----------" << endl;
	mytree4.inOrder_noRecu();
	cout << endl;
	cout << "---------���Էǵݹ��������¶�����1----------" << endl;
	mytree4.postOrder_noRecu();
	cout << endl;
	BinaryTree<char> mytree5;//����������
	mytree5.CreateBTreeAccordPO((char*)"DBACE", (char*)"DBECA");
	cout << "---------���Էǵݹ�ǰ������¶�����2----------" << endl;
	mytree5.preOrder_noRecu();
	cout << endl;
	cout << "---------���Էǵݹ���������¶�����2----------" << endl;
	mytree5.inOrder_noRecu();
	cout << endl;
	cout << "---------���Էǵݹ��������¶�����2----------" << endl;
	mytree5.postOrder_noRecu();
	return 0;
}