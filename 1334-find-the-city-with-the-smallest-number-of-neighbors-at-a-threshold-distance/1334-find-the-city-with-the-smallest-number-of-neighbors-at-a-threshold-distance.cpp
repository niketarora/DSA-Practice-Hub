class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for(int i=0; i<n; i++)  dist[i][i] = 0;
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)  continue;
                    dist[i][j] = min(dist[i][j] , (dist[i][via] + dist[via][j]));
                }
            }
        }

        int city = -1;
        int cityTravel = n;  
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count<=cityTravel){
                cityTravel = count;
                city = i;
            }
        }
        return city;
    }
};