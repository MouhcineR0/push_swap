#!/bin/bash

# Check if an argument is provided
if [ -z "$1" ]; then
  echo "Please provide an argument."
  exit 1
fi

# Execute the argument as a command and count the number of lines in the output
$1 | wc -l
