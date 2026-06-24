#include<iostream>
using namespace std;
void DisplayRec(int num){
    if(num>0){
        cout<<num<<endl;
        DisplayRec(num-1);
    }
}
int main(){
    int num =10;
    DisplayRec(10);
    
    return 0;
}