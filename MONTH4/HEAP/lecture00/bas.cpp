#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Heap is a complete binary tree (sare level completely filled except last level and insertion always from left side such that it satisfy heapify property

// HEAPIFY PROPOERTY-> max heap and min heap
// max heap-> sab child humesha parent se chote honge
// min heap-> sab child humesha parent se bade honge

// left child 2*i+1  index(0 based indexing)
// left child 2*i  index(1 based indexing)
// right child 2*i+1  index(1 based indexing)
// right child 2*i+2 index(0 based indexing)

// parent = i/2th index

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val)
    {
        // TC-> O(logn)

        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            // Condition for max heap and  for min heap same code but in  else part
            if (arr[parent] < arr[index])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletion()
    {
        // TC-> O(logn)
        if (size == 0)
        {
            cout << "Empty Heap" << endl;
            return;
        }

        // step1: Put last element into first index
        arr[1] = arr[size];

        // step 2:remove last element
        size--;

        // take root node to correct position
        int i = 1;
        while (i < size)
        {
            // 1 based indexing
            int leftIdx = 2 * i;
            int rightIdx = 2 * i + 1;

            if (leftIdx <= size && arr[i] < arr[leftIdx])
            {
                swap(arr[i], arr[leftIdx]);
                i = leftIdx;
            }

            else if (rightIdx <= size && arr[i] < arr[rightIdx])
            {
                swap(arr[i], arr[rightIdx]);
                i = rightIdx;
            }

            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void maxHeapify(int arr[], int n, int i)
{
    // FOR COMPLETE BINARY TREE (n/2+1) se (n) tak leaf node exist krte hai to inko process krne ki jarrurat nhi hai for 1 based indexing
    // FOR COMPLETE BINARY TREE (n/2) se (n) tak leaf node exist krte hai to inko process krne ki jarrurat nhi hai for 0 based indexing

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        // aab age ka bhi check krlo
        maxHeapify(arr, n, largest);
    }
}
void minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[smallest] > arr[left])
    {
        smallest = left;
    }

    if (right <= n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        // aab age ka bhi check krlo
        minHeapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n)
{

    // step 1: swap arr[1] to arr[last]
    // step 2: size kam kro
    // step 3: heapify Call kro

    int size = n;
    while (size > 1)
    {
        // step 1: swap
        swap(arr[size], arr[1]);

        // step 2:
        size--;

        // step 3:heapifyCall
        maxHeapify(arr, size, 1);
    }
}

void print(int arr[], int size)
{
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    heap h;
    h.insert(10);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);

    // h.print();

    h.deletion();
    h.deletion();

    // h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        maxHeapify(arr, n + 1, i);
    }

    cout << "Print the heapified array" << endl;
    print(arr, n);

    heapSort(arr, n);
    print(arr, n);

    // STL FOR MINHEAP AND MAX HEAP INCLUDE  QUEUE HEADER FILE

    // Max Heap: by default maxHeap banega
    priority_queue<int> maxheap;
    maxheap.push(4);
    maxheap.push(2);
    maxheap.push(5);
    maxheap.push(3);

    cout << "Element at top: " << maxheap.top() << endl;
    maxheap.pop();
    cout << "Element at top: " << maxheap.top() << endl;
    cout << "Size is " << maxheap.size();

    // // MinHeap using priority Queue
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "Element at top: " << minheap.top() << endl;
    minheap.pop();
    cout << "Element at top: " << minheap.top() << endl;
    cout << "Size is " << minheap.size();

    return 0;
}