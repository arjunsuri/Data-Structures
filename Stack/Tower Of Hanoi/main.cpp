#include <iostream>

using namespace std;

void toh(int a, int b, int c, int n) {

if(n<=0)
    return;

toh(a, c, b, n-1);
cout<<"From "<<a<<" To "<<c<<endl;
toh(b, a, c, n-1);
}



int main()
{
    cout<<"Steps taken for transferring disk from source to destination:-"<<endl;
    toh(1, 2, 3, 3);

    return 0;
}
