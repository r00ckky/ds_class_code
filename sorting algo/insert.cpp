#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;



void insert_sort(int a[], int n){
    clock_t time_req;
    time_req = clock();
    for(int i = 0; i<n;i++){
        int next = a[i];
        int j = i-1;
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

    insert_sort(arr, s);
    // for(int i = 0; i<7;i++){
    //     cout<<arr[i]<<'\n';
    // }

    cout<<"Normal sort\n";
    sort(arr2, s);
    // for(int i = 0; i<7;i++){
    //     cout<<arr2[i]<<'\n';
    // }

    return 0;
}