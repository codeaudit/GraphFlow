// Framework: GraphFlow
// Class: RisiLayer1D
// Author: Machine Learning Group of UChicago
// Institution: Department of Computer Science, The University of Chicago
// Copyright 2017 (c) UChicago. All rights reserved.

#ifndef __RISILAYER1D_H_INCLUDED__
#define __RISILAYER1D_H_INCLUDED__

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <assert.h>

#include "Vector.h"

using namespace std;

class RisiLayer1D: public Vector {
public:
	RisiLayer1D(int size) : Vector(size) {
		vectors.clear();
	}

	void add_vector(Vector *vect) {
		assert(size == vect -> size);
		vectors.push_back(vect);
	}

	void clear() {
		vectors.clear();
	}

	void forward() {
		for (int i = 0; i < size; ++i) {
			value[i] = 0.0;
		}

		for (int v = 0; v < vectors.size(); ++v) {
			for (int i = 0; i < size; ++i) {
				value[i] += vectors[v] -> value[i];
			}
		}

		for (int i = 0; i < size; ++i) {
			gradient[i] = 0.0;
		}
	}

	void backward() {
		for (int v = 0; v < vectors.size(); ++v) {
			for (int i = 0; i < size; ++i) {
				vectors[v] -> gradient[i] += gradient[i];
			}
		}
	}

	vector < Vector* > vectors;

	~RisiLayer1D() {
	}
};

#endif
