#include <iostream>
#include <string>
#include <vector>

using namespace std;

int res = 0;

//
// DFS 함수
// Root를 기준으로 +, - 해가면서 tree를 만들어 가도록 함
//
void dfs(vector<int> numbers, int target, int sum, int depth)
{
    if(depth >= numbers.size())
    {
        if(sum == target)
        {
            res += 1;
        }
        return;
    }
    dfs(numbers,target,sum+numbers[depth],depth+1);
    dfs(numbers,target,sum-numbers[depth],depth+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(numbers, target, numbers[0], 1);
    dfs(numbers, target, numbers[0]*(-1), 1);

    answer = res;
    
    return answer;
}

int main(void)
{
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);
    numbers.push_back(1);

    int target = 3;

    int result = solution(numbers,target);

    cout << result << endl;    
}