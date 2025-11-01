#include <iostream>
#include <unistd.h>
using namespace std;


int main()
{
    cout << "我是SB\n";
    // fork();
    pid_t pid = fork();
    if (pid > 0) {
        sleep(1); // 父进程休眠1秒
        cout << pid << "是父进程\n";
        cout << "我是爸爸\n";
    } 
    else if (pid == 0) {
        cout << pid << "是子进程\n";
        cout << "我是儿子\n";
    } 
    else {
        cout << "Fork failed!\n";
    }

}
