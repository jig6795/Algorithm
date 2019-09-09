#include <iostream>

using namespace std;

int main(void)
{
    unsigned int a, b, c;
    cin >> a >> b >> c;
    
    int n = 1;

    if(b >= c)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (a/(c-b)) + 1 << endl;
    }

    return 0;
}