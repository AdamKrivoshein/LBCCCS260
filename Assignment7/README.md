# Assignment 7: Hash Table

## Design Requirements
|#|Requirement|Test|
|-|-----------|----|
|1|**insert():** Should take a value, run it through a hash function, and insert it at the appropriate location.|printTable() should allow us to verify insertions are done correctly.|
|1a|**hash():** Should convert a given value into an index and return that index.|printTable() along with hand calculating the expected index value.|
|2|**contains():** Should return the value if it exists in the table.|Inserting or not inserting values to search for, alongside printTable() should verify this.|
|3|**printTable():** Should display every index and value pairing.|Knowing what to expect from previous insert() operations will verify this.|

## hashTable.h
**table:** Array of strings

**size:** Size of the array (Number of different hashed keys that can exist)

**insert():**

*Inputs: string*

*Outputs: None.*

    index = call hash() with string key
    array at index = key (doubles as the value)

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
    if array at index = key (doubles as value):
        return true
    return false

**printTable():**

*Inputs: *

*Outputs: *

    for each index in array:
        print contents

## driver.cpp
Initializes and runs the hash table