#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct DropCoins
{
    int a[40][40],s[40][40];
    int getMinimum(vector <string> board,int K)
    {
        int n=board.size(),m=board[0].size();
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                a[i][j]=board[i-1][j-1]=='o';
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
            }
        int ans=-1;
        for (int i=1;i<=n;i++)
            for (int j=i;j<=n;j++)
                for (int k=1;k<=m;k++)
                    for (int l=1;l<=m;l++)
                        if (get(i,k,j,l)==K)
                        {
                            int now=min(i-1,n-j)+i-1+n-j+min(k-1,m-l)+k-1+m-l;
                            if (ans==-1 || now<ans)
                                ans=now;
                        }
        return(ans);
    }
    int get(int x1,int y1,int x2,int y2)
    {
        return(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
    }
};
int main(){}

