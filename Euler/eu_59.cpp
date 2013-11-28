#include <cstdio>
#include <cstdlib>
#include <cctype>
int a[100000];
int main()
{
   int n=0,x;
   while (scanf("%d%*c",&x)==1)
      a[n++]=x;
   int s0,s1,s2,ans=0;
   for (int i='a';i<='z';i++)
      for (int j='a';j<='z';j++)
         for (int k='a';k<='z';k++)
         {
            int tot=0,b[3]={i,j,k};
            for (int p=0;p<n;p++)
            {
               int x=a[p]^b[p%3];
               if (isalpha(x) || isspace(x))
                  tot++;
            }
            if (tot>ans)
            {
               ans=tot;
               s0=i,s1=j,s2=k;
            }
         }
   int b[3]={s0,s1,s2};
   ans=0;
   for (int i=0;i<n;i++)
      ans+=a[i]^b[i%3];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
