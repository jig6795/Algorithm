#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int c;

    string str;
    char ch;

    for(int i=0;i<n;i++)
    {
        cin >> c;
        cin >> str;

        for(int j=0;j<str.length();j++)
        {
            ch = str.at(j);

            for(int k=0;k<c;k++)
            {
                cout << ch;
            }
        }
        cout << endl;
    }

    return 0;
}