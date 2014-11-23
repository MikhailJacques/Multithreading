// Example for thread::join

// Join thread
// The function returns when the thread execution has completed. 
// This synchronizes the moment this function returns with the completion of all the operations in the thread: 
// This blocks the execution of the thread that calls this function until the function called on construction 
// returns (if it hasn't yet).
// After a call to this function, the thread object becomes non-joinable and can be destroyed safely.

#include <thread>		// thread, this_thread::sleep_for
#include <chrono>		// chrono::seconds
#include <iostream>		// cout

using namespace std;

void pause_thread(int n) 
{
	this_thread::sleep_for (chrono::seconds(n));
	cout << "Thread " << this_thread::get_id() << " pause of " << n << " seconds ended\n";
}

int main() 
{
	cout << "Thread " << this_thread::get_id() << " started execution\n";

	cout << "Spawning 3 threads...\n";

	thread t1 (pause_thread, 2);
	thread t2 (pause_thread, 6);
	thread t3 (pause_thread, 4);

	cout << "Done spawning threads. Now waiting for them to join...\n";

	t1.join();
	
	cout << "First thread joined!\n";

	t2.join();

	cout << "Second thread joined!\n";

	t3.join();

	cout << "Third thread joined!\n";

	pause_thread(2);

	cout << "All threads joined!\n";

	cin.get();

	return 0;
}