//
// Created by User on 15.04.2020.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class LEFT_MAX {
    long long *h;         // указатель на массив кучи
    long long int HeapSize; // размер кучи
public:
    explicit LEFT_MAX(long long int SizeHeap);  // конструктор кучи,
    void push_heap(long long int value);  // добавление элемента кучи c сортировкой
    long long int pop_heap();  // удаление вершины (максимального элемента)
    void heapify(long long int index);  // упорядочение кучи
    long long int element_heap(long long int element); // доступ к элементам кучи(изменять нельзя)
    void printOut();// вывод элементов кучи в форме массива
    long long int size();
};

//Конструктор кучи
LEFT_MAX::LEFT_MAX(long long int SizeHeap) {
    h = new long long int[SizeHeap];
    HeapSize = 0;
}

long long int LEFT_MAX::size() {
    return HeapSize;
}

void LEFT_MAX::push_heap(long long int value) {
    long long int i = HeapSize, parent, temp;
    h[i] = value;
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (h[i] > h[parent]) {
            temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i - 1) / 2;
    }
    HeapSize++;
}

void LEFT_MAX::heapify(long long int index) {
    long long int leftChild, rightChild, temp;
    long long int largestChild;
    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largestChild = index;
        if (leftChild < HeapSize && h[leftChild] > h[largestChild]) {
            largestChild = leftChild;
        }
        if (rightChild < HeapSize && h[rightChild] > h[largestChild]) {
            largestChild = rightChild;
        }
        if (largestChild == index) {
            break;
        }
        temp = h[index];
        h[index] = h[largestChild];
        h[largestChild] = temp;
        index = largestChild;
    }
}

//Удаление вершины кучи (максимального элемента)
long long int LEFT_MAX::pop_heap() {
    long long int x;
    x = h[0];
    h[0] = h[HeapSize - 1];
    HeapSize--;
    heapify(0);
    return (x);
};

long long int LEFT_MAX::element_heap(long long int element) {
    return h[element];
}

//Вывод элементов кучи в форме массива
void LEFT_MAX::printOut() {
    for (int i = 0; i < HeapSize; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
}

class RIGHT_MIN {
    long long *h;         // указатель на массив кучи
    long long int HeapSize; // размер кучи
public:
    explicit RIGHT_MIN(long long int SizeHeap);  // конструктор кучи,
    void push_heap(long long int value);  // добавление элемента кучи c сортировкой
    long long int pop_heap();  // удаление вершины (максимального элемента)
    void heapify(long long int index);  // упорядочение кучи
    long long int element_heap(long long int element); // доступ к элементам кучи(изменять нельзя)
    void printOut();  // вывод элементов кучи в форме массива
    long long int size();
};

//Конструктор кучи
RIGHT_MIN::RIGHT_MIN(long long int SizeHeap) {
    h = new long long int[SizeHeap];
    HeapSize = 0;
}

long long int RIGHT_MIN::size() {
    return HeapSize;
}

void RIGHT_MIN::push_heap(long long int value) {
    long long int i = HeapSize, parent, temp;
    h[i] = value;
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (h[i] < h[parent]) {
            temp = h[i];
            h[i] = h[parent];
            h[parent] = temp;
        }
        i = parent;
        parent = (i - 1) / 2;
    }
    HeapSize++;
}

void RIGHT_MIN::heapify(long long int index) {
    long long int leftChild, rightChild, temp;
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
        temp = h[index];
        h[index] = h[largestChild];
        h[largestChild] = temp;
        index = largestChild;
    }
}

//Удаление вершины кучи (максимального элемента)
long long int RIGHT_MIN::pop_heap() {
    long long int x;
    x = h[0];
    h[0] = h[HeapSize - 1];
    HeapSize--;
    heapify(0);
    return (x);
};

long long int RIGHT_MIN::element_heap(long long int element) {
    return h[element];
}

//Вывод элементов кучи в форме массива
void RIGHT_MIN::printOut() {
    for (int i = 0; i < HeapSize; i++) {
        cout << h[i] << " ";
    }
    cout << endl;
}

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    long long int N, element;
    fin >> N;

    LEFT_MAX leftMax(N);
    RIGHT_MIN rightMin(N);
    long long int mass_res[N];


    for (int i = 0; i < N; i++) {
        fin >> element;
        if (element <= leftMax.element_heap(0)) {
            leftMax.push_heap(element);
        } else
            rightMin.push_heap(element);

        if (leftMax.size() < rightMin.size()) {
            leftMax.push_heap(rightMin.pop_heap());
        } else
            rightMin.push_heap(leftMax.pop_heap());

        mass_res[i] = leftMax.element_heap(0);
        leftMax.printOut();
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        fout << mass_res[i] << " ";
    }

}