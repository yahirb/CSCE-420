import time
import math

start_time = time.time()

### Parse File
fname = "hw1pr1_data.txt"
data = []
with open(fname) as f:
    data = [tuple(map(int, line.split())) for line in f]


### BFS Algorithm
# Distance Formula
def distance(p0, p1):
    return math.sqrt((p0[0] - p1[0])**2 + (p0[1] - p1[1])**2)
# Variables
new_data = []
length = 0
# Start of Algorithm
cPair = data[0]
print (cPair)
new_data.append(cPair)
data.pop(0)
sDistance = 10000000
sIndex = 0
# Run until exhaust data list
while len(data) > 0:
    # search through list for closest
    for i in range(0, len(data)):
        if distance(cPair, data[i]) < sDistance:
            sDistance = distance(cPair, data[i])
            sIndex = i
        else:
            continue
    # Add values to variables and reset for next loop
    cPair = data[sIndex]
    print (cPair)
    new_data.append(cPair)
    data.pop(sIndex)
    length = length + sDistance
    sDistance = 10000000
    sIndex = 0


### Print Total Path Length
print("--- Length : %s ---" % length)


### Print Alloted Time
print("--- %s seconds ---" % (time.time() - start_time))
