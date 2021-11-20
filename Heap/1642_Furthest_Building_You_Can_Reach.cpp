class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        priority_queue<int>q;
        for(int i=1;i<heights.size();i++)
        {
            if(heights[i]>heights[i-1])
            {
                if(bricks>=heights[i]-heights[i-1])
                {
                    bricks-=(heights[i]-heights[i-1]);
                    q.push(heights[i]-heights[i-1]);
                }
                else if(ladders>=1)
                {
                    if(q.size()>=1)
                    {
                        if(heights[i]-heights[i-1]<q.top())
                        {
                            bricks+=q.top();
                            bricks-=(heights[i]-heights[i-1]);
                            q.pop();
                            q.push(heights[i]-heights[i-1]);
                        }
                    }
                      ladders--;
                }
                else
                return i-1;
            }
        }
        return heights.size()-1;
    }
};