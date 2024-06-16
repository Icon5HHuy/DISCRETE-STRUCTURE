#include <iostream> 
#include <string>
using namespace std;

void copyToFinal(int curr_path[], int n);
int firstMin(int G[20][20], int i, int n);
int secondMin(int G[20][20], int i, int n);
void TSPRec(int G[20][20], int curr_bound, int curr_weight, int level, int curr_path[], int n);
string Traveling(int G[20][20], int n, char start);