#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    if(s.substr(8, 2) == "AM" && s.substr(0, 2) != "12"){
        s = s.substr(0, 8);
    }else if(s.substr(8, 2) == "AM" && s.substr(0, 2) == "12"){
        s = "00" + s.substr(2, 6);
    }else if(s.substr(8, 2) == "PM" && s.substr(0, 2) == "12"){
        s = s.substr(0, 8);
    }else if(s.substr(8, 2) == "PM" && s.substr(0, 2) != "12"){
        if(s[0] == '1')s[0] = '2';
        if(s[0] == '0')s[0] = '1';
        if(s[1] == '1'){
            s[1] = '3';
        }else if(s[1] == '2'){
            s[1] = '4';
        }else if(s[1] == '3'){
            s[1] = '5';
        }else if(s[1] == '4'){
            s[1] = '6';
        }else if(s[1] == '5'){
            s[1] = '7';
        }else if(s[1] == '6'){
            s[1] = '8';
        }else if(s[1] == '7'){
            s[1] = '9';
        }else if(s[1] == '8'){
            s[1] = '0';
        }else if(s[1] == '9'){
            s[1] = '1';
        }else if(s[1] == '0'){
            s[1] = '2';
        }
    }
    s = s.substr(0, 8);
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
