
import time
import math

start_time = time.time()

### Parse File
fname = "hw1pr2_data.txt"
points_original = []
with open(fname) as f:
    points_original = [tuple(map(int, line.split())) for line in f]


### Functions
# Return Ordered List by Distance
def get_ordered_list(pts, pt):
    temp = pts
    temp.sort(key = lambda p: math.sqrt((p[0] - pt[0])**2 + (p[1] - pt[1])**2))
    return temp

# Distance Formula
def distance_formula(p0, p1):
    return math.sqrt((p0[0] - p1[0])**2 + (p0[1] - p1[1])**2)

# Start of Algorithm
current_point = points_original[0]
points_original.pop(0)
distances = []
sorted_points = []
def makeDo(pt, d, pts):

    points = pts
    distance = d
    point = pt
    """
    if(len(points) > 4):
        sorted_points = get_ordered_list(points,pt)[0:4]
        for i in range(0,len(sorted_points)-1):
            spt = sorted_points[i]
            distance = distance + distance_formula(pt, spt)
            distances.append(distance)
            points.pop(i)
            new_points = points
            makeDo(sorted_points[i], distance, new_points)
            points.insert(i, spt)
            distance = distance - distance_formula(pt, spt)
    """
    if (len(points) > 1):
        for i in range(0,len(points)):
            print (len(points))
            spt = points[i]
            new_distance = distance + distance_formula(point, spt)
            #distances.append(new_distance)
            new_points = points
            new_points.pop(i)
            makeDo(spt, new_distance, new_points)

    elif (len(points) == 1):
        print ("length = 1")
        for i in range(0,len(points)):
            spt = points[i]
            new_distance = distance + distance_formula(point, spt)
    else:
        return



makeDo(current_point, 0, points_original)
