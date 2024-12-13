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
     * Complete the 'kaprekarNumbers' function below.
     *
     * The function accepts following parameters:
     *  1. INTEGER p
     *  2. INTEGER q
     */

    static bool checker(int n){
        long square = (long)n*n;
        string sq = square.ToString();
        int d = n.ToString().Length;
        int l = sq.Length;
        if(int.Parse(sq.Substring(0, l-d))+int.Parse(sq.Substring(l-d)) == n){
                return true;
        }
        return false;
    }
    
    public static void kaprekarNumbers(int p, int q)
    {
        bool helper = true;
        if(1 >= p){
            Console.Write(1 + " ");
            helper = false;
        }
        if(9 >= p)Console.Write(9 + " ");
        if(45 >= p)Console.Write(45 + " ");
        if(55 >= p)Console.Write(55 + " ");
        if(99 >= p)Console.Write(99 + " ");
        if(p <= 297){
            for(int i = 297; i <= q; i++){
                if(checker(i)){
                    Console.Write(i + " ");
                    i+=98;
                    helper = false;
                }
            }
        }else{
            for(int i = p; i <= q; i++){
                if(checker(i)){
                    Console.Write(i + " ");
                    i+=98;
                    helper = false;
                }
            }
        }
        if(helper)Console.Write("INVALID RANGE");
    }
}

class Solution
{
    public static void Main(string[] args)
    {
        int p = Convert.ToInt32(Console.ReadLine().Trim());

        int q = Convert.ToInt32(Console.ReadLine().Trim());

        Result.kaprekarNumbers(p, q);
    }
}
