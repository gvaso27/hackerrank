#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'organizingContainers' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts 2D_INTEGER_ARRAY container as parameter.
 */

string organizingContainers(vector<vector<int>> container) {
    vector<long> counter(container.size(), 0);
    for(int i = 0; i < container.size(); i++){
        for(int j = 0; j < container.size(); j++){
            counter[j]+= container[i][j];
        }
    }
    vector<long> counter1(container.size(), 0);
    for(int i = 0; i < container.size(); i++){
        for(int j = 0; j < container.size(); j++){
            counter1[i]+=container[i][j];
        }
    }
    int m = 0;
    long tmp;
    for(int i = 0; i < container.size(); i++){
        m=i;
        while(true){
            if(m>=counter.size())return "Impossible";
            if(counter[i] != counter1[m]){
                m++;
            }else{
                tmp = counter1[i];
                counter1[i] = counter1[m];
                counter1[m] = tmp;
                break;
            }
        }
    }
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> container(n);

        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            string container_row_temp_temp;
            getline(cin, container_row_temp_temp);

            vector<string> container_row_temp = split(rtrim(container_row_temp_temp));

            for (int j = 0; j < n; j++) {
                int container_row_item = stoi(container_row_temp[j]);

                container[i][j] = container_row_item;
            }
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

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
