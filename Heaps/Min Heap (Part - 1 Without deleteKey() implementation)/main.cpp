#include <iostream>

using namespace std;

int arr[1000], heap_size;

int parent(int i) {
 return (i-1)/2;
}

int left(int i) {
 return (2*i + 1);
}

int right(int i) {
 return (2*i + 2);
}

void swap_value(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}

int get_min() {
 return arr[0];
}

void min_heapify(int i) {
   int l = left(i);
   int r = right(i);
   int smallest = i;

   if((l < heap_size) && (arr[l] < arr[smallest])) {
    smallest = l;
   }

   if((r < heap_size) && (arr[r] < arr[smallest])) {
    smallest = r;
   }

   if(smallest != i) {
    swap_value(&arr[smallest], &arr[i]);
    min_heapify(smallest);
   }

}

void insert_key(int data) {
if (heap_size >= 1000) {
    cout<<"could not insert key"<<endl;
    return;
}

heap_size++;
int i = heap_size-1;
arr[i] = data;

while (i != 0 && arr[parent(i)] > arr[i]) {
    swap_value(&arr[i], &arr[parent(i)]);
    i = parent(i);
}
}

int extract_min() {
    if(heap_size <= 0) {
        return -1;
    }
    else if(heap_size == 1) {
        heap_size--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    min_heapify(0);
    return root;
}

void initialise_heap() {
 heap_size = 0;
}

int main()
{
    initialise_heap();
    insert_key(3);
    insert_key(2);
    insert_key(15);
    insert_key(5);
    insert_key(4);
    insert_key(45);
    cout << "Minimum value in heap extracted: " << extract_min() << " ";
    cout << "Minimum value in heap currently " << get_min() << " ";

    return 0;
}
