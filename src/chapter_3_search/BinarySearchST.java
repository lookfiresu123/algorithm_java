package chapter_3_search;

import chapter_1.BinarySearch;

/**
 * Created by lookfiresu on 16-3-21.
 */
public class BinarySearchST<Key extends Comparable<Key>, Value> {
    private Key[] keys;
    private Value[] vals;
    private int N;

    // 构造函数
    public BinarySearchST(int capacity) {
        keys = (Key[]) new Comparable[capacity];
        vals = (Value[]) new Comparable[capacity];
    }

    // 返回键值对数量
    public int size() {
        return N;
    }

    // 基于有序数组的二分查找（迭代），返回key所在的位置，或key该插入的位置
    public int rank(Key key) {
        int lo = 0, hi = N-1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cmp = key.compareTo(keys[mid]);
            if (cmp < 0)        // 若key < keys[mid]，则取右半部分
                hi = mid - 1;
            else if (cmp > 0)   // 若key < keys[mid]，则取左半部分
                lo = mid + 1;
            else    // 若key == keys[mid]，则返回mid
                return mid;     // 返回key所在的位置
        }
        return lo;  // 返回key该插入的位置
    }

    // 判断是否为空
    public boolean isEmpty() {
        return size() == 0;
    }

    // keys是否为full
    public boolean isFull() {
        return N == keys.length;
    }

    // 获得给定键的值
    public Value get(Key key) {
        if (isEmpty())
            return null;
        int pos = rank(key);
        if (pos < N && keys[pos].compareTo(key) == 0)   // 若key存在，则返回对应的值
            return vals[pos];
        else
            return null;
    }

    // 查找键，找到则更新值，否则创建新值
    public void put(Key key, Value val) {
        int pos = rank(key);
        if (pos < N && keys[pos].compareTo(key) == 0)   // 若key存在，则更新值
            vals[pos] = val;
        else {
            // keys是否为full
            if (isFull()) {
                System.out.println("the table is full");
                return;
            }
            // 后移后面的键值对并将N+1
            for (int i = N ; i > pos ; i--) {
                keys[i] = keys[i-1];
                vals[i] = vals[i-1];
            }
            keys[pos] = key;
            vals[pos] = val;
            N++;
        }
    }

    // 删除给定的键值对
    public void delete(Key key) {
        int pos = rank(key);
        if (pos < N && keys[pos].compareTo(key) == 0) {
            // 前移后面的键值对，并将N-1
            for (int i = pos ; i < N-1 ; i++) {
                keys[i] = keys[i+1];
                vals[i] = vals[i+1];
            }
            N--;
        }
    }

    // 输出所有键值对
    public void print() {
        for (int i = 0 ; i < N ; i++)
            System.out.println(keys[i] + " " + vals[i]);
    }

    // 返回最小键
    public Key min() {
        if (! isEmpty())
            return keys[0];
        return null;
    }

    // 返回最大键
    public Key max() {
        if (! isEmpty())
            return keys[N-1];
        return null;
    }

    // 返回指定位置的键
    public Key select(int k) {
        return keys[k];
    }

}
