typedef long long ll;
const int mod=1000000007;
struct TrafficCongestion
{
    int power(int y)
    {
        int ret=1,x=2;
        for (;y;y>>=1)
        {
            if (y&1)
                ret=ll(ret)*x%mod;
            x=ll(x)*x%mod;
        }
        return(ret);
    }
    int theMinCars(int treeHeight)
    {
        int ans=0;
        for (int i=treeHeight;i>=1;i-=2)
            ans=(ans+power(i-1))%mod;
        if (treeHeight%2==0)
            ans=(ans+1)%mod;
        return(ans);
    }
};
int main(){}

