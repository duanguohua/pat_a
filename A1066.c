#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ���Ľ�㶨�� */
typedef int ElementType;
typedef struct TreeNode
{
	ElementType data;
	struct TreeNode *left, *right;
	int height;
} TreeNode, *AVL;

/* ���еĶ��� */
typedef AVL QElementTye;
typedef struct QNode
{
	QElementTye *data;
	int size;
	int front, rear;
}QNode, *Queue;

AVL Create(ElementType x);                  /* ����һ������㣬����ָ���ʼ�� */

AVL Insert(AVL BST, ElementType x);         /* ��AVL���в����� */

//AVL������ת 
AVL SingleRightRotation(AVL A); 
AVL SingleLeftRotaton(AVL A);
AVL DoubleRightLeftRotation(AVL A);
AVL DoubleLeftRightRotation(AVL A);

int GetHeight(AVL T);       //��ø߶� 
int Max(int a, int b);      //���ֵ  


int main(void)
{
	freopen("test.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int i, tmp;
	AVL BST = NULL;
	for (i=0; i<n; i++)
	{
		scanf("%d", &tmp);
		BST = Insert(BST, tmp);
	}
    
	printf("%d", BST->data);
	
	return 0;
}

void ProOrder(AVL T)
{
	if (T)
	{
		printf("%d ", T->data);
		ProOrder(T->left);
		ProOrder(T->right);
	}
}

AVL Insert(AVL BST, ElementType x)
{

	if (!BST)
	{
		BST = Create(x);		
	}
	else
	{
		if (x>BST->data)
		{
			BST->right = Insert(BST->right, x);
			if (GetHeight(BST->right)
				-GetHeight(BST->left)>1)
			{
				if (x > BST->right->data)
				{
					BST = SingleRightRotation(BST);
				}
				else
				{
					BST = DoubleRightLeftRotation(BST);
				}
			}
		}
		else if (x<BST->data)
		{
			BST->left = Insert(BST->left, x);
			if (GetHeight(BST->left)
				-GetHeight(BST->right)>1)
			{
				if (x < BST->left->data)
				{
					BST = SingleLeftRotaton(BST);
				}
				else
				{
					BST = DoubleLeftRightRotation(BST);
				}
			}
		}
	}
	
	BST->height = GetHeight(BST);
	
	return BST;
}

AVL Create(ElementType x)
{
	AVL tmp = (AVL) malloc(sizeof(TreeNode));
	tmp->data = x;
	tmp->height = 0;
	tmp->left = tmp->right = NULL;             //ָ��û�г�ʼ�������´��� 
	return tmp;
}

AVL SingleRightRotation(AVL A)
{	    
	AVL B = A->right;
	A->right = B->left;
	B->left = A;
	A->height =1+ Max(GetHeight(A->left), GetHeight(A->right));
	B->height = 1 + Max(GetHeight(B->right), A->height);
	return B;
}

AVL SingleLeftRotaton(AVL A)
{	
	AVL B = A->left;
	A->left = B->right;
	B->right = A;
	A->height =1+ Max(GetHeight(A->left), GetHeight(A->right));
	B->height = 1 + Max(GetHeight(B->left), A->height);
	return B;
}

AVL DoubleRightLeftRotation(AVL A)
{	
	A->right = SingleLeftRotaton(A->right);
	return SingleRightRotation(A);
}

AVL DoubleLeftRightRotation(AVL A)
{	
	A->left = SingleRightRotation(A->left);
	return SingleLeftRotaton(A);
}

int Max(int a, int b)
{
	return a>b?a:b;
}

int GetHeight(AVL T)
{
    
	int HR, HL;
	HR = HL = 0;
	
	if (T==NULL)
	{
		return 0;		
	}
	else
	{  
		HR = GetHeight(T->right);		
		HL = GetHeight(T->left);	
		return 1+(HR>HL ? HR:HL);
	}
}

