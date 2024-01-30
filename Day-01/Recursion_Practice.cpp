#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
//Question-1 => subswquence of a string(power set of string)
void subsequence(string s, string ans,int i=0){
    if(i>=s.length()){
        cout<<ans<<endl;
        return;
    }    
    subsequence(s,ans,i+1);
    ans.push_back(s[i]);
    subsequence(s,ans,i+1);
}

    //Question-2 => Array given hai and target hai ab element ka sum se jo bhi target hai unke pair print karana hai
int targetSumPair(vector<int> arr, int target){
    if(target == 0){
        return 0;
    }
    if(target < 0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++){
        int ans = targetSumPair(arr, target - arr[i]);
        if(ans != INT_MAX){
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

// Question-3 => Cut into segments of given length x, y, z and find the maximum number of cuts needed
int minCut(int n, int x, int y, int z){
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return INT_MAX;
    }
    int a = minCut(n-x, x, y, z) + 1;
    int b = minCut(n-y, x, y, z) + 1;
    int c = minCut(n-z, x, y, z) + 1;

    int ans = max(a,max(b,c));
    return ans;
}

// Question-4 => Max sum of non-adjacent elements
int maxSum(vector<int> arr,int i, int sum, int maxi){
    if(i>=arr.size()){
        maxi = max(maxi, sum);
        return maxi;
    }
    //include
    maxSum(arr, i+2, sum+arr[i], maxi);
    //exclude
    maxSum(arr, i+1, sum, maxi);
}

//Question-5 => Last Occurrence of character
int lastOccurrence(string s, char x, int ans, int i){
    if(s[i] == x){
        ans = i;
    }
    if(i == s.length()){
        return ans;
    }
    return lastOccurrence(s, x, ans, i+1);
}

//Question-6 => Reverse a string
int rev(string s,int i,int e){
    if(i>=e){
        return 0;
    }
    swap(s[i],s[e]);
    return rev(s,i+1,e-1);
}

//Question-7 => Adding two numbers in a string
string add(string s1, string s2, int carry, int p1, int p2){
    if(p1 < 0 && p2 < 0){
        if(carry != 0){
            return string(1, carry + '0');
        }
        return "";
    }
    int n1 = (p1 >= 0 ? s1[p1] - '0' : 0);
    int n2 = (p2 >= 0 ? s2[p2] - '0' : 0);
    int sum = n1 + n2 + carry;
    return add(s1, s2, sum / 10, p1 - 1, p2 - 1) + string(1, sum % 10 + '0');
}

//Question-8 => Printing all subarray
int subarray(vector<int> arr1,int i,int e){
    if(e>= arr1.size()){
        return 0;
    }
    for (int j=i;j<=e;j++){
        cout<<arr1[j]<<" ";
    }
    cout<<endl;
    return subarray(arr1,i,e+1);
}
int main(){
    //Question-1
    string s;
    cout<<"Enter string:  ";
    cin>>s;
    string ans="";
    subsequence(s,ans);


    //Question-2
    int target;
    cout << "Enter target from 1 to 9:  ";
    cin >> target;
    vector<int> arr{1,2,3,4,5,6,7,8,9};
    cout << targetSumPair(arr, target) << endl;


    //Question-3
    int n=7;
    int x = 5;
    int y = 2;
    int z = 2;
    cout<<minCut(n, x, y, z);

    //Question-4
    vector<int> arr1{5, 5, 10, 100, 10, 5};
    int maxi = INT_MIN;
    cout<<maxSum(arr1,0,0,maxi);

    //Question-5
    cout<<lastOccurrence("aabaa", 'a',0,0);

    //Question-6
    int i = 0;
    int e = s.length()-1;
    cout<<rev(s,i,e);

    //Question-7
    string s1 = "123";
    string s2 = "456";
    cout << add(s1, s2, 0, s1.length() - 1, s2.length() - 1) << endl;


    //Question-8   
    std::vector<int> arr1{1,2,3,4};
    cout<<subarray(arr1,0,0);
    return 0;
}