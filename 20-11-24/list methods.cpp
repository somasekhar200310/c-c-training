#include <iostream>
#include <list>
#include <algorithm>  // For sort
#include <numeric>    // For accumulate

int main() {
    // Creating a list with initial values
    std::list<int> lst = {1, 2, 3, 4, 5};

    // 1. Size of the list
    std::cout << "Size of list: " << lst.size() << std::endl;

    // 2. Accessing elements (front, back)
    std::cout << "First element: " << lst.front() << std::endl;
    std::cout << "Last element: " << lst.back() << std::endl;

    // 3. Adding elements (push_back, push_front)
    lst.push_back(6);  // Adds 6 to the end
    lst.push_front(0); // Adds 0 to the front
    std::cout << "After push_back(6) and push_front(0): ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // 4. Removing elements (pop_back, pop_front)
    lst.pop_back();  // Removes the last element
    lst.pop_front(); // Removes the first element
    std::cout << "After pop_back() and pop_front(): ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // 5. Inserting elements (insert)
    auto it = lst.begin();
    std::advance(it, 2);  // Move iterator to index 2
    lst.insert(it, 10);   // Inserts 10 at index 2
    std::cout << "After insert(10) at index 2: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // 6. Erasing elements (erase)
    it = lst.begin();
    std::advance(it, 1);  // Move iterator to index 1
    lst.erase(it);        // Erase element at index 1
    std::cout << "After erase at index 1: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // 7. Clearing the list (clear)
    lst.clear();
    std::cout << "After clear(), size: " << lst.size() << std::endl;

    // 8. Re-initializing list
    lst = {1, 2, 3, 4, 5};

    // 9. Sorting the list (sort)
    lst.sort();  // Sorts the list in ascending order
    std::cout << "After sort: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // 10. Reversing the list (reverse)
    lst.reverse();  // Reverses the order of elements in the list
    std::cout << "After reverse: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // 11. Merging two lists (merge)
    std::list<int> lst2 = {6, 7, 8};
    lst.merge(lst2);  // Merges lst2 into lst (lst2 is emptied)
    std::cout << "After merge with lst2: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // 12. Accumulating elements (accumulate)
    int sum = std::accumulate(lst.begin(), lst.end(), 0);
    std::cout << "Sum of elements: " << sum << std::endl;

    // 13. Reserving space in the list (not applicable for std::list)
    // `std::list` does not have a `reserve()` method because it does not allocate contiguous memory like `std::vector`.

    // 14. Removing duplicate elements (unique)
    lst.push_back(3); // Adding a duplicate element for testing
    lst.push_back(4);
    lst.push_back(4);
    lst.push_back(5);
    lst.unique();  // Removes consecutive duplicates
    std::cout << "After unique(): ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    // 15. Splicing (splice)
    std::list<int> lst3 = {9, 10};
    lst.splice(lst.end(), lst3);  // Splice elements from lst3 to lst at the end
    std::cout << "After splice with lst3: ";
    for (int val : lst) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}
