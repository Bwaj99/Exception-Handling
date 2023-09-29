#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index); //returns integer that represents the index of the minimum element in the vector

template<typename T>
void selection_sort(vector<T> &vals); //takes a reference to a vector vals of type T and sorts it in ascending order 

template<typename T>
T getElement(vector<T> vals, int index); ////takes copy of a vector vals of type T and an integer index and returns element of vector at the given index
vector<char> createVector();  //returns a vector of characters

int main(){ //Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0){
        cout << "Enter a number: " << endl;
        cin >> index;
        curChar = getElement(vals,index);
        cout << "Element located at " << index << ": is " << curChar << endl;
    }

    vector<int> myVector{5, 2, 10, 7, 1, 6};
    selection_sort(myVector);
    if (myVector.at(0) != 1){
        cout << "Selection sort does not work" << endl;
    }else{
        cout << "Selection sort works!" << endl;
    }

    return 0;
}

vector<char> createVector(){ //Given
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++){
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned indexMin = index;
    for (unsigned i = index; i < vals.size(); ++i){ //compares each element with the current minimum element
        if (vals.at(i) < vals.at(indexMin)){
            indexMin = i; //element smaller than existing minimum element is stored in indexMin
        }
    }

    return indexMin; //returns index of the smallest element found
}

template<typename T>
void selection_sort(vector<T> &vals) {
    for (unsigned i = 0; i < vals.size(); ++i){
        unsigned minValue = min_index(vals, i); //finding index of the smallest element starting from each index
        T temp = vals.at(i);
        vals.at(i) = vals.at(minValue); //swaps the current element with the smallest element found 
        vals.at(minValue) = temp; //repeats process until entire vector is sorted in ascending order
    }
}

template<typename T>
T getElement(vector<T> vals, int index) {
    return vals.at(index); //takes a copy of vals of type T and an integer index and returns element of the vector at given index
}