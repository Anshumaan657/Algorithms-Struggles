#include<iostream>
using namespace std;
int main(){
    // Array Declaration and Initialization
    int A[10];
    cout<<"A = "; // This will give me the garbage values
    for (int i =0; i<10; i++){
        cout<<A[i]<<" ";
    }

    //2
    int B[5] = {2,4,6,8,10};
    cout<<"\nB = ";
    for (int i =0; i<5; i++){
        cout<<B[i]<<" ";
    }
    
    //3
    float C[10] = {2,4,6};
    cout<<"\nC = ";
    for (int i =0; i<10; i++){
        cout<<C[i]<<" ";
    }

    //4
    int D[] = {2,4,6,8,10};
    cout<<"\nD = ";
    for (int i =0; i<5; i++){
        cout<<D[i]<<" ";
    }

    return 0;
}