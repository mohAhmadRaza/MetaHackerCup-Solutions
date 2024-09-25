def main():
    
    # # Initializing two files, From input file we will get inputs to run on our code
    # input_file = "C:/Users/LENOVO/Documents/MyReactJourney/DSA/Meta Hacker Cup Question/CheeseBurgers-II/Inputs.txt"

    # # from outputs file, we will be stroing outputs of our code
    # out_file = "C:/Users/LENOVO/Documents/MyReactJourney/DSA/Meta Hacker Cup Question/CheeseBurgers-II/Outputs.txt"
    
    # opping file to read inputs
    # with open(input_file, 'r') as file:
    
        # Redaing first line
        T = int(input())  # Number of test cases

        # list for stroing oupts
        # results = []

        for i in range(1, T + 1):

            # reading next inputs from file and storinf in three variables
            A, B, C = map(int, input().split())

            if C < A and C < B:
                print(f'Case #{i}: 0')

            elif C > A and C > B:
                S, D = C // A, (C % A) // B
                buns1, petties1 = (S + D) * 2, S + (D * 2)

                D, S = C // B, (C % B) // A
                buns2, petties2 = (S + D) * 2, S + (D * 2)

                if petties1 > petties2:
                    print(f'Case #{i}: {petties1}') 
                else:
                    if buns2 > petties2:
                        print(f'Case #{i}: {petties2}')
                    else:
                        print(f'Case #{i}: {petties2-1}')

            elif C < A and C == B:
                print(f'Case #{i}:  1')
            elif C < B and C == A:
                print(f'Case #{i}:  1')
    
    # # Stroing the output in Outputs file
    # with open(out_file, 'w') as file:
    #     file.write('\n'.join(results))


# Call the main function
main()
