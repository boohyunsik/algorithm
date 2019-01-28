import java.util.Hashtable;
import java.util.ArrayList;
class Solution {
    static public boolean solution(String[] phone_book) {
        boolean answer = true;
        int minLength = 987654321;
        for (String num : phone_book) {
            if (minLength > num.length()) {
                minLength = num.length();
            }
        }

        Hashtable<String, ArrayList<String>> hashTable = new Hashtable();
        for (String num : phone_book) {
            String substr = num.substring(0, minLength);
            if (hashTable.containsKey(substr)) {
                hashTable.get(substr).add(num);
                for (String val : hashTable.get(substr)) {
                    if (val.equals(substr)) {
                        answer = false;
                        break;
                    }
                }
            } else {
                ArrayList<String> list = new ArrayList();
                list.add(num);
                hashTable.put(substr, list);
            }
        }

        
        return answer;
    }
}
