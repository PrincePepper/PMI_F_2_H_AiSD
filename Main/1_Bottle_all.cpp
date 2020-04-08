//
// Created by User on 08.04.2020.
//
#include <iostream>
#include <fstream>

using namespace std;

//Реализация класса кучи
class Heap {
    int *h;        // указатель на массив кучи
    int HeapSize; // размер кучи
public:
    explicit Heap(unsigned int SizeHeap);  // конструктор кучи,
    void addElement(int);  // добавление элемента кучи
    void out();  // вывод элементов кучи в форме массива
    int getMax();  // удаление вершины (максимального элемента)
    void heapify(int);  // упорядочение кучи
    int element_heap(unsigned int element); // доступ к элементам кучи
};

//Конструктор кучи
Heap::Heap(unsigned int SizeHeap) {
    h = new int[SizeHeap];
    HeapSize = 0;
}

void Heap::addElement(int n) {
    int i, parent;
    i = HeapSize;
    h[i] = n;
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (h[i] > h[parent]) {
            int temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i - 1) / 2;
    }
    HeapSize++;
}

//Вывод элементов кучи в форме массива
void Heap::out() {
    for (int i = 0; i < HeapSize; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
}

//Упорядочение кучи
void Heap::heapify(int i) {
    int left, right;
    int temp;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < HeapSize) {
        if (h[i] < h[left]) {
            temp = h[i];
            h[i] = h[left];
            h[left] = temp;
            heapify(left);
        }
    }
    if (right < HeapSize) {
        if (h[i] < h[right]) {
            temp = h[i];
            h[i] = h[right];
            h[right] = temp;
            heapify(right);
        }
    }
}

//Удаление вершины кучи (максимального элемента)
int Heap::getMax() {
    int x;
    x = h[0];
    h[0] = h[HeapSize - 1];
    HeapSize--;
    heapify(0);
    return (x);
}

int Heap::element_heap(unsigned int element) {
    return element > HeapSize ? -1 : h[element];
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    int N, M;
    fin >> N >> M;
    Heap heap(N + 1);
    for (int i = 0; i < N; i++) {
        int k;
        fin >> k;
        heap.addElement(k);
    }
    while (M != 0) {
        int head = heap.getMax();
        head /= 10;
        heap.addElement(head);
        M--;
    }
    int num = 0;
    for (int i = 0; i < N; i++) {
        num += heap.element_heap(i);
    }
    fout.open("output.txt");
    fout << num;
    fout.close();
}