#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=100000007;
pair <int,int> b[510];
vector <int> s,o;
vector <pair <int,int> > m;
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    int num=int(sqrt(double(mod)));
    while (T--)
    {
        int N,K,B,R,M=1;
        scanf("%d%d%d%d",&N,&K,&B,&R);
        for (int i=1;i<=B;i++)
        {
            scanf("%d%d",&b[i].first,&b[i].second);
            M=max(M,b[i].first);
        }
        sort(b+1,b+B+1);
        int ans=1,t=1,value=power(K-1,N);
        for (int i=1;i<=M;)
        {
            s.clear();
            while (t<=B && b[t].first==i)
                s.push_back(b[t++].second);
            int x=N-s.size(),y=0;
            for (int j=0;j<o.size();j++)
                if (!binary_search(s.begin(),s.end(),o[j]))
                {
                    x--;
                    y++;
                }
            if (i==1)
                y+=x,x=0;
            ans=ll(ans)*power(K-1,x)%mod*power(K,y)%mod;
            if (!s.empty() || t>B)
            {
                o=s;
                i++;
            }
            else
            {
                o.clear();
                ans=ll(ans)*power(value,b[t].first-i-1)%mod;
                i=b[t].first;
            }
        }
        if (ans!=R)
        {
            M++;
            int x=N-o.size(),y=o.size();
            ans=ll(ans)*power(K-1,x)%mod*power(K,y)%mod;
            if (ans!=R)
            {
                int v=value,p;
                m.clear();
                for (int i=1;i<=num;i++)
                {
                    m.push_back(make_pair(v,i));
                    p=v;
                    v=ll(v)*value%mod;
                }
                p=power(p,mod-2);
                R=ll(R)*power(ans,mod-2)%mod;
                sort(m.begin(),m.end());
                while (1)
                {
                    int k=lower_bound(m.begin(),m.end(),make_pair(R,0))-m.begin();
                    if (k!=m.size() && m[k].first==R)
                    {
                        M+=m[k].second;
                        break;
                    }
                    M+=num;
                    R=ll(R)*p%mod;
                }
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,M);
    }
    return(0);
}

