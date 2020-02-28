#include <bits/stdc++.h>
using namespace std;

vector<string> possib = {
        "123456789", 
        "321654987",
        "369258147",
        "147258369",
        "789456123",
        "987654321",
        "741852963",
        "963852741"
    };

bool check_shift(vector<int> v1, vector<int> v2){
    int n = v1.size(), m = v2.size();
    if(n != m){
        return false;
    }

    int min_ele = INT_MAX;
    sort(v1.begin(), v1.end());
    for(auto x : v1){ 
        min_ele = min(min_ele, x);
    }
    for(int i = 0; i < n; i++){
        v1[i] -= min_ele;
    }

    min_ele = INT_MAX;
    for(auto x : v2){ 
        min_ele = min(min_ele, x);
    }
    for(int i = 0; i < n; i++){
        v2[i] -= min_ele;
    }
    
    // cout << "---------- \n";
    for(int i = 0; i < v1.size(); i++){
        // cout << v1[i] << ", " << v2[i] << endl;
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;
}

bool check(vector<string>& m1, vector<string>& m2){
    vector<int> dot_m1;
    vector<int> star_m2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(m1[i][j] == '.'){
                dot_m1.push_back(i * 3 + j + 1);
            }
            if(m2[i][j] == '*'){
                star_m2.push_back(i * 3 + j);
            }
        }
    }
    
    int min_ele = INT_MAX;
    
    for(auto it1: possib){
        vector<int> tmp;
        for(auto it2: star_m2){
            // cout << "get " << it2 << " , " << it1[it2] << endl; 
            tmp.push_back(it1[it2] - '0');
        }
        if(check_shift(tmp, dot_m1)){
            return true;
        }
    }
    return false;
}

int main(){
    // IO
    vector<string> m1;
    vector<string> m2;
    string str;
    int flag = 0;
    while(cin >> str){
        if(m1.size() < 3){
            m1.push_back(str); 
        }
        else{
            m2.push_back(str); 
        }
    }

    int c1 = check(m1, m2);
    int c2 = check(m2, m1);

    if(c1 || c2){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0; 
}
