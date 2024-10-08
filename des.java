import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;
import java.util.Scanner;
public class des{
public static void main(String[] args){
  Scanner sc=new Scanner(System.in);
  System.out.println("Enter the message: ");
  String originalData=sc.nextLine();
  SecretKey key=KeyGenerator.getInstance("DES").generateKey();
  String encryptedData=encryptData(originalData,key);
  System.out.println("Encrypted Data: "+encryptedData);
  String decryptedData=decryptData(encryptedData,key);
  System.out.println("Decrypted Data: "+decryptedData);
  sc.close();
}
private static String encryptData(String data,SecretKey key){
  Cipher cipher=Cipher.getInstance("DES");
  cipher.init(Cipher.ENCRYPT_MODE,key);
  return Base64.getEncoder().encodeToString(cipher.doFinal(data.getBytes()));
}
private static String decryptData(String encryptedData,SecretKey key){
  Cipher cipher=Cipher.getInstance("DES");
  cipher.init(Cipher.DECRYPT_MODE,key);
  return new String(cipher.doFinal(Base64.getDecoder().decode(encryptedData)));
}
}
