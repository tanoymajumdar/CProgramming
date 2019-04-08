#include<stdio.h>
#include<stdlib.h>

struct treeNode
{
	int key;
	struct treeNode *left;
	struct treeNode *right;
};

typedef struct treeNode treeNode;

treeNode* Insert(treeNode *currentNode,int key)
{
	if(currentNode==NULL)
	{
		treeNode *temp;
		temp=(treeNode *)malloc(sizeof(treeNode));
		temp->key=key;
		temp->left=temp->right=NULL;
		return temp;
	}

	if(key>(currentNode->key))
	{
		currentNode->right=Insert(currentNode->right,key);
	}
	else if(key<(currentNode->key))
	{
		currentNode->left=Insert(currentNode->left,key);
	}
	return currentNode;
}


treeNode * Find(treeNode *currentNode, int key)
{
	if(currentNode==NULL)
	{
		return NULL;
	}

//printf("Access node %d \n",currentNode->key);
	if(key>currentNode->key)
	{
		return Find(currentNode->right,key);
	}

	else if(key<currentNode->key)
	{
		return Find(currentNode->left,key);
	}
	else
	{
		return currentNode;
	}
}

treeNode* FindMin(treeNode *currentNode)
{
	if(currentNode==NULL)
	{
		return NULL;
	}

	if(currentNode->left!=NULL)
	{
		return FindMin(currentNode->left);
	}
	else
	return currentNode;
}

treeNode* FindMax(treeNode *currentNode)
{
	if(currentNode==NULL)
	{
		return NULL;
	}

	if(currentNode->right!=NULL)
	{
		return FindMax(currentNode->right);
	}
	else
	{
		return currentNode;
	}
}


int main()
{
	treeNode *root=NULL;

	root=Insert(root,8);
	root=Insert(root,10);
	root=Insert(root,3);
	root=Insert(root,1);
	root=Insert(root,6);
	root=Insert(root,14);
	root=Insert(root,7);
	root=Insert(root,4);
	root=Insert(root,13);


	treeNode *temp;
	temp=Find(root,14);
	if(temp==NULL)
	{
		printf("Element14 not found\n");
	}

	else
	{
		printf("Element 14 found\n");
	}

	temp = FindMin(root);
	printf("Minimum element is %d\n",temp->key);
	
	temp = FindMax(root);
	printf("Maximum element is %d\n",temp->key);




}

