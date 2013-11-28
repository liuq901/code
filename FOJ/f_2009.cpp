#include <cstdio>
#include <cstdlib>
#include <cstring>
bool f[10],g[10];
int ans,now[10];
char s1[10],s2[10],s3[10];
int main()
{
   void search(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%s %s %s",s1,s2,s3);
      memset(g,0,sizeof(g));
      for (int i=0;i<strlen(s1);i++)
         g[s1[i]-'A']=true;
      for (int i=0;i<strlen(s2);i++)
         g[s2[i]-'A']=true;
      for (int i=0;i<strlen(s3);i++)
         g[s3[i]-'A']=true;
      ans=0;
      search(0);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void search(int dep)
{
   void check();
   if (dep==5)
   {
      check();
      return;
   }
   if (!g[dep])
   {
      search(dep+1);
      return;
   }
   for (int i=0;i<10;i++)
   {
      if (f[i])
         continue;
      f[i]=true;
      now[dep]=i;
      search(dep+1);
      f[i]=false;
   }
}
void check()
{
   int l1=strlen(s1),l2=strlen(s2),l3=strlen(s3);
   if (l1>1 && !now[s1[0]-'A'] || l2>1 && !now[s2[0]-'A'] || l3>1 && !now[s3[0]-'A'])
      return;
   int a,b,c;
   a=b=c=0;
   for (int i=0;i<l1;i++)
      a=a*10+now[s1[i]-'A'];
   for (int i=0;i<l2;i++)
      b=b*10+now[s2[i]-'A'];
   for (int i=0;i<l3;i++)
      c=c*10+now[s3[i]-'A'];
   ans+=(a+b==c)+(a-b==c)+(a*b==c);
   if (b && b*c==a)
      ans++;
}
