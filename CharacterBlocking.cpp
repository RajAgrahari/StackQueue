//https://codeforces.com/contest/1840/problem/E
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
        string a,b;
        cin>>a>>b;
        ll num = a.size();
        set<ll> st;
        for(ll i=0;i<num;i++)
        {
            if(a[i]!=b[i])
            st.insert(i);
        }
        ll n,qn;
        cin>>n>>qn;
        queue<pair<ll,ll>> qu;
        for(ll i=1;i<=qn;i++)
        {
            while(!qu.empty() && qu.front().first == i)
            {
                ll po = qu.front().second;
                qu.pop();
                if(a[po]!=b[po])
                st.insert(po);
            }
            ll x;
            cin>>x;
            if(x==1)
            {
                ll pos;
                cin>>pos;
                pos--;
                qu.push({n+i,pos});
                st.erase(pos);
            }
            else if(x==2)
            {
                ll y,z,p,q;
                cin>>y>>z>>p>>q;
                y--,z--,p--,q--;
                char c;
                if(p==0)
                {
                    if(y==0)
                    {
                        c = a[z];
                        a[z] = a[q];
                        a[q] = c;
                    }
                    else{
                        c = b[z];
                        b[z] = a[q];
                        a[q] = c;
                    }
                }
                else{
                    if(y==0)
                    {
                        c = a[z];
                        a[z] = b[q];
                        b[q] = c;
                    }
                    else{
                        c = b[z];
                        b[z] = b[q];
                        b[q] = c;
                    }
                }
                st.erase(z);
                if(a[z]!=b[z])
                st.insert(z);
                st.erase(q);
                if(a[q]!=b[q])
                st.insert(q);
            }
            else{
                string ans = (st.size()==0)?"YES":"NO";
                cout<<ans<<'\n';
            }
        }
    }
    return 0;
}
