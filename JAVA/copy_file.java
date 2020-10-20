import java.io.FileInputStream;
import java.io.FileOutputStream;

class Main {
  public static void main(String[] args) {

    byte[] array = new byte[50];
    try {
      FileInputStream sourceFile = new FileInputStream("input.txt");
      FileOutputStream destFile = new FileOutputStream("newFile");

      // reads all data from input.txt
      sourceFile.read(array);

      // writes all data to newFile
      destFile.write(array);
      System.out.println("The input.txt file is copied to newFile.");

      // closes the stream
      sourceFile.close();
      destFile.close();
    }
    catch (Exception e) {
      e.getStackTrace();
    }
  }
}
