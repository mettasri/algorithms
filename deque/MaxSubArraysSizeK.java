/*
 * k = 4
 * 2 7 6 4 1 5 8
 * 7 6 4           ->  7
 *   7 6 4 1       ->  7
 *     6 5         ->  6
 *       8         ->  8
 *************************
 * k = 4
 * 3 5 4 2 -1 4 0 -3
 * 5 4 2           ->  5
 *   5 4 2         ->  5
 *     4 2  4      ->  4
 *          4      ->  4
 *          4      ->  4
 *
 * deque contains elements in descending order
 *       remove the elements if they are smaller than current
 * deque dq 
 *
 * remove
 *   
 *   
 *
 * for i -> k
 *   / insert maximum candidate
 *   while !dq.empty() && dq.back <= a[i]
 *     dq.pop_back
 *   dq.push_back(i)
 *   
 * / result
 * maximums.push_back(dq.front)
 *
 * for i -> k to size
 *   / insert maximum candidate
 *   while !dq.empty() && dq.back <= a[i]
 *     dq.pop_back
 *   dq.push_back(i)
 *   
 *   / remove the maximum candidate if this is out of window
 *   / 0 1 2 3 4 5 6 7
 *     |     |
 *             |
 *   if (dq.front <= i - k)
 *     dq.pop_front
 *
 *   / result
 *   maximums.push_back(dq.front)
 */
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Arrays;

public class MaxSubArraysSizeK {
  public static int[] maxOfSubarrays(int[] arr, int k) {
    int count = 0;
    int[] result = new int[arr.length - k + 1];
    Deque<Integer> dq = new ArrayDeque<Integer>();
    for (int i = 0; i < k; ++i) {
      while (!dq.isEmpty() && arr[dq.getLast()] <= arr[i])
        dq.removeLast();
      dq.addLast(i);
    }
    result[count++] = arr[dq.getFirst()];
    for (int i = k; i < arr.length; ++i) {
      while (!dq.isEmpty() && arr[dq.getLast()] <= arr[i])
        dq.removeLast();
      dq.addLast(i);

      if (dq.getFirst() <= (i - k))
        dq.removeFirst();
      result[count++] = arr[dq.getFirst()];
    }

    return result;
  }

  public static void main(String[] args) {
    int[] arr;
    int[] result;

    arr = new int[]{2, 7, 6, 4, 1, 5, 8};
    result = maxOfSubarrays(arr, 4);
    System.out.println(Arrays.equals(result, new int[]{7, 7, 6, 8}));

    arr = new int[]{1, 2, 3, 1, 4, 5, 2, 3, 6};
    result = maxOfSubarrays(arr, 3);
    System.out.println(Arrays.equals(result, new int[]{3, 3, 4, 5, 5, 5, 6}));
  }
}
