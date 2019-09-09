#include <iostream>
#include <cstdlib>

using namespace std;

int croatiaAlpha(string& s)
{
    int count = 0;

    for(int i=0;i<s.length();i++)
    {
        if(s[i] == 'c')
        {
            if(s[i+1] == '=' || s[i+1] == '-')
            {
                i++;
            }
        }
        else if(s[i] == 'd')
        {
            if(s[i+1] == 'z' && s[i+2] == '=')
            {
                i++;
                i++;
            }
            else if(s[i+1] == '-')
            {
                i++;
            }
        }
        else if(s[i] == 'l' && s[i+1] == 'j')
        {
            i++;
        }
        else if(s[i] == 'n' && s[i+1] == 'j')
        {
            i++;
        }
        else if(s[i] == 's' && s[i+1] == '=')
        {
            i++;
        }
        else if(s[i] == 'z' && s[i+1] == '=')
        {
            i++;
        }
        count++;
    }
    
    return count;
}

int main(void)
{
    string str;
    cin >> str;

    int result = 0;

    result = croatiaAlpha(str);

    cout << result << endl;

    return 0;
}