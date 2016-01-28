package chapter_1;

/**
 * Created by lookfiresu on 16-1-26.
 */
import java.lang.*;
import java.util.*;
import java.math.*;

public class BinarySearch {
    public static int rank(int key, int[] a) {
        // 数组必须是有序的
        int left = 0, right = a.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;    // 这里不能用 int mid = (left + right) / 2;
            if (key < a[mid])
                right = mid - 1;    // 取左半部分
            else if (key > a[mid])
                left = mid + 1;     // 取右半部分
            else
                return mid;
        }
        return -1;
    }

    public static void main(String[] args) {
        int N = 50;
        int[] a = new int[N];
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        // 产生N个随机数
        for (int i = 0 ; i < N ; ++i)
            a[i] = random.nextInt(N);
        Arrays.sort(a);     // 将数组a按升序排序
        int key = random.nextInt(N);    // 产生关键值
        int result = rank(key, a);    // 排序
        if (result == -1)
            System.out.println("miss this number " + key);
        else
            System.out.println("get this number " + key);
    }
}
