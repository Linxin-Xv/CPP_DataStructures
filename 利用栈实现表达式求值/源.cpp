#include <iostream>
#include<string>
using namespace std;
//中缀表达式：运算符在操作数中间
//利用栈将中缀表达式转化成后缀表达式，然后再次利用栈对这个后缀表达式求值得到结果。
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
int main()
{
	LinkStack<int> obj;//初始化一个int型的链式栈的对象
	obj.Push(1);
	obj.Push(2);
	obj.Push(3);
	obj.Push(4);
	obj.Push(5);
	obj.DisplayLinkStack();
	int k;
	obj.Pop(k);
	obj.DisplayLinkStack();
	obj.Pop(k);
	obj.DisplayLinkStack();
	bool ifMatchSuce = true;//是否匹配成功的标志，先标记匹配成功。
	LinkStack<char> charleftobj;//初始化一个保存左括号的char型的链式栈
	string strExp = "[({}){}]";
	for (int i = 0; i < strExp.size(); ++i)
	{
		if (strExp[i] == '(' || strExp[i] == '[' || strExp[i] == '{')
		{
			charleftobj.Push(strExp[i]);//左括号全部入栈
		}
		else
		{
			//当前是个右括号，则从栈顶取出一个左括号
			char tmptopchar;
			if (charleftobj.Pop(tmptopchar) == false)//从栈顶取数据失败
			{
				ifMatchSuce = false;
				break;
			}
			//取得了站顶部的一个左括号，看一看是否匹配
			if ((strExp[i] == ')' && tmptopchar == '(') || (strExp[i] == ']' && tmptopchar == '[') || (strExp[i] == '}' && tmptopchar == '{'))
			{
				continue;
			}
			else
			{
				//括号不匹配
				ifMatchSuce = false;
				break;
			}
		}//end if
	}//end for
	//扫描完成，还要确定charleftobj为空才行
	if (ifMatchSuce == true && charleftobj.Empty() == false)
	{
		ifMatchSuce = false;
	}
	if (ifMatchSuce == true)
	{
		cout << "\"" << strExp << "\"格式合法，括号配对数量和顺序都正确。" << endl;
	}
	else
	{
		cout << "\"" << strExp << "\"格式非法，括号配对数量或顺序存在错误。" << endl;
	}
	return 0;
}