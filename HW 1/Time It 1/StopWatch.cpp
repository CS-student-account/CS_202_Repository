#include "StopWatch.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include <iterator>
using std::endl;
using std::string;
using std::cin;
using std::cout;
using std::this_thread::sleep_for;
using namespace std::chrono;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;
using std::search;
using std::binary_search;
using std::find;
using std::fill;
using std::search_n;

StopWatch::StopWatch() 
{
	//cout << "Default constructor!" << endl << endl;
    startTime = high_resolution_clock::now();
    timerRunning = true;
}

StopWatch::StopWatch(const StopWatch& watch)
{
	//cout << "Copy constructor!" << endl << endl;
}

StopWatch::~StopWatch()
{
	//cout << "Destructor!" << endl;
}

void StopWatch::Start()
{
    startTime = high_resolution_clock::now();
    timerRunning = true;
}

void StopWatch::Stop()
{
    endTime = high_resolution_clock::now();
    timerRunning = false;
}

double StopWatch::elapsedMilliseconds()
{
    /*time_point<high_resolution_clock> elapsedTime;

    if (timerRunning)
    {
        elapsedTime = high_resolution_clock::now();
    }
    else
    {
        elapsedTime = endTime;
    }*/
    double time_taken = duration_cast<nanoseconds>(endTime - startTime).count();
    return (endTime - startTime).count()/1'000'000;
}

double StopWatch::elapsedSeconds()
{
    return elapsedMilliseconds() / 1000;
}

int randomTarget()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10);
    int random = dist(gen);
    return random;
}

void lookForTen()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "------------------------------" << endl << "[Vector of size 10 elements]" << endl;

    cout << endl << "{find algorithm}";
    vector<int> vectorTenFind(10);
    generate(begin(vectorTenFind), end(vectorTenFind), random);
    int targetTen = vectorTenFind[vectorTenFind.size() / randomTarget()];
    StopWatch timerTenFind;
    for (int i = 0; i < 5; i++)
    {
        auto findTen = find(vectorTenFind.begin(), vectorTenFind.end(), targetTen);
    }
    timerTenFind.Stop();
    cout << endl << "Milliseconds: " << timerTenFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenFind.elapsedSeconds() << endl;

    cout << endl << "{binary_search algorithm}";
    vector<int> vectorTenBinarySearch(10);
    generate(begin(vectorTenBinarySearch), end(vectorTenBinarySearch), random);
    targetTen = vectorTenBinarySearch[vectorTenBinarySearch.size() / randomTarget()];
    StopWatch timerTenBinarySearch;
    sort(vectorTenBinarySearch.begin(), vectorTenBinarySearch.end());
    for (int i = 0; i < 5; i++)
    {
        auto binarySearchTen = binary_search(vectorTenBinarySearch.begin(), vectorTenBinarySearch.end(), targetTen);
    }
    timerTenBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerTenBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenBinarySearch.elapsedSeconds() << endl;

    cout << endl << "{upper_bound algorithm}";
    vector<int> vectorTenUpperBound(10);
    generate(begin(vectorTenUpperBound), end(vectorTenUpperBound), random);
    targetTen = vectorTenUpperBound[vectorTenUpperBound.size() / randomTarget()];
    StopWatch timerTenUpperBound;
    sort(vectorTenUpperBound.begin(), vectorTenUpperBound.end());
    for (int i = 0; i < 5; i++)
    {
        auto upperBoundTen = upper_bound(vectorTenUpperBound.begin(), vectorTenUpperBound.end(), targetTen) - vectorTenUpperBound.begin();
    }
    timerTenUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerTenUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenUpperBound.elapsedSeconds() << endl;

    cout << endl << "{search_n algorithm}";
    vector<int> vectorTenSearchN(10);
    generate(begin(vectorTenSearchN), end(vectorTenSearchN), random);
    targetTen = vectorTenSearchN[vectorTenSearchN.size() / randomTarget()];
    StopWatch timerTenSearchN;
    for (int i = 0; i < 5; i++)
    {
        auto searchNTen = search_n(vectorTenSearchN.begin(), vectorTenSearchN.end(), 1, targetTen);
    }
    timerTenSearchN.Stop();
    cout << endl << "Milliseconds: " << timerTenSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenSearchN.elapsedSeconds() << endl;

    cout << "------------------------------" << endl;
}

void lookForHundred()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "------------------------------" << endl << "[Vector of size 100 elements]" << endl;

    cout << endl << "{find algorithm}";
    vector<int> vectorHundredFind(100);
    generate(begin(vectorHundredFind), end(vectorHundredFind), random);
    int targetHundred = vectorHundredFind[vectorHundredFind.size() / randomTarget()];
    StopWatch timerHundredFind;
    for (int i = 0; i < 5; i++)
    {
        auto findHundred = find(vectorHundredFind.begin(), vectorHundredFind.end(), targetHundred);
    }
    timerHundredFind.Stop();
    cout << endl << "Milliseconds: " << timerHundredFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredFind.elapsedSeconds() << endl;

    cout << endl << "{binary_search algorithm}";
    vector<int> vectorHundredBinarySearch(100);
    generate(begin(vectorHundredBinarySearch), end(vectorHundredBinarySearch), random);
    targetHundred = vectorHundredBinarySearch[vectorHundredBinarySearch.size() / randomTarget()];
    StopWatch timerHundredBinarySearch;
    sort(vectorHundredBinarySearch.begin(), vectorHundredBinarySearch.end());
    for (int i = 0; i < 5; i++)
    {
        auto binarySearchHundred = binary_search(vectorHundredBinarySearch.begin(), vectorHundredBinarySearch.end(), targetHundred);
    }
    timerHundredBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerHundredBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredBinarySearch.elapsedSeconds() << endl;

    cout << endl << "{upper_bound algorithm}";
    vector<int> vectorHundredUpperBound(100);
    generate(begin(vectorHundredUpperBound), end(vectorHundredUpperBound), random);
    targetHundred = vectorHundredUpperBound[vectorHundredUpperBound.size() / randomTarget()];
    StopWatch timerHundredUpperBound;
    sort(vectorHundredUpperBound.begin(), vectorHundredUpperBound.end());
    for (int i = 0; i < 5; i++)
    {
        auto upperBoundHundred = upper_bound(vectorHundredUpperBound.begin(), vectorHundredUpperBound.end(), targetHundred) - vectorHundredUpperBound.begin();
    }
    timerHundredUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerHundredUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredUpperBound.elapsedSeconds() << endl;

    cout << endl << "{search_n algorithm}";
    vector<int> vectorHundredSearchN(100);
    generate(begin(vectorHundredSearchN), end(vectorHundredSearchN), random);
    targetHundred = vectorHundredSearchN[vectorHundredSearchN.size() / randomTarget()];
    StopWatch timerHundredSearchN;
    for (int i = 0; i < 5; i++)
    {
        auto searchNHundred = search_n(vectorHundredSearchN.begin(), vectorHundredSearchN.end(), 1, targetHundred);
    }
    timerHundredSearchN.Stop();
    cout << endl << "Milliseconds: " << timerHundredSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredSearchN.elapsedSeconds() << endl;

    cout << "------------------------------" << endl;
}

void lookForThousand()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "------------------------------" << endl << "[Vector of size 1,000 elements]" << endl;

    cout << endl << "{find algorithm}";
    vector<int> vectorThousandFind(1'000);
    generate(begin(vectorThousandFind), end(vectorThousandFind), random);
    int targetThousand = vectorThousandFind[vectorThousandFind.size() / randomTarget()];
    StopWatch timerThousandFind;
    for (int i = 0; i < 5; i++)
    {
        auto findThousand = find(vectorThousandFind.begin(), vectorThousandFind.end(), targetThousand);
    }
    timerThousandFind.Stop();
    cout << endl << "Milliseconds: " << timerThousandFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerThousandFind.elapsedSeconds() << endl;

    cout << endl << "{binary_search algorithm}";
    vector<int> vectorThousandBinarySearch(1'000);
    generate(begin(vectorThousandBinarySearch), end(vectorThousandBinarySearch), random);
    targetThousand = vectorThousandBinarySearch[vectorThousandBinarySearch.size() / randomTarget()];
    StopWatch timerThousandBinarySearch;
    sort(vectorThousandBinarySearch.begin(), vectorThousandBinarySearch.end());
    for (int i = 0; i < 5; i++)
    {
        auto binarySearchThousand = binary_search(vectorThousandBinarySearch.begin(), vectorThousandBinarySearch.end(), targetThousand);
    }
    timerThousandBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerThousandBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerThousandBinarySearch.elapsedSeconds() << endl;

    cout << endl << "{upper_bound algorithm}";
    vector<int> vectorThousandUpperBound(1'000);
    generate(begin(vectorThousandUpperBound), end(vectorThousandUpperBound), random);
    targetThousand = vectorThousandUpperBound[vectorThousandUpperBound.size() / randomTarget()];
    StopWatch timerThousandUpperBound;
    sort(vectorThousandUpperBound.begin(), vectorThousandUpperBound.end());
    for (int i = 0; i < 5; i++)
    {
        auto upperBoundThousand = upper_bound(vectorThousandUpperBound.begin(), vectorThousandUpperBound.end(), targetThousand) - vectorThousandUpperBound.begin();
    }
    timerThousandUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerThousandUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerThousandUpperBound.elapsedSeconds() << endl;

    cout << endl << "{search_n algorithm}";
    vector<int> vectorThousandSearchN(1'000);
    generate(begin(vectorThousandSearchN), end(vectorThousandSearchN), random);
    targetThousand = vectorThousandSearchN[vectorThousandSearchN.size() / randomTarget()];
    StopWatch timerThousandSearchN;
    for (int i = 0; i < 5; i++)
    {
        auto searchNThousand = search_n(vectorThousandSearchN.begin(), vectorThousandSearchN.end(), 1, targetThousand);
    }
    timerThousandSearchN.Stop();
    cout << endl << "Milliseconds: " << timerThousandSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerThousandSearchN.elapsedSeconds() << endl;

    cout << "------------------------------" << endl;
}

void lookForTenThousand()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "------------------------------" << endl << "[Vector of size 10,000 elements]" << endl;

    cout << endl << "{find algorithm}";
    vector<int> vectorTenThousandFind(10'000);
    generate(begin(vectorTenThousandFind), end(vectorTenThousandFind), random);
    int targetTenThousand = vectorTenThousandFind[vectorTenThousandFind.size() / randomTarget()];
    StopWatch timerTenThousandFind;
    for (int i = 0; i < 5; i++)
    {
        auto findTenThousand = find(vectorTenThousandFind.begin(), vectorTenThousandFind.end(), targetTenThousand);
    }
    timerTenThousandFind.Stop();
    cout << endl << "Milliseconds: " << timerTenThousandFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenThousandFind.elapsedSeconds() << endl;

    cout << endl << "{binary_search algorithm}";
    vector<int> vectorTenThousandBinarySearch(10'000);
    generate(begin(vectorTenThousandBinarySearch), end(vectorTenThousandBinarySearch), random);
    targetTenThousand = vectorTenThousandBinarySearch[vectorTenThousandBinarySearch.size() / randomTarget()];
    StopWatch timerTenThousandBinarySearch;
    sort(vectorTenThousandBinarySearch.begin(), vectorTenThousandBinarySearch.end());
    for (int i = 0; i < 5; i++)
    {
        auto binarySearchTenThousand = binary_search(vectorTenThousandBinarySearch.begin(), vectorTenThousandBinarySearch.end(), targetTenThousand);
    }
    timerTenThousandBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerTenThousandBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenThousandBinarySearch.elapsedSeconds() << endl;

    cout << endl << "{upper_bound algorithm}";
    vector<int> vectorTenThousandUpperBound(10'000);
    generate(begin(vectorTenThousandUpperBound), end(vectorTenThousandUpperBound), random);
    targetTenThousand = vectorTenThousandUpperBound[vectorTenThousandUpperBound.size() / randomTarget()];
    StopWatch timerTenThousandUpperBound;
    sort(vectorTenThousandUpperBound.begin(), vectorTenThousandUpperBound.end());
    for (int i = 0; i < 5; i++)
    {
        auto upperBoundTenThousand = upper_bound(vectorTenThousandUpperBound.begin(), vectorTenThousandUpperBound.end(), targetTenThousand) - vectorTenThousandUpperBound.begin();
    }
    timerTenThousandUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerTenThousandUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenThousandUpperBound.elapsedSeconds() << endl;

    cout << endl << "{search_n algorithm}";
    vector<int> vectorTenThousandSearchN(10'000);
    generate(begin(vectorTenThousandSearchN), end(vectorTenThousandSearchN), random);
    targetTenThousand = vectorTenThousandSearchN[vectorTenThousandSearchN.size() / randomTarget()];
    StopWatch timerTenThousandSearchN;
    for (int i = 0; i < 5; i++)
    {
        auto searchNTenThousand = search_n(vectorTenThousandSearchN.begin(), vectorTenThousandSearchN.end(), 1, targetTenThousand);
    }
    timerTenThousandSearchN.Stop();
    cout << endl << "Milliseconds: " << timerTenThousandSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenThousandSearchN.elapsedSeconds() << endl;

    cout << "------------------------------" << endl;
}

void lookForHundredThousand()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "------------------------------" << endl << "[Vector of size 100,000 elements]" << endl;

    cout << endl << "{find algorithm}";
    vector<int> vectorHundredThousandFind(100'000);
    generate(begin(vectorHundredThousandFind), end(vectorHundredThousandFind), random);
    int targetHundredThousand = vectorHundredThousandFind[vectorHundredThousandFind.size() / randomTarget()];
    StopWatch timerHundredThousandFind;
    for (int i = 0; i < 5; i++)
    {
        auto findHundredThousand = find(vectorHundredThousandFind.begin(), vectorHundredThousandFind.end(), targetHundredThousand);
    }
    timerHundredThousandFind.Stop();
    cout << endl << "Milliseconds: " << timerHundredThousandFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredThousandFind.elapsedSeconds() << endl;

    cout << endl << "{binary_search algorithm}";
    vector<int> vectorHundredThousandBinarySearch(100'000);
    generate(begin(vectorHundredThousandBinarySearch), end(vectorHundredThousandBinarySearch), random);
    targetHundredThousand = vectorHundredThousandBinarySearch[vectorHundredThousandBinarySearch.size() / randomTarget()];
    StopWatch timerHundredThousandBinarySearch;
    sort(vectorHundredThousandBinarySearch.begin(), vectorHundredThousandBinarySearch.end());
    for (int i = 0; i < 5; i++)
    {
        auto binarySearchHundredThousand = binary_search(vectorHundredThousandBinarySearch.begin(), vectorHundredThousandBinarySearch.end(), targetHundredThousand);
    }
    timerHundredThousandBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerHundredThousandBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredThousandBinarySearch.elapsedSeconds() << endl;

    cout << endl << "{upper_bound algorithm}";
    vector<int> vectorHundredThousandUpperBound(100'000);
    generate(begin(vectorHundredThousandUpperBound), end(vectorHundredThousandUpperBound), random);
    targetHundredThousand = vectorHundredThousandUpperBound[vectorHundredThousandUpperBound.size() / randomTarget()];
    StopWatch timerHundredThousandUpperBound;
    sort(vectorHundredThousandUpperBound.begin(), vectorHundredThousandUpperBound.end());
    for (int i = 0; i < 5; i++)
    {
        auto upperBoundHundredThousand = upper_bound(vectorHundredThousandUpperBound.begin(), vectorHundredThousandUpperBound.end(), targetHundredThousand) - vectorHundredThousandUpperBound.begin();
    }
    timerHundredThousandUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerHundredThousandUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredThousandUpperBound.elapsedSeconds() << endl;

    cout << endl << "{search_n algorithm}";
    vector<int> vectorHundredThousandSearchN(100'000);
    generate(begin(vectorHundredThousandSearchN), end(vectorHundredThousandSearchN), random);
    targetHundredThousand = vectorHundredThousandSearchN[vectorHundredThousandSearchN.size() / randomTarget()];
    StopWatch timerHundredThousandSearchN;
    for (int i = 0; i < 5; i++)
    {
        auto searchNHundredThousand = search_n(vectorHundredThousandSearchN.begin(), vectorHundredThousandSearchN.end(), 1, targetHundredThousand);
    }
    timerHundredThousandSearchN.Stop();
    cout << endl << "Milliseconds: " << timerHundredThousandSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredThousandSearchN.elapsedSeconds() << endl;

    cout << "------------------------------" << endl;
}

void lookForMillion()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "------------------------------" << endl << "[Vector of size 1,000,000 elements]" << endl;

    cout << endl << "{find algorithm}";
    vector<int> vectorMillionFind(1'000'000);
    generate(begin(vectorMillionFind), end(vectorMillionFind), random);
    int targetMillion = vectorMillionFind[vectorMillionFind.size() / randomTarget()];
    StopWatch timerMillionFind;
    for (int i = 0; i < 5; i++)
    {
        auto findMillion = find(vectorMillionFind.begin(), vectorMillionFind.end(), targetMillion);
    }
    timerMillionFind.Stop();
    cout << endl << "Milliseconds: " << timerMillionFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerMillionFind.elapsedSeconds() << endl;

    cout << endl << "{binary_search algorithm}";
    vector<int> vectorMillionBinarySearch(1'000'000);
    generate(begin(vectorMillionBinarySearch), end(vectorMillionBinarySearch), random);
    targetMillion = vectorMillionBinarySearch[vectorMillionBinarySearch.size() / randomTarget()];
    StopWatch timerMillionBinarySearch;
    sort(vectorMillionBinarySearch.begin(), vectorMillionBinarySearch.end());
    for (int i = 0; i < 5; i++)
    {
        auto binarySearchMillion = binary_search(vectorMillionBinarySearch.begin(), vectorMillionBinarySearch.end(), targetMillion);
    }
    timerMillionBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerMillionBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerMillionBinarySearch.elapsedSeconds() << endl;

    cout << endl << "{upper_bound algorithm}";
    vector<int> vectorMillionUpperBound(1'000'000);
    generate(begin(vectorMillionUpperBound), end(vectorMillionUpperBound), random);
    targetMillion = vectorMillionUpperBound[vectorMillionUpperBound.size() / randomTarget()];
    StopWatch timerMillionUpperBound;
    sort(vectorMillionUpperBound.begin(), vectorMillionUpperBound.end());
    for (int i = 0; i < 5; i++)
    {
        auto upperBoundMillion = upper_bound(vectorMillionUpperBound.begin(), vectorMillionUpperBound.end(), targetMillion) - vectorMillionUpperBound.begin();
    }
    timerMillionUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerMillionUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerMillionUpperBound.elapsedSeconds() << endl;

    cout << endl << "{search_n algorithm}";
    vector<int> vectorMillionSearchN(1'000'000);
    generate(begin(vectorMillionSearchN), end(vectorMillionSearchN), random);
    targetMillion = vectorMillionSearchN[vectorMillionSearchN.size() / randomTarget()];
    StopWatch timerMillionSearchN;
    for (int i = 0; i < 5; i++)
    {
        auto searchNMillion = search_n(vectorMillionSearchN.begin(), vectorMillionSearchN.end(), 1, targetMillion);
    }
    timerMillionSearchN.Stop();
    cout << endl << "Milliseconds: " << timerMillionSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerMillionSearchN.elapsedSeconds() << endl;

    cout << "------------------------------" << endl;
}

void lookForTenMillion()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "------------------------------" << endl << "[Vector of size 10,000,000 elements]" << endl;

    cout << endl << "{find algorithm}";
    vector<int> vectorTenMillionFind(10'000'000);
    generate(begin(vectorTenMillionFind), end(vectorTenMillionFind), random);
    int targetTenMillion = vectorTenMillionFind[vectorTenMillionFind.size() / randomTarget()];
    StopWatch timerTenMillionFind;
    for (int i = 0; i < 5; i++)
    {
        auto findTenMillion = find(vectorTenMillionFind.begin(), vectorTenMillionFind.end(), targetTenMillion);
    }
    timerTenMillionFind.Stop();
    cout << endl << "Milliseconds: " << timerTenMillionFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenMillionFind.elapsedSeconds() << endl;

    cout << endl << "{binary_search algorithm}";
    vector<int> vectorTenMillionBinarySearch(10'000'000);
    generate(begin(vectorTenMillionBinarySearch), end(vectorTenMillionBinarySearch), random);
    targetTenMillion = vectorTenMillionBinarySearch[vectorTenMillionBinarySearch.size() / randomTarget()];
    StopWatch timerTenMillionBinarySearch;
    sort(vectorTenMillionBinarySearch.begin(), vectorTenMillionBinarySearch.end());
    for (int i = 0; i < 5; i++)
    {
        auto binarySearchTenMillion = binary_search(vectorTenMillionBinarySearch.begin(), vectorTenMillionBinarySearch.end(), targetTenMillion);
    }
    timerTenMillionBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerTenMillionBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenMillionBinarySearch.elapsedSeconds() << endl;

    cout << endl << "{upper_bound algorithm}";
    vector<int> vectorTenMillionUpperBound(10'000'000);
    generate(begin(vectorTenMillionUpperBound), end(vectorTenMillionUpperBound), random);
    targetTenMillion = vectorTenMillionUpperBound[vectorTenMillionUpperBound.size() / randomTarget()];
    StopWatch timerTenMillionUpperBound;
    sort(vectorTenMillionUpperBound.begin(), vectorTenMillionUpperBound.end());
    for (int i = 0; i < 5; i++)
    {
        auto upperBoundTenMillion = upper_bound(vectorTenMillionUpperBound.begin(), vectorTenMillionUpperBound.end(), targetTenMillion) - vectorTenMillionUpperBound.begin();
    }
    timerTenMillionUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerTenMillionUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenMillionUpperBound.elapsedSeconds() << endl;

    cout << endl << "{search_n algorithm}";
    vector<int> vectorTenMillionSearchN(10'000'000);
    generate(begin(vectorTenMillionSearchN), end(vectorTenMillionSearchN), random);
    targetTenMillion = vectorTenMillionSearchN[vectorTenMillionSearchN.size() / randomTarget()];
    StopWatch timerTenMillionSearchN;
    for (int i = 0; i < 5; i++)
    {
        auto searchNTenMillion = search_n(vectorTenMillionSearchN.begin(), vectorTenMillionSearchN.end(), 1, targetTenMillion);
    }
    timerTenMillionSearchN.Stop();
    cout << endl << "Milliseconds: " << timerTenMillionSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerTenMillionSearchN.elapsedSeconds() << endl;

    cout << "------------------------------" << endl;
}

void lookForHundredMillion()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "------------------------------" << endl << "[Vector of size 100,000,000 elements]" << endl;

    cout << endl << "{find algorithm}";
    vector<int> vectorHundredMillionFind(100'000'000);
    generate(begin(vectorHundredMillionFind), end(vectorHundredMillionFind), random);
    int targetHundredMillion = vectorHundredMillionFind[vectorHundredMillionFind.size() / randomTarget()];
    StopWatch timerHundredMillionFind;
    for (int i = 0; i < 5; i++)
    {
        auto findHundredMillion = find(vectorHundredMillionFind.begin(), vectorHundredMillionFind.end(), targetHundredMillion);
    }
    timerHundredMillionFind.Stop();
    cout << endl << "Milliseconds: " << timerHundredMillionFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredMillionFind.elapsedSeconds() << endl;

    cout << endl << "{binary_search algorithm}";
    vector<int> vectorHundredMillionBinarySearch(100'000'000);
    generate(begin(vectorHundredMillionBinarySearch), end(vectorHundredMillionBinarySearch), random);
    targetHundredMillion = vectorHundredMillionBinarySearch[vectorHundredMillionBinarySearch.size() / randomTarget()];
    StopWatch timerHundredMillionBinarySearch;
    sort(vectorHundredMillionBinarySearch.begin(), vectorHundredMillionBinarySearch.end());
    for (int i = 0; i < 5; i++)
    {
        auto binarySearchHundredMillion = binary_search(vectorHundredMillionBinarySearch.begin(), vectorHundredMillionBinarySearch.end(), targetHundredMillion);
    }
    timerHundredMillionBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerHundredMillionBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredMillionBinarySearch.elapsedSeconds() << endl;

    cout << endl << "{upper_bound algorithm}";
    vector<int> vectorHundredMillionUpperBound(100'000'000);
    generate(begin(vectorHundredMillionUpperBound), end(vectorHundredMillionUpperBound), random);
    targetHundredMillion = vectorHundredMillionUpperBound[vectorHundredMillionUpperBound.size() / randomTarget()];
    StopWatch timerHundredMillionUpperBound;
    sort(vectorHundredMillionUpperBound.begin(), vectorHundredMillionUpperBound.end());
    for (int i = 0; i < 5; i++)
    {
        auto upperBoundHundredMillion = upper_bound(vectorHundredMillionUpperBound.begin(), vectorHundredMillionUpperBound.end(), targetHundredMillion) - vectorHundredMillionUpperBound.begin();
    }
    timerHundredMillionUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerHundredMillionUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredMillionUpperBound.elapsedSeconds() << endl;

    cout << endl << "{search_n algorithm}";
    vector<int> vectorHundredMillionSearchN(100'000'000);
    generate(begin(vectorHundredMillionSearchN), end(vectorHundredMillionSearchN), random);
    targetHundredMillion = vectorHundredMillionSearchN[vectorHundredMillionSearchN.size() / randomTarget()];
    StopWatch timerHundredMillionSearchN;
    for (int i = 0; i < 5; i++)
    {
        auto searchNHundredMillion = search_n(vectorHundredMillionSearchN.begin(), vectorHundredMillionSearchN.end(), 1, targetHundredMillion);
    }
    timerHundredMillionSearchN.Stop();
    cout << endl << "Milliseconds: " << timerHundredMillionSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerHundredMillionSearchN.elapsedSeconds() << endl;

    cout << "------------------------------" << endl;
}

void lookForBillion()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "------------------------------" << endl << "[Vector of size 1,000,000,000 elements]" << endl;

    cout << endl << "{find algorithm}";
    vector<int> vectorBillionFind(1'000'000'000);
    generate(begin(vectorBillionFind), end(vectorBillionFind), random);
    int targetBillion = vectorBillionFind[vectorBillionFind.size() / randomTarget()];
    StopWatch timerBillionFind;
    for (int i = 0; i < 5; i++)
    {
        auto findBillion = find(vectorBillionFind.begin(), vectorBillionFind.end(), targetBillion);
    }
    timerBillionFind.Stop();
    cout << endl << "Milliseconds: " << timerBillionFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerBillionFind.elapsedSeconds() << endl;

    cout << endl << "{binary_search algorithm}";
    vector<int> vectorBillionBinarySearch(1'000'000'000);
    generate(begin(vectorBillionBinarySearch), end(vectorBillionBinarySearch), random);
    targetBillion = vectorBillionBinarySearch[vectorBillionBinarySearch.size() / randomTarget()];
    StopWatch timerBillionBinarySearch;
    sort(vectorBillionBinarySearch.begin(), vectorBillionBinarySearch.end());
    for (int i = 0; i < 5; i++)
    {
        auto binarySearchBillion = binary_search(vectorBillionBinarySearch.begin(), vectorBillionBinarySearch.end(), targetBillion);
    }
    timerBillionBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerBillionBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerBillionBinarySearch.elapsedSeconds() << endl;

    cout << endl << "{upper_bound algorithm}";
    vector<int> vectorBillionUpperBound(1'000'000'000);
    generate(begin(vectorBillionUpperBound), end(vectorBillionUpperBound), random);
    targetBillion = vectorBillionUpperBound[vectorBillionUpperBound.size() / randomTarget()];
    StopWatch timerBillionUpperBound;
    sort(vectorBillionUpperBound.begin(), vectorBillionUpperBound.end());
    for (int i = 0; i < 5; i++)
    {
        auto upperBoundBillion = upper_bound(vectorBillionUpperBound.begin(), vectorBillionUpperBound.end(), targetBillion) - vectorBillionUpperBound.begin();
    }
    timerBillionUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerBillionUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerBillionUpperBound.elapsedSeconds() << endl;

    cout << endl << "{search_n algorithm}";
    vector<int> vectorBillionSearchN(1'000'000'000);
    generate(begin(vectorBillionSearchN), end(vectorBillionSearchN), random);
    targetBillion = vectorBillionSearchN[vectorBillionSearchN.size() / randomTarget()];
    StopWatch timerBillionSearchN;
    for (int i = 0; i < 5; i++)
    {
        auto searchNBillion = search_n(vectorBillionSearchN.begin(), vectorBillionSearchN.end(), 1, targetBillion);
    }
    timerBillionSearchN.Stop();
    cout << endl << "Milliseconds: " << timerBillionSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerBillionSearchN.elapsedSeconds() << endl;

    cout << "------------------------------" << endl;
}