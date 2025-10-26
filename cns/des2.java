import java.util.Scanner;
import javax.crypto.*;

public class des2 {
    static Scanner s = new Scanner(System.in);
    private static Cipher cipher;
    private static byte[] encrypt(String data, SecretKey key1, SecretKey key2, int flag) throws Exception {
        String algo = (flag == 2) ? "DESede" : "DES";
        cipher = Cipher.getInstance(algo + "/ECB/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE, key1);
        byte[] encrypted = cipher.doFinal(data.getBytes());

        if (flag == 1) {
            cipher.init(Cipher.ENCRYPT_MODE, key2);
            encrypted = cipher.doFinal(encrypted);
        }
        System.out.println("Encrypted: " + new String(encrypted));
        return encrypted;
    }

    private static String decrypt(byte[] data, SecretKey key1, SecretKey key2, int flag) throws Exception {
        String algo = (flag == 2) ? "DESede" : "DES";
        byte[] decrypted;
        cipher = Cipher.getInstance(algo + "/ECB/PKCS5Padding");
        if(flag == 1) {
            cipher.init(Cipher.DECRYPT_MODE, key2);
            decrypted = cipher.doFinal(data);
        } else {
            decrypted = data;
        }
        cipher.init(Cipher.DECRYPT_MODE, key1);
        decrypted = cipher.doFinal(decrypted);
        System.out.println("Decrypted: " + new String(decrypted));
        return new String(decrypted);
    }

    public static void main(String[] args) {
        try {
            System.out.println("Enter plaintext: ");
            String data = s.nextLine();
            System.out.println("Enter 1 for 2DES or 2 for 3DES");
            int flag = s.nextInt();
            KeyGenerator keygen = KeyGenerator.getInstance((flag == 2)?"DESede":"DES");
            SecretKey key1 = keygen.generateKey();
            SecretKey key2 = keygen.generateKey();
            byte[] encrypted = encrypt(data, key1, key2, flag);
            decrypt(encrypted, key1, key2, flag);   
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
