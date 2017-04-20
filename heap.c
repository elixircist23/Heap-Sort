#include<stdio.h>
#include<string.h>
#include<math.h>
 
int getParent(int);
int getLeft(int);
int getRight(int);
void swap(int[], int, int);
void heapify(int[], int, int);
void buildHeap(int[], int);
void heapSort(int[], int);
void printA(int[], int);
 
int main(){
     
    int a[20] = {1, 5, 7, 35, 23, 77, 44, 11, 5, 30, 20,  4, 3, 6, 1, 7, 8, 9, 0, 2};
    int arraySize = (sizeof(a)/sizeof(a[0]));
 
    heapSort(a, arraySize);
    printA(a, arraySize);
 
    return 0;
 
}
 
void heapSort(int A[], int n){
    buildHeap(A, n);
    while(n > 1){
        swap(A, 0, n-1);
        n--;
        heapify(A, 0, n);
    }
}
 
void buildHeap(int A[], int n){
    int len = floor(n/2);
    for(int i = len; i >= 0; i--){
        heapify(A, i, n);
    }
}
 
void heapify(int A[], int i, int n){
    int l = getLeft(i);
    int r = getRight(i);
    int largest = i;
 
    if(l < n && A[l] > A[largest]){
        largest = l;
    }
    if(r < n && A[r] > A[largest]){
        largest = r;
    }
    if(largest != i){
        swap(A, i, largest);
        heapify(A, largest, n);
    }
}
 
void swap(int A[], int i, int j){
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}
 
void printA(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%i ", A[i]);
    }
    printf("\n");
}
 
int getParent(int i){
    return (i-1)/2;
}
int getLeft(int i){
    return (2*i) + 1;
}
int getRight(int i){
    return (2*i) + 2;
}
