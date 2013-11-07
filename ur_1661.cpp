/*
Java:
import java.io.*;
import java.math.*;
import java.util.*;
public class Main
{
    int a[]=new int[40];
    BigInteger factor[]=new BigInteger[40];
    public static void main(String args[])
    {
        new Main().run();
    }
    void run()
    {
        Scanner in=new Scanner(System.in);
        factor[0]=BigInteger.ONE;
        for (int i=1;i<=30;i++)
        {
            int x=in.nextInt();
            a[x]++;
            factor[i]=factor[i-1].multiply(BigInteger.valueOf(i));
        }
        BigInteger ans=BigInteger.ZERO;
        for (int i=1;i<=30;i++)
        {
            if (a[i]==0)
                continue;
            a[i]--;
            for (int j=1;j<=30;j++)
            {
                if (a[j]==0)
                    continue;
                a[j]--;
                ans=ans.add(calc(2,14,15));
                a[j]++;
            }
            a[i]++;
        }
        ans=ans.add(calc(1,30,1)).add(calc(5,6,24)).add(calc(3,10,20));
        System.out.println(ans.divide(BigInteger.valueOf(60)));
    }
    BigInteger calc(int x,int y,int z)
    {
        for (int i=1;i<=30;i++)
            if (a[i]%x!=0)
                return(BigInteger.ZERO);
        for (int i=1;i<=30;i++)
            a[i]/=x;
        BigInteger ret=factor[y];
        for (int i=1;i<=30;i++)
            ret=ret.divide(factor[a[i]]);
        for (int i=1;i<=30;i++)
            a[i]*=x;
        return(ret.multiply(BigInteger.valueOf(z)));
    }
}
*/
int main(){}

