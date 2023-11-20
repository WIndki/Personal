#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<queue>
#define MaxSize 1000
#define SElemType char

using namespace std;

struct ElemType {
	SElemType value;
};
typedef struct BiTNode {	//二叉树的链式存储
	ElemType data;	//数据域
	struct BiTNode *lchild, *rchild;	//左、右孩子
} BiTNode, *BiTree;

//二叉树的建立
void CreatBiTree(BiTree &T) {
	SElemType a, b, c;
	BiTree BT;
	queue<BiTree> Q;
	cin >> a;
	if (a == '#') return ;//创建第一个结点
	T = (BiTNode *)malloc(sizeof(BiTNode));
//	T = new BiTNode;
	T->data.value = a;
	T->lchild = T->rchild = NULL;
	Q.push(T);	//将结点地址入队
	while (cin >> a) {
		if (a == '#') break;
		BT = Q.front();//从队列中取出一个结点的地址
		Q.pop();
		cin >> b;
		if (b == '0') BT->lchild = NULL;
		else {	//分配新结点，作为出队结点的左孩子
			BT->lchild = (BiTNode *)malloc(sizeof(BiTNode));
			BT->lchild->data.value = b;
			BT->lchild->lchild = BT->lchild ->rchild = NULL;
			Q.push(BT->lchild);	//新结点入队
		}
		cin >> c;
		if (c == '0') BT->rchild = NULL;
		else {	//分配新结点，作为出队结点的右孩子
			BT->rchild = (BiTNode *)malloc(sizeof(BiTNode));
			BT->rchild->data.value = c;
			BT->rchild->lchild = BT->rchild->rchild = NULL;
			Q.push(BT->rchild);
		}
	}
}

int TreeDeep(BiTree T) {	//求树的深度
	if (T == NULL) {
		return 0;
	} else {
		int l = TreeDeep(T->lchild);	//计算左子树的深度
		int r = TreeDeep(T->rchild);	//计算右子树的深度
		return l > r ? l + 1 : r + 1;	//深度还要加上根结点这一层
	}
}
int main() {
	BiTree T;
	int high;
	CreatBiTree(T);
	high = TreeDeep(T);
	cout<<high<<endl;
	return 0;
}