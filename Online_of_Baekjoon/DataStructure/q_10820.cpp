// Q10820
// 문자열 분석
// 시간복잡도 - O(n^2)
// -> 문장이 100문장이고 문자열의 길이가 전부 100일 때

#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;

    while(getline(cin, str))
    {
        if(str == "")
        {
            break;
        }

        int small = 0;
        int big = 0;
        int num = 0;
        int jump = 0;
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                big += 1;
            }
            else if(str[i] >= 'a' && str[i] <= 'z')
            {
                small += 1;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                num += 1;
            }
            else if(str[i] == ' ')
            {
                jump += 1;
            }
        }

        cout << small << " " << big << " " << num << " " << jump << '\n';
    }

    return 0;
}