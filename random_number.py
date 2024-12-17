import random

unique_numbers = random.sample(range(-10000, 10000), 100)
numbers_str = ' '.join(map(str, unique_numbers))
with open("test", "w") as file:
    file.write(numbers_str)
