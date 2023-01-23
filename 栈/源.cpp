#include <iostream>
using namespace std;
//栈的操作
//为了方便，将数组下标为0的一端作为栈底
//顺序栈的类定义
#define InitSize 10 //动态数组尺寸
#define IncSize 5 //当动态数组存满数据后每次扩容所能多保存的元素数量
template <typename T>//T代表数组中元素类型
class SeqStack
{
public:
	SeqStack(int length = InitSize);//构造函数
	~SeqStack();//析构函数
	bool Push(const T& e);//入栈（增加数据）
	bool Pop(T& e);//出栈（删除栈顶数据）
	bool GetTop(T& e);//获取栈顶元素数据
	void DisplayStack();//扫描栈内元素
	int StackLength();//获取栈的长度
	bool IsEmpty();//判断栈是否为空栈
	bool IsFull();//判断栈是否已满
private:
	void IncreaseSize();//当顺序栈存满数据后可以调用此函数来扩容
	T* m_data;//存放顺序栈中的元素
	int m_maxsize;//动态数组最大容量
	int m_top;//栈顶指针（用作数组下标），指向栈顶元素
};
template <typename T>
SeqStack<T>::SeqStack(int length)
{
	m_data = new T[length];//为一维数组动态分配内存
	m_maxsize = length;
	m_top = -1;//空栈时取-1值
}
template <typename T>
SeqStack<T>::~SeqStack()
{
	delete[] m_data;//删除数组
}
template <typename T>
bool SeqStack<T>::Push(const T& e)//入栈操作
{
	if (IsFull())
	{
		cout << "顺序栈已满，正在扩容......" << endl;
		IncreaseSize();
	}
	m_top++;//栈顶指针往后走
	m_data[m_top] = e;//存入数据
	return true;
}
template <typename T>
void SeqStack<T>::IncreaseSize()//扩容函数
{
	T* p = m_data;
	m_data = new T[m_maxsize + IncSize];//重新为顺序栈分配更大的数据空间
	for (int i = 0; i <= m_top; ++i)
	{
		*(m_data + i) = *(p + i);//将数据再赋值
	}
	m_maxsize += IncSize;//最大容量加5 
	delete [] p;
}
template <typename T>
bool SeqStack<T>::Pop(T& e)//出栈函数
{
	if (IsEmpty())
	{
		cout << "空栈,无法出栈！" << endl;
		return false;
	}
	e = m_data[m_top];//栈顶元素值返回到e中
	m_top--;
	return true;
}
template <typename T>
bool SeqStack<T>::GetTop(T& e)
{
	if (IsEmpty())
	{
		cout << "空栈,没有栈顶元素！" << endl;
		return false;
	}
	e = m_data[m_top];//获取栈顶元素
	return true;
}
template <typename T>
bool SeqStack<T>::IsFull()
{
	if (m_top == m_maxsize - 1)
	{
		return true;
	}
	return false;
}
template <typename T>
bool SeqStack<T>::IsEmpty()
{
	if (m_top < 0)
	{
		return true;
	}
	return false;
}
template <typename T>
void SeqStack<T>::DisplayStack()
{
	for (int i = m_top; i >=0; i--)
	{
		cout << m_data[i] << " ";
	}
	cout << endl;
}
template <typename T>
int SeqStack<T>::StackLength()
{
	return m_top = +1;
}
int main()
{
	SeqStack<int> obj(10);
	int k;
	obj.Push(150);
	obj.Push(200);
	obj.Push(300);
	obj.Push(450);
	obj.Push(500);
	obj.Push(110);
	obj.Push(15);
	obj.DisplayStack();
	obj.Pop(k);
	obj.DisplayStack();
	return 0;
}