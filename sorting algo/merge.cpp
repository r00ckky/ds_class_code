#include<iostream>
#include<vector>
using namespace std;


void merge_sort(int a[], int start, int end){
    vector<int> left_arr, right_arr;
    int mid = (start+end)/2;

    for(int i = 0;i<mid;i++)left_arr.push_back(a[i]);
    for(int i = mid+1;i<end;i++)right_arr.push_back(a[i]);
    int left_size = left_arr.size(), right_size = right_arr.size(), i = 0, j = 0, k = start;

    while(i<left_size && j<right_size){
        if(left_arr[i]<right_arr[j]){
            a[k] = left_arr[i];
            i++;
        }
        else{
            a[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while(i<left_size){
        a[k] = left_arr[i];
        i++;
        k++;
    }
    while(j<right_size){
        a[k]=right_arr[j];
        j++;
        k++;
    }

}

void merge(int a[], int start, int end){
    int mid = (start+end)/2;
    if(mid<end){
        merge(a, mid, end);
        merge(a, start, mid-1);
        merge_sort(a, start, end);
    }
}


int main(){
    int a[] = {9,11,6,9,10,4};
    merge(a, 0, 6);
    for(int i = 0;i < 6;i++){
        cout<<a[i]<<", ";
    }
    return 0;
}