package chapter_1;

/**
 * Created by lookfiresu on 16-1-30.
 */

import java.awt.geom.Point2D;
import java.lang.*;
import java.util.Random;

public class AbstractData {
    private static Point2D[][] init(double Max_x, double Max_y, int M, int N) {
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        Point2D[][] result = new Point2D[M][N];
        for (int i = 0 ; i < M ; ++i) {
            for (int j = 0 ; j < N ; ++j) {
                result[i][j] = new Point2D.Double(random.nextDouble() * Max_x, random.nextDouble() * Max_y);
            }
        }
        return result;
    }

    // 练习1.2.1：编写一个Point2D用例，接受一个整数N，在单位正方形中生成N个随机点，然后计算两点之间的距离
    public static double get_distance(double Max_x, double Max_y, int N) {
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        Point2D[][] nodes = init(Max_x, Max_y, N, N);
        // 选择两个点a[i][j],b[m][n]
        int i = random.nextInt(N);      // 0,...,N-1
        int j = random.nextInt(N);
        int m = random.nextInt(N);
        int n = random.nextInt(N);
        double result = nodes[i][j].distance(nodes[m][n]);
        return result;
    }


    public static void main() {
        int practice_index = 1;
        if (practice_index == 1) {
            System.out.println(get_distance(10.0, 10.0, 10));
        }
    }
}
