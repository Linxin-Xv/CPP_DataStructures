#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
typedef struct CLinkList
{
	int data;
	struct CLinkList* next;
}node;
void ds_insert(node** pNode, int i)
{
	node* temp;
	node* target;
	node* p;
	int item;
	int j = 1;
	printf("����Ҫ����ڵ��ֵ:");
	cin >> item;
	if (i == 1)
	{//�²���Ľڵ���Ϊ��һ���ڵ�
		temp = (node*)malloc(sizeof(struct CLinkList));
		if (!temp)
		{
			exit(0);
		}
		temp->data = item;
		//Ѱ�ҵ����һ���ڵ�
		for (target = (*pNode); target->next != (*pNode); target = target->next)
			;
		temp->next = (*pNode);
		target->next = temp;
		*pNode = temp;
	}
	else
	{
		target = *pNode;
		for (; j < (i - 1); ++j)
		{
			target = target->next;
		}
		temp = (node*)malloc(sizeof(struct CLinkList));
		if (!temp)
		{
			exit(0);
		}
		temp->data = item;
		p = target->next;
		target->next = temp;
		temp->next = p;
	}
}
void ds_init(node** pNode)
{
	int item;
	node* temp;
	node* target;
	cout << "����ڵ��ֵ������0��ɳ�ʼ����" << endl;
	while (1)
	{
		cin >> item;
		fflush(stdin);
		if (item == 0)
		{
			return;
		}
		if ((*pNode) == NULL)
		{//ѭ������ֻ��һ���ڵ�
			*pNode = (node*)malloc(sizeof(struct CLinkList));
			if (!(*pNode))
			{
				exit(0);
			}
			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		}
		else
		{//�ҵ�nextָ���һ���ڵ�Ľڵ�
			for (target = (*pNode); target->next != (*pNode); target = target->next)
				;
			//����һ���µĽڵ�
			temp = (node*)malloc(sizeof(struct CLinkList));
			if (!temp)
			{
				exit(0);
			}
			temp->data = item;
			temp->next = *pNode;
			target->next = temp;
		}
	}
}
/*ɾ�����*/
void ds_delete(node** pNode, int i)
{
	node* target;
	node* temp;
	int j = 1;

	if (i == 1)
	{ //ɾ�����ǵ�һ�����
		/*�ҵ����һ�����*/
		for (target = *pNode; target->next != *pNode; target = target->next)
			;

		temp = *pNode;
		*pNode = (*pNode)->next;
		target->next = *pNode; 
		free(temp);
	}
	else
	{
		target = *pNode;

		for (; j < i - 1; ++j)
		{
			target = target->next;
		}

		temp = target->next;
		target->next = temp->next;
		free(temp);
	}
}
int ds_count(node** pNode)//����������
{   
	node* target;
	int count=1;
	target = *pNode;
	do
	{
		target = target->next;
		count++;
	} while ((target->next) != (*pNode));
	return count;
}
void ds_out_scan(node** pNode, int i)//����ɨ��
{
	node* target;
	node* temp;
	int j = 1;
	for (j; j < i - 1; j++)
	{
		target = *pNode;
		for (int k = 0; k < 3 * j - 1; k++)
		{
			target = target->next;
		}
		temp = target->next;
		cout << temp->data;
		if ((i - j) * (i - j) > 4)
		{
			cout << "->";
		}
		else
		{
			cout << endl;
		}
	}
}
void ds_out_delete(node** pNode,int i)//һ��ɨ�裬һ������ɾ��
{
	node* target;
	node* temp;
	//node* count;
	int j = 1;
	int count_num = 1;
	for (j; j < i - 1; j++)
	{
		target = *pNode;
		for (int k = 0; k < 2 * j - 1; k++)
		{
			target = target->next;
		}
		temp = target->next;
		cout << temp->data;
		if ((i - j) * (i - j) > 4)
		{
			cout << "->";
		}
		else
		{
			cout << endl;
		}
		target->next = temp->next;
	}
	//target = *pNode;
	//count = *pNode;
	//do
	//{
	//	target = target->next;
	//	temp = target->next;
	//	cout << temp->data << "->";
	//	target->next = temp->next;
	//	free(temp);
	//	j--;
	//	//cout << ((target->next)->next)->data << "->";
	//	///*target = temp_1;
	//	//target->next = temp_2->next;*/
	//	//temp = (target->next)->next;
	//	//(target->next)->next = temp->next;
	//	//target = temp;
	//	//free(temp);
	//} while (j > 2);
	//if (i == 1)
	//{ //ɾ�����ǵ�һ�����
	//	/*�ҵ����һ�����*/
	//	for (target = *pNode; target->next != *pNode; target = target->next)
	//		;

	//	temp = *pNode;
	//	*pNode = (*pNode)->next;
	//	target->next = *pNode;
	//	free(temp);
	//}
	//else
	//{
	//	target = *pNode;

	//	for (; j < i - 1; ++j)
	//	{
	//		target = target->next;
	//	}

	//	temp = target->next;
	//	target->next = temp->next;
	//	free(temp);
	//}
}
/*���ؽ������λ��*/
int ds_search(node* pNode, int elem)
{
	node* target;
	int i = 1;

	for (target = pNode; target->data != elem && target->next != pNode; ++i)
	{
		target = target->next;
	}

	if (target->next == pNode) /*���в����ڸ�Ԫ��*/
		return 0;
	else
		return i;
}

/*����*/
void ds_traverse(node* pNode)
{
	node* temp;
	temp = pNode;
	printf("***********�����е�Ԫ��******************\n");

	do
	{
		printf("%4d ", temp->data);
	} while ((temp = temp->next) != pNode);

	printf("\n");
}
int main()
{
	node* pHead = NULL;
	ds_init(&pHead);
	cout << endl;
	int k;
	k = ds_count(&pHead);
	ds_traverse(pHead);
	cout << k << endl;
	ds_out_delete(&pHead,k);
	ds_traverse(pHead);
	/*while (opp != '0')
	{
		cin >> opp;
		switch (opp)
		{
		case '1':
			ds_init(&pHead);
			cout << endl;
			ds_traverse(pHead);
			break;

		case '2':
			printf("������Ҫ�������λ�ã�");
			cin >> find;
			ds_insert(&pHead, find);
			printf("��λ��%d����ֵ��\n", find);
			ds_traverse(pHead);
			printf("\n");
			break;

		case '3':
			printf("������Ҫɾ���Ľ��λ�ã�");
			cin >> find;
			ds_delete(&pHead, find);
			printf("ɾ����%d������:\n", find);
			ds_traverse(pHead);
			printf("\n");
			break;

		case '4':
			printf("��Ҫ���ҵ����ڼ�������ֵ��");
			cin >> find;
			printf("Ԫ��%d����λ�ã�%d\n", find, ds_search(pHead, find));
			//ListTraverse(L);
			printf("\n");
			break;

		case '5':
			ds_traverse(pHead);
			printf("\n");
			break;

		case '0':
			exit(0);
		}
	}*/
	return 0;
}