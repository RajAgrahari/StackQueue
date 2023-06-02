//https://codeforces.com/contest/546/problem/C
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
        ll n;
        cin>>n;
        map<pair<queue<ll>,queue<ll>>,ll> mp;
        queue<ll> q1,q2;
        ll n1;
        cin>>n1;
        while(n1--)
        {
            ll x;
            cin>>x;
            q1.push(x);
        }
        ll n2;
        cin>>n2;
        while(n2--)
        {
            ll x;
            cin>>x;
            q2.push(x);
        }
        ll cnt=0;
        while(true)
        {
            if(q1.empty())
            {
                cout<<cnt<<' '<<2<<'\n';
                break;
            }
            if(q2.empty())
            {
                cout<<cnt<<' '<<1<<'\n';
                break;
            }
            if(mp.count({q1,q2}))
            {
                cout<<"-1\n";
                break;
            }
            mp[{q1,q2}]++;
            ll a = q1.front();
            q1.pop();
            ll b = q2.front();
            q2.pop();
            if(a>b)
            {
                // cout<<a<<' '<<b<<'\n';
                q1.push(b);
                q1.push(a);
            }
            else{
                // cout<<a<<' '<<b<<'\n';
                q2.push(a);
                q2.push(b);
            }
            cnt++;
        }
    return 0;
}
