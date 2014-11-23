// Example of mutex::try_lock

// Lock mutex if not locked
// Attempts to lock the mutex, without blocking:
// If the mutex isn't currently locked by any thread, the calling thread locks it 
// (from this point, and until its member unlock is called, the thread owns the mutex).
// If the mutex is currently locked by another thread, the function fails and returns false, 
// without blocking (the calling thread continues its execution).
// If the mutex is currently locked by the same thread calling this function, it produces a deadlock (with undefined behavior). 
// See recursive_mutex for a mutex type that allows multiple locks from the same thread.

// This function may fail spuriously when no other thread has a lock on the mutex, 
// but repeated calls in these circumstances shall succeed at some point.

// All lock and unlock operations on the mutex follow a single total order, with all visible effects 
// synchronized between the lock operations and previous unlock operations on the same object.

#include <mutex>		// mutex
#include <thread>		// thread
#include <iostream>		// cout

using namespace std;

mutex mtx;					// mutex that locks access to counter
volatile int counter (0);	// non-atomic counter

void attempt_10k_increases () 
{
	for (int i = 0; i < 10000; ++i) 
	{
		if (mtx.try_lock()) 
		{   
			// Only increase if currently not locked:
			++counter;
			mtx.unlock();
		}
	}
}

int main ()
{
	const int num_threads = 10;
	thread threads[num_threads];

	// Spawn 10 threads:
	for (int i = 0; i < num_threads; ++i)
		threads[i] = thread(attempt_10k_increases);

	for (auto& th : threads) 
		th.join();
	
	cout << counter << " successful increases of the counter.\n";

	cin.get();

	return 0;
}

// Output samples:
// 93498 successful increases of the counter.
// 48503 successful increases of the counter.
// 97782 successful increases of the counter.
// 100000 successful increases of the counter.