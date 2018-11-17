#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Heap
{
    //parent = (index-1)/2
    //left = index*2 + 1
    //right = index*2 + 2

    vector<int> root;

public:

    enum HeapType {MIN , MAX };

    void insert(int d)
    {
        root.push_back(d);
    }

    void print() const
    {
        for(auto const& value: root)
            cout << value << " ";

        cout << endl;
    }

    void sort(vector<int> & sortedArray, Heap::HeapType heapType) const
    {
        vector<int> sortedArr;
        vector<int> tempRoot = root;

        while(!tempRoot.empty())
        {
            for(int i = 0 ; i < tempRoot.size(); ++i)
                heapify(i, tempRoot, heapType);

            sortedArray.push_back(tempRoot[0]); //first element of root

            tempRoot[0] = tempRoot[tempRoot.size() - 1];

            tempRoot.pop_back();
        }
    }

    void createMinHeap()
    {
        for(int i = 0 ; i < root.size(); ++i)
            heapify(i, root, Heap::MIN);
    }

    void createMaxHeap()
    {
        for(int i = 0 ; i < root.size(); ++i)
            heapify(i, root, Heap::MAX);
    }

private:

    void heapify(int index, vector<int> & tempRoot, Heap::HeapType heapType) const
    {
        int currentIndex = index;
        int parentIndex = (currentIndex-1)/2;
        while(parentIndex >= 0 && (currentIndex-1) >= 0)
        {
            if(((heapType == MIN) && tempRoot[parentIndex] > tempRoot[currentIndex])
                    ||((heapType == MAX) && tempRoot[parentIndex] < tempRoot[currentIndex]))
            {
                int data = tempRoot[parentIndex];
                tempRoot[parentIndex] = tempRoot[currentIndex];
                tempRoot[currentIndex] = data;
            }
            currentIndex = parentIndex;
            parentIndex = (currentIndex-1)/2;
        }
    }
};

int main()
{
    Heap heapObj;

    heapObj.insert(7);
    heapObj.insert(3);
    heapObj.insert(10);
    heapObj.insert(2);
    heapObj.insert(55);

    cout << "Binary Heap ";
    heapObj.print();

    vector<int> sortedArray;
    heapObj.sort(sortedArray, Heap::MAX);

    cout << "Sorted Array in Desc ";
    for(auto const& value: sortedArray)
        cout << value << " ";

    cout << endl;

    sortedArray.clear();

    heapObj.sort(sortedArray, Heap::MIN);

    cout << "Sorted Array in Asc ";
    for(auto const& value: sortedArray)
        cout << value << " ";

    cout << endl;

    heapObj.createMaxHeap();

    cout << "Max Heap ";
    heapObj.print();

    heapObj.createMinHeap();

    cout << "Min Heap ";
    heapObj.print();

    return 0;
}
