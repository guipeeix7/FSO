import sys
import os
from time import sleep

bashPocess = sys.argv[1]


myString = """SIGINT
SIGTERM
SIGUSR1
SIGTERM
SIGUSR2
SIGALRM
SIGINT"""
# clear && gcc aquele_flau_reverso.c && ./a.out < in.txt 
sigDict = {
    'SIGHUP' : 1, 
    'SIGINT' : 2,  
    'SIGUSR1' : 10,
    'SIGTERM' : 15, 
    'SIGUSR2' : 12,
    'SIGKILL' : 9,
    'SIGALRM' : 14,
}

# print(sys.argv)
try:
    if((sys.argv[2] == '9')):
        os.system("kill -s "+str(sigDict['SIGKILL'])+" "+str(bashPocess))
        exit()
except: 
    pass

for sig in myString.split('\n'): 
    os.system("kill -s "+str(sigDict[sig])+" "+str(bashPocess))
    # input("Press Enter to continue...")
    print("kill -s "+str(sigDict[sig])+" "+str(bashPocess)+" "+str(sig))
    sleep(1)

    




# print(myString)
# kill -s 9 143