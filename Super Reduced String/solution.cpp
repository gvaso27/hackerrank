#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    int i = 0;
    while(i < s.length()-1 && !s.empty()){
        if(s[i] == s[i+1]){
            s = s.substr(0, i) + s.substr(i+2);
            i = 0;
        }else{i++;}
    }
    if(s.empty())return "Empty String";
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

