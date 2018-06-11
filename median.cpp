#include <bits/stdc++.h>

using namespace std;

float findTheMedian(vector<int>v){
    int n= v.size();
    if(n%2==0){
        float sol;
        nth_element(v.begin(), v.begin() + n/2-1, v.end());
        sol = (float)v[n/2-1];
        nth_element(v.begin(), v.begin() + n/2, v.end());
        sol+= (float)v[n/2];
        return sol/2;
    }
    else {
        nth_element(v.begin(), v.begin() + (n-1)/2, v.end());
        return (float)v[(n-1)/2];

    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a;
    cout.precision(2);
    
    for (int i = 0; i < n; i++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a.push_back(a_item);
        printf("%.1f\n", findTheMedian(a));
    }

    return 0;
}
