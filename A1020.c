#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TNode
{
    int data;
    struct TNode *left, *right;
}TNode, *BinTree;

typedef BinTree QElementType;
typedef struct QNode
{
    QElementType *data;
    int front, rear;
    int size;
} QNode, *Queue;


BinTree create(int pL, int pR, int mL, int mR);
BinTree create1(int pL, int pR, int mL, int mR);
void PreOrder(BinTree BT);
bool IsFull(Queue Q);
bool AddQ(Queue Q, QElementType x);
bool IsEmpty(Queue Q);
QElementType DeleteQ(Queue Q);
Queue CreateQ(int maxsize);
void LevelOrder(BinTree BT);

int n;
int *p, *m;



int main(void)
{
    freopen("由先-中序得树.txt", "r", stdin);
    
    scanf("%d", &n);
    
    p = (int *) malloc(n * sizeof(int));
    m = (int *) malloc(n * sizeof(int));
    
    memset(p, 0, sizeof(p));
    memset(m, 0, sizeof(m));
    
    int i;
    
    for (i=0; i<n; i++)
    {
        scanf("%d", &p[i]);
//        printf("%d ", p[i]);
    }
//    putchar('\n');
    for (i=0; i<n; i++)
    {
        scanf("%d", &m[i]);
//        printf("%d ", m[i]);
    }
    
    BinTree BT = create1(0, n-1, 0, n-1);


//    putchar('\n');
    LevelOrder(BT);
//    printf("*");
    return 0;
}

void PreOrder(BinTree BT)
{
    if (BT)
    {
        
        PreOrder(BT->left);
        
        PreOrder(BT->right);
        printf("%d ", BT->data);
    }
}

BinTree create(int pL, int pR, int mL, int mR)
{/*前序，中序得树*/
    int root = p[pL];
    int j, numL;
    numL = 0;
    if (pL >pR) return NULL;
    
    BinTree T = (BinTree) malloc(sizeof(TNode));
    T->left = T->right = NULL;
    T->data = root;
    
    for (j=mL; j<=mR && m[j]!=root; j++);
    numL = j-mL;
    
    T->left = create(pL+1, pL+numL, mL, j-1);
    T->right = create(pL+numL+1, pR, j+1, mR);
    return T;    
}

BinTree create1(int pL, int pR, int mL, int mR)
{/*后序，中序得树*/
    
    int root = p[pR];
    int j, numL;
    numL = 0;
    if (pL>pR) return NULL;
    
//    printf("%d\n", root);
    BinTree T = (BinTree) malloc(sizeof(TNode));
    T->left = T->right = NULL;
    T->data = root;
    
    for (j=mL; j<=mR && m[j]!=root; j++);
    numL = j - mL;
//    printf("numL:%d\n", numL);
//    printf("pL, pL+numL-1, mL, j-1: %d %d %d %d\n", pL, pL+numL-1, mL, j-1);
//    printf("pL+numL, pR-1, j+1, mR: %d %d %d %d\n", pL+numL, pR-1, j+1, mR);
    T->left = create1(pL, pL+numL-1, mL, j-1);
    T->right = create1(pL+numL, pR-1, j+1, mR);
    
    return T;    
}

void LevelOrder(BinTree BT)
{
    if (!BT) return;
    BinTree tmp = NULL;
    Queue Q = CreateQ(100);
    AddQ(Q, BT);
    int cnt = 1;
    while (!IsEmpty(Q))
    {
        tmp = DeleteQ(Q);
        if (cnt == 1)
        {
            printf("%d", tmp->data);
            cnt++;
        }
        else
        {
            printf(" %d", tmp->data);
        }
//        printf(" %d", tmp->data);
        if (tmp->left) AddQ(Q, tmp->left);
        if (tmp->right) AddQ(Q, tmp->right);
    }
//    printf("\b");
}


Queue CreateQ(int maxsize)
{
    Queue Q = (Queue) malloc(sizeof(QNode));
    Q->data = (QElementType *) malloc(maxsize * sizeof(QElementType));
    Q->front = Q->rear = -1;
    Q->size = maxsize;
    return Q;
}

bool IsFull(Queue Q)
{
    return Q->front == (Q->rear+1)%Q->size;
}

bool AddQ(Queue Q, QElementType x)
{
    if (IsFull(Q))
    {
        printf("is full");
        return false;
    }
    else
    {
        Q->rear = (Q->rear + 1)%Q->size;
        Q->data[Q->rear] = x;
        return true;
    }
    
}

bool IsEmpty(Queue Q)
{
    return Q->front == Q->rear;
}

QElementType DeleteQ(Queue Q)
{
    if (IsEmpty(Q))
    {
        return NULL;
    }
    else
    {
        Q->front = (Q->front+1)%Q->size;
        return Q->data[Q->front];
    }    
}

