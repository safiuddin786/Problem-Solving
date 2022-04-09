import java.util.*;

class SListIterator<T> {
    public SList<T> head;

}

class SList<T> {
    public T data;
    public SList<T> next;

    SListIterator<T> listIterator() {
        return new SListIterator<T>();
    }
}

public class JavaAssignment10 {
    public static void main(String[] args) {
        // SList<Integer> myList = new SList<Integer>();
        // SListIterator<Integer> myIterator = myList.listIterator();
        List<String> names = new LinkedList<>();
        names.add("Welcome");
        names.add("To");
        names.add("Gfg");

        List<String> names2 = new LinkedList<>();
        names2.add("ikram");
        names2.add("safi");
        names2.add("azam");
        // Getting ListIterator
        ListIterator<String> namesIterator = names.listIterator();

        // Traversing elements
        while (namesIterator.hasNext()) {
            System.out.println(namesIterator.next());
        }
        System.out.println("in list 2");
        namesIterator = names2.listIterator();
        while (namesIterator.hasNext()) {
            System.out.println(namesIterator.next());
        }
        namesIterator = names.listIterator();
        names.add("java");
        names.add("fun");
        while (namesIterator.hasNext()) {
            System.out.println(namesIterator.next());
        }

    }
}