//Recursion without the static variable
//A static variable is a variable that is initialized only once and retains its value throughout the program's execution, even after the function in which it is declared has finished executing.
#include<iostream>
using namespace std;

    int fun1(int n){
        static int x=0;
        if(n > 0)
        {
            x++;
            return fun1(n-1)+x;
            
        }
        return 0;
    }
    int main(){
        int num = 5;
        cout<<fun1(num);
        return 0;
    }

