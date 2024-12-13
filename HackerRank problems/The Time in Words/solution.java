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
     * Complete the 'timeInWords' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. INTEGER h
     *  2. INTEGER m
     */

    public static String converter(int n){
        if(n == 0)return "";
        if(n == 1)return "one";
        if(n == 2)return "two";
        if(n == 3)return "three";
        if(n == 4)return "four";
        if(n == 5)return "five";
        if(n == 6)return "six";
        if(n == 7)return "seven";
        if(n == 8)return "eight";
        if(n == 9)return "nine";
        if(n == 10)return "ten";
        if(n == 11)return "eleven";
        if(n == 12)return "twelve";
        return "";
    }
    public static String timeInWords(int h, int m) {
        String minutes = "";
        String hours = "";
        String pastto = "";
        String round = "";
        if(m == 0){
            return converter(h) + " o' clock";
        }
        if(m == 15){
            return "quarter past " + converter(h);
        }
        if(m == 30){
            return "half past " + converter(h);
        }
        if(m == 45){
            if(h == 12){
                return "quarter to one ";
            }else{
                return "quarter to " + converter(h+1);
            }
        }
        if(m < 30){
            hours += converter(h);
            pastto += " past ";
        }else{
            if(h == 12){
                hours += converter(1);
                pastto += " to ";
            }else{
                hours += converter(h+1);
                pastto += " to ";
            }
            m = 60 - m;
        }
        if(m/10 == 0){
            minutes += converter(m);
        }else if(m/10 == 1){
            if(m == 11)minutes += "eleven";
            if(m == 12)minutes += "twelve";
            if(m == 13)minutes += "thirteen";
            if(m == 14)minutes += "fourteen";
            if(m == 15)minutes += "fifteen";
            if(m == 16)minutes += "sixteen";
            if(m == 17)minutes += "seventeen";
            if(m == 18)minutes += "eighteen";
            if(m == 19)minutes += "nineteen";
        }else if(m/10 == 2){
            round += "twenty ";
            minutes += converter(m%10);
        }
        if(m!=1){
            return round + minutes + " minutes" + pastto + hours;
        }else{
            return round + minutes + " minute" + pastto + hours;
        }
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int h = Integer.parseInt(bufferedReader.readLine().trim());

        int m = Integer.parseInt(bufferedReader.readLine().trim());

        String result = Result.timeInWords(h, m);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
