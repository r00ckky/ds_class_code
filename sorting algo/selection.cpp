#include<iostream>
#include<algorithm>
using namespace std;


void selection_sort(int a[], int n){
    for(int i = n-1; i>0; i--){
        int maxIdx = i;
        for(int j = 0; j<i; j++){
            if(a[j] >= a[maxIdx]){
                maxIdx = j;
            }
            swap(a[i], a[maxIdx]);
        }
    }
}

int main(){
    int a[] = {4,5,10,9,7,8};
    int n = sizeof(a)/sizeof(a[0]);
    selection_sort(a,n);
    cout<<"Sorted array: ";
    for(int i = 0; i<n ;i++){
        cout<<a[i]<<", ";
    }
    return 0;
}