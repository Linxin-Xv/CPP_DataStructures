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