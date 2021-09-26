#include <iostream> 
#include <queue> 
#include <vector> 

using namespace std; 

int n, ind = 0;
vector<int> connect[40000]; 

struct city{
    int train[3];
    int sum;
    int visit[3];
};

void bfs(city* c, int start){ 
    if(start >= 2) ind = 2;
    else ind= start;
    queue<int> q; 
    q.push(start); 
    c[start].visit[ind] = 1; 
    c[start].train[ind] = 0;

    while(!q.empty()){
        int x = q.front(); 
        q.pop(); 
        for(int i=0; i< connect[x].size(); i++){ 
            int y = connect[x][i];
            if(!c[y].visit[ind]){ 
                c[y].train[ind] = c[x].train[ind] + 1;
                q.push(y); 
                c[y].visit[ind] = 1; 
            } 
        } 
    } 
} 

int main(void){ 
    int p, q, r, n, m, first, second, min = 0, check = 0; 
    
    cin >> p >> q >> r >> n >> m;

    city * c = new city[n];

    for(int i = 0; i < m; i++){
        cin >> first >> second;
        connect[first-1].push_back(second-1);
        connect[second-1].push_back(first-1);
    }

    for(int i = 0; i < n ; i++){
        c[i].visit[0] = 0;
        c[i].visit[1] = 0;
        c[i].visit[2] = 0;
    }
  
    bfs(c, 0);
    bfs(c, 1);
    bfs(c, n-1);

    if(!c[0].train[2] || !c[1].train[2]) cout << min;
    else{
        for(int i = 0; i < n; i++){
            c[i].sum = c[i].train[0] * p + c[i].train[1] * q + c[i].train[2] * r;
            if(!check && c[i].sum!=0) {
                min = c[i].sum;
                check = 1;
            }
            else if(c[i].sum<min && c[i].sum!=0) min = c[i].sum;
        } 
        cout << min;
    }

    delete[] c;
    return 0;
}