import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class j17_FileHandling {

    public static boolean isPalindrome(String word) {
        word = word.toLowerCase();

        int i = 0, j = word.length() - 1;

        while (i < j) {
            if (word.charAt(i) != word.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    public static int countPal(String fileName) {
        int count = 0;

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;

            while ((line = br.readLine()) != null) {
                String[] words = line.split("\\s+");

                for (String word : words) {
                    // clean word properly using regex
                    word = word.replaceAll("[^a-zA-Z]", "");

                    if (word.length() > 0 && isPalindrome(word)) {
                        count++;
                    }
                }
            }

        } catch (IOException e) {
            System.out.println("Error reading file");
            return -1;
        }

        return count;
    }

    public static void main(String[] args) {
        int count = countPal("j17_file.txt");
        System.out.println(count);
    }
}
