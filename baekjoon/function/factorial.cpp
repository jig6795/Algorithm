#include <iostream>

using namespace std;

void factorial(int n)
{
    int fac = 1;

    for(int i=1;i<=n;i++)
    {
        fac *= i;
    }

    cout << fac << endl;
}

int main()
{
    int n;
    cin >> n;
    
    factorial(n);

    return 0;
}