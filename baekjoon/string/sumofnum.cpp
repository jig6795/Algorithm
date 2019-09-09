#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{  
    int n;
    cin >> n;

    int sum=0;

    char ch;

    for(int i=0;i<n;i++)
    {
        cin >> ch;

        sum = sum + (ch - 48);
    }

    cout << sum << endl;

    return 0;
}