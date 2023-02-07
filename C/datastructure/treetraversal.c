#include<stdio.h>
#include<stdlib.h>
//Binary Tree with linkedlist

typedef struct node
{
	int key;
	struct node* leftChild, * rightChild;
}treeNode;

treeNode* makeBTreeNode(int key)
{
	treeNode* ptr = (treeNode*)malloc(sizeof(treeNode));

	ptr->key = key;
	ptr->leftChild = ptr->rightChild = NULL;

	return ptr;
}

void preorder(treeNode* root)//전위순회
{
	if (root)
	{
		printf("%d", root->key);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

void inorder(treeNode* root)//중위순회
{
	if (root)
	{
		inorder(root->leftChild);
		printf("%d", root->key);
		inorder(root->rightChild);
	}


}
void postorder(treeNode* root)//후위순회
{
	if (root)
	{
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%d", root->key);
	}
}
int main()
{
    treeNode *bt1 = makeBTreeNode(1);
    treeNode *bt2 = makeBTreeNode(2);
    treeNode *bt3 = makeBTreeNode(3);
    treeNode *bt4 = makeBTreeNode(4);
    bt1->leftChild = bt2;
    bt1->rightChild = bt3;
    bt2->leftChild = bt4;
    printf("%d\n", bt1->leftChild->leftChild->key);

    //중위순회
    //1. 왼쪽 서브트리를 방문한다 2. 루트 노드를 방문한다 3. 오른쪽 서브트리를 방문한다
    printf("inorder: ");
    inorder(bt1);
    printf("\n");

    //전위순회
    // 1. 루트 노드를 방문한다 2. 왼쪽 서브트리를 방문한다 3. 오른쪽 서브트리를 방문한다
    printf("preorder: ");
    preorder(bt1);
    printf("\n");

    //후위순회
    //1. 왼쪽 서브트리를 방문한다 2. 오른쪽 서브트리를 방문한다 3. 루트 노드를 방문한다
    printf("postorder: ");
    postorder(bt1);
    printf("\n");

    return 0;
}