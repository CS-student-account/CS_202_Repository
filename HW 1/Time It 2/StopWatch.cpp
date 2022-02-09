#include "StopWatch.h"
#include <string>
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <list>
#include <deque>
using std::endl;
using std::string;
using std::cout;
using namespace std::chrono;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;
using std::binary_search;
using std::find;
using std::search_n;
using std::to_string;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::istream;
using std::istream_iterator;
using std::list;
using std::deque;

StopWatch::StopWatch() //default constructor
{
    startTime = high_resolution_clock::now();
}

StopWatch::StopWatch(const StopWatch& watch) //copy constructor
{
}

StopWatch::~StopWatch() //destructor
{
}

void StopWatch::Start() //restart timer
{
    startTime = high_resolution_clock::now();
}

void StopWatch::Stop() //stop timer and print duration
{
    endTime = high_resolution_clock::now();

    double time_taken = duration_cast<nanoseconds>(endTime - startTime).count();

    double elapsedMilliseconds = (endTime - startTime).count() / 1'000'000;

    cout << endl << "That took " << elapsedMilliseconds << " ms / "
        << (elapsedMilliseconds / 1000) << " s" << endl;
}

// vary location of target string for each search
int randomTarget(vector<string> &temp)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, temp.size()-1);
    int random = dist(gen);
    return (random);
}

bool checkFile(const string& filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Cannot open file." << endl;
        return false;
    }
    else
    {
        while (true)
        {
            string line;
            getline(fin, line);

            if (!fin)
            {
                if (fin.eof())
                {
                    cout << "Successfully read the whole file of " << filename << endl;
                    return true;
                }
                else
                {
                    cout << "Error during transmit." << endl;
                    return false;
                }
                break;
            }
        }
    }
}

struct Line
{
    // Store data here
    string data;
    // Convert object to string
    operator string const& () const 
    { 
        return data; 
    }
    // Read a line from a stream.
    friend istream& operator>>(istream& stream, Line& line)
    {
        return getline(stream, line.data);
    }
};

void timeIt2(string &book)
{
    if (checkFile(book))
    {
        cout << "--------------------------------------------------" << endl
            << "[Time to copy " << book << " into a vector container]" << endl;
        cout << "{vector container}";
        StopWatch timerVectorRead;
        ifstream bookVectorRead(book);
        vector<string> stringVectorRead(istream_iterator<Line>{bookVectorRead}, istream_iterator<Line>{});
        timerVectorRead.Stop();

        cout << endl << "[Time to find a random string within " << book << " within that vector]" << endl;
        cout << "{vector container}";
        StopWatch timerVectorFind;
        ifstream bookVectorFind(book);
        
        timerVectorFind.Stop();

        /* ----------------------------------------------------------------------------------------- */

        cout << endl << "[Time to copy " << book << " into a list container]" << endl;
        cout << "{list container}";
        StopWatch timerListRead;
        ifstream bookListRead(book);
        list<string> stringListRead(istream_iterator<Line>{bookListRead}, istream_iterator<Line>{});
        timerListRead.Stop();

        cout << endl << "[Time to find a random string within " << book << " within that list]" << endl;
        cout << "{list container}";
        StopWatch timerListFind;
        ifstream bookListFind(book);
        list<string> stringListFind(istream_iterator<Line>{bookListFind}, istream_iterator<Line>{});
        timerListFind.Stop();

        /* ----------------------------------------------------------------------------------------- */

        cout << endl << "[Time to copy " << book << " into a deque deque]" << endl;
        cout << "{deque container}";
        StopWatch timerDequeRead;
        ifstream bookDequeRead(book);
        deque<string> stringDequeRead(istream_iterator<Line>{bookDequeRead}, istream_iterator<Line>{});
        timerDequeRead.Stop();

        cout << endl << "[Time to find a random string within " << book << " within that deque]" << endl;
        cout << "{deque container}";
        StopWatch timerDequeFind;
        ifstream bookDequeFind(book);
        deque<string> stringDequeFind(istream_iterator<Line>{bookDequeFind}, istream_iterator<Line>{});
        timerDequeFind.Stop();

        cout << endl << "--------------------------------------------------" << endl << endl;
    }
}

/*void lookForInt(int& temp)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, temp*10);
    auto random = [&dist, &gen]()
    {
        return dist(gen);
    };

    cout << endl << "--------------------------------------------------" << endl
        << "[Vector of size " << vectorSize(temp) << " elements]" << endl;


    cout << endl << "{find algorithm}";
    vector<int> vectorFind(temp); //initialize vector
    generate(begin(vectorFind), end(vectorFind), random); //fill vector
    int target = vectorFind[randomTarget(vectorFind)]; //random int target
    StopWatch timerFind; //start timer
    for (int i = 0; i < 100; i++) //search for target int 100 times
    {
        auto findTarget = find(vectorFind.begin(), vectorFind.end(), target);
    }
    timerFind.Stop(); //stop timer
    cout << endl << "Milliseconds: " << timerFind.elapsedMilliseconds()
        << endl << "Seconds: " << timerFind.elapsedSeconds() << endl;


    cout << endl << "{binary_search algorithm}"; //same as above, different algorithm
    vector<int> vectorBinarySearch(temp);
    generate(begin(vectorBinarySearch), end(vectorBinarySearch), random);
    target = vectorBinarySearch[randomTarget(vectorBinarySearch)];
    sort(vectorBinarySearch.begin(), vectorBinarySearch.end());
    StopWatch timerBinarySearch;
    for (int i = 0; i < 100; i++)
    {
        auto binarySearchTarget = binary_search(vectorBinarySearch.begin(),
            vectorBinarySearch.end(), target);
    }
    timerBinarySearch.Stop();
    cout << endl << "Milliseconds: " << timerBinarySearch.elapsedMilliseconds()
        << endl << "Seconds: " << timerBinarySearch.elapsedSeconds() << endl;


    cout << endl << "{upper_bound algorithm}"; //same as above, but different algorithm
    StopWatch timerUpperBound;
    for (int i = 0; i < 100; i++)
    {
        auto upperBoundTarget = upper_bound(vectorBinarySearch.begin(),
            vectorBinarySearch.end(), target) - vectorBinarySearch.begin();
    }
    timerUpperBound.Stop();
    cout << endl << "Milliseconds: " << timerUpperBound.elapsedMilliseconds()
        << endl << "Seconds: " << timerUpperBound.elapsedSeconds() << endl;


    cout << endl << "{search_n algorithm}"; //same as above, but different algorithm
    vector<int> vectorSearchN(temp);
    generate(begin(vectorSearchN), end(vectorSearchN), random);
    target = vectorSearchN[randomTarget(vectorSearchN)];
    StopWatch timerSearchN;
    for (int i = 0; i < 100; i++)
    {
        auto searchNTarget = search_n(vectorSearchN.begin(), vectorSearchN.end(),
            1, target);
    }
    timerSearchN.Stop();
    cout << endl << "Milliseconds: " << timerSearchN.elapsedMilliseconds()
        << endl << "Seconds: " << timerSearchN.elapsedSeconds() << endl;


    cout << "--------------------------------------------------" << endl;
}*/