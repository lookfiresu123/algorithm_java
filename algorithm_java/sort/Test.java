package chapter_2_sort;

import java.util.Random;

/**
 * Created by lookfiresu on 16-2-2.
 */
public class Test {
    private static void HeapCopy(Comparable[] a, Comparable[] b) {
        int n = a.length;
        for (int i = 0 ; i < n ; i++)
            b[i+1] = a[i];
    }

    private static void HeapRecovery(Comparable[] a, Comparable[] b) {
        int n = a.length;
        for (int i = 0 ; i < n ; i++)
            a[i] = b[i+1];
    }

    private static void HeapSortHelper(Comparable[] a) {
        Comparable[] b = new Comparable[a.length+1];
        HeapCopy(a, b);
        HeapSort hs = new HeapSort();
        hs.sort(b);
        HeapRecovery(a, b);
    }

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
        // QuickSort.sort(a);
        HeapSortHelper(a);
        assert BaseSort.isSorted(a);
        BaseSort.show(a);
    }
}
