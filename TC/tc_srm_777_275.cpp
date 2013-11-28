#include <vector>
using namespace std;
struct P8XGraphBuilder
{
    vector <int> a;
    bool vis[60][60];
    int f[60][60];
    int solve(vector <int> scores)
    {
        int n=scores.size()+1;
        a=scores;
        int ans=0;
        for (int i=1;i<n;i++)
            ans=max(ans,calc(i,n-i-1)+a[i-1]);
        return(ans);
    }
    int calc(int x,int y)
    {
        if (vis[x][y])
            return(f[x][y]);
        vis[x][y]=true;
        int &ret=f[x][y];
        ret=-1<<30;
        if (x==0)
            ret=y==0?0:-1<<30;
        else
            for (int i=0;i<=y;i++)
                for (int j=0;j<=y-i;j++)
                    ret=max(ret,calc(x-1,i)+calc(j,y-i-j)+a[j]);
        return(ret);
    }
};
int main(){}

