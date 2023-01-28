#include <iostream>
using namespace std;
/*栈实现区域*/
//链式栈中每个节点的定义
template <typename T>
struct StackNode
{
	T data;//数据域
	StackNode<T>* next;//指向个下一个同类型的节点
};
//链式栈的定义
template <typename T>
class LinkStack
{
public:
	LinkStack();//构造函数
	~LinkStack();//析构函数
	bool Push(const T& e);//入栈操作
	bool Pop(T& e);//出栈操作
	bool GetTop(T& e);//获取栈顶元素
	void DisplayLinkStack();//扫描输出链式栈
	bool Empty();//判断链式栈是否为空栈
	int ListLength();//返回链式栈长度
private:
	int m_length;//栈长度
	StackNode<T>* m_top;//栈顶地址(指针）
};
template <typename T>
LinkStack<T>::LinkStack()
{
	int m_length = 0;//初始化栈的长度为0
	m_top = nullptr;//栈顶指针为空指针
}
template <typename T>
LinkStack<T>::~LinkStack()//析构函数
{
	T k;
	while (m_length > 0)
	{
		Pop(k);//不断出栈直至链式栈的长度为零以完成析构
	}
}
template <typename T>
bool LinkStack<T>::Push(const T& e)
{
	if (m_length == 0)//如果是空栈
	{
		StackNode<T>* p = new StackNode<T>;//为栈顶元素分配内存
		p->data = e;//给栈顶元素传数据
		m_top = p;//将p的地址传给栈顶
		m_top->next = nullptr;//将栈顶指针的next指向空指针
		m_length++;//链式栈的长度增加
		return true;
	}
	else
	{
		StackNode<T>* p = new StackNode<T>;//为栈顶元素分配内存
		p->data = e;//给栈顶元素传数据
		StackNode<T>* q = m_top;//获取原先栈顶元素的地址
		m_top = p;//将p的地址传给栈顶
		m_top->next = q;//将栈顶指针的next指向原先的栈顶
		m_length++;//链式栈的长度增加
		return true;
	}
}
template <typename T>
bool LinkStack<T>::Pop(T& e)
{
	if (m_length == 0)
	{
		cout << "该链式栈为空栈，无法出栈！" << endl;
		return false;
	}
	else
	{
		e = m_top->data;//将栈顶的数据传给e
		StackNode<T>* p = m_top;
		m_top = m_top->next;//栈顶元素指向栈顶元素的下一位
		delete p;//释放原先栈顶元素的空间
		m_length--;//链式栈的长度减少
		return true;
	}
}
template <typename T>
bool LinkStack<T>::GetTop(T& e)
{
	if (m_length == 0)
	{
		cout << "该链式栈为空栈，获取栈顶元素数据失败！" << endl;
		return false;
	}
	else
	{
		e = m_top->data;//将栈顶的数据传给e
		return true;
	}
}
template <typename T>
void LinkStack<T>::DisplayLinkStack()
{
	if (m_length == 0)
	{
		cout << "该链式栈为空栈！" << endl;
	}
	else
	{
		StackNode<T>* p = m_top;
		for (int i = 0; i < m_length; i++)
		{
			cout << p->data << " ";//输出p的data
			p = p->next;
		}
		cout << endl;//输出结束后换行
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
/*队列实现区域*/
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
enum  ECCHILDSIGN//节点标记
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
//为实现二叉树的非递归后序遍历引入新的类模板
template <typename T>
struct BTNode_extra
{
	BinaryTreeNode<T>* point;
	int pointSign;
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
	//求二叉树节点个数
	int getSize();
	//求二叉树高度
	int getHeight();
	//查找某个节点（假设二叉树的节点各不相同）
	BinaryTreeNode<T>* SearchElem(const T& e);
	//查找某个节点的父节点
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* tSonNode);
	//树的拷贝
	void CopyTree(BinaryTree<T>* targettree);
	//非递归方式前序遍历二叉树
	void preOrder_noRecu();
	//非递归方式中序遍历二叉树
	void inOrder_noRecu();
	//非递归方式后序遍历二叉树
	void postOrder_noRecu();
	//根据前序和中序遍历序列来创建二叉树
	void CreateBTreeAccordPI(char *pP_T,char *pI_T);
	//根据后序和中序遍历序列来创建二叉树
	void CreateBTreeAccordPO(char* pP_T, char* pI_T);
private:
	BinaryTreeNode<T>* root;//树根节点的指针
	//利用扩展二叉树的前序遍历序列创建二叉树的递归函数
	void CreateBiTreeAccordPTRecu(BinaryTreeNode<T>*& tnode,char* &pstr);//参数类型为引用，确保递归调用中对参数的改变会影响到调用值
	void preOrder(BinaryTreeNode<T>* tNode);//前序遍历
	void inOrder(BinaryTreeNode<T>* tNode);//中序遍历
	void postOrder(BinaryTreeNode<T>* tNode);//后序遍历
	void levelOrder(BinaryTreeNode<T>* tNode);//层序遍历
	//求二叉树节点个数
	int getSize(BinaryTreeNode<T>* tNode);//也可以用遍历二叉树的方式求节点个数
	//求二叉树高度
	int getHeight(BinaryTreeNode<T>* tNode);
	//查找某个节点（假设二叉树的节点各不相同）
	BinaryTreeNode<T>* SearchElem(BinaryTreeNode<T>* tNode, const T& e);
	//树的拷贝
	void CopyTree(BinaryTreeNode<T>* tSouce, BinaryTreeNode<T>*& tTarget);//注意第二个参数类型引用
	//非递归方式前序遍历二叉树
	void preOrder_noRecu(BinaryTreeNode<T>* tNode);
	//非递归方式中序遍历二叉树
	void inOrder_noRecu(BinaryTreeNode<T>* tNode);
	//非递归方式后序遍历二叉树
	void postOrder_noRecu(BinaryTreeNode<T>* tNode);
	//根据前序和中序遍历序列来创建二叉树
	void CreateBTreeAccordPI(BinaryTreeNode<T>* &tNode, char* pP_T, char* pI_T, int n);
	//根据后序和中序遍历序列来创建二叉树
	void CreateBTreeAccordPO(BinaryTreeNode<T>*& tNode, char* pP_T, char* pI_T, int n);
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
//求二叉树节点个数
template <typename T>
int BinaryTree<T>::getSize()
{
	return getSize(root);
}
//求二叉树节点个数
template <typename T>
int BinaryTree<T>::getSize(BinaryTreeNode<T>* tNode)
{
	if (tNode == nullptr)
	{
		return 0;
	}
	return getSize(tNode->leftChild) + getSize(tNode->rightChild) + 1;//左子树节点个数加上右子树节点个数再加上自身
}
//求二叉树高度
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
	int lheight = getHeight(tNode->leftChild);//左子树高度
	int rheight = getHeight(tNode->rightChild);//右子树高度
	if (lheight > rheight)
	{
		return lheight + 1;
	}
	return rheight + 1;
}
//查找某个节点（假设二叉树的节点各不相同）
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::SearchElem(const T& e)
{
	return SearchElem(root, e);
}
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::SearchElem(BinaryTreeNode<T>* tNode, const T& e)
{

	if (tNode != nullptr)//若二叉树非空
	{
		BinaryTreeNode<T>* tmpnode;
		LinkQueue<BinaryTreeNode<T>* > lnobj;//注意队列元素类型是节点指针类型
		lnobj.EnQueue(tNode);//先把根节点指针入队
		while (!lnobj.Empty())//循环判断队列是否为空
		{
			lnobj.DeQueue(tmpnode);//出队列
			if (tmpnode->data == e)
			{
				return tmpnode;
			}
			if (tmpnode->leftChild != nullptr)
			{
				lnobj.EnQueue(tmpnode->leftChild);//左孩子入队
			}
			if (tmpnode->rightChild != nullptr)
			{
				lnobj.EnQueue(tmpnode->rightChild);//右孩子入队
			}
		}//end while
		return nullptr;
	}// end if
}
//查找某个节点的父节点
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::GetParent(BinaryTreeNode<T>* tSonNode)
{
	if (tSonNode == nullptr)
	{
		return nullptr;
	}
	BinaryTreeNode<T>* tmpnode;
	LinkQueue<BinaryTreeNode<T>* > lnobj;//注意队列元素类型是节点指针类型
	lnobj.EnQueue(root);//先把根节点指针入队
	while (!lnobj.Empty())//循环判断队列是否为空
	{
		lnobj.DeQueue(tmpnode);//出队列
		if (tmpnode->leftChild == tSonNode|| tmpnode->rightChild == tSonNode)
		{
			return tmpnode;
		}
		if (tmpnode->leftChild != nullptr)
		{
			lnobj.EnQueue(tmpnode->leftChild);//左孩子入队
		}
		if (tmpnode->rightChild != nullptr)
		{
			lnobj.EnQueue(tmpnode->rightChild);//右孩子入队
		}
	}//end while
	return nullptr;
}
//树的拷贝
template <typename T>
void BinaryTree<T>::CopyTree(BinaryTree<T>* targetTree)
{
	CopyTree(root, targetTree->root);
}
template <typename T>
void BinaryTree<T>::CopyTree(BinaryTreeNode<T>* tSouce, BinaryTreeNode<T>*& tTarget)//注意第二个参数类型引用
{
	if (tSouce == nullptr)
	{
		tTarget = nullptr;
	}
	else
	{
		tTarget = new BinaryTreeNode<T>;
		tTarget->data = tSouce->data;
		CopyTree(tSouce->leftChild, tTarget->leftChild);//对左子树拷贝
		CopyTree(tSouce->rightChild, tTarget->rightChild);//对右子树拷贝
	}
}
//非递归方式实现前序遍历
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
	obj.Push(tNode);//根节点入栈
	while (!obj.Empty())//如果栈不为空则循环下面的步骤，直至栈为空
	{
		obj.Pop(k);//栈顶元素出栈
		cout << k->data << " ";//并访问（显示节点值）这个元素
		if (k->rightChild != nullptr)//如果这个被访问的元素右子节点不为空，则把其右子节点入栈
		{
			obj.Push(k->rightChild);
		}
		if (k->leftChild != nullptr)//如果这个被访问的元素左子节点不为空，则把其左子节点入栈
		{
			obj.Push(k->leftChild);
		}
	}//end while
} 
//非递归方式实现中序遍历
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
	obj.Push(tNode);//根节点入栈
	while (!obj.Empty())//如果栈不为空则循环下面的步骤，直至栈为空
	{
		while (tNode->leftChild != nullptr)
		{
			obj.Push(tNode->leftChild);//将当前节点的左子节点入栈
			tNode = tNode->leftChild;//将当前节点的左子节点重新标记为当前节点；
		}
		obj.Pop(k);//栈顶元素出栈
		cout << k->data << " ";//访问栈顶元素
		if(k->rightChild != nullptr)//如果当前节点的右子节点不为空，则把自己的右节点设定为当前节点，并且入栈；
		{
			tNode = k->rightChild;//将刚刚出栈的元素的右节点标记为当前节点
			obj.Push(tNode);//将当前节点入栈
		}
	}
}
//非递归方式实现中序遍历
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
			ext_tmpnode.pointSign = 1;//标记先处理该节点的左孩子
			obj.Push(ext_tmpnode);
			tNode = tNode->leftChild;
		}//循环2
		while (!obj.Empty())
		{
			obj.Pop(ext_tmpnode);//出栈
			if (ext_tmpnode.pointSign == 1)
			{
				ext_tmpnode.pointSign = 0;//标记该节点为右孩子
				obj.Push(ext_tmpnode);//重新入栈
				tNode = ext_tmpnode.point->rightChild;
				break;//终止while循环
			}
			else
			{
				cout << ext_tmpnode.point->data << " ";
			}

		}//循环3
	} while (!obj.Empty());//循环1
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
		//(1)在中序遍历序列中找根前序遍历中根是在最前面的。
		int tmpindex = 0;
		while (pP_T[0] != pI_T[tmpindex])
		{
			tmpindex++;
		}
		tNode = new BinaryTreeNode<T>;//创建根节点
		tNode->data = pI_T[tmpindex];
		//（2）创建左孩子
		CreateBTreeAccordPI(
			tNode->leftChild,//创建左孩子
			pP_T + 1,//找到前序遍历序列中左树开始节点的位置，这里跳过了根节点
			pI_T,//找到中序遍历序列中左树开始节点的位置
			tmpindex //左孩子的节点个数
		);
		//(3)创建右孩子
		CreateBTreeAccordPI(
			tNode->rightChild,//创建右孩子
			pP_T + tmpindex + 1,//找到前序遍历序列中右树开始节点的位置，这里跳过了根节点
			pI_T + tmpindex + 1,//找到中序遍历序列中右树开始节点的位置
			n - tmpindex - 1 //左孩子的节点个数
		);
	}
}
//通过中序遍历序列和后序遍历序列来还原二叉树
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
		int tmpindex = 0;//下标
		while (pPost_T[n - 1] != pI_T[tmpindex])
		{
			tmpindex++;
		}//找到中序遍历中的树根
		tNode = new BinaryTreeNode<T>;//创建新节点
		tNode->data = pI_T[tmpindex];
		//创建左孩子
		CreateBTreeAccordPO(
			tNode->leftChild,//创建左孩子
		    pI_T,//中序遍历序列
			pPost_T,//后序遍历序列
			tmpindex//左孩子节点数量
		);
		//创建右孩子
		CreateBTreeAccordPO(
			tNode->rightChild,//创建右孩子
			pI_T+tmpindex+1,//找到中序遍历序列右树开始节点位置
			pPost_T+tmpindex,//找到后序遍历序列右树开始节点位置
			n-tmpindex-1//右孩子节点数量
		);
	}
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
	cout << "二叉树的节点个数为：" << mytree2.getSize() << endl;
	cout << "二叉树的高度为：" << mytree2.getHeight() << endl;
	//查找某节点
	char val = 'E';
	BinaryTreeNode<char>* p = mytree2.SearchElem(val);
	if (p != nullptr)
	{
		cout << "找到了值为" << val << "的节点！" << endl;
	}
	else
	{
		cout << "没有找到值为" << val << "的节点！" << endl;
	}
	BinaryTreeNode<char>* parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "找到了值为" << val << "的节点的父节点！" << parp->data << endl;
	}
	else
	{
		cout << "没有找到值为" << val << "的节点！" << endl;
	}
	char val1 = 'A';
	p = mytree2.SearchElem(val1);
	if (p != nullptr)
	{
		cout << "找到了值为" << val1 << "的节点！" << endl;
	}
	else
	{
		cout << "没有找到值为" << val1 << "的节点！" << endl;
	}
	parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "找到了值为" << val1 << "的节点的父节点！" << parp->data << endl;
	}
	else
	{
		cout << "没有找到值为" << val1 << "的节点的父节点！" << endl;
	}
	char val2 = 'B';
	p = mytree2.SearchElem(val2);
	if (p != nullptr)
	{
		cout << "找到了值为" << val2 << "的节点！" << endl;
	}
	else
	{
		cout << "没有找到值为" << val2 << "的节点！" << endl;
	}
	parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "找到了值为" << val2 << "的节点的父节点！" << parp->data << endl;
	}
	else
	{
		cout << "没有找到值为" << val2 << "的节点的父节点！" << endl;
	}
	char val3 = 'C';
	p = mytree2.SearchElem(val3);
	if (p != nullptr)
	{
		cout << "找到了值为" << val3 << "的节点！" << endl;
	}
	else
	{
		cout << "没有找到值为" << val3 << "的节点！" << endl;
	}
	parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "找到了值为" << val3 << "的节点的父节点！" << parp->data << endl;
	}
	else
	{
		cout << "没有找到值为" << val3 << "的节点的父节点！" << endl;
	}
	char val4 = 'D';
	p = mytree2.SearchElem(val4);
	if (p != nullptr)
	{
		cout << "找到了值为" << val4 << "的节点！" << endl;
	}
	else
	{
		cout << "没有找到值为" << val4 << "的节点！" << endl;
	}
	parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "找到了值为" << val4 << "的节点的父节点！" << parp->data << endl;
	}
	else
	{
		cout << "没有找到值为" << val4 << "的节点的父节点！" << endl;
	}
	char val5 = 'K';
	p = mytree2.SearchElem(val5);
	if (p != nullptr)
	{
		cout << "找到了值为" << val5 << "的节点！" << endl;
	}
	else
	{
		cout << "没有找到值为" << val5 << "的节点！" << endl;
	}
	parp = mytree2.GetParent(p);
	if (parp != nullptr)
	{
		cout << "找到了值为" << val5 << "的节点的父节点！" << parp->data << endl;
	}
	else
	{
		cout << "没有找到值为" << val5 << "的节点的父节点！" << endl;
	}
	//测试树的拷贝
	cout << "---------测试树的拷贝----------" << endl;
	BinaryTree<char> mytree3;
	mytree2.CopyTree(&mytree3);
	mytree3.levelOrder();
	cout << endl;
	//测试非递归前序遍历
	cout << "---------测试非递归前序遍历----------" << endl;
	mytree2.preOrder_noRecu();
	cout << endl;
	cout << "---------测试非递归中序遍历----------" << endl;
	mytree2.inOrder_noRecu();
	cout << endl;
	cout << "---------测试非递归后序遍历----------" << endl;
	mytree2.postOrder_noRecu();
	cout << endl;
	BinaryTree<char> mytree4;//创建二叉树
	mytree4.CreateBTreeAccordPI((char*)"ABDCE", (char*)"DBACE");
	cout << "---------测试非递归前序遍历新二叉树1----------" << endl;
	mytree4.preOrder_noRecu();
	cout << endl;
	cout << "---------测试非递归中序遍历新二叉树1----------" << endl;
	mytree4.inOrder_noRecu();
	cout << endl;
	cout << "---------测试非递归后序遍历新二叉树1----------" << endl;
	mytree4.postOrder_noRecu();
	cout << endl;
	BinaryTree<char> mytree5;//创建二叉树
	mytree5.CreateBTreeAccordPO((char*)"DBACE", (char*)"DBECA");
	cout << "---------测试非递归前序遍历新二叉树2----------" << endl;
	mytree5.preOrder_noRecu();
	cout << endl;
	cout << "---------测试非递归中序遍历新二叉树2----------" << endl;
	mytree5.inOrder_noRecu();
	cout << endl;
	cout << "---------测试非递归后序遍历新二叉树2----------" << endl;
	mytree5.postOrder_noRecu();
	return 0;
}