import re

def filterLists(vforkList, forkList):
    vforkList.pop(0)
    forkList.pop(0)

    vforkList.pop(len(vforkList) - 1)
    vforkList.remove(vforkList[-1])

    forkList.pop(len(forkList) - 1)
    forkList.remove(forkList[-1])

f_fork = open("benchmark_fork.txt", "r")
f_vfork = open("benchmark_vfork.txt", "r")

forkList = []
vforkList = []
line = str()

for x in f_fork:
    line = re.sub('\n', '', x)
    forkList.append(line)

for x in f_vfork:
    line = re.sub('\n', '', x)
    vforkList.append(line)

filterLists(vforkList, forkList)

f_fork.close()
f_vfork.close()

f = open("benchmark.txt", "a")

it = 0

for i in range(len(vforkList)):
    str = '{0} {1} {2}'.format(i ,forkList[i], vforkList[i])
    str+= "\n"
    f.write(str)
    i+=1
    str = ""

f.close()