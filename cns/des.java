import javax.crypto.*;
import java.util.*;

public class des {
    static Scanner s = new Scanner(System.in);
    private static Cipher cipher;

    private static byte[] encrypt(String data) throws Exception{
        byte[] encrypted = cipher.doFinal(data.getBytes());
        System.out.println(encrypted);
        return encrypted;
    }

    private static byte[] decrypt(byte[] data) throws Exception {
        byte[] decrypted = cipher.doFinal(data);
        System.out.println(new String(decrypted));
        return decrypted;
    }

    public static void main(String[] args) {
        try {
            String data = s.nextLine();
            KeyGenerator keygen = KeyGenerator.getInstance("DES");
            SecretKey key = keygen.generateKey();
            cipher = Cipher.getInstance("DES");
            cipher.init(Cipher.ENCRYPT_MODE, key);
            byte[] encrypted = encrypt(data);
            cipher.init(Cipher.DECRYPT_MODE, key);
            decrypt(encrypted);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
