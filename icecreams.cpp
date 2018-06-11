#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


// void merge (int arr[], int l, int m, int r){

//     int i, j, k;
//     int n1 = m - l + 1;
//     int n2 = r - m;
//     //int L[n1], R[n2];
//     vector<pair<int, int> >L(n1), R(n2);

//     for (i = 0; i < n1; i++){
//         L[i] = arr[i + l];
//     }

//     for (j = 0; j < n2; j++)
//         R[j] = arr[j + m + 1];

//     i=0;
//     j=0;
//     k=l;

//     while (i<n1 && j< n2){
//         if(L[i].first <= R[j].first)
//             arr[k++] = L[i++];
//         else 
//             arr[k++] = R[j++];
//     }

//     while (i < n1)
//         arr[k++]=L[i++];
    
//     while (j < n2)
//         arr[k++]=R[j++];
// }

// void mergeSort(vector<pair<int,int> > arr, int l, int r){
//     if (l<r){
        
//         int m = l+(r-l)/2;

//         mergeSort(arr, l, m);
//         mergeSort(arr, m+1, r);
//         merge(arr, l, m, r);
//     }
// }



void solve(vector <int> arr, int money) {
    
    unordered_map<int, pair<int, int> > iceCreamMap;

    for (int i = 0; i<arr.size(); i++){
        if (iceCreamMap.find(money-arr[i]) == iceCreamMap.end()){
            iceCreamMap[money-arr[i]].first = arr[i];
            iceCreamMap[money-arr[i]].second = i;
        }
    }

    for (int i = 0; i<arr.size(); i++){
        if ((iceCreamMap.find(arr[i]) != iceCreamMap.end()) && i!=iceCreamMap[arr[i]].second){
            fout << (i<iceCreamMap[arr[i]].second?i:iceCreamMap[arr[i]].second) + 1 << ' ' <<(i>iceCreamMap[arr[i]].second?i:iceCreamMap[arr[i]].second) + 1<< endl;
            return;
        }
    }

    // // create my data structure
    // vector<pair<int, int> >ds(arr.size());
    // for (int i=0; i<arr.size(); i++){
    //     ds[i].first = arr[i];
    //     ds[i].second = i;
    // }
    
    // // sort dell'array
    // sort(ds.begin(), ds.end());

    // int i=0, j = arr.size()-1;
    // while (i!=j){
    //     if (money == (ds[i].first + ds[j].first)){
    //         fout << (ds[i].second < ds[j].second ? ds[i].second : ds[j].second ) + 1 << ' ' << (ds[i].second > ds[j].second ? ds[i].second : ds[j].second) + 1 << endl;
    //         return;
    //     }

    //     if ((ds[i].first + ds[j].first) < money)
    //         i++;
        
    //     else j--;
    // }

}

int main() {
    int t;
    fin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int money;
        fin >> money;
        int n;
        fin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           fin >> arr[arr_i];
        }
        solve(arr, money);
    }
    return 0;
}
