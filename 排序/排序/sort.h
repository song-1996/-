#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>
void Print(int* arr, int sz);
void InsertSort(int *arr, int sz);
void ShellSort(int* arr, int sz);
void SelectSort(int* arr, int sz);
void SelectSortOp(int* arr, int sz);
void SelectSortOp1(int* arr, int sz);
void HeapSort(int* arr, int sz);
void BubbleSort(int* arr, int sz);
void QuickSort(int* arr,int left,int right);
void MergeSort(int* arr, int sz);
void PcountSort(int *arr, int sz);
void MergeSortNor(int* arr, int sz);