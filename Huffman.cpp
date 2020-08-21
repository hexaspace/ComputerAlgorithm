//hexaspace computer algorithm 10
//huffman code
//input : number [n] &\n& n lines [character & number] (length:4) &\n& total number [s]
//output : number of bits using [fixed-length code &\n&  huffman code]

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

#define MAX_TREE_HT 100 
int sum = 0;

struct MinHeapNode {
	int freq;
	struct MinHeapNode *left, *right;
};

struct MinHeap {
	int size;
	int capacity;
	struct MinHeapNode** array;
};

struct MinHeapNode* newNode(int freq)
{
	struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	temp->left = temp->right = NULL;
	temp->freq = freq;
	return temp;
}
struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}
void minHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

int isSizeOne(struct MinHeap* minHeap)
{
	return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap)
{
	int n = minHeap->size - 1;
	int i;
	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}

int isLeaf(struct MinHeapNode* root)
{
	return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(int freq[], int size)
{
	struct MinHeap* minHeap = createMinHeap(size);
	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(freq[i]);

	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}

struct MinHeapNode* buildHuffmanTree(int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;
	struct MinHeap* minHeap = createAndBuildMinHeap(freq, size);

	while (!isSizeOne(minHeap)) {
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		top = newNode(left->freq + right->freq);
		top->left = left;
		top->right = right;

		insertMinHeap(minHeap, top);
	}
	return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top, int leng)
{
	if (root->left) {
		printCodes(root->left, arr, top + 1, leng + 1);
	}
	if (root->right) {
		printCodes(root->right, arr, top + 1, leng + 1);
	}
	if (isLeaf(root)) {
		sum += leng*root->freq;
	}
}
void HuffmanCodes(int freq[], int size)
{
	struct MinHeapNode* root = buildHuffmanTree(freq, size);
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top, 0);
}

int main()
{
	int num = 0, i, total, fixed = 0;
	char arr[30000][5];
	int freq[30000];
	cout << "#huffman code\n\n";
	//입력
	cout << ">>number of character? : \n";
	cin >> num;
	cout << ">>character(4) & number : \n";
	for (i = 0; i < num; ++i) {
		cin >> arr[i];
		cin >> freq[i];
	}
	cout << ">>total number : \n";
	cin >> total;
	if (num == 1) { fixed = 1; }
	for (i = num - 1; i > 0; i /= 2) {
		fixed++;
	}
	//계산
	HuffmanCodes(freq, num);
	//출력
	cout << ">>result :\n\tfixed-length : ";
	cout << total*fixed;
	cout << "\n\thuffman : ";
	cout << sum << "\n";

	return 0;
}
