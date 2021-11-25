import os
import sys


def open_file(file_path: str, operate: str):
    print("enter python script function success")
    print(os.getcwd())
    if os.path.exists(file_path):
        if operate == "1":
            os.system(file_path)
        elif operate == "0":
            os.remove(file_path)
        else:
            print("any operation is executed")
    else:
        print("file not exist")


if __name__ == '__main__':
    argvs = sys.argv
    print(argvs)
    print("enter python script success")
    # print(argvs[0], argvs[1])
    open_file(argvs[0], argvs[1])
