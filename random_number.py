import random

# Generate 100 unique random numbers between -1000 and 1000
unique_numbers = random.sample(range(-1000000, 1000001), 100)

# Print the numbers in the desired format
for i in range(0, 100, 10):
    print(' '.join(map(str, unique_numbers[i:i+10])))