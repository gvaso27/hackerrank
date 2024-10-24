import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'biggerIsGreater' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING w as parameter.
     */

    public static String biggerIsGreater(String w) {
        char[] arr = w.toCharArray();
        int i = w.length()-2;
        char ch = '~';
        int SecondIndex = 0;
        boolean id = false;
        while(true){
            if(i < 0)break;
            for(int j = i+1; j < w.length(); j++){
                if(arr[j] > arr[i] && arr[j] < ch){
                    ch = arr[j];
                    SecondIndex = j;
                } 
            }
            if(ch != '~'){
                id = true;
                arr[SecondIndex] = arr[i];
                arr[i] = ch;
                break;
            }
            i--;
        }
        if(id){
            Arrays.sort(arr, i + 1, arr.length);
            String str = new String(arr);
            return str;
        }else{
            return "no answer";
        }
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int T = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, T).forEach(TItr -> {
            try {
                String w = bufferedReader.readLine();

                String result = Result.biggerIsGreater(w);

                bufferedWriter.write(result);
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
