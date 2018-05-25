/*
 * 567. Short Permutation in a Long String 
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's permutations
 * is the substring of the second string.
 * 
 * Example 1:
 * Input:s1 = "ab" s2 = "eidbaooo"
 * Output:True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * Example 2:
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 */
class ShortPermutationInLongString {
  public boolean IsShortPermutationInLongString(String s1, String s2) {
    int len1 = s1.length(), len2 = s2.length();
    if (len1 > len2) return false;

    int[] s1map = new int[256];
    int[] s2map = new int[256];
    for (int i = 0; i < len1; ++i) {
      s1map[s1.charAt(i)]++;
      s2map[s2.charAt(i)]++;
    }
    int count = 0;
    for (int i = 0; i < 256; ++i) {
      if (s1map[i] == s2map[i]) count++;
    }
    System.out.println(s1 + " - " + s2.substring(0, len1) + " " + (256 - count));

    for (int i = len1; i < len2; ++i) {
      if (count == 256) return true;

      char r = s2.charAt(i);
      s2map[r]++;
      if (s1map[r] == s2map[r]) count++;
      if (s1map[r] == (s2map[r] - 1)) count--;

      char l = s2.charAt(i - len1);
      s2map[l]--;
      if (s1map[l] == s2map[l]) count++;
      if (s1map[l] == (s2map[l] + 1)) count--;
      System.out.println(s1 + " - " + s2.substring(i - len1 + 1, i + 1) + " " + (256 - count));
    }
    return count == 256;
  }

  public static void main(String[] args) {
    String s1;
    String s2;
    ShortPermutationInLongString obj = new ShortPermutationInLongString();

    s1 = "ab"; s2 = "eidbaooo";
    if(obj.IsShortPermutationInLongString(s1, s2)) System.out.println("PASS"); else System.out.println("FAIL");

    s1 = "ab"; s2 = "eidboaoo";
    if(!obj.IsShortPermutationInLongString(s1, s2)) System.out.println("PASS"); else System.out.println("FAIL");

    s1 = "adc"; s2 = "dcda";
    if(obj.IsShortPermutationInLongString(s1, s2)) System.out.println("PASS"); else System.out.println("FAIL");

    s1 = "abc"; s2 = "bbbca";
    if(obj.IsShortPermutationInLongString(s1, s2)) System.out.println("PASS"); else System.out.println("FAIL");

    s1 = "rokx"; s2 = "otrxvfszxroxrzdsltg";
    if(!obj.IsShortPermutationInLongString(s1, s2)) System.out.println("PASS"); else System.out.println("FAIL");
  }
}
