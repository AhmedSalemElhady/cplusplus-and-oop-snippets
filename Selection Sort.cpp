#include <iostream>
#include <vector>
#include <chrono>
using namespace std;



vector<int> selectionSort(vector<int> arrToSort){

    vector<int> sortedVector(arrToSort.size());
    int minimumValue; 

    int nextIndexInSortedArray = 0;
    while (nextIndexInSortedArray < sortedVector.size()){
        minimumValue = 999999; // * infinity

        for(int i = 0; i<arrToSort.size(); ++i){
            if(nextIndexInSortedArray ==0 ){
                if(arrToSort[i] < minimumValue)
                    minimumValue = arrToSort[i];
            }
            else {
                if(arrToSort[i] < minimumValue && arrToSort[i]> sortedVector[nextIndexInSortedArray-1])
                    minimumValue = arrToSort[i];
            }      
        }
        // * min Value heya as3'ar wa7ed fel arrToSort beykon akbar men a5er raqam fel sortedVector
        sortedVector[nextIndexInSortedArray] = minimumValue;
        nextIndexInSortedArray ++;
    }
    return sortedVector;
}


// * N.B: arr should be passed by reference not value, since it is in-place sort
void insertionSort(vector<int>& arrToSort){

    //* start from index 1 msh 0 3ashan single element is always sorted
    int index = 1;
    while(index < arrToSort.size()){
        //* loop from index --> 0:
        for(int i = index; i>0; i--){
            if(arrToSort[i] < arrToSort[i-1]){
                // ** Swap them

                int holder = arrToSort[i];
                arrToSort[i] = arrToSort[i-1];
                arrToSort[i-1] = holder;
            }
        }
        index ++;
    }
}

// * N.B: arr should be passed by reference not value, since it is in-place sort
void bubbleSort(vector<int>& arrToSort){

    bool swapHappened;

    do{
        swapHappened = false;
        
        for( int i=0; i<=arrToSort.size()-2; i++){

            if(arrToSort[i] > arrToSort[i+1]){
                //* Swap them
                int holder = arrToSort[i];
                arrToSort[i] = arrToSort[i+1];
                arrToSort[i+1] = holder;
                swapHappened = true;
            }   
        }
    }while(swapHappened==true);

}

void printVector(vector<int> vec){

    for(vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr ++ ){
        cout<<(*itr)<<" ";
    }
    cout<<endl;
}


vector<int> merge(vector<int> left, vector<int>right){


    int leftPartIdx = 0;
    int rightPartIdx = 0;

    vector<int> mergedArr;
    while(leftPartIdx < left.size() && rightPartIdx < right.size()){

        if(left[leftPartIdx] < right[rightPartIdx]){
            mergedArr.push_back(left[leftPartIdx]);
            leftPartIdx ++;
        }else{
            mergedArr.push_back(right[rightPartIdx]);
            rightPartIdx ++;
        }
    }

    // * Et2aked en both arrays are finished, if not put the unfinished one completely:
    while(leftPartIdx < left.size()){
        mergedArr.push_back(left[leftPartIdx]);
        leftPartIdx ++;
    }

    while(rightPartIdx < right.size()){
        mergedArr.push_back(right[rightPartIdx]);
        rightPartIdx ++;
    }

    return mergedArr;
}

vector<int> mergeSort(vector<int> arrToSort){


    // * Termintion Condition:
    if(arrToSort.size() == 1){
        return arrToSort;
    }

    // * split to two parts
    int middle = arrToSort.size()/2;

    vector<int> leftPart;
    // fill in left part
    for(int i=0; i<middle; ++i){
        leftPart.push_back(arrToSort[i]);
    }

    vector<int> rightPart;
    for(int i=middle; i<arrToSort.size(); ++i){
        rightPart.push_back(arrToSort[i]);
    }


    // * then recursively call:
    vector<int> leftArraySorted = mergeSort(leftPart);
    vector<int> rightArraySorted = mergeSort(rightPart);

    // * Merge the two sorted parts
    return merge(leftArraySorted, rightArraySorted);
}

int main(){

    vector<int> notSorted;
    notSorted.push_back(5);
    notSorted.push_back(1);
    notSorted.push_back(4);
    notSorted.push_back(9);
    notSorted.push_back(7);
    notSorted.push_back(3);
    notSorted.push_back(8);
    notSorted.push_back(2);
    notSorted.push_back(10);
    notSorted.push_back(6);

    cout<<"Unsorted List:\n";
    printVector(notSorted);
    auto start = std::chrono::high_resolution_clock::now();
    vector<int> sorted = selectionSort(notSorted);
    auto stop = std::chrono::high_resolution_clock::now();

    cout<<"Sorted List by Selection Sort:\n";
    printVector(sorted);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout<<"It took time: "<<duration.count()<<endl;
    cout<<"--------------\n"; 

    vector<int> insertionSortVec = notSorted;
    auto start2 = std::chrono::high_resolution_clock::now();
    insertionSort(insertionSortVec);
    auto stop2 = std::chrono::high_resolution_clock::now();
    cout<<"Sorted List by Insertion Sort:\n";
    printVector(insertionSortVec);   
    auto duration2= std::chrono::duration_cast<std::chrono::microseconds>(stop2- start2);
    cout<<"It took time: "<<duration2.count()<<endl;
    cout<<"--------------\n"; 

    vector<int> bubbleSortVec = notSorted;
    auto start3 = std::chrono::high_resolution_clock::now();
    bubbleSort(bubbleSortVec);
    auto stop3 = std::chrono::high_resolution_clock::now();
    cout<<"Sorted List by Bubble Sort:\n";
    printVector(bubbleSortVec);  
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);
    cout<<"It took time: "<<duration3.count()<<endl;
    cout<<"--------------\n"; 

    auto start4 = std::chrono::high_resolution_clock::now();
    vector<int> mergeSortVec = mergeSort(notSorted);
    auto stop4 = std::chrono::high_resolution_clock::now();
    cout<<"Sorted List by Merge Sort:\n";
    printVector(mergeSortVec);    
    auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(stop4 - start4);
    cout<<"It took time: "<<duration4.count()<<endl;
    cout<<"--------------\n"; 

    return 0;
}