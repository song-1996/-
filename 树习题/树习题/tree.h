#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode Node;

int GetNodeCount(Node* root);
int isSameTree(Node* p, Node* q);
Node* CreatBTree(int* arr, int size);
void DestroyBTree(Node** root);
//Node* _buildTree(int *pre, int preSize, int* ino, int left, int right, int* index);
//Node* buildTree1(int* preorder, int preorderSize, int* inorder, int inorderSize);
Node* _buildTree(int* ino, int inoSize, int* pos, int left, int right, int* index);
Node* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize);