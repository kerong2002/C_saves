#include<iostream>
 
using namespace std;
 
int main()
{
    int a, b;
 
    while(1)
    {
    cin.clear();
 
        cin >> a >> b;
 
        if (!cin) continue;
 
        cout << a << " " << b << endl;
    }
}
