package chapter_2_sort;

/**
 * Created by lookfiresu on 16-2-2.
 */
public class InsertSort extends BaseSort{
    public static void sort(Comparable[] a) {
        int N = a.length;
        for (int i = 0 ; i < N ; ++i)
            for (int j = i ; j > 0 && less(a[j], a[j-1]) ; --j)
                exch(a, j, j-1);
    }

    public static void sort_advanced(Comparable[] a) {
        int N = a.length;
        Comparable temp;
        for (int i = 0 ; i < N ; ++i) {
            temp = a[i];
            int j;
            for (j = i ; j > 0 && less(temp, a[j-1]) ; --j)    // 从后往前迭代，这样最省时间
                a[j] = a[j-1];    // 使用后移代替交换，这样可以减少访问数组的次数
            a[j] = temp;
        }
    }
}
