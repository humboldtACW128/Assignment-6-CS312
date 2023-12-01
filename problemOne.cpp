#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>

using namespace std;

vector<int> greedyActivityAlgorithm(int[],int[],int);
vector<int> greedyActivityAlgorithmWithDuration(int[],int[],int,vector<int>);

int main(int argc,char **argv) {

    int n = 11;
    int starts[n] = {1,3,0,5,3,5,6,8,8,2,12};
    int ends[n] = {4,5,6,7,9,9,10,11,12,14,16};
    vector<int> durs;
    map<int,int> durationCount;
    for(int i = 0;i < n;i++) {
        if (durationCount[ends[i] - starts[i]] < 1) {
            durationCount[ends[i] - starts[i]]++;
            durs.push_back(ends[i] - starts[i]);
        }
    }
    sort(durs.begin(),durs.end());
    vector<int> path = greedyActivityAlgorithmWithDuration(starts,ends,n,durs);
    for(int i =0;i < path.size();i++) {
        cout << starts[path[i]] << " " << ends[path[i]] << endl;
    }
    return 0;
};

vector<int> greedyActivityAlgorithm(int s[],int f[],int n) {
    vector<int> temp;
    temp.push_back(0);
    int j = 0;
    for(int i = 1;i < n;i++) {
        if(s[i] >= f[j]) {
            temp.push_back(i);
            j=i;
        }
    }
    return temp;
};

// int s[]            - Holds start times.
// int f[]            - Holds finish times.
// int n              - Holds array length.
// vector<int> durs   - Holds the durations from smallest to largest.
vector<int> greedyActivityAlgorithmWithDuration(int s[],int f[],int n,vector<int> durs) {
    vector<int> temp;
    int j = 0;
    //Choose earliest meeting with shortest duration.
    for(int i = 0;i < n;i++) {
        if((f[i] - s[i]) == durs[0]) {
            temp.push_back(i);
            j=i;
            break;
        }
    }
    //Choose earliest meetings after first chosen with shortest duration.
    for(int k = 0;k <= durs.size();k++) {
        for(int i = 1;i < n;i++) {
            if(s[i] >= f[j] && (f[i] - s[i]) <= durs[k]) {
                temp.push_back(i);
                j=i;
            }
        }
    }
    return temp;
};





