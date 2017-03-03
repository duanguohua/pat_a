#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct TreeNode
{
	ElementType data;
	struct TreeNode *left, *right;
	int height;
} TreeNode, *AVL;

typedef AVL QElementTye;
typedef struct QNode
{
	QElementTye *data;
	int size;
	int front, rear;
}QNode, *Queue;

AVL Create(ElementType x);
AVL Insert(AVL BST, ElementType x);

AVL Insert(AVL BST, ElementType x);
AVL SingleRightRotation(AVL A);
AVL SingleLeftRotaton(AVL A);
AVL DoubleRightLeftRotation(AVL A);
AVL DoubleLeftRightRotation(AVL A);

void LevelOrder(AVL BT);
Queue CreateQ(int maxsize);
bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
bool AddQ(Queue Q, QElementTye x);
QElementTye DeleteQ(Queue Q);

int GetHeight(AVL T);
int Max(int a, int b);
void ProOrder(AVL T);

void IsComplete(AVL BT);

bool iscomplete = true;

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
//	putchar('\n');
//	ProOrder(BST);
//	putchar('\n');
	LevelOrder(BST);
	
	iscomplete ? printf("\nYES"):printf("\nNO");
	
	
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
//    printf("%d\n", x);
	if (!BST)
	{
		BST = Create(x);		
//        printf("ok\n");
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
	
//	printf("height: %d\n", BST->height);
	return BST;
}

AVL Create(ElementType x)
{
	AVL tmp = (AVL) malloc(sizeof(TreeNode));
	tmp->data = x;
	tmp->height = 0;
	tmp->left = tmp->right = NULL;             //指针没有初始化，导致错误 
	return tmp;
}

AVL SingleRightRotation(AVL A)
{	
//printf("%s\n", __func__);
    
	AVL B = A->right;
	A->right = B->left;
	B->left = A;
	A->height =1+ Max(GetHeight(A->left), GetHeight(A->right));
	B->height = 1 + Max(GetHeight(B->right), A->height);
	return B;
}

AVL SingleLeftRotaton(AVL A)
{	
//printf("%s\n", __func__);
	AVL B = A->left;
	A->left = B->right;
	B->right = A;
	A->height =1+ Max(GetHeight(A->left), GetHeight(A->right));
	B->height = 1 + Max(GetHeight(B->left), A->height);
	return B;
}

AVL DoubleRightLeftRotation(AVL A)
{	
//printf("%s\n", __func__);
	A->right = SingleLeftRotaton(A->right);
	return SingleRightRotation(A);
}

AVL DoubleLeftRightRotation(AVL A)
{	
//printf("%s\n", __func__);
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
//	    printf("0");
		return 0;		
	}
	else
	{
	    
		HR = GetHeight(T->right);		
		HL = GetHeight(T->left);	
		
//		printf("HR: %d, HL: %d", HR, HL);
		
		return 1+(HR>HL ? HR:HL);
	}
}

void LevelOrder(AVL BT)
{
	if (!BT)
	{
//		printf("is NULL");
		return;
	}
	int i = 1;
	AVL tmp;
	int maxsize = 50;
	Queue Q = CreateQ(maxsize);
	AddQ(Q, BT);
	
	while (!IsEmpty(Q))
	{
		tmp = DeleteQ(Q);
		if (tmp)  //不空就打印和将子树不判断就进队， 
        {
            i? printf("%d", tmp->data) : printf(" %d", tmp->data);
            i=0;      
        	AddQ(Q, tmp->left);
           	AddQ(Q, tmp->right);  
        } 
        else       //判断是否为完全树 
        {
            if (Q->data[Q->front+1])
            {
                iscomplete = false;
            }
         } 
//    	IsComplete(tmp);
	}
	
}

Queue CreateQ(int maxsize)
{
	Queue q = (Queue) malloc(sizeof(QNode));
	q->front = q->rear = -1;
	q->data = (QElementTye *) malloc(maxsize * sizeof(QElementTye));
	q->size = maxsize;
	return q;
}

bool IsFull(Queue Q)
{
	return Q->front == (Q->rear+1)%Q->size;
}

bool IsEmpty(Queue Q)
{
	return Q->front == Q->rear;
}

bool AddQ(Queue Q, QElementTye x)
{
	if (IsFull(Q))
	{
//		printf("queue is full");
		return false;
	}
	else
	{
		Q->rear = (Q->rear+1)%Q->size;
		Q->data[Q->rear] = x;
		return true;
	}
	
}

QElementTye DeleteQ(Queue Q)
{
	if (IsEmpty(Q))
	{
//		printf("queue is empty");
		return NULL;
	}
	else
	{
		Q->front = (Q->front +1)%Q->size;
		return Q->data[Q->front];
	}
}

void IsComplete(AVL BT)     //s本身无错，在但层序输出函数中调用上有问题 
{
	int HR, HL;
	HR = HL = 0;
	HR = GetHeight(BT->right);
	HL = GetHeight(BT->left);
	if (HR > HL)
	{
		iscomplete = false;
	}
}

