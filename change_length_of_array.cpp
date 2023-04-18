#include<iostream>
#include<algorithm>
using namespace std;

void changeLength1D(int a[], int oldLength, int newLength){
    if(newLength<0){
        throw "new length shall be greater than 0";
    }
    cout<<"The new array"<<endl;
    int temp[newLength];
    int number = min(oldLength, newLength);
    copy(a, a+number, temp);
    a = temp;
}

int main(){
    int a[5]={1,2,35,4,5};
    changeLength1D(a, 5, 10);
    for(int i = 0; i<10;i++)cout<<a[i]<<"\n";
    return 0;
}