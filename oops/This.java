package oops;

class Demo {
    private int value1;
    private int value2;

    Demo(int value1) {
        this.value1 = value1;
        // do some tasks after assigning the value1.
    }

    Demo(int value1, int value2) {
        // reusing the previous constructor, called constuctor chaining.
        this(value1);

        this.value2 = value2;
    }
}

public class This {
    public static void main(String[] args) {
        Demo demo = new Demo(10, 12);
    }
}
