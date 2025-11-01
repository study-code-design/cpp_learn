#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;


void EXIT(int signum)
{   
    cout << "exit signal " << signum << endl;
    cout << "exit program" << endl;
    exit(0);
}

class control_signal
{
public:
    control_signal()
    {
        for(int ii=0; ii<NSIG; ii++) signal(ii,SIG_IGN);
        signal(2,EXIT);
        signal(15,EXIT);
    }
    ~control_signal()
    {
        cout << "exit control_signal" << endl;
    }
    
};




void timer_test(int signum)
{
    cout << "Timer expired!" << endl;
    alarm(5); // reset alarm
}

void sig_handler(int signum)
{
    cout << "Signal " << signum << " received." << endl;
    signal(signum,SIG_DFL);
    // exit(0);
}
int main()
{
    control_signal cs;
    // signal(SIGINT, sig_handler);
    signal(1, SIG_IGN); // ignore SIGHUP
    signal(14, timer_test);
    alarm(5); // set alarm for 5 seconds
    // atexit(control_signal::~control_signal);
    while (1)
    {
        cout << "Hello, world!" << endl;

        sleep(1);
    }
    
}