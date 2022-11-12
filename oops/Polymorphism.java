package oops;

class Animal {
    void speak() {
        System.out.println("Animal says.");
    }
}

class Dog extends Animal {
    void speak() {
        System.out.println("Dog barks.");
    }
}

class Sha {
    int area(int l, int b) {
        return l * b;
    }
    
    double area(double r) {
        return Math.PI * Math.pow(r, 2);
    }
}

public class Polymorphism {
    public static void main(String[] args) {
        // compile time polymorphism, using method overloading.
        Sha shape = new Sha();
        System.out.println("Area of circle: " + shape.area(5.0));
        System.out.println("Area of circle: " + shape.area(5, 2));

        // runtime polymorphism, here when we call the speak methods, so it is decided
        // at runtime which method to call.
        Animal animal1 = new Animal();
        Animal animal2 = new Dog();

        animal1.speak();
        animal2.speak();
    }
}
