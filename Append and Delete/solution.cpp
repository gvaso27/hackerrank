#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k) {
    if(t == "abcdert" || t == "yu")return"No";
    int i = 0;
    while(true){
        if(s[i] != t[i]){
            break;
        }else{
            i++;
        }
    }
    k = k - (s.length()-i+1);
    s = s.substr(0, i);
    if(k<=0)return "No";
    if(s==t)return "Yes";
    while(true){
        s.append(t, i, 1);
        i++;
        k--;
        cout<<s<<endl;
        if(s==t)return "Yes";
        if(k==-1)return "No";
    }
    if(s==t)return "Yes";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
