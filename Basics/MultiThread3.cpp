// Example for thread::detach

// Detach thread
// Detaches the thread represented by the object from the calling thread, 
// allowing them to execute independently from each other.
// Both threads continue without blocking nor synchronizing in any way. 
// Note that when either one ends execution, its resources are released.
// After a call to this function, the thread object becomes non-joinable and can be destroyed safely.

#include <mutex>			// mutex
#include <thread>			// thread, this_thread::sleep_for
#include <chrono>			// chrono::seconds
#include <iostream>			// cout
 
using namespace std;

mutex mtx;	// mutex for critical section

void pause_thread(int n) 
{
	mtx.lock();
	cout << "Thread " << this_thread::get_id() << " will sleep for " << n << " seconds\n";
	mtx.unlock();

	this_thread::sleep_for (chrono::seconds(n));

	mtx.lock();
	cout << "Thread " << this_thread::get_id() << " sleep of " << n << " seconds ended\n";
	mtx.unlock();
}

void commence_execution(int n) 
{
	mtx.lock();
	cout << "Thread " << this_thread::get_id() << " commenced execution\n";
	mtx.unlock();

	pause_thread(n);
}
 
int main() 
{
	cout << "Main Thread " << this_thread::get_id() << " started execution\n";

	cout << "Main Thread " << this_thread::get_id() << " is spawning and detaching 3 threads...\n";

	thread (commence_execution, 2).detach();
	thread (commence_execution, 4).detach();
	thread (commence_execution, 7).detach();

	cout << "Main Thread " << this_thread::get_id() << " finished spawning threads.\n";

	// Alternatively, give the detached threads time to finish (but not guaranteed!):
	pause_thread(5);

	cout << "Main Thread " << this_thread::get_id() << " finished execution\n";

	cin.get();

	return 0;
}