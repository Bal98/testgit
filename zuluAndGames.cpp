#include<bits/stdc++.h>
#define ll long long
#define pb push_back;
#define all(x) x.begin(),x.end()
using namespace std;
vector<pair<int,int>>v;
const int mod = 1e9+7;

int mul(ll num1,ll num2)
{
  ll ans  = num1*num2;
  ans%=mod;
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  int n;
  cin>>n;
  int s[n],e[n],rs[n+1],A[n+1],B[n+1];
  for(int i=0;i<n;i++)
  cin>>s[i];
  for(int i=0;i<n;i++)
  cin>>e[i];

  for(int i=0;i<n;i++)
  v.push_back({e[i],s[i]});

  sort(v.begin(),v.end());
  rs[0]=v[0].first,A[0]=1;B[0]=1;
  for(int i=0;i<n;i++)
  {
    A[i]=1;
    int ind = lower_bound(v.begin(),v.end(),make_pair(v[i].second-1,INT_MAX))-v.begin();
    ind--;
    if(ind>=0)
    A[i]=B[ind];
    rs[i]=0;
    B[i]=0;
    int left=0;
    for(int j=i;j>=0;j--)
    {
      if(v[j].first<left)break;
      B[i]+=A[j];
      B[i]%=mod;
      int ge = mul(A[j],v[j].first);
      rs[i]+=ge;
      rs[i]%=mod;
      left = max(left,v[j].second);
    }
  }
  cout<<rs[n-1]<<endl;
  return 0;

}
