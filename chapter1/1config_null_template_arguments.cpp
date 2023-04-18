//test stl null template arguments
#include<iostream>
#include<cstddef> //for size_t
using namespace std;
class alloc{

};
//deque
template<class T, class Alloc = alloc, size_t BufSiz = 0>
class deque{
    public:
    deque(){cout<<"deque"<<' ';}
};
template<class T, class Sequence = deque<T>>
class stack{
    //OK
    friend bool operator==<T>(const stack<T>&, const stack<T>&);
    friend bool operator<<T>(const stack<T>&, const stack<T>&);
    //OK
    friend bool operator==<T>(const stack&, const stack&);
    friend bool operator<<T>(const stack&, const stack&);
    //OK
    friend bool operator==<>(const stack&, const stack&);
    friend bool operator<<>(const stack&, const stack&);
    //NOT OK
    //friend bool operator==(const stack&, const stack&);
    //friend bool operator<(const stack&, const stack&);
    public:
    stack(){cout<<"stack"<<endl;}
    private:
    Sequence c;
};
template<class T, class Sequence>
bool operator==(const stack<T, Sequence>&x, const stack<T, Sequence>&y){
    return cout<<"operator =="<<'\t';
}
template<class T, class Sequence>
bool operator<(const stack<T, Sequence>&x, const stack<T, Sequence>){
    return cout<<"operator <"<<'\t';
}
int main(){
    stack<int> x;
    stack<int> y;
    cout<<(x==y)<<endl;
    cout<<(x<y)<<endl;
    stack<char> y1;
}

