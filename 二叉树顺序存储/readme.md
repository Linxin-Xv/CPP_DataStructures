树形结构是一种非线性数据结构，是一种一对多的关系，一样的数字可以分支出很多子树枝、树叶等。  

二叉树最常用；  

数$(tree)$是n个节点的有限集；n=0是为空树；若不是空树，则有且只有一个节点称为树根$(root)$的节点；  

$n>1$时，其余节点可以分为$m(m>0)$个互不相交的有限集$（T_1、T_2、T_3...T_m）$每个集合自身又是一棵树并称呼为根的子树；  

控制顺序：从上往下；  

有序树：各个子树是有次序的，否则就是无序树；  

节点拥有的子树数目叫做节点的度；  

度为0的节点称为叶节点或者终端节点；  

度不为0的节点称为分支节点或者非终端节点；  

除根节点外的分支节点也叫内部节点；  

树的度就是树内各节点度的最大值；  

节点的子树的根称为该节点的子节点；  

每个节点只能有一个父节点，根节点没有父节点；  

节点的层次：树的高度或者深度是节点的最大层数；  

相同父节点的子节点之间互称兄弟节点$(Sibling)$；层次相同但父节点不同的子节点互称堂兄弟节点；  

# 二叉树  

## （1）基本概念  

每个节点最多有两个子树（左子树和右子树）是一个有序树  

定义：二叉树是$n(n>=0)$个节点的有限集合，该集合或者为空集（$n=0$,空二叉树），或者由一个根节点和两个互不相交的该根节点的左子树和右子树构成；左子树和右子树又分别是一棵二叉树；  

二叉树不一定是度为2的有序树；  

## (2)特殊二叉树  

### 1.满二叉树  

#### 特点：1）.所有分支节点都有左子树和右子树；  

#### 2）.所有叶子节点都在同一层（最下层）；  

#### 3）.不存在度为非$0$或者非2的节点；  

定义：一棵高度为h，并且含有$2^h-1$个节点的二叉树；  

### 2.完全二叉树  

#### 特点1）.叶子节点在最底下两层；  

#### 2）.最后一层的叶子节点都靠左侧连续，并且除了最后一层，其它层的节点个数都要达到最大；  

#### 3）.倒数第二层如果有叶子节点，则叶子节点都是靠右侧连续；  

#### 4）.如果节点度为1，则该节点只有左子树，不可以只有右子树，而且最多只有一个度为1的节点；  

满二叉树是一棵完全二叉树，而完全二叉树不一定是满二叉树；  

### 3.斜树  

左斜树、右斜树;  

## （3）二叉树的性质  

### 性质1.二叉树的第i层，最多有$2^{(i-1)}$个节点；  

### 性质2.高度为k的二叉树，最多有$2^k-1$个节点；  

### 性质3.二叉树节点的总数量等于每个节点的总度数加1；  

### 性质4.任何一个二叉树，如果叶节点的数量为$n_0$，度为2的节点数量为$n_2$;  

若假设度为1的节点总数量为$n_1$；则二叉树节点总数量$n=n_0+n_1+n_2$;  

$二叉树的节点总度数=2*n_2+n_1$;  

又由性质3  

$2*n_2+n_1+1=n_0+n_1+n_2$;  

所以$n_0=n_2+1$;  
### 知道了一个完全二叉树的节点总数$n$，如何求出$n_0,n_1$和$n_2$?
#### 1.完全二叉树最多只有一个度为1的节点；$n_1=0或者n_1=1$；
#### 2.根据公式：$n=2*n_2+n_1+1$,
其中$(2*n_2+1)$的结果肯定是奇数；
#### 3.那么，如果该完全二叉树的总数是偶数，那么$n_1=1$;
如果该完全二叉树的总数是奇数，那么$n_1=0$;  
#### 4.根据公式可以求得$n_0,n_2$的值；
### 性质5.具有$n(n>0)$个节点的完全二叉树的高度为$\lceil log_2(n+1) \rceil$ 或者$\lfloor log_2 n \rfloor+1$。
其中符号$\lceil X \rceil$表示向上取整、符号$\lfloor X \rfloor$表示向下取整。  
## (4)二叉树的遍历  
从根出发，依次访问二叉树所有节点，使每个节点都被访问且只被访问一次；
### 经典遍历方式：前序遍历、中序遍历、后序遍历；（深度优先搜索/深度优先遍历[沿着每一个分支路径进行深入访问]）
### 前序遍历基本概念（先序遍历/先根遍历） 口诀：根左右；
### 中序遍历基本概念（中根遍历）口诀：左根右；
### 后序遍历基本概念 口诀：左右根；
### 前序、中序，后序遍历针对普通二叉树的遍历顺序伪代码  
``` C++
//前序遍历伪代码
void preOrder(BinaryTreeNode* tNode)//前序遍历二叉树
{
    if(tNode != nullptr)//如果二叉树非空
    {
       visit(tNode);//访问根节点
       preOrder(tNode->leftChild);//递归访问左子树
       preOrder(tNode->rightChild);//递归访问右子树
    }
}
//中序遍历伪代码
void inOrder(BinaryTreeNode* tNode)//中序遍历二叉树
{
 if(tNode != nullptr)//如果二叉树非空
    {
       inOrder(tNode->leftChild);//递归访问左子树
       visit(tNode);//访问根节点
       inOrder(tNode->rightChild);//递归访问右子树
    }
}
//后序遍历伪代码
void postOrder(BinaryTreeNode* tNode)//中序遍历二叉树
{
 if(tNode != nullptr)//如果二叉树非空
    {
       postOrder(tNode->leftChild);//递归访问左子树
       postOrder(tNode->rightChild);//递归访问右子树
       visit(tNode);//访问根节点
    }
}
```
### 二叉树遍历推导已经遍历的一些结论：
#### a)已知中序遍历，无法唯一确定一棵二叉树；
#### b)已知前序遍历，无法唯一确定一棵二叉树；
#### c)已知后序遍历，无法唯一确定一棵二叉树；
#### d)已知前序后后序遍历，无法唯一确定一棵二叉树；
### e)已知前序和中序遍历、或者已知中序和后序遍历可以唯一确定一棵二叉树；
#### 已知一棵二叉树的前序遍历序列是$ABCDEF$,中序遍历序列是$CBAEDF$,求这个二叉树；
##### 1)根：$A$;
##### 2)根据中序 $CBAEDF$可以确定$C,B$是根节点$A$的左子树中的节点，$E,D,F$是根节点$A$的左子树中的节点；
##### 3)根据前序和中序序列，$A$的左子树就绘制出来了；
##### 4)根据前序序列的$DEF$和中序序列的$EDF$可以推断出$A$的右子树；
### 总结给定的遍历序列确定一个二叉树的办法
#### a)找到根节点；
#### b)根据中序遍历序列来划分左子树和右子树；
#### c)进一步找到左右子树根节点以及分支和叶子节点；
### 扩展二叉树/扩充二叉树
#### a)如果给出一个扩展二叉树的前序序列或者后序遍历序列，是能够唯一确定一棵二叉树的；
#### b)给出一个扩展二叉树的中序遍历序列是无法唯一确定一棵二叉树的；
### 层序遍历/层次遍历（也称为广度优先遍历/广度优先搜索）
#### 一般要借助队列实现.
#### 从根节点开始，从上到下，从左到右；
#### 已知层序遍历序列，不能唯一确定一棵二叉树；
#### 已知层序和中序遍历序列，可以唯一确定一棵二叉树；
### 层序遍历的过程：
#### a)初始化一个队列；
#### b)把二叉树的根节点入队列；
#### c)判断队列是否为空，如果为空，就让队头节点出队（相当于遍历了该节点），同时将这个刚刚出队的节点的左孩子和有孩子分别入队列（如果该节点有左右孩子）；
## （5）二叉树的存储结构：基于数组的顺序存储、链式存储
### 顺序存储方式：用一段连续的内存单元（数组）依次从上到下、从左到右存储二叉树各个节点元素
#### 顺序存储结构一般用于存储完全二叉树；
### 链式存储方式
#### 因为多了左右子节点指针，所以适合存储普通二叉树；
#### 节点结构：一个数据域，两个指针域，二叉链表(一个节点带两个指针);
#### 在设计节点结构时再增加一个指针域用于指向其父节点，这种节点结构所得到的二叉树存储结构称为三叉链表(一个节点三个指针)；
## （6）二叉树顺序存储的常用操作（代码展示/实现前序遍历）
``` c++
#include <iostream>
using namespace std;
#define MaxSize 100  //数组的尺寸
enum ECCHILDSIGN
{
	E_Root,//树根
    E_ChildLeft,//左孩子
	E_ChildRight//右孩子
};
//树中每个节点的定义
template <typename T>//T代表数据元素的类型
struct BinaryTreeNode
{
	T data;//数据域
	bool isValid;//该节点是否有效(只有保存了实际节点数据的节点才是有效的) 
};
//二叉树的定义
template <typename T>
class BinaryTree
{
public:
	BinaryTree()//构造函数
	{
		for (int i = 0; i < MaxSize + 1; i++)
		{
			SqBiTree[i].isValid = false;//开始是节点无效
		}
	}
	~BinaryTree()//析构函数
	{

	}
	//创建一个树节点
	int CreateNode(int parindex, ECCHILDSIGN pointsign, const T& e);
	//获取父节点的下标
	int GetParentIdx(int sonindex)
	{
		if (ifValidRangeIdx(sonindex) == false)//位置不合理
		{
			return -1;
		}
		if (SqBiTree[sonindex].isValid == false)//不是合理的节点
		{
			return -1;
		}
		return int(sonindex / 2);//获取父节点的下标
	}
	//获取节点的高度
	int GetPointLevel(int index)//根据性质6
	{
		if (ifValidRangeIdx(index) == false)//位置不合理
		{
			return -1;
		}
		if (SqBiTree[index].isValid == false)//不是合理的节点
		{
			return -1;
		}
		else//采用公式计算
		{
			int level = int(log(index) / log(2) + 1);//c++是以e为底数的log。
			return level;
		}
	}
	//获取二叉树的深度
	int GetLevel()
	{
		if (SqBiTree[1].isValid == false)//没根
		{
			return 0;
		}
		int i;
		for (i = MaxSize; i >= 1; i--)
		{
			if (SqBiTree[i].Valaid == true)//找到了最后一个有效节点
			{
				break;
			}//end for
			return GetPointLevel(i);
		}
	}
	//判断是否是个完全二叉树
	bool ifCompleteBT()
	{
		int i;
		if (SqBiTree[1].isValid == false)//没根
		{
			return false;
		}
		for (i = MaxSize; i >= 1; i--)
		{
			if (SqBiTree[i].Valaid == true)//找到了最后一个有效节点
			{
				break;
			}//end for			
		}
		for (int k = 1; k <= i; k++)
		{
			if (SqBiTree[i].isValid == false)//所有节点都必须有效
			{
				return false;
			}
		}
		return true;
	}
	//前序遍历二叉树
	void preOrder()
	{
		if (SqBiTree[1].isValid == false)//没根
		{
			return;
		}
		preOrder(1);//根节点的数组下标是1，所以这里把根的下标传递进去
	}
	void preOrder(int index)
	{
		if (ifValidRangeIdx(index) == false)//位置不合理
		{
			return;
		}
		if (SqBiTree[index].isValid == false)//不是合理的节点
		{
			return;
		}
		else//采用公式计算
		{
			cout << SqBiTree[index].data << " ";//输出节点数据域的值
			preOrder(2 * index);//处理左子树
			preOrder(2 * index + 1);//处理右子树
		}
	}
private:
	BinaryTreeNode<T> SqBiTree[MaxSize + 1];//存储二叉树节点的数组，下标为0的不使用
	bool ifValidRangeIdx(int index)//是否是一个有效的下标值
	{
		//位置必须合理
		if (index < 1 || index > MaxSize)
		{
			return false;
		}
		return true;
	}
};
//创建一个树节点
template <typename T>
//参数1：父节点所在的数组下标
//参数2：标记所创建的是树根还是左孩子、右孩子
//参数3：传入新建树节点的数据
int BinaryTree<T>::CreateNode(int parindex, ECCHILDSIGN pointsign, const T& e)
{
	if (pointsign != E_Root)//非根节点，要求父节点是合法的
	{
		if (ifValidRangeIdx(parindex) == false)//父节点位置不合法
		{
			return -1;
		}
		if (SqBiTree[parindex].isValid == false)//父节点位置尚未使用
		{
			return -1;
		}
	}
	int index = -1;
	if (pointsign == E_Root)//创建根节点
	{
		index = 1;//根节点固定在下标为1的位置
	}
	else if(pointsign == E_ChildLeft)//如果插入的是左孩子
	{
		index = 2 * parindex;
		if (ifValidRangeIdx(index) == false)//父节点位置不合法
		{
			return -1;
		}
	}
	else
	{
		index = 2 * parindex + 1;
		if (ifValidRangeIdx(index) == false)//父节点位置不合法
		{
			return -1;
		}
	}
	SqBiTree[index].data = e;//传入数据
	SqBiTree[index].isValid = true;//传入节点类型
	return 0;
}
int main()
{
	BinaryTree<int> mytree;//创建一棵二叉树
	mytree.CreateNode(0, E_Root, 1);
	mytree.CreateNode(1, E_ChildLeft, 2);
	mytree.CreateNode(1, E_ChildRight, 45);
	mytree.CreateNode(2, E_ChildLeft, 79);
	//mytree.CreateNode(3,E_ChildRight, 16);
	mytree.CreateNode(2, E_ChildRight, 25);
	mytree.CreateNode(3, E_ChildLeft, 43);
	mytree.preOrder();
	cout << endl;
	return 0;
}
```