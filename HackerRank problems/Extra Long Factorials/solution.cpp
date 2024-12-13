#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
vector<int> plus12(vector<int> a, vector<int>b){
    vector<int> res(200);
    int carry = 0;
    for(int i = 199; i >= 0; i--){
        res[i] = ((a[i] + b[i]) + carry)%10;
        carry = (a[i] + b[i] + carry)/10;
    }
    return res;
}
void extraLongFactorials(int n) {
    vector<int> res(200);
    int tmp = n;
    n--;
    int l = 199;
    while(tmp != 0){
        res[l] = tmp%10;
        l--;
        tmp/=10;        
    }
    vector<int> tmp1(200);
    while(n!=0){
        tmp1 = res;
        for(int i = 0; i < n-1; i++){
            res = plus12(res, tmp1);
        }
        n--;        
    }
    int i = 0;
    while(res[i] == 0)i++;
    while(i != 200){
        cout<<res[i];
        i++;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
