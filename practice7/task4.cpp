#include <iostream>
#include <chrono>
#include <fstream>
#include <pthread.h>
#include <string>

using namespace std;

#define THREAD 2

struct ThreadArgs {
	long int* array;
	long int size;
	int thread;
};

void* createThread(void*);

void create_array(long int*, long int);

void print_last_hundred(long int*, long int, bool);

int main(int argc, char* argv[]) {
	// sain size = 2 095 226 koulun linuxilla ssh kautta kerran, mutta luku
	// muuttuu core dumbiksi ajoittain, joten otin 2miljoonaa varmuuden vuoksi
	// EDIT: koko laski vielä jälkeenpäin 1miljoonaan
	bool silent = false;
	bool timer = false;
	const long int size = 1000000;
	long int list[size];

	// tarkistaa, onko argc:ssa jotain ja varmistaa, onko se "-s" jotta coutin saa hiljennettyä
	for (int i = 1; i < argc; ++i) {
		if (string(argv[i]) == "-s") {
			silent = true;
		} else if (string(argv[i]) == "-time") {
			timer = true;
		}
	}
	// jos ohjelman kutsuessa on lisätty -time argumentti, tulosta ohjelman ajoon kuluva
	// aika terminaaliin
	if (timer) {
		auto startTime = chrono::high_resolution_clock::now();
		create_array(list, size);
		auto endTime = chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
		print_last_hundred(list, size, silent);
		cout << "Time: " << duration.count() << endl;
	} else {
		create_array(list, size);
		print_last_hundred(list, size, silent);
	}
	return 0;
}

// luo thread käyttäen structissa annettuja arvoja
void* createThread(void* arg) {
	ThreadArgs* threadArgs = static_cast<ThreadArgs*>(arg);
	long int* array = threadArgs->array;
	long int size = threadArgs->size;
	int thread = threadArgs->thread;
	long int index_area = size / THREAD;
	long int start_index = (index_area * thread) + 1;
	long int end_index = start_index + index_area;

	// lisää arrayhin indeksin kohdalle indeksin numeron riippuen mikä thread on menossa
	if (thread == 0) {
		// cout << "thread " << thread << endl;
		for (long int i = 0; i < index_area; i++) {
			array[i] = i;
		}
	} else {
		// cout << "thread " << thread << endl;
		for (long int i = start_index; i < end_index; i++) {
			array[i] = i;
		}
	}

	return nullptr;
}

// Luo arrayn ja threadit
void create_array(long int* array, long int size) {
	const int num_threads = 2;
	pthread_t threads[THREAD];
	ThreadArgs threadArgs[THREAD];
	for (int i = 0; i < THREAD; ++i) {
		threadArgs[i].array = array;
		threadArgs[i].size = size;
		threadArgs[i].thread = i;
		int result = pthread_create(&threads[i], nullptr, createThread, &threadArgs[i]);
		if (result != 0) {
			cerr << "Thread creating failure, error: " << result << endl;
			return;
		}
	}
	// odottaa, että threadit ovat valmiina
	for (int i = 0; i < THREAD; ++i) {
		pthread_join(threads[i], nullptr);
	}
}

void print_last_hundred(long int* array, long int size, bool silenter) {
	if (!silenter) {
		for (long int i = size - 100; i < size; i++) {
			cout << array[i] << endl;
		}
	}
}
