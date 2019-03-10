template <class T1, class T2> 
    inline const pair<T1,T2> operator-(const pair<T1,T2> &p1,const pair<T1,T2> &p2){
        pair<T1,T2> res;
        res.first = p1.first-p2.first;
        res.second = p1.second-p2.second;
        return res;
    }
template <class T1, class T2>
    inline const int operator *(const pair<T1,T2> &p1,const pair<T1,T2> &p2){
        return p1.first*p2.second - p1.second*p2.first;
    }

ostream& operator<<(ostream& os, const pair<int,int> p){
    cout<<"{"<<p.first<<","<<p.second<<"}"<<endl;
    return os;
}
class Solution {
public:
    friend ostream& operator<<(ostream& os, const pair<int,int> p);
    
    bool intersect(pair<int,int> &A, pair<int,int> &B, pair<int,int> &C, pair<int,int> &D) {
//         A, B are on the opposite sides of CD
        int p0 = ((D-C)*(A-C))*((D-C)*(B-C));
//         C, D are on the opposite sides of AB
        int p1 = ((B-A)*(C-A))*((B-A)*(D-A));
        return p0<=0 && p1<=0;
    }
};