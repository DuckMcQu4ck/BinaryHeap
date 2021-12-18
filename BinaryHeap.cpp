// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;


struct Heap
{
    int* harr; 
    int capacity;
    int heap_size; 

    Heap(int aCapacity);

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    int pop();
    void Sort(int);
    void decreaseKey(int i, int new_val);
    int peek() { return harr[0]; }
    void deleteKey(int i);
    void push(int k);
    void swap(int* x, int* y);
    void print();
    void build();
};

Heap::Heap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void Heap::push(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void Heap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int Heap::pop()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }


    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    Sort(0);

    return root;
}

void Heap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    pop();
}

void Heap::Sort(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        Sort(smallest);
    }
}

void Heap::swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Heap::print() {
    for (int i = 0; i < heap_size; i++) {
        cout << harr[i] << " ";
    }
}


int main()
{
    Heap heap(11);
    heap.push(3);
    heap.push(2);
    heap.deleteKey(1);
    heap.push(15);
    heap.push(5);
    heap.push(4);
    heap.push(45);


    heap.print();
    cout << endl;

    heap.push(0);
    heap.print();
    cout << endl;

    heap.push(100);
    heap.print();
    cout << endl;

    heap.Sort(0);
    heap.print();

    return 0;
}