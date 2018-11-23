/*
 *                ABC/
 *                 |            
 *                BC/A 
 *          ---------------
 *          |             |
 *        C/AB           C/BA
 *     -----------     -----------
 *     |    |    |     |    |    |
 *    CAB  ACB  ABC   CBA  BCA  BAC
 */
class Permutations {
  void Permute(String str, StringBuffer res) {
    if (str.length() == 0) {
      System.out.println(res);
      return;
    }
  
    for (int i = 0; i <= res.length(); ++i) {
      StringBuffer s = new StringBuffer(res);
      s.insert(i, str.charAt(0));
      Permute(str.substring(1), s);
    }
  }
  public static void main(String[] args) {
    Permutations obj = new Permutations();
    List<Integer> 
    obj.Permute("ABC", res);
  }
}
