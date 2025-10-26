import java.security.MessageDigest;
import java.util.HexFormat;
import java.util.Scanner;

public class md5 {
    static Scanner s = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        System.out.println("Enter input data: ");
        String data = s.nextLine();
        MessageDigest md = MessageDigest.getInstance("MD5");
        System.out.println("Message digest object info: ");
        System.out.println("Algorithm = " + md.getAlgorithm());
        System.out.println("ToString = " + md.toString());
        md.update(data.getBytes());
        System.out.println("MD5\"" + data + "\"=" + HexFormat.of().formatHex(md.digest()));        
    }
}
