#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool can_move_to(vector<int>& available_move_for_ud, int y) {
    for (int move : available_move_for_ud) {
        if(move >= abs(y) && (move - y)%2 == 0 ){
        return true;
        break;
        }
    }
    return false;
}

vector<int> get_lr_candidate(int t, int x) {
    vector<int> lr_candidate;
    if (t >= abs(x)){
        for(int i = 0; i <= abs(x)/2; i++){
        lr_candidate.push_back(abs(x) + 2 * i);
        }
    }
    else if(x == 0){
        for(int i = 0; i <= t/2; i++){
        lr_candidate.push_back(2 * i);
        }
    }
    return lr_candidate;
}

vector<int> get_available_move(vector<int>& lr_candidate,int t) {
    vector<int> available_move_for_ud;
        for (int i = 0; i < lr_candidate.size(); i++) {
        available_move_for_ud.push_back(t - lr_candidate[i]);
        }
    return available_move_for_ud;
}

bool move_possible(vector<int>& ti, vector<int>& xi, vector<int>& yi) {
    int N = ti.size();
    for (int i = 0; i < N; i++) {
        int t = ti[i];
        int x = xi[i];
        int y = yi[i];
        vector<int> lr_candidate = get_lr_candidate(t, x);
        vector<int> available_move_for_ud = get_available_move(lr_candidate, t);
        if (!can_move_to(available_move_for_ud, y)) {
            return false; 
        }
    }
    return true; 
}


int main() {
    int N;
    cin >> N;
    vector<int> ti(N);
    vector<int> xi(N);
    vector<int> yi(N);
    for (int i = 0; i < N; i++) {
        cin >> ti[i];
        cin >> xi[i];
        cin >> yi[i];
    }
    for(int i = N; i >= 1; i--){
       ti[i]-= ti[i-1];
       xi[i]-= xi[i-1];
       yi[i]-= yi[i-1];
}
    for(int i = 0; i < N; i++){
        xi[i]=abs(xi[i]);
        yi[i]=abs(yi[i]);
    }
    
    if (move_possible(ti, xi, yi)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}