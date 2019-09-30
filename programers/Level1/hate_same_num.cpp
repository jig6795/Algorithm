#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int temp;

    for(int i=0;i<arr.size();i++)
    {
        int temp = arr[i];
        answer.push_back(temp);

        for(int j=i+1;j<arr.size();j++)
        {
            if(temp != arr[j])
            {   
                break;
            }
            i += 1;
        }
    }

    return answer;
}

int main(void)
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(3);
    //arr.push_back(1);
    //arr.push_back(1);

    vector<int> answer = solution(arr);

    for(int i=0;i<answer.size();i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}