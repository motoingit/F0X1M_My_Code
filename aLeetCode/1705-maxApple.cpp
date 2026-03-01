#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {

        priority_queue <
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>> //! i dont know that it will be on based on days min
            >pq;

        int xApples = 0, xDays = 0;
        
        while (!pq.empty() || xDays < days.size()){
            //* Step 1: Add today's apples
            if (xDays < days.size() && apples[xDays] > 0) {
                pq.push({xDays + days[xDays], apples[xDays]});
            }

            //* deleting expired apples
            while(!pq.empty() && pq.top().first <= xDays){
                pq.pop();
            }

            //* Step 3: Eat apple if available
            if(!pq.empty()){
                auto currNode = pq.top();
                pq.pop();

                if(currNode.second > 1){
                    xApples++;
                    currNode.second--;
                    pq.push(currNode);
                }else if(currNode.second <= 1){
                    xApples++;
                }
            }

            xDays++;
        }
        
        return xApples;
    }
};
