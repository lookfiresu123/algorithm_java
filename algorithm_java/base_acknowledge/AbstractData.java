package chapter_1;

/**
 * Created by lookfiresu on 16-1-30.
 */

import java.awt.geom.Point2D;
import java.lang.*;
import java.util.Random;

public class AbstractData {
    // 直线上的间隔
    private static class Interval1D {
        private double lo;
        private double hi;
        public Interval1D(double x, double y) {
            lo = x;
            hi = y;
        }
        public double length() {
            return Math.abs(hi - lo);
        }
        public boolean contains(double x) {
            return x <= hi && x >= lo;
        }
        public boolean intersect(Interval1D that) {
            double intermid = (lo + (hi - lo)/2) - (that.lo + (that.hi - that.lo)/2);
            intermid = Math.abs(intermid);
            double[] temp = new double[4];
            temp[0] = length();
            temp[1] = that.length();
            temp[2] = Math.abs(hi - that.lo);
            temp[3] = Math.abs(that.hi - lo);
            double max = 0;
            for (int i = 0 ; i < temp.length ; ++i)
                if (max < temp[i])
                    max = temp[i];
            return intermid <= max;
        }
    }

    private static Point2D[] initPoint(double Max_x, double Max_y, int N) {
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        Point2D[] result = new Point2D[N];
        for (int i = 0 ; i < N ; ++i) {
            result[i] = new Point2D.Double(random.nextDouble() * Max_x, random.nextDouble() * Max_y);
        }
        return result;
    }

    // 练习1.2.1：编写一个Point2D用例，接受一个整数N，在单位正方形中生成N个随机点，然后计算两点之间的距离
    public static double get_distance(double Max_x, double Max_y, int N) {
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        Point2D[] nodes = initPoint(Max_x, Max_y, N);
        // 选择两个点a[i],b[n]
        int i = random.nextInt(N);      // 0,...,N-1
        int n = random.nextInt(N);
        double result = nodes[i].distance(nodes[n]);
        return result;
    }

    // 练习1.2.2：编写一个Interval1D用例，打印出N个间隔中相交的间隔对
    public static void print_interval1D(double Max_x, double Max_y, int N) {
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        final Interval1D[] inters = new Interval1D[N];
        for (int i = 0 ; i < N ; ++i)
            inters[i] = new Interval1D(random.nextDouble() * Max_x, random.nextDouble() * Max_y);
        for (int i = 0 ; i < N ; i++) {
            for (int j = i ; j < N ; j++) {
                if (inters[i].intersect(inters[j]))
                    System.out.println(i + " 相交于 " + j);
            }
        }
    }

    // 练习1.2.6：判断一个字符串s是否是另一个字符串的回环字符串
    public static boolean circular_rotation(String s, String t) {
        boolean result = false;
        if (s.length() == t.length()) {
            char c = t.charAt(0);
            for (int i = 0 ; i < s.length() ; ++i) {
                if (c == s.charAt(i)) {
                    String head = s.substring(0, i);
                    String tail = s.substring(i, s.length());
                    String new_string = tail + head;
                    if (new_string.equals(t)) {
                        result = true;
                        break;
                    }
                }
            }
        } else
            result = false;
        return result;
    }


    public static void main(String[] args) {
        int practice_index = 3;
        if (practice_index == 1) {
            System.out.println(get_distance(10.0, 10.0, 10));
        } else if (practice_index == 2)
            print_interval1D(10.0, 10.0, 10);
        else if (practice_index == 3)
            System.out.println(circular_rotation("ACTGACG", "TGACGAC"));
    }
}
