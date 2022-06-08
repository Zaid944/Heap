#include<bits/stdc++.h>
using namespace std;
bool compareTo(int i, int j, bool isMaxHeap, vector<int>&arr)
{
    // first argument ke respect mei soch
    if (isMaxHeap)
    {
        return arr[i] > arr[j];
    }
    else
    {
        return arr[i] < arr[j];
    }
}
void downHeapify(vector<int>&arr, bool inc, int par, int li) // O(logn)
{
    int maxidx = par;
    int lc = 2 * par + 1;
    int rc = 2 * par + 2;
    if (lc <= li and compareTo(lc, maxidx, inc, arr))
    {
        maxidx = lc;
    }
    if (rc <= li and compareTo(rc, maxidx, inc, arr))
    {
        maxidx = rc;
    }

    if (par != maxidx)
    {
        swap(arr[par], arr[maxidx]);
        downHeapify(arr, inc, maxidx, li);
    }
}

void heapSort(vector<int>&arr, bool inc){
    for(int i = arr.size() - 1; i >= 0; i--){
        downHeapify(arr, inc, i, arr.size() - 1);
    }
    int li = arr.size() - 1;
    while(li >= 0){
        // cout<<arr[0] << endl;
        swap(arr[0], arr[li]);
        li--;
        downHeapify(arr, inc, 0, li);
    }
}

int main(){
    vector<int>arr = {1,2,3,-1,9,91,5,-100,393, -10, 39,9392};
    heapSort(arr, true); // time (O(N + NlogN)) space : O(logN)
    for(int e : arr)cout << e << " ";
    cout << endl;
}