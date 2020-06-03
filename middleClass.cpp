#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    double x;
    cin>>n>>x;
    ll ar[n+5];
    for(int i=0;i<n;i++)
    cin>>ar[i];

    sort(ar,ar+n);
    int ans=0;
    double sum=0;
    int j=1;
    for(int i=n-1;i>=0;i--)
    {
      sum+=ar[i];
      double avg = (sum)/j;
      if(avg>=x)
      ans++;
      j++;
    }
    cout<<ans<<endl;
  }
  return 0;
}
