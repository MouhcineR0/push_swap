#!/bin/bash

# Number of unique random numbers to generate
NUM_COUNT=100
MAX0=0

# Check if Python is installed
if ! command -v python3 &> /dev/null; then
  echo "Python3 is required but not installed. Please install Python3."
  exit 1
fi

# Infinite loop
while true; do
  echo "Running test..."

  # Generate 500 unique random numbers using Python
  ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-10000, 10000), $NUM_COUNT))))")

  # Execute push_swap with the generated numbers and count the number of lines in the output
  RESULT=$(./push_swap $ARG | wc -l)

  # Update MAX0 if a new maximum is found
  if [ "$RESULT" -gt "$MAX0" ]; then
    MAX0=$RESULT
  fi

  # Display the result
  echo "Arguments: $ARG"
  echo "Instructions: $RESULT (Max so far: $MAX0)"
  echo "---------------------------------"

  # Check if instructions exceed 5500
  if [ "$RESULT" -gt 5500 ]; then
    echo "Test stopped: Found a result with instructions greater than 5500."
    break
  fi
done