# Compound Types: References and Pointers

## Introduction to Compound Data Types

Now imagine a case where you're writing a program that needs to keep a list of employee IDs. You might try to write something like this:

``` C++
int main(){
    int id1 { 42 };
    int id2 { 57 };
    int id3 { 162 };
    // and so on
}
```

But what if you had 100 employees? First, you'd need to type in 100 variable names. And what if you needed to print them all? Or pass them to a function? We'd be in for a lot of typing. This simply doesn't scale.

Clearly fundamental types will only carry us so far.

### Compound Data Types

Fortunately, C++ supports a second set of data types called `compound data types`. **Compound data types** (also sometimes called **composite data types**) are data types that can be constructed from fundamental data types (or other compound data types). Each compound data type has its own unique properties as well.

C++ supports the following compound types:

* Functions
* Arrays
* Pointer Types:
  * Pointer to Object
  * Pointer to Function
* Pointer to Member Types:
  * Pointer to Data Member
  * Pointer to Member Function
* Reference Types:
  * L-value References
  * R-value References
* Enumerated Types:
  * Unscoped Enumerations
  * Scoped Enumerations
* Class Types:
  * Structs
  * Classes
  * Unions

## Value Catagories (L-Values and R-Values)
