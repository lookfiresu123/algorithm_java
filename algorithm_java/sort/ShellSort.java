package chapter_2_sort;

/**
 * Created by lookfiresu on 16-2-14.
 */
public class ShellSort extends BaseSort{
    public static void sort(Comparable[] a) {
        int N = a.length;
        // 预处理h，使h = max{x | x mod 3 = 1 且 x < N}
        int h = 1;
        while (h < N/3)
            h = 3 * h + 1;
        while (h >= 1) {
            for (int i = h ; i < N ; i++)
                for (int j = i ; j >= h && less(a[j], a[j-h]) ; j -= h)
                    exch(a, j, j-h);
            h = h / 3;
        }
    }
}
