# # !/bin/bash
# # echo "Today is" `date`
# var=`date`
# echo "var is $var"
# # echo -e "\nWhat is your file name?"
# # read filename
# # echo "Your file name is $filename"

# echo `ls`
# # 判断文件是否存在  
# # if [ -f $filename ]
# # then
# #     echo "File $filename exists"
# # else
# #     echo "File $filename does not exist"
# # fi
# #这个代表在命令行执行后加上的参数
# t=$1

# #读取文件操作
# # while read line
# # do
# #   echo $line
# # done < inn_area.cpp
# # echo "test num"
# # read num 
# if (( t=="-w" ));then
#     echo "1"
# else
#     echo "2"
# fi

# # echo -n "add_executable(3_quote 3_quote.cpp)" >> CMakeLists.txt
# make ./build

# t=`cat CMakeLists.txt | grep "add_executable"`
# t=$(cat CMakeLists.txt | grep "add_executable")
# echo $t
# echo "add_executable(test test.cpp)" >> CMakeLists.txt

t2="4_quote_return"
temp="${t2%e*}"
echo "$temp" 

t=$(cat example.txt)
if ["$t" == ""]; then
    echo "empty"
else
    echo "not empty"
fi
# cat example.txt > test.txt