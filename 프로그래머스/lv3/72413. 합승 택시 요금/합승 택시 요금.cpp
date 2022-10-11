#include <string>
#include <vector>
#include <algorithm>

#define NMAX 9876543
using namespace std;

int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = NMAX;
    
    fill(&dist[0][0], &dist[201][0], NMAX);
    
    for(int i = 0; i<=n; i++){
        dist[i][i] = 0;
    }
    
    for(int i = 0; i < fares.size(); i++){
        
        int aa = fares[i][0];
        int bb = fares[i][1];
        int cc = fares[i][2];
        dist[aa][bb] = cc;
        dist[bb][aa] = cc;
        
    }
    
    for(int k = 1; k <=n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= n; j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    
    // t는 환승하는 곳

    for(int t = 1; t<= n; t++){
        
        int both = dist[s][t];
        int a_cost = dist[t][a];
        int b_cost = dist[t][b];
        int r = both + a_cost + b_cost;
        answer = min(answer, r);
        
    }
    
    
    return answer;
}