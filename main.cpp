#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;
int g=0;
class Test
{
    static mutex mtx;
    // mutex mtx;
    public:
        void print(int i)
        {
            lock_guard<mutex> lg(mtx);
            cout<<" value of I="<<i<<endl;
        }
};

mutex Test::mtx;


int main()
{
    vector<thread> worker;
    for(int i=0;i<100;i++)
    {
        g++;
        worker.emplace_back([](int val){
                             Test obj;
                             obj.print(val);

                            },g);
    }
    for(int i=0;i<100;i++)
    {
        worker[i].join();
    }
    return 0;
}
