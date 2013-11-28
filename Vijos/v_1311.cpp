#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,ans,flag[21],f[21][21];
char h,s[21][260];
int main()
{
   void make(),work(int,int);
   int i,j;
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
      scanf("%s",s[i]);
   while (1)
   {
      scanf("%c",&h);
      if (h>='a' && h<='z')
         break;
      if (h>='A' && h<='Z')
         break;
   }
   memset(flag,0,sizeof(flag));
   make();
   ans=0;
   for (i=1;i<=n;i++)
      if (s[i][0]==h)
      {
         flag[i]=1;
         work(i,strlen(s[i]));
         flag[i]=0;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void make()
{             
   int i,j,k,l,t,bo;
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
         for (k=strlen(s[i])-1;k>=0;k--)
         {
            if (strlen(s[i])-k>strlen(s[j]))
            {
               bo=0;
               break;
            }

            t=-1;
            bo=1;
            for (l=k;l<strlen(s[i]);l++)
            {
               t++;
               if (s[i][l]!=s[j][t])
               {
                  bo=0;
                  break;
               }
            }
            if (bo)
               break;
         }
         if (!bo)
            f[i][j]=0;
         else
            f[i][j]=strlen(s[j])-t-1;
      }
}
void work(int x,int l)
{
   int i;
   if (l>ans)
      ans=l;
   for (i=1;i<=n;i++)
      if (f[x][i]!=0 && flag[i]<2)
      {
         flag[i]++;
         work(i,l+f[x][i]);
         flag[i]--;
      }
}
