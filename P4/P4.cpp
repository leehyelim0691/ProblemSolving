#include <iostream>
#include <vector>  
#include <cstdint>

using namespace std;

struct func_f{
    long long a;
    long long fa;
};
struct func_g{
    long long a;
    long long ga;
};

int main(void){
    long long p, q, kf, kg, indf = 0, indg = 0;
    unsigned long long gap, before = 0, result = 0;

    vector<long long> a;  
    vector<long long> func;  

    cin >> kf;
    struct func_f f[kf];
    for(int i = 0; i < kf; i++) cin >> f[i].a >> f[i].fa;

    cin >> kg;
    struct func_g g[kg];
    for(int i = 0; i < kg; i++) cin >> g[i].a >> g[i].ga;

    cin >> p >> q;

    while(1){
        if(indf >= kf && indg >= kg) break;
        else if(indf >= kf){
            if(before < g[indg].ga){
                a.push_back(g[indg].a);
                func.push_back(g[indg].ga);
                before = g[indg].ga;
            }
            indg++;
        }
        else if(indg >= kg){
            if(before < f[indf].fa){
                a.push_back(f[indf].a);
                func.push_back(f[indf].fa);
                before = f[indf].fa;
            }
            indf++;
        }
        else{
            if(f[indf].a < g[indg].a) {
                if(before < f[indf].fa){
                    a.push_back(f[indf].a);
                    func.push_back(f[indf].fa);
                    before = f[indf].fa;
                }
                indf++;
            }
            else if(f[indf].a > g[indg].a) {
                if(before < g[indg].ga){
                    a.push_back(g[indg].a);
                    func.push_back(g[indg].ga);
                    before = g[indg].ga;
                }
                indg++;
            }
            else {
                if(f[indf].fa > g[indg].ga){
                    a.push_back(f[indf].a);
                    func.push_back(f[indf].fa); 
                    before = f[indf].fa;
                }
                else{
                    a.push_back(g[indg].a);
                    func.push_back(g[indg].ga);  
                    before = g[indg].ga;
                }
                indf++;
                indg++;
            }
        }
    }

    if(q < a[0]) result = 0;
    else if(q == a[0]) result = func[0];
    else if(p > a[a.size()-1]) result = (q-p+1) * func[a.size()-1];
    else{
        if(p < a[0]) p = a[0];
        if(a.size() == 1){
            if(p <= a[0]) result = (q-a[0]+1) * func[0];
            else result = (q-p+1) * func[0];
        }
        for (int i = 0; i < a.size(); i++){
            if(i == a.size()-1){
                result += (q-p+1) * func[i];
                break; 
            }
            else if(a[i] <= p && p < a[i+1]){
                gap = a[i+1] - p;
                if(gap > q-p){
                    result += (q-p+1) * func[i];
                    break;
                }
                else if(gap == q-p){
                    result += (q-p) * func[i] + func[i+1];
                    break;
                }
                else{
                    result += gap * func[i];
                    p += gap;
                }
            }
        }
    }
    cout << (result % 10007) << "\n";

    return 0;
}
