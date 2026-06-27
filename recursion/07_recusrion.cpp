//Sum of all the natural numbers using recursion
#include<iostream>
using namespace std;
int sum(int n){
    if(n==0){
        return 0;
    }
    else {
       return sum(n-1)+n;
    }
}
int main(){
    int n =10;
    cout<<"Sum of all the natural numbers from 1 to "<<n<<" is:"<<sum(n)<<"  ";
    return 0;
}