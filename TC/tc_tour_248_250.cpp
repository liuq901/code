#include <vector>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct SixteenBricks
{
    int cnt[65540],f[65540];
    int maximumSurface(vector <int> height)
    {
        sort(height.begin(),height.end());
        reverse(height.begin(),height.end());
        for (int i=0;i<1<<16;i++)
            cnt[i]=__builtin_popcount(i);
        f[0]=0;
        for (int i=0;i<1<<16;i++)
        {
            int x=cnt[i];
            for (int j=0;j<16;j++)
            {
                if (i>>j&1)
                    continue;
                f[i|1<<j]=max(f[i|1<<j],f[i]+calc(i,height[x],j));
            }
        }
        return(f[65535]);
    }
    int calc(int state,int height,int pos)
    {
        int x0=pos/4,y0=pos%4;
        int ret=height*4+1;
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>=0 && x<4 && y>=0 && y<4)
            {
                int now=x*4+y;
                if (state>>now&1)
                    ret-=height*2;
            }
        }
        return(ret);
    }
};
int main(){}

