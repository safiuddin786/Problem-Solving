import java.io.*;
import java.util.*;

class Student {
    int regno;
    int marks[];
    double average;

    Student(int regno, int marks[]) {
        this.average = 0;
        this.regno = regno;
        marks = new int[5];
        this.marks[0] = marks[0];
        this.marks[1] = marks[1];
        this.marks[2] = marks[2];
        this.marks[3] = marks[3];
        this.marks[4] = marks[4];
        for (int i = 0; i < 5; i++) {
            this.average += marks[i];
        }
        this.average = this.average / 5;
        Students s = new Students(this);
    }
}

class Students {
    public static Student students[];
    int pos = 0;

    Students() {
    }

    Students(Student s) {
        if (pos == 0) {
            students = new Student[10];
            students[pos] = s;
        } else {
            students[pos] = s;
        }
        pos++;
    }
}

class MultiThread implements Runnable {
    int type;

    MultiThread(int type) {
        this.type = type;
    }

    public void run() {
        try {
            Students s = new Students();
            Student students[] = s.students;
            if (type == 1) {
                // class average for each course
                for (int i = 0; i < 5; i++) {
                    double average = 0;
                    for (int j = 0; j < students.length; j++) {
                        average += students[j].marks[i];
                    }
                    average = average / 5;
                    System.out.println("average marks of subject" + (i + 1) + ": " + average);
                }
            } else if (type == 2) {
                // class average for each student
                for (int i = 0; i < students.length; i++) {
                    double average = 0;
                    for (int j = 0; j < 5; j++) {
                        average += students[i].marks[j];
                    }
                    average = average / 5;
                    System.out.println("average marks of student" + (i + 1) + ": " + average);
                }
            } else {
                // class average for each course
                for (int i = 0; i < 5; i++) {
                    int max = -1;
                    int min = 99999;
                    for (int j = 0; j < students.length; j++) {
                        if (max < students[j].marks[i])
                            max = students[j].marks[i];
                        if (min > students[j].marks[i])
                            min = students[j].marks[i];
                    }
                    System.out.println("min of subject" + (i + 1) + ": " + min);
                    System.out.println("max of subject" + (i + 1) + ": " + max);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class StudentT {
    public static void main(String args[]) {
        try {
            Scanner s = new Scanner(System.in);
            for (int i = 0; i < 10; i++) {
                int regno = s.nextInt();
                int[] marks = new int[5];
                marks[0] = s.nextInt();
                marks[1] = s.nextInt();
                marks[2] = s.nextInt();
                marks[3] = s.nextInt();
                marks[4] = s.nextInt();
                Student student = new Student(regno, marks);
            }
            Runnable r = new MultiThread(1);
            Runnable r1 = new MultiThread(2);
            Runnable r2 = new MultiThread(3);
            new Thread(r).start();
            new Thread(r1).start();
            new Thread(r2).start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}