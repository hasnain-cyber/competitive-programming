// write a java program to create an array, and convert it to list
// and then add an element to the list and print the list

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class test {
    public static void main(String[] args) {
        String[] arr = {"a", "b", "c"};
        List<String> list = new ArrayList<>(Arrays.asList(arr));
        list.add("d");
        System.out.println(list);
    }
}