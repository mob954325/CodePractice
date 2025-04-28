#include <iostream>

using namespace std;

// 선형 검색 함수
int linearSearch(int arr[], int n, int key) 
{    
    for (int i = 0; i < n; i++) 
    {       
        if (arr[i] == key) 
        {            
            return i; // 요소를 찾은 경우 인덱스 반환        
        }    
    }    
    return -1; // 요소를 찾지 못한 경우 -1 반환
}

struct TreeNode {
    int Data;    
    TreeNode* left;    
    TreeNode* right;
    TreeNode(int data) 
        : Data(data), left(nullptr), right(nullptr) {}
};

TreeNode* insertNode(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data); 
    }
    if (data < root->Data) { 
        root->left = insertNode(root->left, data);
    }
    else if (data > root->Data) 
    { 
        root->right = insertNode(root->right, data); 
    }
    return root;
}

void inorder(TreeNode* root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std::cout << root->Data << ' ';
        inorder(root->right);
    }
}

void preorder(TreeNode* root)
{
    if (root != nullptr)
    {
        std::cout << root->Data << ' ';
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode* root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->Data << ' ';
    }
}

// HeapTree

#define MAX_SIZE 100

struct MaxHeap {
    int data[MAX_SIZE];
    int size;
};

void initHeap(struct MaxHeap* heap)
{
    heap->size = 0;
}

void insertHeap(struct MaxHeap* heap, int value)
{
    int index;
    if (heap->size >= (MAX_SIZE - 1))
    {
        std::cout << "힙이 가득찼습니다." << std::endl;
    }
    else 
    {
        heap->size++;
        index = heap->size;
        heap->data[index] = value;

        while ((index != 1) && (heap->data[index] > heap->data[index / 2]))
        {
            // 부모 자리바꾸기
            int temp = heap->data[index / 2];
            heap->data[index / 2] = heap->data[index];
            heap->data[index] = temp;

            index = index / 2;
        }
    }
}

int DeleteHeap(struct MaxHeap* heap)
{
    int cur, child;
    int deleteData = heap->data[1];
    
    if (heap->size == 0)
    {
        std::cout << "힙이 없습니다." << std::endl;
        return 0;
    }
    else
    {
        heap->data[1] = heap->data[heap->size];
        heap->size--;

        cur = 1;
        //부모 자식간 노드비교 후 위치 교환
        while ((cur * 2) <= heap->size)
        {
            child = cur * 2;

            if (((child + 1) <= heap->size) && (heap->data[child] < (heap->data[child + 1])))
            {
                child++;
            }


            if (heap->data[child] <= heap->data[cur])
                break;
            
            int temp = heap->data[child];
            heap->data[child] = heap->data[cur];
            heap->data[cur] = temp;

            cur = child;
        }
    }

    return deleteData;
}

void HeapPrint(struct MaxHeap* heap)
{
    std::cout << "힙 ";
    for (int i = 1; i <= heap->size; i++)
    {
        std::cout << heap->data[i]<<" ";
    }
    std::cout << std::endl;
}



int main() {
    int arr[] = { 12, 45, 23, 6, 78, 11, 3, 56, 67, 9 };    

    int n = sizeof(arr) / sizeof(arr[0]);   
    int key = 56;

    int result = linearSearch(arr, n, key);

    if (result != -1) { 
        std::cout << "요소 " << key << "은 배열의 인덱스 " << result << "에 있습니다. " << std::endl; 
    }
    else 
    { 
        std::cout << "요소를 찾지 못했습니다." << std::endl; 
    }

    TreeNode* root = nullptr;    

    root = insertNode(root, 23); // 트리 생성

    for (int i = 0; i < n; i++) 
    { 
        insertNode(root, arr[i]); 
    }

    std::cout << root->Data << '\n';

    std::cout << "중위" << " ";
    inorder(root);
    std::cout << "\n";

    std::cout << "전위" << " ";
    preorder(root);
    std::cout << "\n";

    std::cout << "하위" << " ";
    postorder(root);
    std::cout << "\n";

    struct MaxHeap maxHeap;
    initHeap(&maxHeap);
    std::cout << "\n";

    for (int i = 0; i < n; i++)
    {
        insertHeap(&maxHeap, arr[i]);
    }

    HeapPrint(&maxHeap);
    std::cout << "\n";

    int heapsize = maxHeap.size;
    for (int i = 0; i < heapsize; i++)
    {
        std::cout << "Heap 삭제 - " << DeleteHeap(&maxHeap) << std::endl;
    }

    return 0;
}