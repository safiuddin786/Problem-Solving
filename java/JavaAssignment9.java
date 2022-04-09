import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class JavaAssignment9 {
    public static void main(String[] args) throws FileNotFoundException {
        StringBuilder str;
        Scanner sc = new Scanner(new File("javaRead.txt"));
        while (sc.hasNext()) {
            str = new StringBuilder("");
            while (sc.hasNext()) {
                String s = sc.next();
                if (s.endsWith(".")) {
                    str.append(s + " ");
                    System.out.println(str);
                    break;
                } else {
                    str.append(s + " ");
                }
            }
            System.out.println(Pattern.compile("^[A-Z].*.$").matcher(str).matches());

        }
    }
}
