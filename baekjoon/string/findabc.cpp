#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
    string ch;
    cin >> ch;

    for(int i=0;i<26;i++)
    {
        if(ch.find((char)i+97)<100)
        {
            cout << ch.find((char)i+97) << " ";
            continue;
        }
        cout << -1 << " ";
    }

    return 0;
}