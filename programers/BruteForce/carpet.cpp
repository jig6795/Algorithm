#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int half_brown = brown/2;
    int red_row = 0;
    int red_col = 0;
    int red_col_temp = 0;

    while(1)
    {
        //red_row가 red의 수를 넘어가면 면적을 구할 수 없으므로 가로 : 0 세로 : 0 을 출력
        if(red_row > red)
        {
            answer.push_back(0);
            answer.push_back(0);
            break;
        }

        // ((red의 가로 + 1) + (red의 세로 + 1)) = brown/2
        if(((red_row + 1) + (red_col + 1)) == (brown/2))
        {
            // 이때, row와 col의 곱이 red가 되면 출력
            if(red_col*red_row == red)
            {
                answer.push_back(red_col + 2);
                answer.push_back(red_row + 2);
                break;
            }
        }

        //col을 증가할 때, col의 값이 red의 갯수를 초과하거나
        //row가 2 이상일때, col이 row보다 커지게 되면 row를 증가시키면서 col은 red/row로 설정
        if((red_col_temp > red_row) || (red_col_temp > red))
        {
            red_row += 1;
            red_col = red / red_row;
            red_col_temp = 0;
        }
        
        red_col_temp += 1;
    }
    return answer;
}

int main(void)
{
    int brown = 24;
    int red = 24;

    vector<int> answer = solution(brown,red);

    for(int i=0;i<answer.size();i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}