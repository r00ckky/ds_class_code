#include <bits/stdc++.h>
using namespace std;


void print(int arr[], int n){
   for (int i = 0; i < n; i++){
       /* code */
       cout << arr[i] << " ";
   }
   cout << endl;
}


int partition(int arr[], int low, int high){
   int pivot = arr[high];
   int i = (low - 1);
   for (int j = low; j <= high - 1; j++){
       if (arr[j] < pivot){
           i++;
           swap(arr[i],arr[j]);
       }
   }
   swap(arr[i + 1], arr[high]);
   return (i + 1);
}
void quickSort(int arr[], int low, int high){
   if (low < high){
       int pi = partition(arr, low, high);
       quickSort(arr, low, pi - 1);
       quickSort(arr, pi + 1, high);
   }
}


int main(){
   cout << "Enter the length of array: \n";
   int n;
   cin >> n;
   int arr[n];
   cout << "Enter the values of array: \n";
   for (int i = 0; i < n; i++){
       /* code */
       cin >> arr[i];
   }
   cout << "array before sorting\n";
   print(arr, n);
   quickSort(arr, 0, n-1);
   cout << "array after sorting\n";
   print(arr, n);
}
