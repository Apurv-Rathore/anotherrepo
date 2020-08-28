#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

//define a type p just a pair
typedef pair<int,int> p;

//function to compare two pairs
int compare(p p1,p p2){
        if(p1.first == p2.first){
                //note that if the element values are equal the latter element of original array comes first
                return p1.second > p2.second;
        }
        return p1.first < p2.first;
}

//building the segment tree - more like updating the initial tree
void buildTree(int* tree,int pos,int low,int high,int ind,int val){
        //ind - is the original index of current element
        //if ind is out of range of the current range, just stop
        if(ind < low || ind > high) return;
        //if low == high then the current position should be updated to the value
        if(low == high){
                tree[pos] = val;
                return;
        }

        //take the mid point
        int mid = (high+low)/2;

        //recursivly call the function on the child nodes
        buildTree(tree,2*pos + 1,low,mid,ind,val);
        buildTree(tree,2*pos + 2,mid+1,high,ind,val);

        //assign the current position the max of the 2 child nodes
        tree[pos] = max(tree[2*pos + 1],tree[2*pos + 2]);
}

//function to query the tree and find the maximum in given range upto now
int findMax(int* tree,int pos,int low,int high,int st,int ed){
        //uses the 3 rules of segment tree query
        //if the current range is totally inside the query range return the value of current position
        if(low >= st && high <= ed){
                return tree[pos];
        }
        //if it's out of bounds, return the minimum which would be 0 in this case
        if(st > high || ed < low){
                return 0;
        }


        int mid = (high+low)/2;

        //else do the findMax on child nodes and return the maximum of the two
        return max(findMax(tree,2*pos + 1,low,mid,st,ed),findMax(tree,2*pos + 2,mid+1,high,st,ed));
}

int main(){
        int ary[] = {3,1,2,8;

        int n = 4;
        //generate the ary of pairs, we use pairs to store both the element and the index
        p* pairs = new p[n];
        for(int i=0;i<n;i++){
                pairs[i].first = ary[i];
                pairs[i].second = i;
        }

        //using custom sorter to sort the array
        sort(pairs,pairs+n,compare);

        //the max length of segment tree is 2x(nearest power of 2 near n) - 1
        int len = pow(2,(int)(ceil(sqrt(n))) + 1) - 1;
        int* tree = new int[len];

        //loop all the pairs and update the tree
        for(int i=0;i<n;i++){
                buildTree(tree,0,0,n-1,pairs[i].second,findMax(tree,0,0,n-1,0,pairs[i].second) + 1);
        }

        //print the end tree just for debug
        for(int i=0;i<len;i++){
                cout << tree[i] << " ";
        }
        cout << endl;

        //print the value of the longest subsequenc which is the root value
        cout << tree[0] << endl;



}
