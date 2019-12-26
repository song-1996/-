#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<memory.h>
typedef int BTDataType;
typedef struct BTNode
{
	struct BTNode* _Left;
	struct BTNode* _Right;
	BTDataType data;
}BTNode;

BTNode* CreatBTree(BTDataType* arr, int size);
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
void PreOrderNor(BTNode* root);
void InOrderNor(BTNode* root);
void PostOrderNor(BTNode* root);
void LevelOrder(BTNode* root);
BTDataType FindRoot(BTNode* root);
int FindNode(BTNode* root,BTDataType data);
int GetNodeCount(BTNode* root);
int GetLeafCount(BTNode* root);
BTNode* CopyBinTree(BTNode* root);
int GetKlevelNodeCount(BTNode* root, int k);
BTNode* GetNodeParent(BTNode* root, BTNode* Node);
BTNode* GetNode(BTNode* root, BTDataType data);
int Height(BTNode* root);
char* tree2str(BTNode* t);
int isBalanced(BTNode* root);
void DestroyBTree(BTNode** root);
BTNode*  reConstructBinaryTree(int* pre, int* vin,int sz);