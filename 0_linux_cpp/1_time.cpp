#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
using namespace std;


int main()
{
    timeval start,end;
    gettimeofday(&start,NULL); // 计时开始
    time_t now = time(0);
    cout << now << endl;
    tm tmnow;
    localtime_r(&now,&tmnow);
    cout << tmnow.tm_year + 1900 << "-" << tmnow.tm_mon + 1 << "-" << tmnow.tm_mday << " "
         << tmnow.tm_hour << ":" << tmnow.tm_min << ":" << tmnow.tm_sec << endl;
    sleep(1); // 休眠1秒
    gettimeofday(&end,NULL); // 计时结束
    timeval tv;
    tv.tv_usec = end.tv_usec - start.tv_usec;
    timersub(&end,&start,&tv); // 计算时间差
    cout << "运行时间：" << tv.tv_sec << "秒" << endl;
    cout << tv.tv_usec << "微秒" << endl;
    return 0;
}