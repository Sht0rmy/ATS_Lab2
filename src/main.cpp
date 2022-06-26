#include <list>
#include "Segment_tree.h"
#include "Complex.h"
#include "BinomialHeap.h"

int main()
{
    // Segment tree test
    cout << "\nSegment tree test\n";

    vector<ComplexNumber> st_values{{4, -3}, {1, -10}, {13, 75}, {17, 25}};
    int n = st_values.size();
    SegmentTree<ComplexNumber> st(st_values);
    ComplexNumber sum = st.sum(1, 0, n - 1, 0, n - 1);
    cout << sum;

    // BinHeap test
    cout << "BinHeap test\n";

    int ch, key;
    list<BHNode<ComplexNumber> *> _heap;

    // Insert data in the heap
    _heap = insert<ComplexNumber>(_heap, {1, 2});
    _heap = insert<ComplexNumber>(_heap, {3, 5});
    _heap = insert<ComplexNumber>(_heap, {-7, 10});

    cout << "Heap elements after insertion:\n";
    printHeap(_heap);

    BHNode<ComplexNumber> *temp = getMin(_heap);
    cout << "\nMinimum element of heap "
         << temp->data << "\n";

    // Delete minimum element of heap
    _heap = extractMin(_heap);
    cout << "Heap after deletion of minimum element\n";
    printHeap(_heap);

    return 0;

}
