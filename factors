#!/usr/bin/python3
'''Factorize an integer into two ints'''


import sys


def factorize(file_):
    with open(file_) as f:
        for line in f:
            i = 2
            line_int = int(line)
            while i < line_int:
                if line_int % i == 0:
                    quo = int(line_int / i)
                    print("{:d}={:d}*{:d}".format(line_int, quo, i))
                    break
                else:
                    i += 1;
        return
    
def main():
    if len(sys.argv) != 2:
        print("Usage: factor <file>")
        return
    int_file = sys.argv[1]
    factorize(int_file)

main()
