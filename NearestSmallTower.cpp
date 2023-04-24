//https://practice.geeksforgeeks.org/problems/a520c08a8ea9b617be25c38b0fc2fe057e889253/1
vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        
       int right[n];
        for(int i=0;i<n;i++)
        right[i] = -1;
        int i=0;
        while(i<n)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
            i++;
        }
        
        while(!st.empty())
        st.pop();
        
        int left[n];
        for(int i=0;i<n;i++)
        left[i] = -1;
        i=n-1;
        while(i>=0)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
            i--;
        }
        
        for(int i=0;i<n;i++)
        {
            if(left[i]==-1)
            ans[i] = right[i];
            else if(right[i]==-1)
            ans[i] = left[i];
            else{
                if((i-left[i])==(right[i]-i))
                {
                    if(arr[left[i]]<=arr[right[i]])
                    ans[i] = left[i];
                    else
                    ans[i] = right[i];
                }
                else if((i-left[i])<(right[i]-i))
                ans[i] = left[i];
                else
                ans[i] = right[i];
            }
        }
        return ans;
    }
