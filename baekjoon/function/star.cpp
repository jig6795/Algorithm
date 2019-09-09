#include <iostream>

using namespace std;

void star(int n)
{
    for(int i=0;i<n;i++)
    {
        cout << '*';       
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    star(n);

    return 0;
}