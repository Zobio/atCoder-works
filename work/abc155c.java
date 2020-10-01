import java.util.*;

public class abc155c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, Integer> word = new HashMap<String, Integer>();
        String newWord;
        int num = 0;
        for(int i = 0; i < n; i++) {
            newWord = sc.next();
            if(!word.containsKey(newWord)){
                word.put(newWord, 1);
            }else{
                num = word.get(newWord);
                word.remove(newWord);
                word.put(newWord, num + 1);
            }
        } //the number of each words

        int mostNum = 0;
        int current = 0;
        Iterator<Integer> it = word.values().iterator();
        while(it.hasNext()) {
            current = it.next();
            if(mostNum< current) {
                mostNum = current;
            }
        } //choosing the most number

        String[] allWords = new String[n];
        Iterator<String> it3 = word.keySet().iterator();
        int q = 0;
        while(it3.hasNext()) {
            allWords[q] = it3.next();
            q++;
        } //put the words to array from list

        ArrayList<String> mostWords = new ArrayList<String>();
        for(int i = 0; i < q; i++) {
            if(word.get(allWords[i]) == mostNum) {
                mostWords.add(allWords[i]);
            }
        } //choosing the words whose number if "mostNum" and put to Collection
        Collections.sort(mostWords);
        for(int a = 0; a < mostWords.size(); a++) {
            System.out.println(mostWords.get(a));
        }
    }
}