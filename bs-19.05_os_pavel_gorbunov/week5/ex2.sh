#!/bin/bash 
if test ! -f ex2_file; then echo 0 > ex2_file; fi

start(){
    if ln ex2_file ex2.lock       #for modified version, introducing .lock file
#     if [ 1 == 1 ]               # for unmod version
    then 
       for u in `seq 1 5`;              
        do
            l_num=`tail -1 ex2_file`       #critical region, as here the next num
            l_num=$((l_num+1))             #to write to the file is received. 
                                           #if two threads got here at the same time,
            echo $l_num >> ex2_file        #same num is received and then wrote to the file.
        done
        rm ex2.lock               #removing .lock in mod version
    else                          #for modified version,
        sleep 1                   #critical region was not done
        start;                    #try one more time.
    fi
                                
}
start;



#starting with:
#ex2.sh &
#ex2.sh
# From the ex2_file if not modified:
# 0
# 1
# 2
# 3
# 3
# 4
# 4
# 5
# 5
# 6
# 6
# From new same ex2_file, but now it's modified:
# 0
# 1
# 2
# 3
# 4
# 5
# 6
# 7
# 8
# 9
# 10

