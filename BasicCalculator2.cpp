//https://leetcode.com/problems/basic-calculator-ii
int calculate(string s) 
    {
       stack<int> st; 
        int answer=0; 
        long long current_val=0;
        char sign = '+'; 
        for (int i=0;i<s.size();i++) 
        { 
            char c = s[i];
                if (isdigit(c)) 
                {
                    current_val=10*current_val + c-'0'; 
                }
                if(!isdigit(c) && !isspace(c) || i==s.size()-1)
                {
                      if(sign=='+')
                      st.push(current_val);
                      else if(sign=='-')
                      st.push(-current_val);
                      else{
                          int num;
                          if(sign=='*')
                          num = st.top()*current_val;
                          if(sign=='/')
                          num = st.top()/current_val;
                          st.pop();
                          st.push(num);
                      }
                      sign = c;
                      current_val=0;
                }
        }
        while(!st.empty())
        {
            answer += st.top();
            st.pop();
        }
        return answer; 
            
    }
