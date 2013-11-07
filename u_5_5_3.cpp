/*
ID: liuq9011
LANG: C++
TASK: twofive
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int maxc[5],maxr[5],used[26],nways[6][6][6][6][6];
int main()
{
   in=fopen("twofive.in","r");
   out=fopen("twofive.out","w");
   int stoa(char[]);
   void atos(int,char[]);
   int n;
   char ch;
   char s[27];
   fscanf(in,"%c%*c",&ch);
   if (ch=='W')
   {
      fscanf(in,"%s",s);
      n=stoa(s);
      fprintf(out,"%d\n",n);
   }
   else
   {
      fscanf(in,"%d",&n);
      atos(n,s);
      fprintf(out,"%s\n",s);
   }
   fclose(in),fclose(out);
   return(0);
}
int stoa(char s[])
{
   int cal(int[],int);
   int i,j,tmp,ans;
   int a[26],used[26];
   a[0]=0;
   memset(used,0,sizeof(used));
   used[0]=1;
   ans=0;
   for (i=1;i<25;i++)
   {
      for (j=0;j<s[i]-'A';j++)
         if (!used[j])
         {
            a[i]=j;
            tmp=cal(a,i+1);
            ans+=tmp;
         }
      used[j]=1;
      a[i]=j;
   }
   return(ans+1);
}
void atos(int num,char s[])
{
   int cal(int[],int);
   int i,j,tmp,now;
   int a[26],used[26];
   a[0]=0;
   memset(used,0,sizeof(used));
   used[0]=1;
   s[0]='A';
   now=0;
   for (i=1;i<25;i++)
   {
      for (j=0;j<25;j++)
         if (!used[j])
         {
            s[i]=j+'A';
            a[i]=j;
            tmp=cal(a,i+1);
            if (now+tmp>=num)
               break;
            now+=tmp;
         }
      used[j]=1;
   }
   s[25]='\0';
}
int cal(int a[],int n)
{
   int calc(int,int,int,int,int,int);
   int i,r,c,ans;
   int in[5];
   memset(maxc,-1,sizeof(maxc));
   memset(maxr,-1,sizeof(maxr));
   memset(used,0,sizeof(used));
   memset(nways,0,sizeof(nways));
   memset(in,0,sizeof(in));
   nways[5][5][5][5][5]=1;
   for (i=0;i<n;i++)
   {
      r=i/5;
      c=i%5;
      in[r]++;
      if (a[i]<maxr[r] || a[i]<maxc[c])
         return(0);
      maxr[r]=a[i];
      maxc[c]=a[i];
      used[a[i]]=1;
   }
   ans=calc(in[0],in[1],in[2],in[3],in[4],0);
   return(ans);
}
int calc(int a,int b,int c,int d,int e,int l)
{
   int cur;
   if (nways[a][b][c][d][e])
      return(nways[a][b][c][d][e]);
   if (used[l])
   {
      nways[a][b][c][d][e]=calc(a,b,c,d,e,l+1);
      return(nways[a][b][c][d][e]);
   }
   cur=0;   
   if (a<5 && l>maxr[0] && l>maxc[a])
      cur+=calc(a+1,b,c,d,e,l+1);
   if (a>b && l>maxr[1] && l>maxc[b])
      cur+=calc(a,b+1,c,d,e,l+1);
   if (b>c && l>maxr[2] && l>maxc[c])
      cur+=calc(a,b,c+1,d,e,l+1);
   if (c>d && l>maxr[3] && l>maxc[d])
      cur+=calc(a,b,c,d+1,e,l+1);
   if (d>e && l>maxr[4] && l>maxc[e])
      cur+=calc(a,b,c,d,e+1,l+1);
   nways[a][b][c][d][e]=cur;
   return(cur);
}
