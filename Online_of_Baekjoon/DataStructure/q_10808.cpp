// Q10808
// 알파벳 개수
// 시간복잡도 - O(n)

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> freq(26);

    string str;
    getline(cin, str);

    for(int i=0;i<str.length();i++)
    {
        freq[(int)str[i]-97] += 1;
    }

    for(int i=0;i<26;i++)
    {
        cout << freq[i] << " ";
    }

    return 0;
}