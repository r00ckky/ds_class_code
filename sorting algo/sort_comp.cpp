#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

void buble_sort(int array[], int size){
    // float x,y;
	clock_t time_req;
    time_req = clock();
    //loop to access each element in array
    for(int step = 0; step<size ; step++){
        // loop to compare elements
        for(int i = 0; i<size-step ; i++){
            //comparing the two elements
            if (array[i]>array[i+1])swap(array[i], array[i+1]);
        }
    }
    time_req = clock() - time_req;
    cout<<"Time for bubble sort = "<<(float)time_req/CLOCKS_PER_SEC<<"\n";
}

void insert_sort(int a[], int n){
    clock_t time_req;
    time_req = clock();
    for(int i = 0; i<n;i++){
        int next = a[i];
        int j = i-1;
        // The elements are shifted one by one till "next" is smaller
        while(j>= 0 && a[j]>next){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = next;
    }
    time_req = clock() - time_req;
    cout<<"Time for insert sort = "<<(float)time_req/CLOCKS_PER_SEC<<"\n";
}

void sort(int arr[], int n){
    clock_t time_req;
    time_req = clock();
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n ; j++){
            if(arr[j]>arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }
    time_req = clock() - time_req;
    cout<<"Time for normal sort = "<<(float)time_req/CLOCKS_PER_SEC<<"\n";
}

void selection_sort(int a[], int n){
    clock_t time_req;
    time_req = clock();
    for(int i = n-1; i>0; i--){
        int maxIdx = i;
        for(int j = 0; j<i; j++){
            if(a[j] >= a[maxIdx]){
                maxIdx = j;
            }
            swap(a[i], a[maxIdx]);
        }
    }
    time_req = clock() - time_req;
    cout<<"Time for selection sort = "<<(float)time_req/CLOCKS_PER_SEC<<"\n";
}

int main(){
    int s = 5000;
    int arr[s], arr2[s], arr3[s],arr4[s];
    srand(time(NULL));
    for(int i=0; i<s; i++)
    {
        int rnumber = rand()%500;
        arr[i]= rnumber;
    }
    for(int i = 0; i<s;i++){
        int rnumber = rand()%500;
        arr2[i]= rnumber;
    }
    for(int i = 0; i<s;i++){
        int rnumber = rand()%500;
        arr3[i]= rnumber;
    }
    for(int i = 0; i<s;i++){
        int rnumber = rand()%500;
        arr4[i]= rnumber;
    }
    buble_sort(arr, s);
    insert_sort(arr2, s);
    selection_sort(arr4, s);
    sort(arr3, s);
    return 0;
}