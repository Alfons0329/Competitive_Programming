/*
 * Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary representation.If the number can not be represented accurately in binary, print “ERROR”. 
 * */
#include <bits/stdc++.h>

using namespace std;

string double_to_binary(double num){
    string num_str = to_string(num);
    int dot_pos = num_str.find('.');

    int part_int = stoi(num_str.substr(0, dot_pos));
    double part_dec = stof(num_str.substr(dot_pos, num_str.size() - dot_pos));
    string res_int = "";
    string res_dec = "";

    cout << "Int: " << part_int << ", Dec: " << part_dec << '\n';

    while(part_int > 0){
        res_int = (part_int & 1) ? "1" + res_int : "0" + res_int;
        part_int >>= 1;
    }

    while(part_dec > 0){
        if(res_dec.size() > 32){
            return "ERROR";
        }
        part_dec *= 2;

        if(part_dec >= 1){
            res_dec += "1";
            part_dec -= 1;
        }
        else{
            res_dec += "0";
        }
    }

    return res_int + "." + res_dec;
}

int main(){
    while(1){
        double num;
        cin >> num;
        cout << num << " in bin double: \n"<< double_to_binary(num) << '\n';
    }
    return 0;
}
