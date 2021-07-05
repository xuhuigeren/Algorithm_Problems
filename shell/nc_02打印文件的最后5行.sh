# 描述
# 经常查看日志的时候，会从文件的末尾往前查看，于是请你写一个 bash脚本以输出一个文本文件 nowcoder.txt中的最后5行
# 示例:
# 假设 nowcoder.txt 内容如下：
# #include<iostream>
# using namespace std;
# int main()
# {
# int a = 10;
# int b = 100;
# cout << "a + b:" << a + b << endl;
# return 0;
# }


# 你的脚本应当输出：
# int a = 10;
# int b = 100;
# cout << "a + b:" << a + b << endl;
# return 0;
# }


tail -n5 nowcoder.txt

##
awk 'NR>=4{print $0}' nowcoder.txt

NR ||　NF

NR代表的是这个文本文件的行数（记录数）
NF代表的是一个文本文件中一行（一条记录）中的字段个数/列数


September 2003               # NR=1;NF=2
Su Mo Tu We Th Fr Sa         # NR=2;NF=7
    1  2  3  4  5  6         # NR=3;NF=6
07 08 09 10 11 12 13         # NR=4;NF=7
14 15 16 17 18 19 20         # NR=5;NF=7
21 22 23 24 25 26 27         # NR=6;NF=7
28 29 30                     # NR=7;NF=3