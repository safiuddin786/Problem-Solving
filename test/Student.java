package test;

import java.io.*;
import java.util.*;
import java.util.Scanner;

public class Student implements Serializable {

    private static final long serialVersionUID = 1L;
    public HashMap<Integer, List<Integer>> details;

    public Student() throws FileNotFoundException {
        details = new HashMap<>();
        Scanner sc = new Scanner(new File("data.csv"));
        sc.useDelimiter(","); // sets the delimiter pattern
        int i = 0;
        List<Integer> ls;
        while (sc.hasNext()) // returns a boolean value
        {
            System.out.print(sc.next()); // find and returns the next complete token from this scanner
        }
        sc.close(); // closes the scanner
    }

}