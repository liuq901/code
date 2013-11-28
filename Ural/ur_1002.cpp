#include <cstdio>
#include <cstdlib>
#include <cstring>
const int m[26]={2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0};
char a[50001][51];
int c[101][2];
int main()
{
   void print(int);
   char b[101],s[50001];
   int i,j,k,n,l,t,min,len,flag;
   int f[101];
   while(1)
   {
      b[0]='0';
      scanf("%s",b+1);
      if (strcmp(b+1,"-1")==0) 
         break;
      scanf("%d",&n);
      len=101;
      for (i=1;i<=n;i++) 
      {
         scanf("%s",a[i]);
         s[i]=strlen(a[i]);
         if(s[i]<len) len=s[i];
      }
      t=strlen(b)-1;
      if (len>t)
      {
         printf("No solution.\n");
         continue;
      }
      memset(f,-1,sizeof(f));
      f[0]=0;
      for (i=len;i<=strlen(b)-1;i++)
      {
         min=1000;
         for (j=1;j<=n;j++)
         {
            if (s[j]<=i && m[a[j][s[j]-1]-'a']+'0'==b[i] && f[i-s[j]]>=0)
            {
               flag=0;                                                   
               for (k=i;k>=i-s[j]+1;k--)
               {
                  if (b[k]!=m[a[j][s[j]-i+k-1]-'a']+'0') 
                  {
                     flag=1;
                     break;
                  }
               }
               if (flag==0 && f[i-s[j]]+1<min) 
               {
                  min=f[i-s[j]]+1;
                  l=j;
               }
            }
         }
         f[i]=min;
         if (f[i]==1000) 
            f[i]=-1;
         else 
         {
            c[i][0]=i-s[l];
            c[i][1]=l;
         }
      }
      if (f[strlen(b)-1]==-1) 
         printf("No solution.\n");
      else 
      {
         print(strlen(b)-1);
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
void print(int t)
{
   if (t<1) 
      return;
   print(c[t][0]);
   printf("%s ",a[c[t][1]]);
}
