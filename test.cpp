#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> heap;

void sift_up(int index){
    if(index==0)
        return;
    int par_ind = (index-1)/2;
    if(heap[par_ind],heap[index]){
        swap(heap[par_ind],heap[index]);
        sift_up(par_ind);
    }
}

void sift_down(int index){
    int ind_left = 2 * index + 1;
    int ind_right = 2 * index + 2;
    int new_ind = 0;
    if(heap[ind_left]>heap[ind_right])
        new_ind=ind_left;
    else
        new_ind=ind_right;
    if(heap[new_ind]>heap[ind_right])
        new_ind=ind_left;
    else
        new_ind=ind_right;
}

void add_new(int value){
    heap.push_back(value);
    sift_up(heap.size()-1);
}



int max(){
    int MAX = heap[0];
}
int main() {

}