// Example for thread::joinable

// Check if joinable
// Returns whether the thread object is joinable.
// A thread object is joinable if it represents a thread of execution.
// A thread object is not joinable in any of these cases:
// - If it was default-constructed.
// - If it has been moved from (either constructing another thread object, or assigning to it).
// - If either of its members join or detach has been called.

#include <thread>         // thread
#include <iostream>       // cout

using namespace std;

void mythread() 
{
	// do stuff...
	cout << "Inside a thread...\n";
}
 
int main() 
{
	thread foo;				// default-constructed
	thread bar(mythread);

	cout << "\nJoinable after construction:\n" << boolalpha;
	cout << "foo: " << foo.joinable() << endl;
	cout << "bar: " << bar.joinable() << endl;

	if (foo.joinable()) 
		foo.join();

	if (bar.joinable()) 
		bar.join();

	cout << "\nJoinable after joining:\n" << boolalpha;
	cout << "foo: " << foo.joinable() << endl;
	cout << "bar: " << bar.joinable() << endl;

	cin.get();

	return 0;
}