//https://codeforces.com/contest/1837/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define NOOB ios_base::sync_with_stdio(false);
#define CODER cin.tie(NULL);
#define SOLUTION cout.tie(NULL);
   
int main()
{
    NOOB CODER SOLUTION
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll cnt=0;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='(')
            cnt++;
            else
            cnt--;
        }
        if(cnt!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        else{
            stack<ll> st;
            vector<ll> ans(n);
            ll tw=0,o=0;
            for(ll i=0;i<n;i++)
            {
                if(st.empty() || (!st.empty() && s[st.top()]==s[i]))
                {
                     st.push(i);
                }
                else{
                    if(s[st.top()]=='(')
                    {
                        tw++;
                        ans[st.top()] = 2;
                        ans[i] = 2;
                        st.pop();
                    }
                    else{
                        o++;
                        ans[st.top()] = 1;
                        ans[i] = 1;
                        st.pop();
                    }
                }
            }
            if(tw>0 && o>0)
            {
                cout<<2<<'\n';
                for(ll x:ans)
                cout<<x<<' ';
                cout<<'\n';
            }
            else
            {
                cout<<1<<endl;
                for(ll x:ans)
                cout<<1<<' ';
                cout<<'\n';
            }
        }
    }
    return 0;
}
