// DNASpeedTestRevised.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <chrono>

#include "Kmer.h"

using namespace std;

int main()
{
	std::cout << "Start: " << endl;
	const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	kmer s = kmer::First();
	kmer s_last = kmer::Last();
	
	int counter = 1;
	while (s != s_last)
	{
		counter++;
		// You can uncomment the next line to see all k-mers.
		 // cout << s << endl;

		// Increment() creates a new kmer object with next sequence.
		// (use  s = s.Increment();   to step through all k-mers)
		 //kmer newKmer  = s.Increment();

		// ++ updates the existing object inplace.  (This mimics the effect of the original program,
		//  but Increment() is probably what you'd want in a actual application)
		++s;
		
	}

	// You can uncomment the next line to see all k-mers.
	// cout << s << endl;
	cout << "Number of generated k-mers: " << counter << endl;
	cout << "Finish!: " << endl;
	const chrono::steady_clock::time_point end = chrono::steady_clock::now();
	cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	return 0;
}
