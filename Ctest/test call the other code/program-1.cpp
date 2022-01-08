#include <iostream>
#include<time.h>
 
using namespace std;
 
int main()
{
    int a=34, b=40;
 
    while(1)
    {
        usleep(300000);   
        cout << a << " " << b << endl;
    }
}
