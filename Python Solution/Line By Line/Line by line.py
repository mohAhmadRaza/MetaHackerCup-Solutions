    
def main():    
    input_file = "C:/Users/LENOVO/Documents/CodingJourney/DSA Cpluplus and Python/Meta Hacker Cup Question/Line By Line/Input.txt"
    output_file = "C:/Users/LENOVO/Documents/CodingJourney/DSA Cpluplus and Python/Meta Hacker Cup Question/Line By Line/Output.txt"

    res = []

    with open(input_file, 'r') as file:
        T = int(file.readline())

        for i in range(1, T + 1):
            N, P = map(int, file.readline().split())

            calculation = 100 * (P / 100) ** ((N-1)/N)
            calculation -= P

            res.append(f'Case #{i}: {calculation}')

    with open(output_file, 'w') as file:
        file.write('\n'.join(res))

main()
    
