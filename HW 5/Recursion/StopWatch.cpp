#include "StopWatch.h"
#include <string>
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
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
using std::find;
using std::getline;
using std::ifstream;
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

    //elapsed time in milliseconds
    double elapsedMilliseconds = (endTime - startTime).count() / 1'000'000;

    //printing out elapsed time in both ms and s
    cout << endl << "That took " << elapsedMilliseconds << " ms / "
        << (elapsedMilliseconds / 1000) << " s" << endl;
}

//vary location of target string for each search
template <typename T>
int randomTarget(T &temp)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, temp.size() - 1);
    int random = dist(gen);
    return (random);
}

// ensure the text file doesn't have problems
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

void timeIt2(string &book)
{
    cout << "===========================================================" << endl;
    if (checkFile(book)) //check text file first for any problems
    {
        cout << "===========================================================" << endl;


        /* vector container operations */
        cout << "[Time to copy " << book << " into a vector container]";
        StopWatch timerVectorRead; //start timer
        ifstream bookVectorRead(book); //pass text file into filestream
        //pass strings from filestream to vector
        vector<string> stringVectorRead(istream_iterator<string>{bookVectorRead}, 
            istream_iterator<string>{});
        timerVectorRead.Stop();//stop timer and print results


        cout << endl << "[Time to find a random string within " 
            << book << "'s vector container]" << endl;
        int targetStringSeed = randomTarget(stringVectorRead); //random int
        string targetString = stringVectorRead[targetStringSeed]; //random string target
        StopWatch timerFind; //start timer
        auto findTargetVector = find(stringVectorRead.begin(), stringVectorRead.end(), 
            targetString); //iterator for finding the target string
        if (findTargetVector != stringVectorRead.end()) //if target string found
        {
            cout << "String '" << targetString << "' found at position: " 
                << targetStringSeed; //give value and position of target string
        }
        timerFind.Stop(); //stop timer and print results
        

        cout << endl << "[Time to sort " << book << "'s vector container]";
        StopWatch timerVectorSort; //start timer
        sort(stringVectorRead.begin(), stringVectorRead.end());
        timerVectorSort.Stop(); //stop timer and print results


        cout << "__________________________________________________________" << endl;


        /* list container operations */
        cout << endl << "[Time to copy " << book << " into a list container]";
        StopWatch timerListRead; //start timer
        ifstream bookListRead(book);
        list<string> stringListRead(istream_iterator<string>{bookListRead}, 
            istream_iterator<string>{});
        timerListRead.Stop(); //stop timer and print results


        cout << endl << "[Time to find a random string within " 
            << book << "'s list container]" << endl;
        auto listFront = stringListRead.begin();
        advance(listFront, targetStringSeed);
        string targetListString = *listFront;
        StopWatch timerListFind; //start timer
        auto findTargetList = find(stringListRead.begin(), stringListRead.end(), 
            targetString);
        if (findTargetList != stringListRead.end())
        {
            //location of a string in a list is just how many steps we advanced forward
            cout << "String '" << targetListString << "' found at position: " 
                << targetStringSeed;
        }
        timerListFind.Stop(); //stop timer and print results


        cout << endl << "[Time to sort " << book << "'s list container]";
        StopWatch timerListSort; //start timer
        stringListRead.sort();
        timerListSort.Stop(); //stop timer and print results


        cout << "__________________________________________________________" << endl;


        /* deque container operations */
        cout << endl << "[Time to copy " << book << " into a deque container]";
        StopWatch timerDequeRead; //start timer
        ifstream bookDequeRead(book);
        deque<string> stringDequeRead(istream_iterator<string>{bookDequeRead}, 
            istream_iterator<string>{});
        timerDequeRead.Stop(); //stop timer and print results


        cout << endl << "[Time to find a random string within " 
            << book << "'s deque container]" << endl;
        StopWatch timerDequeFind; //start timer
        auto findTargetDeque = find(stringDequeRead.begin(), stringDequeRead.end(), 
            targetString);
        if (findTargetDeque != stringDequeRead.end())
        {
            int targetStringIndex = findTargetDeque - stringDequeRead.begin();
            cout << "String '" << targetString << "' found at position: " << 
                targetStringSeed;
        }
        timerDequeFind.Stop(); //stop timer and print results


        cout << endl << "[Time to sort " << book << "'s deque container]";
        StopWatch timerDequeSort; //start timer
        sort(stringDequeRead.begin(), stringDequeRead.end());
        timerDequeSort.Stop(); //stop timer and print results


        cout << "===========================================================" << endl
            << "===========================================================" 
            << endl << endl << endl;
    }
}