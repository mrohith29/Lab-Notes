import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class substitution_cipher {
    static Scanner sc = new Scanner(System.in);
    static BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));

    public static void main(String[] args) throws IOException
    {
        String encrypt = encrypt();
        String decrypt = decrypt(encrypt);
        System.out.println("The encrypted data is: " +encrypt);
        System.out.println("The decrypted data is: " +decrypt);
    }
    
    public static String encrypt() throws IOException
    {
        String encrypt = "";
        String a = "abcdefghijklmnopqrstuvwxyz";
        String b = "zyxwvutsrqponmlkjihgfedcba";
        System.out.print("Enter any string: ");
        String str = br.readLine();
        char c;
        for(int i=0;i<str.length();i++)
        {
            c = str.charAt(i);
            int j = a.indexOf(c);
            encrypt = encrypt+b.charAt(j);
        }

        return encrypt;
    }

    public static String decrypt(String encrypt)
    {
        String a = "abcdefghijklmnopqrstuvwxyz";
        String b = "zyxwvutsrqponmlkjihgfedcba";
        String decrypt = "";
        char c;
        for(int i=0;i<encrypt.length();i++) {
            c = encrypt.charAt(i);
            int j = a.indexOf(c);
            decrypt = decrypt+b.charAt(j);
        }
        return decrypt;
    }
}
