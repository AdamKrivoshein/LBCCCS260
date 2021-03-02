# Assignment 7: Hash Table

[link](#Design-Requirements)
[link](#hashTable.h)
[link](#driver.cpp)
[link](#Collisions-and-their-effect-on-complexity)

## Design Requirements
|#|Requirement|Test|
|-|-----------|----|
|1|**insert():** Should take a value, run it through a hash function, and insert it at the appropriate location.|printTable() should allow us to verify insertions are done correctly.|
|1a|**hash():** Should convert a given value into an index and return that index.|printTable() along with hand calculating the expected index value.|
|2|**contains():** Should return the value if it exists in the table.|Inserting or not inserting values to search for, alongside printTable() should verify this.|
|3|**printTable():** Should display every index and value pairing.|Knowing what to expect from previous insert() operations will verify this.|

## hashTable.h
**linkedList.h and node.h are used from Assignment 4 as a solution to the collision problem.**

**table:** Array of strings

**size:** Size of the array (Number of different hashed keys that can exist)

**insert():**

*Inputs: string*

*Outputs: None.*

    index = call hash() with string key
    add to list at index

**hash():**

*Inputs: string*

*Outputs: int (index of array)*

    sum = 0
    for each character in key:
        sum = sum + key in ascii
    sum = sum % size of table array
    return sum

**contains():**

*Inputs: string*

*Outputs: bool (true if the value exists in the hash table)*

    index = call hash() with string key
    return call contains() at index

**printTable():**

*Inputs: *

*Outputs: *

    for each index in array:
        call displayList() at index

## driver.cpp
Initializes and runs the hash table

## Collisions and their effect on complexity
While a perfect hash table with no collisions has an insertion and contains complexity of O(1), 
in it's worst case collisions can cause an O(n) complexity for contains, as it's possible all values could somehow end up with the same key,
forcing the program to iterate through the list in search of the item. Insertion would still be O(1) fortunately, as you can always just add
on to the list at the key. Because of this you should seek a hashing function that evenly distributes any collisions so there are no drops in
expected performance due to running into a long list of values with the same key.