#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
using namespace std;

int main(int argc,char *argv[])
{
    // get current working directory
    char path1[256];
    getcwd(path1, 256);
    cout << "Current working directory is " << path1 << endl;
    char *path2 = get_current_dir_name();
    cout << "Current working directory is " << path2 << endl;
    free(path2);

    // change working directory
    bool result =  mkdir("./tt/new_dir", 0755);
    if (!result) cout << "Directory created successfully" << endl;
    else cout << "Error creating directory" << endl;

    // delete directory
    rmdir("./tt/new_dir");
    if (!result) cout << "Directory deleted successfully" << endl;
    else cout << "Error deleting directory" << endl;

    // ------------------------
    // get file list #include <dirent.h>
    DIR *dir;
    if ((dir=opendir(argv[1]))== 0) return -1;
    struct dirent *stdinfo=nullptr;
    while (1)
    {
        if((stdinfo=readdir(dir))==nullptr) break;
        cout << "file name: " << stdinfo->d_name << endl;
        cout << "file type: " << (int)stdinfo->d_type << endl;
    }
    closedir(dir);
}