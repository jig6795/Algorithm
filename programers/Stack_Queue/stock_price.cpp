#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count = 0;

    for(int i=0;i<prices.size();i++)
    {
        count = 0;
        for(int j=i+1;j<prices.size();j++)
        {
            if(prices[i] > prices[j])
            {
                count = j-i;
                answer.push_back(count);
                break;
            }
        }
        
        if(count == 0)
        {
            answer.push_back(prices.size()-1-i);
        }
    }
    return answer;
}

int main(void)
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);

    vector<int> answer = solution(prices);

    for(int i=0;i<answer.size();i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}