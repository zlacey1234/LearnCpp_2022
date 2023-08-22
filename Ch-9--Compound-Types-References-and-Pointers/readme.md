# Compound Types: References and Pointers

## Introduction to Compound Data Types

Now imagine a case where you're writing a program that needs to keep a list of employee IDs. You might try to write something like this:

``` C++
int main() {
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

### The Properties of an Expression

To help determine how expressions should evaluate and where they can be used, all expressions in C++ have two properties: a type and a value category.

### The Type of an Expression

The type of an expression is equivalent to the type of the value, object, or function that results from the evaluated expression.

For example:

``` C++
#include <iostream>

void print(int x) {
    std::cout << x << std::endl;
}

int main() {
    auto v1 { 12 / 4 }; // int / int => int
    auto v2 { 12.0 / 4 }; // double / int => double

    print("foo"); // error: print() was expecting an int argument, we tried to pass in a string literal

    return 0;
}
```

For `v1`, the compiler will determine (at compile time) that a division with two `int` operands will produce an `int` result, so `int` is the type of this expression. Via type inference, `int` will then be used as the type of `v1`.

For `v2`, the compiler will determine (at compile time) that a division with a `double` operand and an int operand will produce a `double` result. Remember that arithmetic operators must have operands of matching types, so in this case, the `int` operand gets converted to a `double`, and a floating point division is performed. So `double` is the type of this expression.

The `print(int)` function is expecting an `int` parameter. However, the type of the expression we’re passing in (the string literal `"foo"`) does not match, and no conversion can be found. So a compile error results.

Note that the type of an expression must be determinable at compile time (otherwise type checking and type deduction wouldn’t work) -- however, the value of an expression may be determined at either compile time (if the expression is constexpr) or runtime (if the expression is not constexpr).

### The Value Category of an Expression

Consider this example:

``` C++
int main() {
    int x{};

    x = 5; // valid: we can assign 5 to x
    5 = x; // error: can not assign value of x to literal value 5

    return 0;
}
```

One of these assignment statements is valid (assigning value `5` to variable `x`) and one is not (what would it mean to assign the value of `x` to the literal value `5`?). So how does the compiler know which expressions can legally appear on either side of an assignment statement?

The answer lies in the second property of expressions: the `value category`. The **value category** of an expression (or subexpression) indicates whether an expression resolves to a value, a function, or an object of some kind.

Prior to C++11, there were only two possible value categories: `lvalue` and `rvalue`.

In C++11, three additional value categories (`glvalue`, `prvalue`, and `xvalue`) were added to support a new feature called `move semantics`.

### L-Value and R-Value Expressions

An **lvalue** (short for "left value" or "locator value", and sometimes written as `l-value`) is an expression that evaluates to an identifiable object or function (or bit-field).

Entities (such as an object or function) with identities can be accessed via an identifier, reference, or pointer, and typically have a lifetime longer than a single expression or statement. 

``` C++
int main() {
    int x { 5 };
    int y { x }; // x is an lvalue expression

    return 0;
}
```

The expression `x` is an lvalue expression as it evaluates to variable `x` (which has an identifier).

Since the introduction of constants into the language, lvalues come in two subtypes:a **modifiable lvalue** is an lvalue whose value can be modified. A **non-modifiable lvalue** is an lvalue whose value can’t be modified (because the lvalue is const or constexpr).

``` C++
int main() {
    int x{};
    const double d{};

    int y { x }; // x is a modifiable lvalue expression
    const double e { d }; // d is a non-modifiable lvalue expression

    return 0;
}
```

An **rvalue** (short for “right value”, and sometimes written as `r-value`) is an expression that is not an l-value. Commonly seen rvalues include literals (except C-style string literals, which are lvalues) and the return value of functions and operators. Rvalues aren’t identifiable (meaning they have to be used immediately), and only exist within the scope of the expression in which they are used.

``` C++
int return5() {
    return 5;
}

int main() {
    int x{ 5 }; // 5 is an rvalue expression
    const double d{ 1.2 }; // 1.2 is an rvalue expression

    int y { x }; // x is a modifiable lvalue expression
    const double e { d }; // d is a non-modifiable lvalue expression
    int z { return5() }; // return5() is an rvalue expression (since the result is returned by value)

    int w { x + 1 }; // x + 1 is an rvalue expression
    int q { static_cast<int>(d) }; // the result of static casting d to an int is an rvalue expression

    return 0;
}
```

You may be wondering why `return5()`, `x + 1`, and `static_cast<int>(d)` are rvalues: the answer is because these expressions produce temporary values that are not identifiable objects.

Now we can answer the question about why `x = 5` is valid but `5 = x` is not: an assignment operation requires the left operand of the assignment to be a modifiable lvalue expression, and the right operand to be an rvalue expression. The latter assignment (`5 = x`) fails because the left operand expression 5 isn’t an lvalue.

``` C++
int main() {
    int x{ };

    // Assignment requires the left operand to be a modifiable lvalue expression and the right operand to be an rvalue expression
    x = 5; // valid: x is a modifiable lvalue expression and 5 is an rvalue expression
    5 = x; // error: 5 is an rvalue expression and x is a modifiable lvalue expression

    return 0;
}
```

## L-Value References

**Note:** An **lvalue reference** is commonly just called a *reference*.

In C++, a **reference** defines an alternative name for an existing object. Once a reference has been defined, any operation on the reference is applied to the object being referenced.

Note: A reference is not an object. Instead, a reference is *just another name for an already existing object*.

### L-Value Reference Types

To declare an lvalue reference type (reference type), we use the `&` in the type declaration:

``` C++
int     // a normal int type
int&    // an lvalue reference to a int object
double& // an lvalue reference to a double object 
```

### L-Value Reference Variables

One of the things we can do with an lvalue reference type is creat an lvalue reference variable. An **lvalue reference variable** is a variable that acts as a reference to an lvalue (usually another variable).

Typically, when we initialize a variable, the value of the initializer is copied into the object we are creating. When we define references, instead of copying the initializer's value, we **bind** the reference to its initializer.

Note: Once initialized, a reference remains bound to its initial object. There is no way to rebind a reference to refer to a different object.

``` C++
#include <iostream>

int main() {
    int x{ 5 };                     // x is a normal integer variable. 5 is copied into the object x. 
    int& ref{ x };                  // ref is a lvalue reference variable that is bound to variable x (and can now be used as an alias for variable x).

    std::cout << x << std::endl;    // print the value of x: 5
    std::cout << ref << std::endl;  // print the value of x via ref: 5

    return 0;
}
```

In the above example, when we are printing out `ref`, the following happens:

1. We are trying to fetch the lvalue reference variable `ref`.
   * This is really fetching the value of the object (`x`) to which the reference (`ref`) is bound to.
   * Recall that the value of object `x` is `5`
2. Print out the value `5` since `ref` is bound to `x`.

Note: A reference variable must be initialized with an object. A reference variable must also be bound to a modifiable lvalue. 

``` C++
int main() {
    int& invalidRef; // error #1: reference must be initialized

    int x { 5 };
    int& ref { x }; // valid: lvalue reference bound to a modifiable lvalue

    const int y { 5 };
    int& invalidRef { y };  // error #2: invalid: can't bind to a non-modifiable lvalue
    int& invalidRef2 { 0 }; // error #3: invalid: can't bind to an rvalue

    return 0;
}
```

### Modifying Values Through an L-Value Reference

``` C++
#include <iostream>

int main() {
    int x { 5 }; // normal integer variable
    int& ref { x }; // ref is now an alias for variable x

    std::cout << x << ref << '\n'; // print 55

    x = 6; // x now has value 6

    std::cout << x << ref << '\n'; // prints 66

    ref = 7; // the object being referenced (x) now has value 7

    std::cout << x << ref << '\n'; // prints 77

    return 0;
}
```

## L-Value References to Const

## Pass by L-Value Reference

What makes lvalue references useful? 

Recall a `pass by value` is where an argument passed to a function is copied into the function's parameter:

``` C++
#include <iostream>

void printValue(int y)
{
    std::cout << y << '\n';
} // y is destroyed here

int main() {
    int x { 2 };

    printValue(x); // x is passed by value (copied) into parameter y (inexpensive)

    return 0;
}
```

In the above program, when `printValue(x)` is called, the value of `x` (`2`) is copied into parameter `y`. Then, at the end of the function, object `y` is destroyed.

This means that when we called the function, we made a copy of our argument’s value, only to use it briefly and then destroy it! Fortunately, because fundamental types are cheap to copy, this isn’t a problem.

### Pass by Reference

Most of the types provided by the standard library (such as `std::string`) are `class types`. Class types are usually expensive to copy. Whenever possible, we want to avoid making unnecessary copies of objects that are expensive to copy, especially when we will destroy those copies almost immediately.

Consider:

``` C++
#include <iostream>
#include <string>

void printValue(std::string y) {
    std::cout << y << '\n';
} // y is destroyed here

int main() {
    std::string x { "Hello, world!" }; // x is a std::string

    printValue(x); // x is passed by value (copied) into parameter y (expensive)

    return 0;
}
```

The `std::string` is a class type that is expensive to copy. And this expensive copy is made every time `printValue()` is called!

One way to avoid making an expensive copy of an argument when calling a function is to use `pass by reference` instead of `pass by value`. When using **pass by reference**, we declare a function parameter as a reference type (or const reference type) rather than as a normal type. When the function is called, each reference parameter is bound to the appropriate argument. Because the reference acts as an alias for the argument, no copy of the argument is made.

``` C++
#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)

    return 0;
}
```
