#include <cstdio>
#include <cstdlib>
#include <cstring>
int q[2600000][4];
bool f[1001][1001];
int main()
{
   void print(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,l,r,ans;
      scanf("%d",&n);
      l=r=1;
      ans=0;
      memset(f,0,sizeof(f));
      f[0][0]=true;
      while (l<=r)
      {
         for (int i=0;i<=9;i++)
         {
            if (q[l][0]+i>n)
               break;
            int x=q[l][0]+i,y=(q[l][1]*10+i)%n;
            if (f[x][y])
               continue;
            f[x][y]=true;
            q[++r][0]=x,q[r][1]=y,q[r][2]=i,q[r][3]=l;
            if (q[r][0]==n && !q[r][1])
            {
               ans=r;
               break;
            }
         }
         l++;
         if (ans)
            break;
      }
      print(ans);
      printf("\n");
   }
   system("pause");
   return(0);
}
void print(int p)
{
   if (!q[p][3])
      return;
   print(q[p][3]);
   printf("%d",q[p][2]);
}
