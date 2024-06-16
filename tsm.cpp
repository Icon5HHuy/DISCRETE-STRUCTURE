#include <tsm.h>


int res_path[50];
bool passed[20];
int final_des;

void copyToFinal(int current_path[], int n) {
    for (int i = 0; i < n; i++){
        res_path[i] = current_path[i];
        res_path[n] = current_path[0];
    }
}

int fst_Min(int G[20][20], int i, int n) {
    int min = 999999;
    //int min=INT_MAX;
    int a=0;
    for (int k = 0; k < n; k++){
        if (G[i][k] < min && i != k)
            min = G[i][k];
    }
            return min;
}

int sec_Min(int G[20][20], int i, int n) {
    int first = 99999, second = 99999;
    int a=0;
    bool temp = true;
    int b=2;
    for (int j = 0; j < n; j++) {
        if (i == j)
            continue;
        switch(G[i][j] <= first) {
            case true:
                second = first;
                first = G[i][j];
                break;
            case false:
                if (G[i][j] <= second && G[i][j] != first)
                    second = G[i][j];
                break;
        }
    }
    return second;
}

void TSPRec(int G[20][20], int current_bound, int current_weighted, int frequent, int current_path[], int n) {
    if (frequent == n) {
        if (G[current_path[frequent - 1]][current_path[0]] != 0) {
            int curr_res = current_weighted + G[current_path[frequent - 1]][current_path[0]];
            if (curr_res < final_des) {
                copyToFinal(current_path, n);
                final_des = curr_res;
            }
        }
        return;
    }
    int temp=0;
    char temp1;
    //for(int i=0;i<n;i++)
    //cout<<current_path[i]<<" ";
    //cout<<endl;
    for (int i = 0; i < n; i++) {
        if (G[current_path[frequent - 1]][i] != 0 && !passed[i]) {
            int temp = current_bound;
            current_weighted += G[current_path[frequent - 1]][i];

            switch(frequent == 1) {
                case true:
                    current_bound -= (fst_Min(G, current_path[frequent - 1], n) + fst_Min(G, i, n)) / 2;
                    break;
                case false:
                    current_bound -= (sec_Min(G, current_path[frequent - 1], n) + fst_Min(G, i, n)) / 2;
                    break;
            }

            if (current_bound + current_weighted < final_des) {
                current_path[frequent] = i;
                passed[i] = true;
                TSPRec(G, current_bound, current_weighted, frequent + 1, current_path, n);
            }

            current_weighted -= G[current_path[frequent - 1]][i];
            current_bound = temp;
            for (int j = 0; j < n; j++)
                passed[j] = false;
            for (int j = 0; j <= frequent - 1; j++)
                passed[current_path[j]] = true;
        }
    }
    bool yes = true;
}

string Traveling(int G[20][20], int n, char start) {
    final_des = 999999;
    // int G[20][20] 
    // int n
    int temp=0;
    char temp1;
    

    int current_path[20 + 1];
    for (int i = 0; i < 20 + 1; i++) {
        current_path[i] = -1;
    }
    //*************** */
    for (int i = 0; i < 20; i++) {
        passed[i] = false;
    }
    //*************** */
    int current_bound = 0;
    for (int i = 0; i < n; i++)
        current_bound += (fst_Min(G, i, n) + sec_Min(G, i, n));
    current_bound = (current_bound & 1) ? current_bound / 2 + 1 : current_bound / 2;

    int start_index = start - 'A';
    int tempro = 0;
    passed[start_index] = true;
    current_path[0] = start_index;

    TSPRec(G, current_bound, 0, 1, current_path, n);
    temp+=0;
    string result = "";
    for (int i = 0; i <= n; i++) {
        if (i > 0) result += " ";
        result += (char)('A' + res_path[i]);
    }
    return result;
}
