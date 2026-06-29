//Tower of Hanoi problem using recursion
#include<iostream>
using namespace std;
void TOH(int n, int A, int B, int c)// A is source rod, B is destination rod, c is auxiliary rod, n is the number of disks
{
    if(n>0)
    {
        TOH(n-1, A, c, B);
        cout<<"Move disk "<<n<<" from rod "<<A<<" to rod "<<B<<endl;
        TOH(n-1, c, B, A);
    }
}
int main(){
    TOH(4, 1, 2, 3);// 3 is the number of disks, 1 is source rod, 2 is destination rod, 3 is auxiliary rod
    return 0;

}