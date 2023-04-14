//https://practice.geeksforgeeks.org/problems/546ea68f97be7283a04ddcc8057e09b46a686471/1
int finLength(int N, vector<int> color, vector<int> radius) 
    {
        stack<int> st;
        int n = color.size();
        int i=0;
        while(i<n)
        {
            while(i<n && !st.empty() && color[st.top()]==color[i] && radius[st.top()]==radius[i])
            {
                st.pop();
                i++;
            }
            if(i<n)
            st.push(i);
            i++;
        }
        return st.size();
    }
