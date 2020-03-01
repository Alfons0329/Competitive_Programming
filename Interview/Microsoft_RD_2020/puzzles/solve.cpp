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
    for(auto x : v1){ 
        min_ele = min(min_ele, x);
    }
    for(auto &x : v1){
        x -= min_ele;
    }

    sort(v2.begin(), v2.end());
    min_ele = v2[0];
    for(auto &x : v2){
        x -= min_ele;
    }

    return v1 == v2;
}

bool solve(vector<string>& m1, vector<string>& m2){
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

    // check shift-wise equivelence 
    for(auto it1: possib){
        vector<int> tmp;
        for(auto it2: star_m2){
            tmp.push_back(it1[it2] - '0');
        }
        if(check_shift(dot_m1, tmp)){
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

    // solve
    int c1 = solve(m1, m2);
    int c2 = solve(m2, m1);
    if(c1 || c2){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0; 
}
