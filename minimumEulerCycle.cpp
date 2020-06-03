#include<bits/stdc++.h>
#define ll long long
#define pb push_back;
#define all(x) x.begin(),x.end()
using namespace std;
int n;
ll l,r,pre[100005];


ll solve(ll x)
{
  if(x>pre[n-1])
  return 1;
  ll pos = lower_bound(pre+1,pre+n,x)-pre;
  ll b = x-pre[pos-1];
  if(b%2==1)
  return pos;
  else return b/2+pos;
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
    {
      pre[i]=pre[i-1]+2*(n-i);
    }
    for(ll i=l;i<=r;i++)
    {
      cout<<solve(i)<<" ";
    }
    cout<<endl;
  }
  return 0;
}
