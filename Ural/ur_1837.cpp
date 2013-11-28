#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map <string,int> s;
int tot,d[310],q[310],b[310],a[610][2];
int main()
{
   void add(int,int);
   int T,n=0;
   scanf("%d",&T);
   while (T--)
   {
      char s1[100],s2[100],s3[100];
      scanf("%s%s%s",s1,s2,s3);
      if (!s.count(s1))
         s[s1]=++n;
      if (!s.count(s2))
         s[s2]=++n;
      if (!s.count(s3))
         s[s3]=++n;
      add(s[s1],s[s2]);
      add(s[s1],s[s3]);
      add(s[s2],s[s3]);
   }
   int l,r;
   l=1,r=0;
   memset(d,-1,sizeof(d));
   if (s.count("Isenbaev"))
   {
      q[++r]=s["Isenbaev"];
      d[q[1]]=0;
   }
   while (l<=r)
   {
      int x=q[l++];
      for (int i=b[x];i;i=a[i][1])
      {
         int y=a[i][0];
         if (d[y]==-1)
         {
            d[y]=d[x]+1;
            q[++r]=y;
         }
      }
   }
   for (map <string,int>::iterator k=s.begin();k!=s.end();k++)
   {
      printf("%s ",k->first.c_str());
      int p=k->second;
      if (d[p]==-1)
         printf("undefined\n");
      else
         printf("%d\n",d[p]);
   }
   system("pause");
   return(0);
}
void add(int x,int y)
{
   a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=b[y],b[y]=tot;
}
