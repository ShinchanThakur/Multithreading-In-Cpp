// INTRODUCTION

// 0. In every application there is a default thread which is main(), in side this we create other threads.
// 1. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads.
//    For example:
//    (a) The browser has multiple tabs that can be different threads.
//    (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
//    (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

// WAYS TO CREATE THREADS IN C++11
// 1. Function Pointers
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static Member functions

// EXAMPLE
// Find the sum of all odd number from 1 to 1900000000 and all even number from 1 to 1900000000


#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define int long long int

void findEven(int end, int &evenSum) {
   //Doesnt works with reference
   //So take pointer instead
   for(int i=0; i<=end; i++)
      if(!(i & 1))
         evenSum += i;
}

void findOdd(int end, int &oddSum) {
   for(int i=0; i<=end; i++)
      if(i & 1)
         oddSum += i;
}

signed main() {

    int end = 1900000000, oddSum=0, evenSum=0;

    auto startTime = high_resolution_clock::now(); 

    std::thread t1(findEven, end, evenSum);
    std::thread t2(findOdd, end, oddSum);

    t1.join();
    t2.join();

    auto stopTime = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "OddSum : " << oddSum << endl;
    cout << "EvenSum : " << evenSum << endl;

    cout << "Sec: " << duration.count()/1000000 << endl;

    return 0;
}

// Without multithreading, this program takes 4 seconds to execute.
// After using multithreading, it executes in 2 seconds.