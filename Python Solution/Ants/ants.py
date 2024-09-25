from collections import defaultdict
from math import gcd
  
def main():    
    inputFile = "c:/Users/LENOVO/Documents/CodingJourney/DSA Cpluplus and Python/Meta Hacker Cup Question/Ants/Inputs.txt"
    outputFile = "c:/Users/LENOVO/Documents/CodingJourney/DSA Cpluplus and Python/Meta Hacker Cup Question/Ants/Output.txt"
    
    with open(inputFile, "r") as file:
        T = int(file.readline().strip())  # Read the number of test cases
        res = []
        
        def checkCollinearity(a, b):
            dx = b[0] - a[0]
            dy = b[1] - a[1]

            if dx == 0:  # Vertical line
                slope = (float('inf'), 0)
                if b[1] != a[1]:
                    return 

            elif dy == 0:  # Horizontal line
                slope = (0, 0)
                if a[0] != b[0]:
                    return
            else:
                divisor = gcd(dx, dy)
                slope = (dy // divisor, dx // divisor)  # Reduced slope to avoid precision issues

            return slope

        for case_num in range(1, T + 1):
            freq = defaultdict(set)
            n = int(file.readline().strip())
            points = []
            
            for _ in range(n):
                A, B = map(int, file.readline().split())
                points.append((A, B))

            max_collinear = 1  # Minimum is 1 (a single point)

            for i in range(n):
                slope_count = defaultdict(int)
                for j in range(n):
                    if i != j:
                        slope = checkCollinearity(points[i], points[j])
                        slope_count[slope] += 1

                if slope_count:
                    max_collinear = max(max_collinear, max(slope_count.values()) + 1)

            value = n - max_collinear
            res.append(f'Case #{case_num}: {value}')
            
    with open(outputFile, 'w') as file:
        file.write('\n'.join(res))

main()
