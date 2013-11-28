#include <cstdio>
#include <cstdlib>
#include <cstring>
const char name[3][10]={"evil","human","divine"};
struct dialogue
{
   int x,y,z;
};
int main()
{
   int id=0;
   while (1)
   {
      int n;
      scanf("%d%*c",&n);
      if (!n)
         break;
      dialogue a[51];
      for (int i=1;i<=n;i++)
      {
         char s[26];
         gets(s);
         a[i].x=s[0]-'A'+1;
         if (s[3]=='I' && s[4]=='t')
         {
            a[i].y=6;
            if (s[9]=='d')
               a[i].z=0;
            else
               a[i].z=1;
         }
         else
         {
            if (s[3]=='I')
               a[i].y=a[i].x;
            else
               a[i].y=s[3]-'A'+1;
            if (s[8]=='e')
               a[i].z=0;
            else if (s[8]=='h')
               a[i].z=1;
            else if (s[8]=='d')
               a[i].z=2;
            else if (s[8]=='l')
               a[i].z=3;
            else if (s[12]=='e')
               a[i].z=4;
            else if (s[12]=='h')
               a[i].z=5;
            else if (s[12]=='d')
               a[i].z=6;
            else
               a[i].z=7;
         }
      }
      int ans[6],p[6];
      memset(ans,-1,sizeof(ans));
      bool possible=false;
      for (p[1]=0;p[1]<=2;p[1]++)
         for (p[2]=0;p[2]<=2;p[2]++)
            for (p[3]=0;p[3]<=2;p[3]++)
               for (p[4]=0;p[4]<=2;p[4]++)
                  for (p[5]=0;p[5]<=2;p[5]++)
                     for (p[0]=0;p[0]<=1;p[0]++)
                     {
                        bool flag=true,f[6];
                        for (int i=1;i<=5;i++)
                           if (!p[i] || p[i]==1 && p[0])
                              f[i]=false;
                           else
                              f[i]=true;
                        for (int i=1;i<=n;i++)
                        {
                           bool now;
                           if (a[i].y==6)
                              now=a[i].z==p[0];
                           else if (a[i].z==3)
                              now=!f[a[i].y];
                           else if (a[i].z==7)
                              now=f[a[i].y];
                           else if (a[i].z<3)
                              now=p[a[i].y]==a[i].z;
                           else
                              now=p[a[i].y]!=a[i].z-4;
                           if (now!=f[a[i].x])
                           {
                              flag=false;
                              break;
                           }
                        }
                        if (flag)
                        {
                           possible=true;
                           for (int i=0;i<=6;i++)
                           {
                              if (ans[i]==-1)
                                 ans[i]=p[i];
                              if (ans[i]!=p[i])
                                 ans[i]=-2;
                           }
                        }
                     }
      printf("Conversation #%d\n",++id);
      if (!possible)
         printf("This is impossible.\n");
      else
      {
         bool flag=true;
         for (int i=1;i<=5;i++)
         {
            if (ans[i]==-2)
               continue;
            flag=false;
            printf("%c is %s.\n",i+'A'-1,name[ans[i]]);
         }
         if (ans[0]!=-2)
         {
            flag=false;
            printf("It is %s.\n",ans[0]?"night":"day");
         }
         if (flag)
            printf("No facts are deducible.\n");
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
