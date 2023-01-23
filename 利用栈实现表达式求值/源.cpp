#include <iostream>
#include<string>
using namespace std;
//��׺���ʽ��������ڲ������м�
//����ջ����׺���ʽת���ɺ�׺���ʽ��Ȼ���ٴ�����ջ�������׺���ʽ��ֵ�õ������
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
int main()
{
	LinkStack<int> obj;//��ʼ��һ��int�͵���ʽջ�Ķ���
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
	bool ifMatchSuce = true;//�Ƿ�ƥ��ɹ��ı�־���ȱ��ƥ��ɹ���
	LinkStack<char> charleftobj;//��ʼ��һ�����������ŵ�char�͵���ʽջ
	string strExp = "[({}){}]";
	for (int i = 0; i < strExp.size(); ++i)
	{
		if (strExp[i] == '(' || strExp[i] == '[' || strExp[i] == '{')
		{
			charleftobj.Push(strExp[i]);//������ȫ����ջ
		}
		else
		{
			//��ǰ�Ǹ������ţ����ջ��ȡ��һ��������
			char tmptopchar;
			if (charleftobj.Pop(tmptopchar) == false)//��ջ��ȡ����ʧ��
			{
				ifMatchSuce = false;
				break;
			}
			//ȡ����վ������һ�������ţ���һ���Ƿ�ƥ��
			if ((strExp[i] == ')' && tmptopchar == '(') || (strExp[i] == ']' && tmptopchar == '[') || (strExp[i] == '}' && tmptopchar == '{'))
			{
				continue;
			}
			else
			{
				//���Ų�ƥ��
				ifMatchSuce = false;
				break;
			}
		}//end if
	}//end for
	//ɨ����ɣ���Ҫȷ��charleftobjΪ�ղ���
	if (ifMatchSuce == true && charleftobj.Empty() == false)
	{
		ifMatchSuce = false;
	}
	if (ifMatchSuce == true)
	{
		cout << "\"" << strExp << "\"��ʽ�Ϸ����������������˳����ȷ��" << endl;
	}
	else
	{
		cout << "\"" << strExp << "\"��ʽ�Ƿ����������������˳����ڴ���" << endl;
	}
	return 0;
}