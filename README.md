# About

A Linear Algebra Library that handles multiplication and transpose operations
of matricies (the two most important function of course :) ).

This module was requested by Brain Corp https://www.braincorp.com/ as a part
of their technical screening process.

### Build

```
$ make
```

### Run

```
$ ./main
```

### Examples

``` C++
int main() {
    std::vector<std::vector<double>>  m1 = {{1,2,3},
        {4,5,6}};

    std::vector<std::vector<double>> m2 = {{7,8,9,10},
        {11,12,13,14},
        {15,16,17,19}};

    std::vector<std::vector<double>> result = LA::multiply(m1, m2);
    LA::print(result);

    // Should print out the following:
    // 74 80 86 95 
    // 173 188 203 224 


    LA::print(m1);
    std::vector<std::vector<double>> newM1 = LA::transpose(m1);
    LA::print(newM1);

    // Should print out the following:
    // 1 2 3 
    // 4 5 6 


    // 1 4 
    // 2 5 
    // 3 6
}
```
