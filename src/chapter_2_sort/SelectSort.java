package chapter_2_sort;

/**
 * Created by lookfiresu on 16-2-2.
 */

// 选择排序：每轮都选择余下序列中最小值放到序列的最前面
public class SelectSort extends BaseSort{
    public static void sort(Comparable[] a) {
        int N = a.length;
        for (int i = 0 ; i < N ; ++i) {
            int min = i;
            for (int j = i+1 ; j < N ; ++j)
                if (less(a[j], a[min]))
                    min = j;
            exch(a, min, i);
        }
    }
}
