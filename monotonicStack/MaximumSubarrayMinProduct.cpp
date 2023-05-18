//https://leetcode.com/problems/maximum-subarray-min-product/description/
long long mod = 1000000007;
    int maxSumMinProduct(vector<int>& nums) 
    {
        long long n = nums.size();
        stack<long long> st;
        vector<long long> pre(n+1);
        pre[0] = 0;
        for(int i=0;i<n;i++)
        {
           pre[i+1] = pre[i] + nums[i];
        }
        long long ans = 0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || nums[st.top()]>nums[i]))
            {
                int idx = st.top();
                st.pop();
                int left = (st.empty()) ? idx : idx-st.top()-1;
                ans = max(ans,nums[idx]*(pre[i]-pre[idx-left]));
            }
            st.push(i);
        }
        return ans%mod;
    }
