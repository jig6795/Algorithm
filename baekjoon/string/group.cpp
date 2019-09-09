#include <iostream>
#include <cstdlib>

using namespace std;

bool check(string& s)
{
    bool alpabet[26] = {false};

    for(int i=0;i<s.length();i++)
    {
        if(alpabet[s[i]-'a'])
        {
            return false;
        }
        else
        {
            char temp = s[i];
            alpabet[s[i]-'a'] = true;

            while(1)
            {
                if(temp != s[++i])
                {
                    i--;
                    break;
                }
            }
        }
    }

    return true;
}

int main(void)
{
    int total;
    cin >> total;

    int result = 0;

    for(int i=0;i<total;i++)
    {
        string str;
        cin >> str;
        
        if(check(str))
        {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}