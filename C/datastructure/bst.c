#include <stdio.h>
#include <stdlib.h>
// Binary Search Tree
// ALL<k <- key -> ALL>k
typedef struct node {
	int key;
	struct node *leftChild, *rightChild;
} treeNode;

treeNode *search_BST_r(treeNode *root, int targetKey)
{
	if (!root)
		return NULL;
	if (targetKey == root->key)
		return root;
	if (targetKey < root->key)
		return search_BST_r(root->leftChild, targetKey);
	return search_BST_r(root->rightChild, targetKey);
}
treeNode *search_BST_i(treeNode *root, int targetKey)
{
	while (root != NULL) {
		if (targetKey == root->key)
			return root;
		else if (targetKey < root->key)
			root = root->leftChild;
		else
			root = root->rightChild;
	}
	return NULL; // 못찾았을 때
}

treeNode *insert_BST_r(treeNode *root, int key)
{
	if (!root) { // 처음으로 삽입할 때
		treeNode *pNew = (treeNode *)malloc(sizeof(treeNode));
		pNew->key = key;
		pNew->leftChild = pNew->rightChild = NULL;
		return pNew;
	}
	if (key < root->key)
		root->leftChild = insert_BST_r(root->leftChild, key);
	else if (key > root->key)
		root->rightChild = insert_BST_r(root->rightChild, key);
	return root;
}
treeNode *insert_BST_i(treeNode *root, int key)
{
	treeNode *pPre, *pLoc, *pNew;
	pPre = NULL;
	pLoc = root;
	while (pLoc) {
		if (key == pLoc->key)
			return root; // 동일한 데이터 삽입 불허. pPre = pLoc;
		pLoc = (key < pLoc->key) ? pLoc->leftChild : pLoc->rightChild;
		pPre = pLoc; // pLoc이 Null이 될 때 pPre는 마지막 노드를 가리킨다
	}
	// pPre의 자식 위치에 새로운 노드 추가
	pNew = (treeNode *)malloc(sizeof(treeNode));
	pNew->key = key;
	pNew->leftChild = pNew->rightChild = NULL;
	if (pPre)
		if (key < pPre->key)
			pPre->leftChild = pNew;
		else
			pPre->rightChild = pNew;
	else
		return pNew;
	return root;
}

treeNode *min_value_node(treeNode *root)
{
	treeNode *tmp = root;
	while (tmp->leftChild)
		tmp = tmp->leftChild;
	return tmp;
}
treeNode *delete_BST_r(treeNode *root, int key)
{
	treeNode *tmp;
	if (!root)
		return NULL;
	if (key < root->key)
		root->leftChild = delete_BST_r(root->leftChild, key);
	else if (key > root->key)
		root->rightChild = delete_BST_r(root->rightChild, key);
	else { // key == root->key
		if (root->leftChild == NULL) {
			tmp = root->rightChild;
			free(root);
			return tmp;
		} 
        else if (root->rightChild == NULL) {
			tmp = root->leftChild;
			free(root);
			return tmp;
		} 
        else {
			tmp = min_value_node(root->rightChild); //오른쪽에서 제일 작은 값 찾기(왼쪽에서 가장 큰 값을 넣을 수 도 있음)
			root->key = tmp->key;
			root->rightChild = delete_BST_r(root->rightChild, tmp->key); //오른쪽에서 제일 작은 값 삭제
		}
	}
	return root;
}
treeNode *delete_BST_i(treeNode *root, int key)
{
	treeNode *pPre, *pLoc;
	treeNode *pPre2, *pLoc2;
	treeNode *child;
	pLoc = root;
	pPre = NULL;
	while (pLoc != NULL) {
		if (key == pLoc->key)
			break;
		pPre = pLoc;
		pLoc = (key < pLoc->key) ? pLoc->leftChild : pLoc->rightChild;
	}
	if (pLoc == NULL) // 탐색 트리 내에 key가 없음
		return root;
	if ((pLoc->leftChild == NULL) || (pLoc->rightChild == NULL)) {
		// case 1: 단말노드이거나 하나의 자식만 가지는 경우
		child = (pLoc->leftChild != NULL) ? pLoc->leftChild : pLoc->rightChild;
		if (pPre != NULL) {
			if (pPre->leftChild == pLoc) // 부모를 자식과 연결
				pPre->leftChild = child;
			else
				pPre->rightChild = child;
			pPre->rightChild = child;
		} else // 만약 부모노드가 NULL이면 삭제되는 노드가 루트
			root = child;
		free(pLoc);
	} else {
		// case 2: 두개의 자식을 모두 가지는 경우
		// 오른쪽 서브트리에서 가장 작은 key를 갖는 노드를 찾는다.
		pPre2 = pLoc;
		pLoc2 = pLoc->rightChild;
		while (pLoc2->leftChild != NULL) {
			pPre2 = pLoc2;
			pLoc2 = pLoc2->leftChild;
		}
		// 오른쪽 서브트리에서 가장 작은 key를 갖는 노드: pLoc2
		// 그 부모 노드: pPre2
		if (pPre2->leftChild == pLoc2)
			pPre2->leftChild = pLoc2->rightChild;
		else
			pPre2->rightChild = pLoc2->rightChild;
		pLoc->key = pLoc2->key;
		free(pLoc2);
	}
	return root;
}

void preorder(treeNode *root) // 전위순회
{
	if (root) {
		printf("%d ", root->key);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

void inorder(treeNode *root) // 중위순회
{
	if (root) {
		inorder(root->leftChild);
		printf("%d ", root->key);
		inorder(root->rightChild);
	}
}
void postorder(treeNode *root) // 후위순회
{
	if (root) {
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%d ", root->key);
	}
}

int main(void)
{
	treeNode *gRoot;
	int i, num;
	printf("pls write some digit to make BST :");
	for (i = 0; i < 5; i++) {
		scanf("%d", &num);
		// gRoot = insert_BST_r(gRoot, num);
		gRoot = insert_BST_r(gRoot, num);
	}
    
    printf("pls write one digit to delete :");
	scanf("%d", &num);
	delete_BST_r(gRoot, num);
	
	printf("preorder: ");
	preorder(gRoot);
	printf("\n");
	printf("inorder: ");
	inorder(gRoot);
	printf("\n");
	printf("postorder: ");
	postorder(gRoot);
	printf("\n");

	return 0;
}