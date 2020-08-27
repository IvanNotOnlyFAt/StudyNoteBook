# File Name: mkdir.sh
# Author: IvanLxy
# mail: yoyiyyo@163.com
# Created Time: Fri 31 Jul 2020 03:11:38 PM CST
#=============================================================
#!/bin/bash

is_directory()
{
    DIR_NAME=$1 
    #if 中 []是第一句，then和return是第二条
    if [ ! -d $DIR_NAME ]; then #要注意命令和各参数之间必须用空格隔开
        return 1
    else
        return 0
    fi
}
#""双引号要做替换
for DIR in "$@";do
    if is_directory "$DIR"
    then : #:表示是空
    else
        echo "$DIR doesn't exist. Creating it now.."
        mkdir $DIR > /dev/null 2>&1
        if [ $? -ne 0 ]; then
            echo "Cannot create directory $DIR"
            exit 1
        fi
    fi
done

#mkdir $DIR > /dev/null 2>&1
#>是用于重定向的
#/dev/null重定向到这个特殊设备中
#把标准错误输出2重定义到1 ，，，，
#为了不使用原来的错误信息，而使用后面自己写的 
#对于& 1 更准确的说应该是文件描述符 1,而1标识标准输出，stdout。
#对于2 ，表示标准错误，stderr。
#2>&1 的意思就是将标准错误重定向到标准输出。这里标准输出已经重定向到了 /dev/null。那么标准错误也会输出到/dev/null

#可以把/dev/null 可以看作"黑洞". 它等价于一个只写文件. 所有写入它的内容都会永远丢失. 而尝试从它那儿读取内容则什么也读不到.
#偶尔也可以把 & 在命令的最后加上，表示让程序后台执行。
