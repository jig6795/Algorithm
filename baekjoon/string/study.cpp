#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
    string al;
    cin >> al;
    int a = al.length();
    int cnt = 0;
    int max = 0;
    char maxAlpha;
    int alpha_cnt[26] = {0};

    for(int i=0;i<a;i++)
    {
        if(al.at(i) >= 65 && al.at(i) <= 90)
        {
            alpha_cnt[(int)al.at(i)-65] += 1;
        }
        else
        {
            alpha_cnt[(int)al.at(i)-97] += 1;
        }
    }

    max = alpha_cnt[0];
    maxAlpha = 65;

    for(int i=1;i<26;i++)
    {
        if(max < alpha_cnt[i])
        {
            max = alpha_cnt[i];
            maxAlpha = i+65;
            cnt = i;
        }

        if(i == 25)
        {
            for(int j=0; j<26; j++)
            {
                if(cnt != j)
                {
                    if(max == alpha_cnt[j])
                    {
                        maxAlpha = '?';
                    }
                }
            }
        }
    }

    cout << maxAlpha << endl;

    return 0;
}

