#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,t,l,n,ans;
   int a[30];
   char s[10000];
   while (1)
   {
      scanf("%s",s);
      l=strlen(s);
      if (l==3 && s[0]=='E' && s[1]=='N' && s[2]=='D')
         break;
      memset(a,0,sizeof(a));
      for (i=0;i<l;i++)
         if (s[i]=='_')
            a[26]++;
         else
            a[s[i]-'A']++;
      for (i=0;i<26;i++)
         for (j=i+1;j<=26;j++)
            if (a[i]>a[j])
               t=a[i],a[i]=a[j],a[j]=t;
      n=0;
      while (a[n]==0)
         n++;
      memmove(a,a+n,sizeof(int)*(27-n));
      n=26-n;
      ans=0;
      for (i=0;i<=n-1;i++)
      {
         ans+=a[i]+a[i+1];
         a[i+1]+=a[i];
         for (j=i+1;j<=n-1;j++)
            if (a[j]>a[j+1])
               t=a[j],a[j]=a[j+1],a[j+1]=t;
      }
      if (ans==0)
         printf("%d %d 8.0\n",8*l,l);
      else
         printf("%d %d %.1lf\n",8*l,ans,8.0*l/ans);
   }
   system("pause");
   return(0);
}
