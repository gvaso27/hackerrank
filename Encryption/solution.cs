using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'encryption' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static string encryption(string s)
    {
        int length = 0;
        string modif = "";
        for(int i = 0; i < s.Length; i++){
            if(s[i] != ' '){
                modif+=s[i];
            }
        }
        length = modif.Length;
        int high = 0;
        while(true){
            if(high*high >= length)break;
            high++;
        }
        int low;
        if(high*(high-1) < modif.Length){
            low = high;
        }else{
            low = high-1;
        }
        string tmp = "";
        string[] grid = new string[low];
        int counter = 0;
        for(int i = 0; i < length; i++){
            if(tmp.Length == high){
                Console.WriteLine(counter);
                grid[counter] = tmp;
                counter++;
                tmp = "";
            }
           tmp += modif[i];
        }
        Console.WriteLine(tmp);
        Console.WriteLine(grid.Length);
        if(counter <= low)grid[counter] = tmp;
        while(grid[counter].Length < high)grid[counter]+=' ';
        string res = "";
        for(int i = 0; i < high; i++){
            for(int j = 0; j < low; j++){
                if(grid[j][i] != ' ')res += grid[j][i];
            }
            res+=' ';
        }
        return res;
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s = Console.ReadLine();

        string result = Result.encryption(s);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
