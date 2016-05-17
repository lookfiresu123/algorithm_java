package chapter_2_sort;

/**
 * Created by lookfiresu on 16-3-7.
 */
public class QuickSort extends BaseSort {
    private static int partition(Comparable[] a, int lo, int hi) {
        // 将数组切分为a[lo : fixed_position-1], a[fixed_position], a[fixed_position+1 : hi]
        int i = lo, j = hi+1;
        Comparable v = a[i];    // 设置v为某个数（作为分堆标准）
        while (true) {
            // 用i从左到右扫描数组，用j从右到左扫描数组，因此分堆
            while (less(a[++i], v)) if (i == hi) break;     // 从i开始找到第一个不小于v的数
            while (less(v, a[--j])) if (j == lo) break;     // 从j开始找到第一个小于v的数
            if (i >= j) break;
            exch(a, i, j);  // 交换a[i],a[j]，用于将小的放入小堆，将大的放入大堆
        }
        exch(a, lo, j); // 将a[fixed_position]放到索引fixed_position中
        return j;
    }

    private static void sort(Comparable[] a, int lo, int hi) {
        if (lo < hi) {
            int fixed_position = partition(a, lo, hi);  // 分堆，左边是全部小于某个数，右边全部大于某个数
            sort(a, lo, fixed_position-1);  // 排序左边的子数组
            sort(a, fixed_position+1 ,hi);  // 排序右边的子数组
        }
    }

    public static void sort(Comparable[] a) {
        StdRandom.shuffle(a);   // 随机打乱数组a，消除输入的影响
        sort(a, 0, a.length-1);
    }
}
