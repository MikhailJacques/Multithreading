// Example for thread::get_id / this_thread::get_id

// Get thread id
// Returns the thread id.
// If the thread object is joinable, the function returns a value that uniquely identifies the thread.
// If the thread object is not joinable, the function returns a default-constructed object of member type thread::id.

#include <thread>         // thread, thread::id, this_thread::get_id
#include <chrono>         // chrono::seconds
#include <iostream>       // cout

using namespace std;
 
thread::id main_thread_id = this_thread::get_id();

void is_main_thread() 
{
	cout << "Main thread ID " << main_thread_id << "\n";
	cout << "This thread ID " << this_thread::get_id() << "\n";

	if ( main_thread_id == this_thread::get_id() )
		cout << "This is the main thread.\n\n";
	else
		cout << "This is not the main thread.\n\n";
}

int main() 
{
	cout << "Thread " << this_thread::get_id() << " started execution\n\n";

	is_main_thread();

	thread th (is_main_thread);

	th.join();

	cin.get();

	return 0;
}