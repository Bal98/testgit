#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(int n)
{
    for(int i=1;i<8;i++)
    {
        int p = pow(i,i);
        if(p==n)
        return true;
    }
    return false;
}

int dp[1000005];

int solve(int n)
{
    if(n<=0)
    return 0;

    if(dp[n]!=-1)
    return dp[n];

    int temp = n;
    bool b = check(n);
    if(b)
    return dp[n]=1;

    while(temp>0)
    {
        int dig = temp%10;
        int nn = n - dig*dig;
        b = b|solve(nn);
        if(b==true)
        break;
        temp=temp/10;
    }
    if(b)
    return dp[n]=1;
    else
    return dp[n]=0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin>>t;
    memset(dp,-1,sizeof dp);
    while(t--)
    {
        int n;
        cin>>n;
        int b = solve(n);
        if(b)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;

}
