/*
 * 46. Permutations
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 */

import java.util.*;

class Permutations {
  void display(int[] perm) {
    for (int i = 0; i < perm.length; ++i) {
      System.out.print(perm[i] + " ");
    }
    System.out.println();
  }
  public void permuteUtil(int[] nums, int[] perm) {
    if (perm.length == nums.length) {
      display(perm);
      return;
    }
    for (int i = 0; i < perm.length; ++i) {
    }
  }

  public List<List<Integer>> permute(int[] nums) {
    List<List<Integer>> result;
    return result;
  }
  
  public static void main(String[] args) {
    Permutations obj = new Permutations();
    int[] nums = new int[] {1, 2, 3};

    obj.permute(nums);
  }
}
