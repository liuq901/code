#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct EllysFigurines
{
    vector <string> a,b;
    int n,m;
    int getMoves(vector <string> board,int R,int C)
    {
        a=board;
        n=a.size();
        m=a[0].size();
        int ans=1<<30;
        for (int i=0;i<1<<n;i++)
        {
            del(i,R);
            ans=min(ans,__builtin_popcount(i)+work(C));
        }
        return(ans);
    }
    void del(int mask,int P)
    {
        b=a;
        bool f[20]={0};
        for (int i=0;i<n;i++)
            if (mask>>i&1)
                for (int j=0;j<P;j++)
                {
                    if (i+j>=n)
                        break;
                    f[i+j]=true;
                }
        for (int i=0;i<n;i++)
        {
            if (!f[i])
                continue;
            for (int j=0;j<m;j++)
                b[i][j]='.';
        }
    }
    int work(int P)
    {
        bool f[20]={0};
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (b[i][j]=='X')
                    f[j]=true;
        int ret=0;
        for (int i=0;i<m;i++)
            if (f[i])
            {
                ret++;
                for (int j=0;j<P;j++)
                {
                    if (i+j>=m)
                        break;
                    f[i+j]=false;
                }
            }
        return(ret);
    }
};
int main(){}

