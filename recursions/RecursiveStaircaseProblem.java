/*
 * Take 1 or 2 steps at a time, ie: {1, 2}
 *
 *            0 <- { [0] }
 *
 * 0  __
 * 1__|       1 <- { [1, 0] }
 *
 * 0    __
 * 1  __|
 * 2__|       2 <- { [2, 1, 0], [2, 0] }
 *
 * 0       __
 * 1     __|
 * 2   __|
 * 3 __|      3 <- { [3, 2, 1, 0], [3, 2, 0], [3, 1, 0] }
 *
 *        num_ways(n) = num_ways(n - 1) + num_ways(n - 2)
 *        num_ways(3) = num_ways(2) + num_ways(1)
 *
 *
 *  n    ways
 * ----------
 *  0     1
 *  1     1
 *  2     2
 *  3     3
 *  4     5
 *  5     8
 *  6    13 
 *  7    21
 *  8    34
 *-----------------------------------------------------------
 *
 * Take 1, 3, 5 steps at a time, ie: {1, 3, 5}
 *
 *            0 <- { [0] }
 *
 * 0  __
 * 1__|       1 <- { [1, 0] }
 *
 * 0    __
 * 1  __|
 * 2__|       2 <- { [2, 1, 0] }
 *
 * 0       __
 * 1     __|
 * 2   __|
 * 3 __|      3 <- { [3, 2, 1, 0], [3, 0] }
 *
 *        num_ways(n) = num_ways(n - 1) +
 *                      num_ways(n - 3) + 
 *                      num_ways[n - 5]
 */

public class RecursiveStaircaseProblem {
  int NumWaysRecursive(int n) {
    if (n == 0 || n == 1)  return 1;
    return NumWaysRecursive(n - 1) + NumWaysRecursive(n - 2);
  }
  int NumWaysDP(int n) {
    int[] ways = new int[n + 1];
    ways[0] = 1; ways[1] = 1;
    for (int i = 2; i <= n; ++i) {
      ways[i] = ways[i - 1] + ways[i - 2];
    }
    return ways[n];
  }

  public static void main(String[] args) {
    RecursiveStaircaseProblem obj = new RecursiveStaircaseProblem();
    System.out.println(obj.NumWaysRecursive(8));
    System.out.println(obj.NumWaysDP(8));
  }
}
