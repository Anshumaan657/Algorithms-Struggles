//Recursion witout the static variable
#include<iostream>
using namespace std;

    int fun1(int n){
        if(n > 0){
            return fun1(n-1)+n;
            
        }
        return 0;
    }
    int main(){
        int num = 10;
        cout<<fun1(num);
        return 0;
    }

