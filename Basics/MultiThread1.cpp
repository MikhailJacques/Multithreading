// Example for thread

// Thread - Class to represent individual threads of execution.

// A thread of execution is a sequence of instructions that can be executed concurrently 
// with other such sequences in multithreading environments, while sharing a same address space.

// An initialized thread object represents an active thread of execution. 
// Such a thread object is joinable, and has a unique thread id.

// A default-constructed (non-initialized) thread object is not joinable
// and its thread id is common for all non-joinable threads.

// A joinable thread becomes not joinable if moved from or if either join or detach are called on them.

#include <chrono>		// chrono::seconds
#include <thread>
#include <iostream>

using namespace std;

void foo() 
{
	// do stuff...
	cout << "Inside foo...\n";
}

void bar(int x)
{
	// do stuff...
	cout << "Inside bar...\n";
}

void bob(int y)
{
	// do stuff...
	cout << "Inside bob...\nBob's number: " << y << "\n";
}

int main() 
{
	thread first(foo);		// spawn new thread that calls foo()
	thread second(bar, 3);	// spawn new thread that calls bar(3)
	thread third(bob, 7);	// spawn new thread that calls bob(7)

	this_thread::sleep_for (chrono::seconds(1));

	cout << "\nMain, foo, bar and bob now execute concurrently...\n";

	this_thread::sleep_for (chrono::seconds(1));

	cout << "\nJoinable after construction:\n" << boolalpha;
	cout << "first: " << first.joinable() << endl;
	cout << "second: " << second.joinable() << endl;
	cout << "third: " << third.joinable() << endl;

	// Synchronize threads:
	first.join();			// pauses until first finishes
	second.join();			// pauses until second finishes
	third.join();			// pauses until third finishes

	this_thread::sleep_for (chrono::seconds(1));

	cout << "\nJoinable after joining:\n" << boolalpha;
	cout << "first: " << first.joinable() << endl;
	cout << "second: " << second.joinable() << endl;
	cout << "third: " << third.joinable() << endl;


	cout << "\nThreads foo, bar and bob completed execution.\n";

	cin.get();

	return 0;
}