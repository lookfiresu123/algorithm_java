package chapter_3_search;
import java.util.Random;

/**
 * Created by lookfiresu on 16-3-21.
 */
public class Test {
    public static void main(String[] args) {
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        Comparable[] keys = {"google","yahoo","apple","microsoft","facebook"};
        Comparable[] values = new Integer[keys.length];
        int n = keys.length;
        for (int i = 0 ; i < n ; i++)
            values[i] = random.nextInt(n);
        SequentialSearchST<Comparable, Comparable> st = new SequentialSearchST<Comparable, Comparable>();
        for (int i = 0 ; i < n ; i++)
            st.put(keys[i], values[i]);
        // st.print();
        System.out.println("the value of google is : " + st.get("google"));
        System.out.println("the size of st is : " + st.size());
    }
}
