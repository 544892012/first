#include <iostream>
/*
本工程参考算法导论第10章 10.4节有根叔小结总结代码。
*/
using namespace std;

/*
下面是一种常用的定义（链表什么的都是这种定义类型）
BiTree:  结点类型
*BiTree： 树结构，指针变量。
*/
typedef struct BitNode     
{  
    char data;                       //数据域  
    struct BitNode *lchid, *rchild;  //左右孩子 
	struct BitNode *p;    // 父节点
}BiTNode, *BiTree;  

/*初始化二叉树*/
void InitBiTree (BiTree* T)
{
	*T = NULL;
}

/*前序输入创建二叉树*/
/* 
C++ 中这样用也是可以的； 主函数直接这样调用  Creat（T）
体现了引用的作用
第一种 Creat  是C++风格，  （http://www.cnblogs.com/markliu/archive/2012/12/02/2798451.html）
第二种 CreateBiTree 是C语言的风格（二级指针）
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

/*销毁二叉树 */
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
** 判断二叉树是否为空
** 若为空，返回TRUE,否则返回FALSE 
************************************/
bool BiTreeEmpty (BiTree T)
{
	if (T)
		return false;
	else
		return true;
}

/*返回二叉树的深度*/
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

/*前序遍历二叉树*/
void PreOrderTraverse (BiTree T)
{
	if (T == NULL)
		return ;
	cout << T->data;
	PreOrderTraverse (T->lchid);
	PreOrderTraverse (T->rchild);
}

/*中序遍历二叉树*/
void InOrderTraverse (BiTree T)
{
	if (T == NULL)
		return ;
	InOrderTraverse (T->lchid);
	cout << T->data;
	InOrderTraverse (T->rchild);
}

/*后序遍历二叉树*/
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

	CreateBiTree(&tree);   //两种创建是一样的
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