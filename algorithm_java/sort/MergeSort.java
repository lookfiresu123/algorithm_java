package chapter_2_sort;

/**
 * Created by lookfiresu on 16-2-23.
 */
/* 自顶向下归并排序 */
public class MergeSort extends BaseSort {
    private static Comparable[] aux;    // 归并所需的辅助数组

    // 原地归并算法
    public static void merge(Comparable[] a, int lo, int mid, int hi) {
        // 将a[lo:mid]和a[mid+1:hi]归并
        int i = lo, j = mid+1;
        for (int k = lo ; k <= hi ; k++)    // 将a[lo:hi]复制到aux[lo:hi]
            aux[k] = a[k];
        for (int k = lo ; k <= hi ; k++) {
            if (i > mid)    // 若aux[lo:mid]已归并结束，则将aux[mid+1:hi]的剩余部分逐一归并到a中
                a[k] = aux[j++];
            else if (j > hi)    // 若aux[mid+1:hi]已归并结束，则将aux[lo:mid]的剩余部分逐一归并到a中
                a[k] = aux [i++];
            else if (less(aux[j], aux[i]))  // 若aux[j]小于aux[i]，则将aux[j]拷贝到a[k]中，并将a[j+1]加入下次比较
                a[k] = aux[j++];
            else    // 若aux[i]不大于aux[j]，则将aux[i]拷贝到a[k]中，并将a[i+1]加入下次比较
                a[k] = aux[i++];
        }
    }

    public static void sort(Comparable[] a, int lo, int hi) {
        // 将数组a[lo:hi]排序
        if (hi <= lo)   // 若当前数组只有一个元素或为空，则不做任何操作
            return;
        int mid = lo + (hi - lo)/2; // 数组a[lo:mid]和a[mid+1:hi]是相邻且连续的
        sort(a, lo, mid);   // 使用归并排序算法将左半边数组a[lo:mid]排序
        sort(a, mid+1, hi); // 使用归并排序算法将右半部数组a[mid:hi]排序
        merge(a, lo, mid, hi);  // 归并已排序子数组a[lo:mid]和a[mid+1:hi]
    }

    public static void sort(Comparable[] a) {
        aux = new Comparable[a.length];     // 一次性分配空间
        sort(a, 0, a.length-1);
    }
}
