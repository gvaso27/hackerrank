#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'surfaceArea' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY A as parameter.
 */

int surfaceArea(vector<vector<int>> A) {
    int totalS = A.size() * A[0].size() * 2;
    if(A.size() == 1){
        totalS += A[0][0];
        totalS += A[0][A[0].size()-1];
        cout<<totalS<<endl;
        for(int i = 0; i < A[0].size()-1; i++){
            totalS+=(2*A[0][i]);
            totalS+=abs(A[0][i] - A[0][i+1]);
        }
        return totalS+(2*A[0][A[0].size()-1]);
    }
    if(A[0].size() == 1){
        totalS += A[0][0];
        totalS += A[A.size()-1][0];
        cout<<totalS<<endl;
        for(int i = 0; i < A.size()-1; i++){
            totalS+=(2*A[i][0]);
            totalS+=abs(A[i][0] - A[i+1][0]);
        }
        return totalS+(2*A[A.size()-1][0]);
    }
    for(int i = 0; i < A.size()-1; i++){
        for(int j = 0; j < A[i].size()-1; j++){
            totalS += abs(A[i+1][j] - A[i][j]);
            totalS += abs(A[i][j+1] - A[i][j]);
            if(i == 0)totalS+=A[i][j];
            if(j == 0)totalS+=A[i][j];
        }
    }
    for(int i = A.size()-1; i > 0; i--){
        totalS+=A[i][A[i].size()-1];
        totalS+=abs(A[i][A[i].size()-1] - A[i-1][A[i].size()-1]);
    }
    for(int i = A[0].size()-1; i > 0; i--){
        totalS+=A[A.size()-1][i];
        totalS+=abs(A[A.size()-1][i] - A[A.size()-1][i-1]);
    }
    totalS+=(2*A[0][A[0].size()-1]);
    totalS+=(2*A[A.size()-1][0]);
    return totalS;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int H = stoi(first_multiple_input[0]);

    int W = stoi(first_multiple_input[1]);

    vector<vector<int>> A(H);

    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        string A_row_temp_temp;
        getline(cin, A_row_temp_temp);

        vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

        for (int j = 0; j < W; j++) {
            int A_row_item = stoi(A_row_temp[j]);

            A[i][j] = A_row_item;
        }
    }

    int result = surfaceArea(A);

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
