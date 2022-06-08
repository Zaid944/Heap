#include <bits/stdc++.h>
using namespace std;
class Heap
{
private:
    vector<int> arr;
    bool isMaxHeap;
    bool compareTo(int i, int j){
        // first argument ke respect mei soch
        if(isMaxHeap){
            return arr[i] > arr[j];
        }
        else{
            return arr[i] < arr[j];
        }
    }
    void constructHeap() // O(nlogn)---> seems to be but it is O(n)
    {
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            downHeapify(i);
        }
    }
    void downHeapify(int par) // O(logn)
    {
        int maxidx = par;
        int lc = 2 * par + 1;
        int rc = 2 * par + 2;
        if (lc < arr.size() and compareTo(lc, maxidx))
        {
            maxidx = lc;
        }
        if (rc < arr.size() and compareTo(rc, maxidx))
        {
            maxidx = rc;
        }

        if(par != maxidx){
            swap(arr[par], arr[maxidx]);
            downHeapify(maxidx);
        }
    }
    void upHeapify(int c){
        int par = (c - 1) / 2;
        if (par >= 0 and compareTo(c, par))
        {
            swap(arr[c], arr[par]);
            upHeapify(par);
        }
    }
public:
    Heap()
    {
        this->isMaxHeap = true;
    }
    Heap(bool isMaxHeap)
    {
        this->isMaxHeap = isMaxHeap;
    }
    Heap(bool isMaxHeap, vector<int> arr)
    {
        this->isMaxHeap = isMaxHeap;
        this->arr = arr;
        constructHeap();
    }
    int getSize()
    {
        return arr.size();
    }
    bool isEmpty()
    {
        return arr.size() == 0;
    }
    void add(int data) // O(nlogn)
    {
        arr.push_back(data);
        upHeapify(arr.size() - 1);
    }
    int pop() // O(logn)
    {
        int remove = arr[0];
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        downHeapify(0);
        return remove;
    }
    int top() // O(1)
    {
        return arr[0];
    }
};

int main(){
    vector<int>arr = {-1,2,3,100,73,283,29,4,5,920};
    Heap h(false, arr);
    while(!h.isEmpty()){
        int x = h.top();
        cout << x << endl;
        h.pop();
    }
}