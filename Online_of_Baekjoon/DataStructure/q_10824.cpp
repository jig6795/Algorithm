// Q10824
// 네 수
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

    string a = "";
    string b = "";
    int cnt = 0;

    for(int i=0;i<str.length();i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(cnt < 2)
            {
                a += str[i];
            }
            else
            {
                b += str[i];
            }
        }
        else if(str[i] == ' ')
        {
            cnt += 1;
        }
        else
        {
            continue;
        }
    }

    cout << stoll(a) + stoll(b) << '\n';

    return 0;
}