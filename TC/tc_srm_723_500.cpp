#include <vector>
using namespace std;
int a[41],f[41][1601][41][2];
const int mod=1000000007;
struct FoxAverageSequence
{
   int theCount(vector <int> seq)
   {
      int n=seq.size();
      for (int i=1;i<=n;i++)
         a[i]=seq[i-1];
      memset(f,0,sizeof(f));
      if (a[1]==-1)
      {
         for (int i=0;i<=40;i++)
            f[1][i][i][0]=1;
      }
      else
         f[1][a[1]][a[1]][0]=1;
      int ans=0;
      for (int i=1;i<=n;i++)
         for (int j=0;j<=i*40;j++)
            for (int k=0;k<=40;k++)
               for (int l=0;l<=1;l++)
               {
                  if (i==n)
                  {
                     ans+=f[i][j][k][l];
                     ans%=mod;
                     continue;
                  }
                  if (a[i+1]!=-1)
                  {
                     int x=a[i+1];
                     if (x*i>j)
                        continue;
                     if (x<k && l==1)
                        continue;
                     int op=x<k?1:0;
                     f[i+1][j+x][x][op]+=f[i][j][k][l];
                     f[i+1][j+x][x][op]%=mod;
                     continue;
                  }
                  for (int x=0;x<=40;x++)
                  {
                     if (x*i>j)
                        continue;
                     if (x<k && l==1)
                        continue;
                     int op=x<k?1:0;
                     f[i+1][j+x][x][op]+=f[i][j][k][l];
                     f[i+1][j+x][x][op]%=mod;
                  }
               }
      return(ans);
   }
};
int main(){}
