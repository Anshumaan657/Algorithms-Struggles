// Selection formula or Combination formula using recursion
#include<iostream>
using namespace std;
int Combination(int n, int r){
if(r==0 || n==r)
{
    return 1;
}
else{
    return Combination(n-1, r-1)+Combination(n-1, r);
}
}

int main(){
    int n;
    int r;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of r: ";
    cin>>r;
    cout<<"Combination of "<<n<<" and "<<r<<" is: "<<Combination(n,r)<<" ";
    return 0;

}