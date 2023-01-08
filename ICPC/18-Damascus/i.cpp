#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T, n;
    
    cin >> T;
    while(T--){
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i<n; ++i){
            cin >> v[i];
        }

        if(n == 1){
            if(v[0] & 1) cout << "Yalalov\n";
            else cout << "Shin\n"; 
            continue;
        }
        else if(n == 2){
            if(v[0] == 1 || v[1] == 1){
                cout << "Yalalov\n";
                continue;
            } 
            else{
                cout << "Shin\n";
                continue;
            }
            if(v[0] % 2 == 0 && v[1] % 2 == 0){
                cout << "Shin\n";
                continue;
            }
            else {
                cout << "Yalalov\n";
                continue;
            }
            
        }
        else{
            int odd = 0, even = 0;
            for(int i = 0; i<n; ++i){
                if(v[i] & 1) odd++;
                else even++;
            }
            if(n & 1){
                if(even & 1)cout << "Shin\n";
                else cout << "Yalalov\n";
                continue;
            }
            else{
                int mid = n/2;
                if(even > mid){
                    if(even % 2 == 0) cout << "Shin\n";
                    else cout << "Yalalov\n";
                    continue;
                }
                if(even == mid){
                    cout << "Yalalov\n";
                    continue;
                }
                if(even < mid){
                    if(even % 2 == 0) cout << "Yalalov\n";
                    else cout << "Shin\n";
                    continue;
                }
            }
        }
    }
    return 0;
}