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

void StopWatch::Stop(const StopWatch &temp) //stop timer and print duration
{
    endTime = high_resolution_clock::now();

    double time_taken = duration_cast<nanoseconds>(endTime - startTime).count();

    double elapsedMilliseconds = (endTime - startTime).count() / 1'000'000;

    cout << endl << "That took " << elapsedMilliseconds << " ms / "
        << (elapsedMilliseconds / 1000) << " s" << endl;
}

// vary location of target string for each search
int randomTarget(vector<int> &temp)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, temp.size()-1);
    int random = dist(gen);
    return (random);
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
            << "[Time to copy " << book << " into various containers]" << endl;

        cout << endl << "{vector container}";
        StopWatch timerVector;
        ifstream bookVector(book);

        // Read the lines of a file into a container.
        vector<string> stringVector(istream_iterator<Line>{bookVector}, istream_iterator<Line>{});

        timerVector.Stop(timerVector);


        cout << endl << "{list container}";
        StopWatch timerList;
        ifstream bookList(book);
        // Read the lines of a file into a container.
        list<string> stringList(istream_iterator<Line>{bookList}, istream_iterator<Line>{});

        timerList.Stop(timerList);


        cout << endl << "{deque container}";
        StopWatch timerDeque;
        ifstream bookDeque(book);
        // Read the lines of a file into a container.
        deque<string> stringDeque(istream_iterator<Line>{bookDeque}, istream_iterator<Line>{});

        timerDeque.Stop(timerDeque);


        cout << endl << "--------------------------------------------------" << endl << endl;
    }
}