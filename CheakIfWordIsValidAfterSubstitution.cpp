//https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
bool isValid(string s) 
    {
        int cnt=0;
        int i=0,n=s.size();
        stack<char> st;
        while(i<n)
        {
            while(i<n && !st.empty() && st.top()=='b' && s[i]=='c')
            {
                st.pop();
                if(!st.empty() && st.top()=='a')
                st.pop();
                else
                return false;
                i++;
            }
            if(i<n)
            st.push(s[i]);
            i++;
        }
        if(!st.empty())
        return false;
        return true;
       
    }
