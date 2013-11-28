#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char s[8010];
int f[260];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%s",s);
      int n=strlen(s);
      memset(f,0,sizeof(f));
      for (int i=0;i<n;i++)
         f[s[i]]++;
      int sum=0;
      for (int i='a';i<='z';i++)
         if (f[i]&1)
            sum++;
      if (sum>1)
         printf("Impossible\n");
      else
      {
         bool flag=false;
         int ans=0,pos;
         for (int i=0;i<=n>>1;i++)
         {
            int l,r;
            r=n-i-1+flag;
            for (int j=r;j>=i;j--)
               if (s[j]==s[i])
               {
                  l=j;
                  break;
               }
            if (l==i)
            {
               flag=true;
               pos=i;
               continue;
            }
            ans+=r-l;
            for (int j=l;j<r;j++)
               swap(s[j],s[j+1]);
         }
         printf("%d\n",ans+((n>>1)-pos)*flag);
      }
   }
   system("pause");
   return(0);
}
