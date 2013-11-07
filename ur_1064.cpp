#include <cstdio>
#include <cstdlib>
int ans[10001][2];
int main()
{
   int search(int,int);
   int s,p,l;
   scanf("%d%d",&p,&l);
   s=0;
   ans[0][1]=-1;
   for (int i=1;i<=10000;i++)
      if (search(p,i)==l)
         if (i==ans[s][1]+1)
            ans[s][1]++;
         else
         {
            s++;
            ans[s][0]=i;
            ans[s][1]=i;
         }
   printf("%d\n",s);
   for (int i=1;i<=s;i++)
      printf("%d %d\n",ans[i][0],ans[i][1]);
   system("pause");
   return(0);
}
int search(int x,int n)
{
   int l,r,s;
   l=s=0,r=n-1;
   while (l<=r)
   {
      int mid=l+r>>1;
      s++;
      if (mid==x)
         return(s);
      if (x<mid)
         r=mid-1;
      else
         l=mid+1;
   }
   return(-1);
}
