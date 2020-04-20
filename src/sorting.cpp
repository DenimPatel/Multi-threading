#include <iostream>
#include <vector>

using namespace std;

namespace Merge{

void merge( vector<int>& array, int left, int mid, int right){

    vector<int> arr1;
    for(int i=left; i<=mid; i++){
        arr1.push_back(array[i]);
    }
    vector<int> arr2;
    for(int i=mid+1; i<=right; i++){
        arr2.push_back(array[i]);
    } 
    // sort arr1 and arr2
    int arr1_index = 0;
    int arr2_index = 0;
    int k = left;
    while (arr1_index<arr1.size() and arr2_index<arr2.size()) {
        if (arr1[arr1_index]<=arr2[arr2_index]) {
            array[k++] = arr1[arr1_index];
            arr1_index++;
        }
        else{
            array[k++] = arr2[arr2_index];
            arr2_index++;
        }
    }
    while(arr2_index<arr2.size()){
        array[k++] = arr2[arr2_index];
            arr2_index++;
    }
    while(arr1_index<arr1.size()){
        array[k++] = arr1[arr1_index];
            arr1_index++;
    }
}
void mergeSortUtil(vector<int>& data, int left, int right) {

    if(left<right){
        int mid = (left+right)/2;
        mergeSortUtil(data, left, mid);
        mergeSortUtil(data, mid+1, right);
        merge(data, left, mid, right);
    }

}
void mergeSort(vector<int>& data){
    mergeSortUtil(data, 0, data.size()-1);
}

}   // END OF NAMESPACE: Merge

namespace QuickSort {

int partition(vector<int>& data, int start, int end){
    // pivot is chosen as the last element
    int pivot = data[end];
    int small_index = start-1;
    for(int i=start; i<end; i++){
        if(data[i]<pivot){
            small_index++;
            swap(data[small_index], data[i]);
        }
    }
    swap(data[end], data[small_index+1]);
    return small_index+1;
}
void quickSortUtil(vector<int>& data, int start, int end){
    if (start<end) {
        // put pivot element at correct position
        int index = partition(data, start, end);
        // then solve two sub problems
        quickSortUtil(data, start, index-1);
        quickSortUtil(data, index+1, end);   
    }
}
void quickSort(vector<int>& data){
    quickSortUtil(data, 0, data.size()-1);
}

}   // END OF QuickSort

int main(){

    vector<int> data = {1,42,3,64,5,86,7};
    auto vec = data;
    //////////////////////////////////
    //  Bubble sort
    //////////////////////////////////
    for(int i=0; i<vec.size(); i++){
        for(int j=i+1; j<vec.size(); j++){
            if(vec[i]>vec[j]) {
                swap(vec[j], vec[i]);
            }
        }
    }

    //////////////////////////////////
    //  Selection sort
    //////////////////////////////////
    vec = data;
    int smallest = 1e5;
    int smallest_index = -1;
    for(int i=0; i<vec.size(); i++){
        smallest = 1e5;
        for(int j=i; j<vec.size(); j++){
            if(vec[j]<smallest){
                smallest_index = j;
                smallest = vec[j];
            }
        }
        swap(vec[i], vec[smallest_index]);
    }

    //////////////////////////////////  
    //  Insertion sort
    //////////////////////////////////
    vec = data;
    for(int i=1; i<vec.size(); i++){
        int key = vec[i];
        int j = i-1;
        while(j>=0 and vec[j]>key){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }

    //////////////////////////////////  
    //  Merge sort
    //////////////////////////////////
    vec = data;
    Merge::mergeSort(vec);

    //////////////////////////////////  
    //  Quick sort
    //////////////////////////////////
    vec = data;
    QuickSort::quickSort(vec);

    for(const auto& item: vec){
        cout<<item <<" ";
    }

    


    return 0;
}