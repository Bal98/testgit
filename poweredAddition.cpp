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
    vector<ll>ar(n);
    for(auto &x:ar)
    cin>>x;

    ll x = ar[0];
    ll mx = 0;
    for(int i=1;i<n;i++)
    {
      if(ar[i]<x)
      mx = max(mx,x-ar[i]);
      x = max(x,ar[i]);
    }

    int ans = ceil(log2(mx+1));
    cout<<ans<<endl;
  }
  return 0;
}
