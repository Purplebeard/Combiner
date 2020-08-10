#!/usr/local/bin/python3.8

#########################################################################
# File Name: number_collection.py
# Author: Kidd Chao
# Mail: zzykid1412@gmail.com
# Created Time: Fri 07 Aug 2020 05:04:49 PM DST
#########################################################################
import re
import os
import sys
import requests
from requests.exceptions import ReadTimeout,HTTPError,RequestException

global data

fw = open("number_list.txt", 'w')

fr = open("urls.txt", 'r')
while 1:
    lines = fr.readlines(1000) #Access URL
    if not lines:
        break
    for line in lines:
        print(line)
            
        try:
            r = requests.get(line)
        except ReadTimeout:
            print("Read timeout")
        except HTTPError:
            print("HTTP ERROR")
        except RequestException:
            print("Request exception")
        else:
            data = r.text
            print(data)
            # '\d+' means numbers
            num_list = re.findall(r"\d+", data)
            #print(num_list)
            for number in num_list:
                if(len(number) == 11):
                    if(number[0] == '1'):
                        fw.write(number+"\n")

        fw.write("\n")
        

fr.close()

fw.close()
