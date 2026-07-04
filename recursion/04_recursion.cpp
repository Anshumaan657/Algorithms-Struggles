// Tree recursion
#include<iostream>
using namespace std;
void fun(int n)
{
    if (n>0){
        cout<<n<<endl;
        fun(n-1);// First of all, the function fun() is called with the argument n-1. This means that the function will be called again with a value that is one less than the current value of n.
        fun(n-1);
    }
}
int main(){
    int a = 3;
    fun(a);
    return 0;
}