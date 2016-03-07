package chapter_2_sort;

import java.util.Random;

/**
 * Created by lookfiresu on 16-2-2.
 */
public class Test {
    public static void main(String[] args) {
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        int n = 50;
        Comparable[] a = new Comparable[n];
        for (int i = 0 ; i < n ; ++i)
            a[i] = random.nextInt(n);
        BaseSort.show(a);
        // SelectSort.sort(a);
        // InsertSort.sort_advanced(a);
        // ShellSort.sort(a);
        // MergeSort.sort(a);
        // MergeBUSort.sort(a);
        QuickSort.sort(a);
        assert BaseSort.isSorted(a);
        BaseSort.show(a);
    }
}
