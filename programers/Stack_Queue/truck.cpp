#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    queue<int> bridge;

    for(int i=0;i<truck_weights.size();i++)
    {
        int truck = truck_weights[i];

        while(1)
        {
            //처음 다리에 트럭이 없을 때
            if(bridge.empty())
            {
                bridge.push(truck);
                answer += 1;
                sum += truck;
                break;
            }
            else if(bridge.size() == bridge_length) //다리가 가득차 있을 경우
            {
                sum -= bridge.front();
                bridge.pop();
            }
            else //무게보다 더 많이 나가는 경우 무게가 0인 트럭을 넣는다.
            {
                if(sum + truck > weight)
                {
                    bridge.push(0);
                    answer += 1;
                }
                else
                {
                    bridge.push(truck);
                    answer += 1;
                    sum += truck;
                    break;
                }       
            }
        }
    }
    
    return answer + bridge_length;
}

int main(void)
{
    vector<int> truck;
    truck.push_back(7);
    truck.push_back(4);
    truck.push_back(5);
    truck.push_back(6);

    int result = solution(2, 10, truck);

    cout << result << endl;

    return 0;
}