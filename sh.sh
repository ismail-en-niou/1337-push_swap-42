#!/bin/bash

# Function to generate a random string
generate_random_string() {
    # Generate a random string of 8 characters (alphanumeric)
    tr -dc 'A-Za-z0-9adlgladgluyuyalsdcgaslvcbxbc' </dev/urandom | head -c 8
}

# Infinite loop for committing and pushing
while true; do
    # Generate a random string
    random_string=$(generate_random_string)

    # Append the random string to the file
    echo "$random_string" >> test.c

    # Broadcast a message to all users (optional)
    wall "tranitte: Appended $random_string"

    # Add changes to staging
    git add .

    # Commit changes with the random string in the commit message
    git commit -m "Added random string: $random_string"

    # Push to the repository
    git push

    # Generate a random delay between 1 and 10 seconds
    random_delay=$((RANDOM % 10 + 1))

    # Wait for the random delay
    sleep $random_delay
done
