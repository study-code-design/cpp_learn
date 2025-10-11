#!/bin/bash



suffix=$1
filename=$2

filename="${filename%.cpp}"
t=$(cat example.txt)
if [ "$suffix" = "run" ]; then
    cd build
    cmake ..
    
    if make; then
        clear
        echo "---build succeeded---"
    else
        echo "---build failed---"
        # 你可以在这里做其他处理（保存 log、发送通知等）
    fi
    # make
    # clear
    ./$filename
    cd ..
    exit 0
fi




if [ "$suffix" = "-w" ]; then

    t=$(cat CMakeLists.txt | grep "add_executable($filename $filename.cpp)")
    if [ ! -e "./$filename" ]; then
        echo "file not exist"
        touch "./$filename.cpp"
        if [ "$t" != "add_executable($filename $filename.cpp)" ]; then
            echo "add_executable($filename $filename.cpp)" >> CMakeLists.txt
        else
            echo "executable has existed"
        fi

        if [ "$t" = "" ]; then
            cat example.txt > "./$filename.cpp"
            echo "***example code has been written to $filename.cpp***"
        else
            echo "***$filename.cpp is not empty***"
        fi
        
    fi
fi

if [ "$suffix" = "-del" ]; then
    if [ -e "./$filename.cpp" ]; then
        echo "file exist"
        rm "./$filename.cpp"
        sed -i "/add_executable($filename $filename.cpp)/d" CMakeLists.txt
    else
        echo "file not exist"
    fi
fi

if [ -d "./build" ]; then
    echo "build directory exists"
    cd build
else
    echo "creating build directory"
    mkdir build
    cd build
fi

cd ..