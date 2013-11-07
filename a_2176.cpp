#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a[110];
int s[110],now[110];
int main()
{
   while (1)
   {
      int n,d;
      scanf("%d%d",&n,&d);
      if (!n && !d)
         break;
      memset(s,0,sizeof(s));
      int ma=-1,maa=-1,mi=1<<30,tot=0;
      for (int i=1;i<=n;i++)
      {
         int m;
         scanf("%d",&m);
         a[i].resize(m);
         now[i]=m;
         tot+=m;
         for (int j=0;j<m;j++)
         {
            scanf("%d",&a[i][j]);
            s[i]+=a[i][j];
         }
         if (s[i]>ma)
            maa=ma,ma=s[i];
         else if (s[i]>maa)
            maa=s[i];
         mi=min(mi,s[i]);
      }
      if (ma-mi>d)
      {
         printf("No\n");
         continue;
      }
      bool fail=false;
      while (tot)
      {
         int k=0;
         for (int i=1;i<=n;i++)
         {
            if (!now[i])
               continue;
            int p=s[i],q=s[i]-a[i][now[i]-1];
            if (p!=ma && ma-q<=d || p==ma && maa-q<=d)
            {
               k=i;
               break;
            }
         }
         if (!k)
         {
            fail=true;
            break;
         }
         int p=s[k];
         s[k]-=a[k][--now[k]];
         mi=min(mi,s[k]);
         if (p==ma || p==maa)
         {
            ma=maa=-1;
            for (int i=1;i<=n;i++)
               if (s[i]>ma)
                  maa=ma,ma=s[i];
               else if (s[i]>maa)
                  maa=s[i];
         }
         tot--;
      }
      printf("%s\n",fail?"No":"Yes");
   }
   system("pause");
   return(0);
}
