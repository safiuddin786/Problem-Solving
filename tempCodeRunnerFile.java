class Animal{
    void sum(int a, int b){
        System.out.println("This is parent class "+(a+b));
    }
}
class Dog extends Animal{
    void sum(int a, int b){
        System.out.println("This is child class "+ (a+b));
    }
    void multiplier(int a, int b){
        System.out.println(a*b);
    }
    void multiplier(int a){
        System.out.println(a*10);
    }
}
public class Mujeeb{
    public static void main(String args[]){
        Animal a1 = new Animal();
        a1.sum(10,20);
        Animal a2 = new Dog();
        a2.sum(10,40);
        Dog d1 = new Dog();
        d1.multiplier(10,20);
        d1.multiplier(10);
    }
}