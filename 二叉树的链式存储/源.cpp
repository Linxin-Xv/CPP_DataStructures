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
enum ECCHILDSIGN//节点标记
{
	E_Root,//树根
	E_ChildLeft,//左孩子
	E_ChildRight//右孩子
};
//树中每个节点的定义
template <typename T>//T代表数据的类型
struct BinaryTreeNode
{
	T data;//数据域
	BinaryTreeNode* leftChild;//左孩子节点指针
	BinaryTreeNode* rightChild;//右孩子节点指针
	//BinaryTreeNode* parent;//父节点指针，根据需要可以引入
};
//二叉树的定义
template <typename T>
class BinaryTree
{
public:
	BinaryTree();//构造函数
	~BinaryTree();//析构函数
	//创建一个树节点
	BinaryTreeNode<T>* CreateNode(BinaryTreeNode<T>* parent, ECCHILDSIGN pointsign, const T& e);
	//释放一个树节点
	void RleaseNode(BinaryTreeNode<T>* pnode);
	//利用扩展二叉树的前序遍历序列来创建一棵二叉树
	void CreateBiTreeAccordPT(char* pstr); 
	void preOrder();//前序遍历
	void inOrder();//中序遍历
	void postOrder();//后序遍历
	void levelOrder();//层序遍历
private:
	BinaryTreeNode<T>* root;//树根节点的指针
	//利用扩展二叉树的前序遍历序列创建二叉树的递归函数
	void CreateBiTreeAccordPTRecu(BinaryTreeNode<T>*& tnode,char* &pstr);//参数类型为引用，确保递归调用中对参数的改变会影响到调用值
	void preOrder(BinaryTreeNode<T>* tNode);//前序遍历
	void inOrder(BinaryTreeNode<T>* tNode);//中序遍历
	void postOrder(BinaryTreeNode<T>* tNode);//后序遍历
	void levelOrder(BinaryTreeNode<T>* tNode);//层序遍历
};
//构造函数
template<typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;//设置为空树
}
//析构函数
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	RleaseNode(root);//从根开始释放节点
}
//释放二叉树节点
template <typename T>
void BinaryTree<T>::RleaseNode(BinaryTreeNode<T>* pnode)
{
	if (pnode != nullptr)
	{
		RleaseNode(pnode->leftChild);//释放它的左孩子
		RleaseNode(pnode->rightChild);//释放它的右孩子
	}
	delete pnode;
}
//创建一个树节点
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::CreateNode(BinaryTreeNode<T>* parentnode, ECCHILDSIGN pointsign, const T& e)
{
	//将新节点创建出来
	BinaryTreeNode<T>* tmpnode = new BinaryTreeNode<T>;
	tmpnode->data = e;//给新节点传入数据
	tmpnode->leftChild = nullptr;
	tmpnode->rightChild = nullptr;
	//把新节点放入正确的位置
	if (pointsign == E_Root)//创建的是树根节点
	{
		root = tmpnode;
	}
	if (pointsign == E_ChildLeft)//创建的是左孩子
	{
		parentnode->leftChild = tmpnode;
	}
	else if (pointsign == E_ChildRight)//创建的是右孩子节点
	{
		parentnode->rightChild = tmpnode;
	}
	return tmpnode;
}
//利用扩展二叉树的前序遍历序列来创建一棵二叉树
template <typename T>
void BinaryTree<T>::CreateBiTreeAccordPT(char* pstr)
{
	CreateBiTreeAccordPTRecu(root, pstr);
}
//利用扩展二叉树的前序遍历序列创建二叉树的递归函数
template <typename T>
void BinaryTree<T>::CreateBiTreeAccordPTRecu(BinaryTreeNode<T>*& tnode, char*& pstr)//参数类型为引用，确保递归
{
	//ABD###C#B##
	if (*pstr == '#')
	{
		tnode = nullptr;
	}
	else
	{
		//根左右
		tnode = new BinaryTreeNode<T>;//创建新节点
		tnode->data = *pstr;
		CreateBiTreeAccordPTRecu(tnode->leftChild, ++pstr);//创建左子树
		CreateBiTreeAccordPTRecu(tnode->rightChild, ++pstr);//创建右子树
	}
}
//前序遍历二叉树
//根左右
template <typename T>
void BinaryTree<T>::preOrder()
{
	preOrder(root);
}
template <typename T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* tNode)
{
	if (tNode != nullptr)//不是空二叉树
	{
		cout << tNode->data << " ";//输出节点的数据域值
		preOrder(tNode->leftChild);//递归方式前序遍历左子树
		preOrder(tNode->rightChild);//递归方式前序遍历右子树
	}
}
//中序遍历二叉树
//左根右
template <typename T>
void BinaryTree<T>::inOrder()
{
	inOrder(root);
}
template <typename T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* tNode)
{
	if (tNode != nullptr)//不是空二叉树
	{
		inOrder(tNode->leftChild);//递归方式中序遍历左子树
		cout << tNode->data << " ";//输出节点的数据域
		inOrder(tNode->rightChild);//递归方式中序遍历右子树
	}
}
//后序遍历二叉树
//左右根
template <typename T>
void BinaryTree<T>::postOrder()
{
	postOrder(root);
}
template <typename T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* tNode)
{
	if (tNode != nullptr)//不是空二叉树
	{
		postOrder(tNode->leftChild);//递归方式后序遍历左子树
		postOrder(tNode->rightChild);//递归方式后序遍历右子树
		cout << tNode->data << " ";//输出节点的数据域
	}
}
//层序遍历二叉树
template <typename T>
void BinaryTree<T>::levelOrder()
{
	levelOrder(root);
}
template <typename T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* tNode)
{
	if (tNode != nullptr)//若二叉树非空
	{
		BinaryTreeNode<T>* tmpnode;
		LinkQueue<BinaryTreeNode<T>* > lnobj;//注意队列元素类型是节点指针类型
		lnobj.EnQueue(tNode);//先把根节点指针入队
		while (!lnobj.Empty())//循环判断队列是否为空
		{
			lnobj.DeQueue(tmpnode);//出队列
			cout << (char)tmpnode->data << " ";
			if (tmpnode->leftChild != nullptr)
			{
				lnobj.EnQueue(tmpnode->leftChild);//左孩子入队
			}
			if (tmpnode->rightChild != nullptr)
			{
				lnobj.EnQueue(tmpnode->rightChild);//右孩子入队
			}
		}//end while
	}// end if
}
int main()
{
	BinaryTree<int> mytree;//创建二叉树
	BinaryTreeNode<int>* rootpoint = mytree.CreateNode(nullptr, E_Root, 'A');//创建根节点A
	BinaryTreeNode<int>* subpoint = mytree.CreateNode(rootpoint, E_ChildLeft, 'B');//创建根节点的左子节点B
	subpoint = mytree.CreateNode(subpoint, E_ChildLeft, 'D');//创建B的左子节点D
    subpoint = mytree.CreateNode(rootpoint, E_ChildRight, 'C');//创建根节点的右子节点C
	subpoint = mytree.CreateNode(subpoint, E_ChildRight, 'E');//创建C的右子节点E
	BinaryTree<char> mytree2;//创建二叉树
	mytree2.CreateBiTreeAccordPT((char*)"ABD###C#E##");//根据扩展二叉树的前序遍历序列创建二叉树
	cout << "前序遍历序列为：";
	mytree2.preOrder();
	cout << endl;
	cout << "中序遍历序列为：";
	mytree2.inOrder();
	cout << endl;
	cout << "后序遍历序列为：";
	mytree2.postOrder();
	cout << endl;
	cout << "层序遍历序列为：";
	mytree2.levelOrder();
	cout << endl;
	return 0;
}