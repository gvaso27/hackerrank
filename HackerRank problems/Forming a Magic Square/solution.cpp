#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int formingMagicSquare(vector<vector<int>> s) {
    vector<int> given;
    vector<vector<int>> sequences = {{8,1,6,7,2,9,4,3}, {4,3,8,1,6,7,2,9}, {2,9,4,3,8,1,6,7},{6,7,2,9,4,3,8,1},{6,1,8,3,4,9,2,7},{8,3,4,9,2,7,6,1},{4,9,2,7,6,1,8,3},{2,7,6,1,8,3,4,9}};
    int cost = 100;
    int middl = 0;
    if(s[1][1] > 5){
        middl = s[1][1] - 5;
    }else{
        middl = 5 - s[1][1];
    }
    int x = 0;
    int y = 0;
    while(true){
        if(x == 0 && y < 2){
            given.push_back(s[x][y]);
            y++;
        }
        if(x < 2 && y == 2){
            given.push_back(s[x][y]);
            x++;
        }
        if(x == 2 && y > 0){
            given.push_back(s[x][y]);
            y--; 
        }
        if(y == 0 && x > 0){
            given.push_back(s[x][y]);
            x--; 
        }
        if(x == 1 && y == 0){
            given.push_back(s[x][y]);
            break;
        }
    }
    int middle;
    for(int i = 0; i < 8; i++){
        middle = middl;
        for(int j = 0; j < 8; j++){
            if(sequences[i][j] > given[j]){
                middle = middle + sequences[i][j] - given[j]; 
            }else{
                middle = middle + given[j] - sequences[i][j]; 
            }
        }
        if(middle < cost)cost = middle;
    }
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
