#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;


void buble_sort(int array[], int size){
	clock_t time_req;
    time_req = clock();
    for(int step = 0; step<size ; step++){
        for(int i = 0; i<size-step ; i++){
            if (array[i]>array[i+1])swap(array[i], array[i+1]);
        }
    }
    time_req = clock() - time_req;
    cout<<"Time for bubble sort = "<<(float)time_req/CLOCKS_PER_SEC<<"\n";
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

int main(){
    int s = 10000;
    int arr[s], arr2[s];
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

    buble_sort(arr, s);
    cout<<"Normal sort\n";
    sort(arr2, s);

    return 0;
}