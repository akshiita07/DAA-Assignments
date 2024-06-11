/*
4. Huffman Coding
*/

#include <stdio.h> 
#include <stdlib.h> 

//maximum height of huffman tree
#define MAX_TREE_HT 100 

//defining node of huffman tree 
struct MinHeapNode{ 
	//characters of msg
    char data; 
    //frequncy/count of character in msg
    int freq; 
    //left n right child
    struct MinHeapNode *left,*right; 
}; 

//creating a collection of huffman tree nodes
struct MinHeap{ 
	//current size of min heap
    int size; 
    //capacity of min heap
    int capacity; 
    //array of min heap node pointers
    struct MinHeapNode** array; 
}; 

//creating node of character n its frequency
struct MinHeapNode* newNode(char data, int freq){ 
    struct MinHeapNode* temp=(struct MinHeapNode*)malloc(sizeof(struct MinHeapNode)); 
    temp->left=temp->right=NULL; 
    temp->data=data; 
    temp->freq=freq; 
    return temp; 
} 

//to create min heap of given capcity
struct MinHeap* createMinHeap(int capacity){ 
    struct MinHeap* minHeap=(struct MinHeap*)malloc(sizeof(struct MinHeap)); 
    //current size is 0
    minHeap->size=0; 
    minHeap->capacity=capacity; 
    minHeap->array=(struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*)); 
    return minHeap; 
} 

//fnc to swap 2 min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b){ 
    struct MinHeapNode* t=*a; 
    *a=*b; 
    *b=t; 
} 

//min heapify fn 
void minHeapify(struct MinHeap* minHeap, int idx){ 
    int smallest=idx, left=2 * idx + 1, right=2 * idx + 2; 
    if(left<minHeap->size && minHeap->array[left]->freq<minHeap->array[smallest]->freq)
        smallest=left; 
    if(right<minHeap->size && minHeap->array[right]->freq<minHeap->array[smallest]->freq)
        smallest=right; 
    if(smallest != idx){ 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 
        minHeapify(minHeap, smallest); 
    } 
} 

//to check if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap){ 
    return(minHeap->size==1); 
} 

//to extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap){ 
    struct MinHeapNode* temp=minHeap->array[0]; 
    minHeap->array[0]=minHeap->array[minHeap->size-1]; 
    --minHeap->size; 
    minHeapify(minHeap, 0); 
    return temp; 
} 

//to insert new node in min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode){ 
    ++minHeap->size; 
    int i=minHeap->size-1; 
    while(i && minHeapNode->freq<minHeap->array[(i-1)/ 2]->freq){ 
        minHeap->array[i]=minHeap->array[(i-1)/ 2]; 
        i=(i-1)/ 2; 
    } 
    minHeap->array[i]=minHeapNode; 
} 

//to build min heap
void buildMinHeap(struct MinHeap* minHeap){ 
    int n=minHeap->size-1; 
    for(int i=(n-1)/ 2; i >= 0; --i)
        minHeapify(minHeap, i); 
} 

//to print array of size n
void printArr(int arr[], int n){ 
    for(int i=0; i<n; ++i)printf("%d", arr[i]); 
    printf("\n"); 
} 

//to check if node is leaf node or not
int isLeaf(struct MinHeapNode* root){ 
    return !(root->left)&& !(root->right); 
} 

//To create a min heap of capacity=size and inserts all ip character in min heap
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){ 
    struct MinHeap* minHeap=createMinHeap(size); 
    for(int i=0; i<size; ++i)minHeap->array[i]=newNode(data[i], freq[i]); 
    minHeap->size=size; 
    buildMinHeap(minHeap); 
    return minHeap; 
} 

//builds huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){ 
    struct MinHeapNode *left, *right, *top; 
    struct MinHeap* minHeap=createAndBuildMinHeap(data, freq, size); 
    while(!isSizeOne(minHeap)){ 
        left=extractMin(minHeap); 
        right=extractMin(minHeap); 
        top=newNode('$', left->freq + right->freq); 
        top->left=left; 
        top->right=right; 
        insertMinHeap(minHeap, top); 
    } 
    return extractMin(minHeap); 
} 

//print codes from root to leaf
void printCodes(struct MinHeapNode* root, int arr[], int top){ 
    if(root->left){ 
        arr[top]=0; 
        printCodes(root->left, arr, top + 1); 
    } 
    if(root->right){ 
        arr[top]=1; 
        printCodes(root->right, arr, top + 1); 
    } 
    if(isLeaf(root)){ 
        printf("%c: ", root->data); 
        printArr(arr, top); 
    } 
} 

int main(){ 
    char arr[]={'a','b','c','d','e','f'}; 
    int freq[]={5,9,12,13,16,45}; 
    int size=sizeof(arr)/ sizeof(arr[0]); 
    struct MinHeapNode* root=buildHuffmanTree(arr,freq,size); 
    int arrCode[MAX_TREE_HT],top=0; 
    printCodes(root,arrCode,top); 
    
    return 0; 
}



