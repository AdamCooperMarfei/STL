#include<numeric>
#include<vector>
#include<functional>
#include<iostream>
#include<iterator>
using namespace std;
struct distance1{
    int dis;
    distance1(int x):dis(x){}
    void operator()(int &x){
        x = x - dis;
    }
};
int main(){
    int ia[5] = {1, 2, 3, 4, 5};
    vector<int> iv(ia, ia + 5);
    distance1 a(5);
    for_each(iv.begin(), iv.end(), a);
    for(int i = 0; i < iv.size(); ++i)
        cout<<iv[i]<<' ';
    cout<<accumulate(iv.begin(), iv.end(), 0)<<endl;
    cout<<accumulate(iv.begin(), iv.end(), 0, minus<int>())<<endl;
    cout<<inner_product(iv.begin(), iv.end(), iv.begin(), 10)<<endl;
    //cout<<inner_product(iv.begin(), iv.end(), iv.begin(), 10, minus<int>(), plus<int>());
    ostream_iterator<int> oite(cout, " ");
    partial_sum(iv.begin(), iv.end(), oite);
    partial_sum(iv.begin(), iv.end(), oite, minus<int>());
    adjacent_difference(iv.begin(), iv.end(), oite);
    //adjacent_difference(iv.begin(), iv.end(), plus<int>());
    int n = 3;
    iota(iv.begin(), iv.end(), n);
    for(int i = 0; i < iv.size(); ++i)
        cout<<iv[i]<<' ';
    return 0;
}