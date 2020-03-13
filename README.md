# simple-spin-lock
Simple Spin Thread-Lock Example

# What is inside ?
Example of custom thread-lock method replacing default STL (Boost, NDX or any other)
thread-lock logic.

# What is spin-lock ?
In cases, when hardware memory transaction is unavailable, spin-lock
allows to save some amount of CPU time, by avoiding unnecessary
synchronization between threads in case of samll operation.

# Usage
Use config.hpp to reconfigure. For example to use other mutex-type.

# Features
 - RAII, means, that mutex & locks are automatically unlocked (exceptions-safe);
 - C++ way to handle atomic-logic, not C;
