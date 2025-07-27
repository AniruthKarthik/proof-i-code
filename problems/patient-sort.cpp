#include <iostream>
#include <vector>
using namespace std ;

class MergeSort{
public:

    static void mergesort(vector<char>&arr,int low,int high){
        if(low<high){
            int mid=(low+high)/2;
            mergesort(arr, low, mid);
            mergesort(arr, mid+1, high);
            merge(arr,low,mid,high );
        }
        return;
    }

    static void merge(vector<char>&arr,int left,int mid,int right){
        vector<int>temp;
        int i=left;
        int j=mid+1;
        while (i<=mid && j<=right) {
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }}
        while (i<=mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while (j<=right) {
            temp.push_back(arr[j]);
            j++;
        }
        for (int k= left;k<=right;k++) {
            arr[k]=temp[k-left];
        }
    }
};

class Hospital{
private:
    vector<char>patients={};

public:
    Hospital(vector<char>&vec):patients(vec){};

    vector<char>& get_patients(){
        return patients;
    }

    void print_patients_list(){
        for(char c:patients){
            cout<< c<<" ";
        }
        cout<<endl;
    }

};

int main(){
    int n;
    cout << "enter no of patients: ";
    cin >> n;
    vector<char> patients(n);
    cout << "enter patient type(C, O, Y): ";
    for (int i = 0; i < n; ++i) {
        cin >> patients[i];
    }
    Hospital hosp(patients);
    cout<<"before sorting: \n";
    hosp.print_patients_list();
    MergeSort sorter;
    sorter.mergesort(hosp.get_patients(), 0,hosp.get_patients().size()-1 );
    cout<<"after sorting: \n";
    hosp.print_patients_list();
}
