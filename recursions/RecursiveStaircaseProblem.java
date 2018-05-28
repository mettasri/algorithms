/*
 * Take 1 or 2 steps at a time
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
 * 3 __|      3 <- { [3, 2, 1, 0], [3, 1, 0], [3, 2, 0] }
 *
 *        num_ways(n) = num_ways(n - 1) + num_ways(n - 2)
 *        num_ways(3) = num_ways(2) + num_ways(1)
 */


public class RecursiveStaircaseProblem {
  int num_ways(int n) {
    if (n <= 0)  return 0;
    if (n == 1)  return 1;
    return num_ways(n - 1) + num_ways(n - 2);
  }

  public static void main(String[] args) {
    RecursiveStaircaseProblem obj = new RecursiveStaircaseProblem();
    System.out.println(obj.num_ways(8));
  }
}
