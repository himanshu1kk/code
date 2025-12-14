#include<bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int> seg;

    public:

    SGTree(int n){
        seg.resize(4*n +1);
    }

void build(int index , int low , int high , int arr[] ){
    if(low==high){
        seg[index] = arr[low];
        return ;
    }

    int mid = (low + (high - low)/2);

    build(2*index + 1 , low , mid , arr);
    build(2*index + 2 , mid + 1 , high , arr);

    seg[index] = min(seg[2*index + 1 ] , seg[2*index + 2]);

    return ;
}

int query(int index , int low  ,  int high , int l  , int  r, int arr[] ){
    //no overlap 
    //[l r ] [low high] //[low high][l r]
    if(r<low || high<l){
        return INT_MAX;
    }

    //complete overlap
    //[l low high r]
    else if(low>=l && high <=r){

        return seg[index];
    }

    int mid = (low + (high - low)/2);
    int lh  = query(2*index +1  , low , mid , l , r , arr );
    int rh = query(2*index + 2 , mid + 1 ,  high , l , r  , arr );
    return min(lh , rh);
    
}

void update(int index , int updateindex , int no ,  int low , int high  , int arr[] , int seg[]){
    if(low==high){
        seg[index] = no;
        return ;
    }

    int mid = (low + (high - low)/2);

    if(updateindex<=mid){
        update(2*index + 1 , updateindex , no  , low , mid , arr , seg);
    }
    else{
        update(2*index + 2 , updateindex , no , mid +1 , high , arr  , seg);
    }

    seg[index] = min(seg[2*index + 1] , seg[2*index + 2]);
    return ;

}
};


int main(){
    SGTree sg1(6);
    //pass the params inside the build methods and this will build for sg1 sg1.build()
    SGTree sg2(6);

//pass the params inside the build method and this will build for sg2 sg2.build()

//now whenever you wanted to make a call just make a call to update aur query //



}