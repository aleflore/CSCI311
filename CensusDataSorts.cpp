/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 * 
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger
 * @date 2/22/13
 */

#include <cmath>
#include <chrono>
#include <random>
#define MAX 81746
#include "CensusData.h"
/*
* Sorts data as it is read in
**/
void CensusData::insertionSort(int type) 
{	
if(type == 0)
	{					
		for(int j = 1; j < getSize(); j++)
		{
			Record * key = data[j];
			int i = j - 1;
			while(i >= 0 && data[i]->population > key->population)
			{
				data[i+1] = data[i];
				i = i -1;
			}
			data[i +1] = key;
		}
	}
	else
	{
		for(int j = 1; j < getSize(); j++)
		{
			Record * key = data[j];
			int i = j - 1;
			while(i >= 0 && (*data[i]->city) >= (*key->city) )
			{
				data[i+1] = data[i];
				i = i - 1;
			}
			data[i +1] = key;
		}
	}
}
/**
* calls mergesort helper function with correct arguments
**/
void CensusData::mergeSort(int type) 
{	
	mergeSort(type,0,getSize()-1);
}
/**
* Sorts every element in data into two subarrays 
**/
void CensusData::mergeSort(int type, int p, int r)
{
	if(p < r)
	{
		int q = floor((p+r)/2);
		mergeSort(type,p,q);
		mergeSort(type,q+1,r);
		merge(type,p,q+1,r+1);
	}
}
/**
* Merges subarrays from mergesort 
**/
void CensusData::merge(int type, int p, int q, int r)
{
	int n1 = q - p;
	int n2 = r - q;
	Record * L[MAX];
	Record * R[MAX];
	int i;
	int j;
	int k;
	int Lsize = 0; 
	int Rsize = 0; 
	for(i = 0; i < n1; i++)
	{
		L[i] = data[p+i];
		Lsize++;
	}
	for(j = 0; j < n2; j++)
	{	
		R[j] = data[q+j];
		Rsize++;
	}
	i = 0;
	j = 0;
	for(k = p; k < r; k++)
	{
		if(j == Rsize)
		{
			data[k] = L[i];
			i = i + 1;
			continue;
		}
		if(i == Lsize)
		{
			data[k] = R[j];
			j = j + 1;
			continue;
		}
		else if(i == Lsize && j == Rsize)
		{
			return;
		}
		if(type == 0)
		{
			if(L[i]->population <= R[j]->population)
			{	
				data[k] = L[i];
				i = i + 1;
			}
			else
			{
				data.at(k) = R[j];
				j = j + 1;
			}
		}
		else if(type == 1)
		{
			if((*L[i]->city).compare(*R[j]->city) <= 0)
			{	
				data[k] = L[i];
				i = i + 1;
			}
			else
			{
				data[k] = R[j];
				j = j + 1;
			}
		}
	}
}		
/*
* sends correct arguments to quicksort helper function
**/
void CensusData::quickSort(int type) 
{	
	quicksort(type,0,getSize()-1);
}
/**
* Sorts subarrays
**/
void CensusData::quicksort(int type, int p, int r)
{    
    if(p < r)
    {
	    int q = partition(type, p, r);
	    quicksort(type, p, q-1);
        quicksort(type, q+1, r);
    }
}
/**
* Partition sets a randomly chosen index as the pivot, data[r], and 
* rearranges subarray data[p..r] in place. Generated seed is based 
* on time clock against a distribution from 0 to r
**/
int CensusData::partition(int type, int p, int r)
{
    using std::swap;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(p,r);
    int i = distribution(generator);
	swap(data[r], data[i]);
	Record * x = data[r];
	i = p-1;
	for(int j = p; j < r ; ++j)
	{
		if(type == 0)
		{
			if(data[j]->population <= x->population)
			{
				i = i + 1; 
				swap(data[i], data[j]);
			}
		}
		else if(type == 1)
		{
			if((*data[j]->city) <= (*data[r]->city))
			{
				i = i + 1;
				swap(data[i], data[j]);
			}
		}
	}
	swap(data[i+1], data[r]);
	return i+1;
}
