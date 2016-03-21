package chapter_3_search;

import java.security.Key;
import java.util.Random;

/**
 * Created by lookfiresu on 16-3-21.
 */
public class Test {
    public static void test_SequentialSearchST(Comparable[] keys, Comparable[] values) {
        SequentialSearchST<Comparable, Comparable> st = new SequentialSearchST<Comparable, Comparable>();
        int n = keys.length;
        for (int i = 0 ; i < n ; i++)
            st.put(keys[i], values[i]);
        // st.print();
        System.out.println("the value of google is : " + st.get("google"));
        System.out.println("the size of st is : " + st.size());
    }

    public static void test_BinarySearchST(String[] keys, Integer[] values) {
        int capacity = 10;
        BinarySearchST<String, Integer> st = new BinarySearchST<String, Integer>(capacity);
        int n = keys.length;
        for (int i = 0 ; i < n ; i++)
            st.put(keys[i], values[i]);
        // st.print();
        System.out.println("the value of google is : " + st.get("google"));
        System.out.println("the size of st is : " + st.size());
    }

    public static void main(String[] args) {
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        String[] keys = {"google","yahoo","apple","microsoft","facebook"};
        Integer[] values = new Integer[keys.length];
        int n = keys.length;
        for (int i = 0 ; i < n ; i++)
            values[i] = random.nextInt(n);
        // test_SequentialSearchST(keys, values);
        test_BinarySearchST(keys, values);
    }
}
