package oops;

abstract class Shape {
    abstract void tell();
}

class Circle extends Shape {
    void tell() {
        System.out.println("I am a circle.");
    }
}

public class Abstract {
    public static void main(String[] args) {

        // cannot create an object of shape class, as it is abstract, the idea is to
        // keep the class as generic as possible but, at the same time, define all the
        // necessary functionality, so that it's children can be implemented wrt them.
        
        // Shape shape = new Shape();
        Circle circle = new Circle();
        circle.tell();
    }
}