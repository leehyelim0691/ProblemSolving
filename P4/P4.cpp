#include <iostream>
#include <vector>  
using namespace std;

struct func_f{
    int a_f;
    int fa;
};
struct func_g{
    int a_g;
    int ga;
};


int main(void){
    int p, q, kf, kg, result = 0, index[2] = {0}, gap, before = 0;
    vector<int> a;  
    vector<int> func;  

    cin >> kf;
    struct func_f ff[kf];
    for(int i = 0; i < kf; i++) cin >> ff[i].a_f >> ff[i].fa;

    cin >> kg;
    struct func_g fg[kg];
    for(int i = 0; i < kg; i++) cin >> fg[i].a_g >> fg[i].ga;

    cin >> p >> q;

    while(1){
        if(index[0] >= kf && index[1] >= kg) break;
        else if(index[0] >= kf){
            if(before < fg[index[1]].ga){
                a.push_back(fg[index[1]].a_g);
                func.push_back(fg[index[1]].ga);
                before = fg[index[1]].ga;
            }
            index[1]++;
        }
        else if(index[1] >= kg){
            if(before < ff[index[0]].fa){
                a.push_back(ff[index[0]].a_f);
                func.push_back(ff[index[0]].fa);
                before = ff[index[0]].fa;
            }
            index[0]++;
        }
        else{
            if(ff[index[0]].a_f < fg[index[1]].a_g) {
                if(before < ff[index[0]].fa){
                    // printf("11. %d %d vs %d %d\n", ff[index[0]].a_f, ff[index[0]].fa, fg[index[1]].a_g, fg[index[1]].ga);
                    a.push_back(ff[index[0]].a_f);
                    func.push_back(ff[index[0]].fa);
                    before = ff[index[0]].fa;
                }
                index[0]++;

                // a.push_back(ff[index[0]].a_f);
                // func.push_back(ff[index[0]].fa);
                // index[0]++;
            }
            else if(ff[index[0]].a_f > fg[index[1]].a_g) {
                if(before < fg[index[1]].ga){
                    // printf("22. %d %d vs %d %d\n", ff[index[0]].a_f, ff[index[0]].fa, fg[index[1]].a_g, fg[index[1]].ga);
                    a.push_back(fg[index[1]].a_g);
                    func.push_back(fg[index[1]].ga);
                    before = fg[index[1]].ga;
                }
                index[1]++;

                // a.push_back(fg[index[1]].a_g);
                // func.push_back(fg[index[1]].ga);      
                // index[1]++;
            }
            else if(ff[index[0]].a_f == fg[index[1]].a_g) {
                // printf("33\n");
                if(ff[index[0]].fa > fg[index[1]].ga){
                    a.push_back(ff[index[0]].a_f);
                    func.push_back(ff[index[0]].fa); 
                    before = ff[index[0]].fa;
                }
                else{
                    a.push_back(fg[index[1]].a_g);
                    func.push_back(fg[index[1]].ga);  
                    before = fg[index[1]].ga;
                }
                index[0]++;
                index[1]++;
            }
        }
    }
    for (int i = 0; i < a.size(); i++)
        cout << "a is " << a[i] << " f is " <<func[i] << "\n";


    // a.push_back(1);
    // a.push_back(3);
    // a.push_back(4);
    // a.push_back(7);
    // a.push_back(13);
    // func.push_back(1);
    // func.push_back(3);
    // func.push_back(7);
    // func.push_back(12);
    // func.push_back(13);

    // cin >> p >> q;


    if(q < a[0]) result = 0;
    else if(q == a[0]) result = func[0];
    else if(p > a[a.size()-1]) result = (q-p+1) * func[a.size()-1];
    else{
        if(p < a[0]) p = a[0];
        for (int i = 0; i < a.size(); i++){
            // printf("** i is %d, p is %d, result is %d\n",i,p,result);
            if(a.size() == 1){
                if(p <= a[0]) result = (q-a[0]+1) * func[0];
                else result = (q-p+1) * func[0];
            }
            else if(i == a.size()-1){
                result += (q-p+1) * func[i];
                // printf("11. p is %d, q is %d, result is %d\n",p ,q, result);
                break; 
            }
            else if(a[i] <= p && p < a[i+1]){
                gap = a[i+1] - p;
                if(gap > q-p){
                    result += (q-p+1) * func[i];
                    // printf("22. p is %d, q is %d, result is %d\n",p ,q, result);
                    break;
                }
                else if(gap == q-p){
                    result += (q-p) * func[i] + func[i+1];
                    // printf("33. p is %d, q is %d, result is %d\n",p ,q, result);
                    break;
                }
                else{
                    result += gap * func[i];
                    // printf("44. p is %d, q is %d, result is %d\n",p ,q, result);
                    p += gap;
                }
            }
            // else {
            //     p++;
            //     printf("00. pass. now p is %d\n",p);
            // }
        }
    }

    cout << (result % 10007) << "\n";

    return 0;
}