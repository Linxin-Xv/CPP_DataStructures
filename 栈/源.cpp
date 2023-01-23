#include <iostream>
using namespace std;
//ջ�Ĳ���
//Ϊ�˷��㣬�������±�Ϊ0��һ����Ϊջ��
//˳��ջ���ඨ��
#define InitSize 10 //��̬����ߴ�
#define IncSize 5 //����̬����������ݺ�ÿ���������ܶౣ���Ԫ������
template <typename T>//T����������Ԫ������
class SeqStack
{
public:
	SeqStack(int length = InitSize);//���캯��
	~SeqStack();//��������
	bool Push(const T& e);//��ջ���������ݣ�
	bool Pop(T& e);//��ջ��ɾ��ջ�����ݣ�
	bool GetTop(T& e);//��ȡջ��Ԫ������
	void DisplayStack();//ɨ��ջ��Ԫ��
	int StackLength();//��ȡջ�ĳ���
	bool IsEmpty();//�ж�ջ�Ƿ�Ϊ��ջ
	bool IsFull();//�ж�ջ�Ƿ�����
private:
	void IncreaseSize();//��˳��ջ�������ݺ���Ե��ô˺���������
	T* m_data;//���˳��ջ�е�Ԫ��
	int m_maxsize;//��̬�����������
	int m_top;//ջ��ָ�루���������±꣩��ָ��ջ��Ԫ��
};
template <typename T>
SeqStack<T>::SeqStack(int length)
{
	m_data = new T[length];//Ϊһά���鶯̬�����ڴ�
	m_maxsize = length;
	m_top = -1;//��ջʱȡ-1ֵ
}
template <typename T>
SeqStack<T>::~SeqStack()
{
	delete[] m_data;//ɾ������
}
template <typename T>
bool SeqStack<T>::Push(const T& e)//��ջ����
{
	if (IsFull())
	{
		cout << "˳��ջ��������������......" << endl;
		IncreaseSize();
	}
	m_top++;//ջ��ָ��������
	m_data[m_top] = e;//��������
	return true;
}
template <typename T>
void SeqStack<T>::IncreaseSize()//���ݺ���
{
	T* p = m_data;
	m_data = new T[m_maxsize + IncSize];//����Ϊ˳��ջ�����������ݿռ�
	for (int i = 0; i <= m_top; ++i)
	{
		*(m_data + i) = *(p + i);//�������ٸ�ֵ
	}
	m_maxsize += IncSize;//���������5 
	delete [] p;
}
template <typename T>
bool SeqStack<T>::Pop(T& e)//��ջ����
{
	if (IsEmpty())
	{
		cout << "��ջ,�޷���ջ��" << endl;
		return false;
	}
	e = m_data[m_top];//ջ��Ԫ��ֵ���ص�e��
	m_top--;
	return true;
}
template <typename T>
bool SeqStack<T>::GetTop(T& e)
{
	if (IsEmpty())
	{
		cout << "��ջ,û��ջ��Ԫ�أ�" << endl;
		return false;
	}
	e = m_data[m_top];//��ȡջ��Ԫ��
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