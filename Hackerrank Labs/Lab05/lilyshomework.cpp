    #include <bits/stdc++.h>
    #include <vector>
    #include <map>
    #include <algorithm>

    using namespace std;

    string ltrim(const string &);
    string rtrim(const string &);
    vector<string> split(const string &);

    /*
    * Complete the 'lilysHomework' function below.
    *
    * The function is expected to return an INTEGER.
    * The function accepts INTEGER_ARRAY arr as parameter.
    */

    int lilysHomework(vector<int> arr) {
    size_t len = arr.size();
    vector<pair<int,int>> eia, eid;

    for (size_t i = 0; i < len; i++) {
        eia.push_back({arr[i], i});
        eid.push_back({arr[i], i});
    }

    sort(eia.begin(), eia.end());
    int sa = 0;
    for (size_t i = 0; i < len; i++){
        size_t index1 = eia[i].second; 
        if (index1 != i) {
            swap(eia[i], eia[index1]);
            sa++;
            i--;
        }
    }
    int sd = 0;
    sort(eid.rbegin(), eid.rend());
    for (size_t i = 0; i < len; i++){
        size_t index2 = eid[i].second; 
        if (index2 != i){
            swap(eid[i], eid[index2]);
            sd++;
            i--;
        }
    }

    return min(sd, sa);
}
    int main()
    {
        ofstream fout(getenv("OUTPUT_PATH"));

        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = lilysHomework(arr);

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
