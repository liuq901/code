/*
ID: liuq9011
LANG: C++
TASK: preface
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
const char g[10][10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
const char s[10][10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const char b[10][10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const char q[4][10]={"","M","MM","MMM"};
int a[26];
int main()
{
   in=fopen("preface.in","r");
   out=fopen("preface.out","w");
   void find(int);
   int i,n;
   int ans[2][10];
   fscanf(in,"%d",&n);
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
      find(i);
   ans[0][1]=a['I'-'A'];
   ans[1][1]='I';
   ans[0][2]=a['V'-'A'];
   ans[1][2]='V';
   ans[0][3]=a['X'-'A'];
   ans[1][3]='X';
   ans[0][4]=a['L'-'A'];
   ans[1][4]='L';
   ans[0][5]=a['C'-'A'];
   ans[1][5]='C';
   ans[0][6]=a['D'-'A'];
   ans[1][6]='D';
   ans[0][7]=a['M'-'A'];
   ans[1][7]='M';
   for (i=1;i<=7;i++)
      if (ans[0][i]!=0)
         fprintf(out,"%c %d\n",ans[1][i],ans[0][i]);
   fclose(in),fclose(out);
   return(0);
}
void find(int x)
{
   int i,k;
   k=x/1000;
   x%=1000;
   for (i=0;i<strlen(q[k]);i++)
         a[q[k][i]-'A']++;
   k=x/100;
   x%=100;
   for (i=0;i<strlen(b[k]);i++)
         a[b[k][i]-'A']++;
   k=x/10;
   x%=10;
   for (i=0;i<strlen(s[k]);i++)
         a[s[k][i]-'A']++;
   for (i=0;i<strlen(g[x]);i++)
         a[g[x][i]-'A']++;
}
