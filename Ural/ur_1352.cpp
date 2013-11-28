#include <cstdio>
int ans[40];
int main()
{
    ans[1]=2;
    ans[2]=3;
    ans[3]=5;
    ans[4]=7;
    ans[5]=13;
    ans[6]=17;
    ans[7]=19;
    ans[8]=31;
    ans[9]=61;
    ans[10]=89;
    ans[11]=107;
    ans[12]=127;
    ans[13]=521;
    ans[14]=607;
    ans[15]=1279;
    ans[16]=2203;
    ans[17]=2281;
    ans[18]=3217;
    ans[19]=4253;
    ans[20]=4423;
    ans[21]=9689;
    ans[22]=9941;
    ans[23]=11213;
    ans[24]=19937;
    ans[25]=21701;
    ans[26]=23209;
    ans[27]=44497;
    ans[28]=86243;
    ans[29]=110503;
    ans[30]=132049;
    ans[31]=216091;
    ans[32]=756839;
    ans[33]=859433;
    ans[34]=1257787;
    ans[35]=1398269;
    ans[36]=2976221;
    ans[37]=3021377;
    ans[38]=6972593;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return(0);
}

