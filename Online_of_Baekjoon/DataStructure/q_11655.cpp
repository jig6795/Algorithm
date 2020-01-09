// Q11655
// ROT13
// 시간복잡도 - O(n)

#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);

    for(int i=0;i<str.length();i++)
    {
        if(str[i] == ' ')
        {
            cout << " ";
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            if((int)str[i] + 13 > 90)
            {
                cout << (char)(64 + (((int)str[i] + 13) - 90));
            }         
            else
            {
                cout << (char)((int)str[i] + 13);
            }
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            if((int)str[i] + 13 > 122)
            {
                cout << (char)(96 + (((int)str[i] + 13) - 122));
            }         
            else
            {
                cout << (char)((int)str[i] + 13);
            }
        }
        else
        {
            cout << str[i];
        }
    }

    return 0;
}