package chapter_3_search;

import javax.xml.soap.Node;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by lookfiresu on 16-3-21.
 */
public class SequentialSearchST<Key, Value> {
    private Node first;     // 链表首结点
    private int N;          // 键值对数量

    // 链表结点的定义
    private class Node {
        Key key;
        Value val;
        Node next;

        public Node(Key key, Value val, Node next) {
            this.key = key;
            this.val = val;
            this.next = next;
        }
    }

    // 查找给定键的值并返回
    public Value get(Key key) {
        for (Node x = first ; x != null ; x = x.next)
            if (key.equals(x.key))
                return x.val;   // 命中
        return null;    // 未命中
    }

    // 查找给定的键，找到则更新其值，否则在表中新建结点
    public void put(Key key, Value val) {
        for (Node x = first ; x != null ; x = x.next) {
            if (key.equals(x.key)) {
                x.val = val;
                return;
            }
        }
        first = new Node(key, val, first);  // 未命中，则在头部新建结点
        N++;
    }

    // 返回表中键值的对数
    public int size() {
        return N;
    }

    // 返回表中所有键的集合
    public Iterable<Key> keys()  {
        Queue<Key> queue = new LinkedList<Key>();
        for (Node x = first; x != null; x = x.next)
            queue.add(x.key);
        return queue;
    }

    // 从表中删除键key
    public void delete(Key key) {
        if (key == null)
            throw new NullPointerException("argument to delete() is null");
        first = delete(first, key);
    }

    private Node delete(Node x, Key key) {
        if (x == null)
            return null;
        if (key.equals(x.key)) {    // 在链表首部
            N--;
            return x.next;
        }
        x.next = delete(x.next, key);   // 递归查找
        return x;
    }

    public void print() {
        for (Node x = first ; x != null ; x = x.next)
            System.out.println(x.key + " " + x.val);
    }
}
