/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String[] args) throws Exception
    {
        Scanner in=new Scanner(System.in);
        int test=0;
        while (true)
        {
            BigInteger a,b;
            a=in.nextBigInteger();
            b=in.nextBigInteger();
            if (a.compareTo(BigInteger.ZERO)==0 && b.compareTo(BigInteger.ZERO)==0)
                break;
            test++;
            System.out.println("Case "+test+":");
            System.out.println(a+" / "+b);
            BigInteger ans[]=new BigInteger[100];
            int n=0;
            while (true)
            {
                n++;
                ans[n]=a.divide(b);
                BigInteger tmp;
                tmp=b;
                b=a.remainder(b);
                a=tmp;
                if (b.compareTo(BigInteger.ZERO)==0)
                {
                    ans[n]=ans[n].subtract(BigInteger.ONE);
                    ans[++n]=BigInteger.ONE;
                    break;
                }
            }
            int len[]=new int[100];
            len[n]=ans[n].toString().length();
            for (int i=n-1;i>=1;i--)
                len[i]=len[i+1]+3+ans[i].toString().length();
            for (int i=1;i<n;i++)
            {
                int pos=(len[i+1]+1)/2+len[1]-len[i+1];
                for (int j=1;j<=len[1];j++)
                    if (j==pos)
                        System.out.print('1');
                    else
                        System.out.print('.');
                System.out.println();
                for (int j=1;j<=len[1]-len[i];j++)
                    System.out.print('.');
                System.out.print(ans[i]+".+.");
                for (int j=1;j<=len[i+1];j++)
                    System.out.print("-");
                System.out.println();
            }
            for (int i=1;i<len[1];i++)
                System.out.print('.');
            System.out.println("1");
        }
    }
}
*/
int main(){}

