#include <iostream>
/*
�����̲ο��㷨���۵�10�� 10.4���и���С���ܽ���롣
*/
using namespace std;

/*
������һ�ֳ��õĶ��壨����ʲô�Ķ������ֶ������ͣ�
BiTree:  �������
*BiTree�� ���ṹ��ָ�������
*/
typedef struct BitNode     
{  
    char data;                       //������  
    struct BitNode *lchid, *rchild;  //���Һ��� 
	struct BitNode *p;    // ���ڵ�
}BiTNode, *BiTree;  

/*��ʼ��������*/
void InitBiTree (BiTree* T)
{
	*T = NULL;
}

/*ǰ�����봴��������*/
/* 
C++ ��������Ҳ�ǿ��Եģ� ������ֱ����������  Creat��T��
���������õ�����
��һ�� Creat  ��C++���  ��http://www.cnblogs.com/markliu/archive/2012/12/02/2798451.html��
�ڶ��� CreateBiTree ��C���Եķ�񣨶���ָ�룩
*/
void Creat(BiTree &T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
    else
	{
        T = new BiTNode;
        T->data = ch;
        Creat(T -> lchid);
        Creat(T -> rchild);
    }
}

void CreateBiTree (BiTree* T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		*T = NULL;
	else
	{
		*T = new BiTNode;
		if (!*T)
			exit (OVERFLOW);
		(*T)->data = ch;
		CreateBiTree (&(*T)->lchid);
		CreateBiTree (&(*T)->rchild);
	}
}

/*���ٶ����� */
void DestroyBiTree (BiTree* T)
{
	if (*T)
	{
		if ((*T)->lchid)
			DestroyBiTree (&(*T)->lchid);
		if ((*T)->rchild)
			DestroyBiTree (&(*T)->rchild);
		free (*T);
		*T = NULL;
	}
}

/************************************ 
** �ж϶������Ƿ�Ϊ��
** ��Ϊ�գ�����TRUE,���򷵻�FALSE 
************************************/
bool BiTreeEmpty (BiTree T)
{
	if (T)
		return false;
	else
		return true;
}

/*���ض����������*/
int BiTreeDepth (BiTree T)
{
	int i, j;
	if (!T)
		return 0;
	if (T->lchid)
		i = BiTreeDepth (T->lchid);
	else
		i = 0;
	if (T->rchild)
		j = BiTreeDepth (T->rchild);
	else
		j = 0;
	return i > j ? i+1 : j+1;
}

/*ǰ�����������*/
void PreOrderTraverse (BiTree T)
{
	if (T == NULL)
		return ;
	cout << T->data;
	PreOrderTraverse (T->lchid);
	PreOrderTraverse (T->rchild);
}

/*�������������*/
void InOrderTraverse (BiTree T)
{
	if (T == NULL)
		return ;
	InOrderTraverse (T->lchid);
	cout << T->data;
	InOrderTraverse (T->rchild);
}

/*�������������*/
void PostOrderTraverse (BiTree T)
{
	if (T == NULL)
		return ;
	PostOrderTraverse (T->lchid);
	PostOrderTraverse (T->rchild);
	cout << T->data;
}

int main()
{
	BiTree tree;

	InitBiTree(&tree);

	CreateBiTree(&tree);   //���ִ�����һ����
	//Creat(tree);

	PreOrderTraverse(tree);
	cout<< endl;
	InOrderTraverse(tree);
	cout<< endl;
	PostOrderTraverse(tree);
	cout<< endl;

	cout<< BiTreeEmpty(tree)<< endl;
	DestroyBiTree(&tree);
	cout<< BiTreeEmpty(tree)<< endl;
	PreOrderTraverse(tree);
	cout<< endl;

	return 0;
}