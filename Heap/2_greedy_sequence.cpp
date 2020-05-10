//
// Created by User on 11.04.2020.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

typedef pair<int, int> valueAndindex;

bool comparator(valueAndindex first_element, valueAndindex second_element) {
    if (first_element.second == second_element.second)
        return first_element.first < second_element.first;
    return first_element.second < second_element.second;
}

//Реализация класса кучи
class Heap {
    vector<valueAndindex> h; //массив кучи
    long long int HeapSize = 0; // размер кучи
public:
    void push_heap(valueAndindex value);  // добавление элемента кучи c сортировкой
    long long int pop_heap();  // удаление вершины (максимального элемента)
    void heapify(long long int index);  // упорядочение кучи
    vector<valueAndindex> out();
};

void Heap::push_heap(valueAndindex value) {
    long long int i = HeapSize, parent;
    h.push_back(value);
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (h[i] < h[parent]) {
            swap(h[i], h[parent]);
        }
        i = parent;
        parent = (i - 1) / 2;
    }
    HeapSize++;
}

void Heap::heapify(long long int index) {
    long long int leftChild, rightChild;
    long long int largestChild;
    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largestChild = index;
        if (leftChild < HeapSize && h[leftChild] < h[largestChild]) {
            largestChild = leftChild;
        }
        if (rightChild < HeapSize && h[rightChild] < h[largestChild]) {
            largestChild = rightChild;
        }
        if (largestChild == index) {
            break;
        }
        swap(h[index], h[largestChild]);
        index = largestChild;
    }
}

//Удаление вершины кучи (максимального элемента)
long long int Heap::pop_heap() {
    long long int x = h[0].first;
    swap(h[0], h[HeapSize - 1]);
    HeapSize--;
    h.pop_back();
    heapify(0);
    return x;
}

vector<valueAndindex> Heap::out() {
    return h;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    long long int N, M;
    fin >> N >> M;
    Heap heap;
    for (long long int i = 0; i < N; i++) {
        long long int k;
        fin >> k;
        heap.push_heap(make_pair(k, i));
    }

    for (long long int i = 0; i < M; i++) {
        long long int head = heap.pop_heap();
        long long int head2 = heap.pop_heap();
        heap.push_heap(make_pair(head + head2, N));
    }

    vector<valueAndindex> heap_list = heap.out();
    sort(heap_list.begin(), heap_list.end(), comparator);
    for (auto &i : heap_list)
        fout << i.first << " ";
}
