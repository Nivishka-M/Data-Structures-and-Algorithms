#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n = 9;
    int arr[n] = {-1,6,15,0,-4,5,-6,20,-13};
    int temp[n];
    float median = 0;

    for (int i = 0; i<= n-1; i++){
            temp[i] = arr[i];
            cout << "Current array :";
            sort(temp, temp + 1);
        // i is (length of the temp array-1)
            int templen =i+1;
            for (int j = 0; j<= i; j++)
                    cout << temp[j]<<" ";
            
            if (templen %2 == 0) {  
                // when templen is even
                median = (float(temp[i/2]-1) + float(temp[(i/2)])) / 2;
                cout <<"     median is  :=>" << median;
            }
            else{
                median = float(temp[i/2]);
                cout <<"     median is  :=>"<< median;

            }
            cout<<endl;  

    }
}
