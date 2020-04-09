//
// Created by User on 08.04.2020.
//
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

//Реализация класса кучи
class Heap {
    long long *h;         // указатель на массив кучи
    long long int HeapSize; // размер кучи
public:
    explicit Heap(unsigned int SizeHeap);  // конструктор кучи,
    void push_heap(long long int);  // добавление элемента кучи c сортировкой

    long long pop_heap();  // удаление вершины (максимального элемента)
    void heapify(long long int);  // упорядочение кучи
    long long element_heap(long long int element); // доступ к элементам кучи(изменять нельзя)
    void printOut();  // вывод элементов кучи в форме массива
};

//Конструктор кучи
Heap::Heap(unsigned int SizeHeap) {
    h = new long long int[SizeHeap];
    HeapSize = 0;
}

void Heap::push_heap(long long int n) {
    long long int i, parent;
    i = HeapSize;
    h[i] = n;
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (h[i] > h[parent]) {
            long long int temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i - 1) / 2;
    }
    HeapSize++;
}

void Heap::heapify(long long int i) {
    long long int leftChild, rightChild;
    long long int largestChild;
    while (true) {
        leftChild = 2 * i + 1;
        rightChild = 2 * i + 2;
        largestChild = i;
        if (leftChild < HeapSize && h[leftChild] > h[largestChild]) {
            largestChild = leftChild;
        }
        if (rightChild < HeapSize && h[rightChild] > h[largestChild]) {
            largestChild = rightChild;
        }
        if (largestChild == i) {
            break;
        }
        long long int temp = h[i];
        h[i] = h[largestChild];
        h[largestChild] = temp;
        i = largestChild;
    }
}
//Удаление вершины кучи (максимального элемента)
long long Heap::pop_heap() {
    long long int x;
    x = h[0];
    h[0] = h[HeapSize - 1];
    HeapSize--;
    heapify(0);
    return (x);
};

long long Heap::element_heap(long long int element) {
    return element > HeapSize ? -1 : h[element];
}

//Вывод элементов кучи в форме массива
void Heap::printOut() {
    for (int i = 0; i < HeapSize; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    long long int N, M;
    fin >> N >> M;
    Heap heap(N + 1);
    for (long long int i = 0; i < N; i++) {
        long long int k;
        fin >> k;
        heap.push_heap(k);
    }

    while (M != 0) {
        long long int head = heap.pop_heap();
        head /= 10;
        heap.push_heap(head);
        M--;
    }

    long long int num = 0;
    for (long long int i = 0; i < N; i++) {
        num += heap.element_heap(i);
    }
    fout.open("output.txt");
    fout << num;
    fout.close();
}