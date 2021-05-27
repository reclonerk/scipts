//Time created: 2021-04-06 09:43:31
// Program to generate arithmetic basic questions.
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007

vector<string>ans[100];

int generate_number(int MAX){
    int val1 = 1 + rand()%MAX;
    int val2 = 1 + rand()%MAX;
    return val1 * val2;
}

int generate_operator(int MAX){
    int val = rand()%MAX;
    return val;
}


double calculate_ans(int a, int b, char ch){
    if(ch == '+'){
        return (double)a + b;
    }
    if(ch == '-'){
        return (double)a - b;
    }
    if(ch == '*'){
        return (double)a * b;
    }
    if(ch == '/'){
        return (double)(a / (double) b);
    }
    return 0;
}

void generate_questions(int n, string date){
    string questions_file = "Tasks/" + date + ".csv";
    const char* cfile = questions_file.c_str();
    freopen(cfile, "w", stdout);
    string s = "++**";
    int MAX = 234412;
     cout << "s.No." << "," << "firstNumber" << ","<<"operator" <<"," << "secondNumber" <<endl;
    // cout<<"----------------------------------------------"<<endl;
    for(int i=1; i<=n; i++){
        int first = generate_number(MAX);
        int second = generate_number(MAX);
        char ch = s[generate_operator(4)];
        string sop(1, ch);
        double answer = calculate_ans(first, second, ch);
        double result = trunc(answer);
        if(result == answer){
            answer = result;
        }
        if(ch == '*') ch = 'x';
        // ans.push_back(to_string(first) + ch + to_string(second) + "=" + to_string(answer));
        ans[i].push_back(to_string(first));
        ans[i].push_back(to_string(second));
        if(sop == "*") sop = "x";
        ans[i].push_back(sop);
        string s_answer = to_string(answer);
        while(s_answer[s_answer.length()-1] == '0'){
            s_answer.pop_back();
        }
        if(s_answer[s_answer.length()-1] == '.'){
            s_answer.pop_back();
        }
        ans[i].push_back(s_answer);
        cout << i << "," << first << ","<<ch <<"," << second <<endl;
        // cout <<"|"<< i << ".\t"<<first << "\t"<< ch << "\t" << second <<" \t|"<< endl;
        // cout<<"----------------------------------------------"<<endl;
    }
}

void generate_answers(int n, string date)
{
    string answer_file = "Tasks/" + date + "_ans.txt";
    const char* cfile = answer_file.c_str();
    freopen(cfile, "w", stdout);
    // freopen(answer_file, "w", stdout);
    for(int i=1; i<=n; i++){
        cout<<i<<".\t"<<ans[i][0]<<"\t" << ans[i][2] << "\t" << ans[i][1] << "\t=\t" << ans[i][3] << endl; 
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(0));
    int n = 50;
    // cin >> n;
    for(int i = 26; i <= 26; i++){
        for(int j =0; j < 100; j++){
            ans[j].clear();
        }
        string date = to_string(i) + "-04-2021";
        generate_questions(n, date);
        generate_answers(n, date);
    }
    return 0;
}