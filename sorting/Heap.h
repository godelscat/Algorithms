//NEVER SEPERATE the definition of templates from declaration
#ifndef HEAP_H
#define HEAP_H
#include <iostream>

void MAX_HEAPIFY (int arr[], int i, int len);
void BUILD_MAX_HEAP (int arr[], int len);
void HEAP_SORT (int arr[], int len);
int HEAP_MAX ( int arr[], int len);
void HEAP_INCRESE_KEY (int arr[], int i, int key);
int HEAP_EXTRACT_MAX (int arr[], int len);

#endif

