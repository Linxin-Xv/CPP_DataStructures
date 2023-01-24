#include <iostream>
using namespace std;
#define MaxSize 100  //����ĳߴ�
enum ECCHILDSIGN
{
	E_Root,//����
    E_ChildLeft,//����
	E_ChildRight//�Һ���
};
//����ÿ���ڵ�Ķ���
template <typename T>//T��������Ԫ�ص�����
struct BinaryTreeNode
{
	T data;//������
	bool isValid;//�ýڵ��Ƿ���Ч(ֻ�б�����ʵ�ʽڵ����ݵĽڵ������Ч��) 
};
//�������Ķ���
template <typename T>
class BinaryTree
{
public:
	BinaryTree()//���캯��
	{
		for (int i = 0; i < MaxSize + 1; i++)
		{
			SqBiTree[i].isValid = false;//��ʼ�ǽڵ���Ч
		}
	}
	~BinaryTree()//��������
	{

	}
	//����һ�����ڵ�
	int CreateNode(int parindex, ECCHILDSIGN pointsign, const T& e);
	//��ȡ���ڵ���±�
	int GetParentIdx(int sonindex)
	{
		if (ifValidRangeIdx(sonindex) == false)//λ�ò�����
		{
			return -1;
		}
		if (SqBiTree[sonindex].isValid == false)//���Ǻ���Ľڵ�
		{
			return -1;
		}
		return int(sonindex / 2);//��ȡ���ڵ���±�
	}
	//��ȡ�ڵ�ĸ߶�
	int GetPointLevel(int index)//��������6
	{
		if (ifValidRangeIdx(index) == false)//λ�ò�����
		{
			return -1;
		}
		if (SqBiTree[index].isValid == false)//���Ǻ���Ľڵ�
		{
			return -1;
		}
		else//���ù�ʽ����
		{
			int level = int(log(index) / log(2) + 1);//c++����eΪ������log��
			return level;
		}
	}
	//��ȡ�����������
	int GetLevel()
	{
		if (SqBiTree[1].isValid == false)//û��
		{
			return 0;
		}
		int i;
		for (i = MaxSize; i >= 1; i--)
		{
			if (SqBiTree[i].Valaid == true)//�ҵ������һ����Ч�ڵ�
			{
				break;
			}//end for
			return GetPointLevel(i);
		}
	}
	//�ж��Ƿ��Ǹ���ȫ������
	bool ifCompleteBT()
	{
		int i;
		if (SqBiTree[1].isValid == false)//û��
		{
			return false;
		}
		for (i = MaxSize; i >= 1; i--)
		{
			if (SqBiTree[i].Valaid == true)//�ҵ������һ����Ч�ڵ�
			{
				break;
			}//end for			
		}
		for (int k = 1; k <= i; k++)
		{
			if (SqBiTree[i].isValid == false)//���нڵ㶼������Ч
			{
				return false;
			}
		}
		return true;
	}
	//ǰ�����������
	void preOrder()
	{
		if (SqBiTree[1].isValid == false)//û��
		{
			return;
		}
		preOrder(1);//���ڵ�������±���1����������Ѹ����±괫�ݽ�ȥ
	}
	void preOrder(int index)
	{
		if (ifValidRangeIdx(index) == false)//λ�ò�����
		{
			return;
		}
		if (SqBiTree[index].isValid == false)//���Ǻ���Ľڵ�
		{
			return;
		}
		else//���ù�ʽ����
		{
			cout << SqBiTree[index].data << " ";//����ڵ��������ֵ
			preOrder(2 * index);//����������
			preOrder(2 * index + 1);//����������
		}
	}
private:
	BinaryTreeNode<T> SqBiTree[MaxSize + 1];//�洢�������ڵ�����飬�±�Ϊ0�Ĳ�ʹ��
	bool ifValidRangeIdx(int index)//�Ƿ���һ����Ч���±�ֵ
	{
		//λ�ñ������
		if (index < 1 || index > MaxSize)
		{
			return false;
		}
		return true;
	}
};
//����һ�����ڵ�
template <typename T>
//����1�����ڵ����ڵ������±�
//����2��������������������������ӡ��Һ���
//����3�������½����ڵ������
int BinaryTree<T>::CreateNode(int parindex, ECCHILDSIGN pointsign, const T& e)
{
	if (pointsign != E_Root)//�Ǹ��ڵ㣬Ҫ�󸸽ڵ��ǺϷ���
	{
		if (ifValidRangeIdx(parindex) == false)//���ڵ�λ�ò��Ϸ�
		{
			return -1;
		}
		if (SqBiTree[parindex].isValid == false)//���ڵ�λ����δʹ��
		{
			return -1;
		}
	}
	int index = -1;
	if (pointsign == E_Root)//�������ڵ�
	{
		index = 1;//���ڵ�̶����±�Ϊ1��λ��
	}
	else if(pointsign == E_ChildLeft)//��������������
	{
		index = 2 * parindex;
		if (ifValidRangeIdx(index) == false)//���ڵ�λ�ò��Ϸ�
		{
			return -1;
		}
	}
	else
	{
		index = 2 * parindex + 1;
		if (ifValidRangeIdx(index) == false)//���ڵ�λ�ò��Ϸ�
		{
			return -1;
		}
	}
	SqBiTree[index].data = e;//��������
	SqBiTree[index].isValid = true;//����ڵ�����
	return 0;
}
int main()
{
	BinaryTree<int> mytree;//����һ�ö�����
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