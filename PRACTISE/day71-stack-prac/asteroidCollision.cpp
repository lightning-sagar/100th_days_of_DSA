class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //check if the next element is greater than the current element if not then then sub both if it is greater than 0 then push it else pop it
        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            if(st.empty() || asteroids[i]>0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                while(!st.empty() && st.top()>0 && st.top()+asteroids[i]<0)
                {
                    st.pop();
                }
                if(st.empty() || st.top()<0)
                {
                    st.push(asteroids[i]);
                }
                else if(st.top()+asteroids[i]==0)
                {
                    st.pop();
                }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};