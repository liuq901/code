/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String args[]) throws Exception
    {
        BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer=new PrintWriter(System.out);
        String tmp=reader.readLine();
        int T=Integer.parseInt(tmp);
        while (T-->0)
        {
            int n=0;
            BigDecimal a[]=new BigDecimal[100+10];
            while (true)
            {
                tmp=reader.readLine();
                if (tmp.equals("0"))
                    break;
                a[++n]=new BigDecimal(tmp);
            }
            BigDecimal ans=BigDecimal.ZERO;
            for (int i=1;i<=n;i++)
                ans=ans.add(a[i]);
            if (ans.signum()==0)
                ans=BigDecimal.ZERO;
            writer.println(ans.stripTrailingZeros().toPlainString());
        }
        reader.close();
        writer.close();
    }
}
*/
int main(){}

