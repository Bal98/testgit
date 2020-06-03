#include<bits/stdc++.h>
#define ll long long
#define pb push_back;
#define all(x) x.begin(),x.end()
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    ll a,b;
    vector<pair<ll,ll>>v;
    for(int i=0;i<n;i++)
    {
      cin>>a>>b;
      v.push_back({a,b});
    }

    ll mn = 1e18;
    ll s=0;
    ll extra[n+5];
    for(int i=0;i<n;i++)
    {
      int prev = (i+n-1)%n;
      extra[i]=max(0LL,v[i].first-v[prev].second);
      s+=extra[i];
    }
    for(int i=0;i<n;i++)
    mn = min(mn,s-extra[i]+v[i].first);
    cout<<mn<<endl;
  }
  return 0;
}
