#!/bin/bash

# Stored credentials
correct_username="Gokhan"
correct_password_hash="03ac674216f3e15c761ee1a5e255f067953623c8b388b4459e13f978d7c846f4"  # hash of '1234'

# Read inputs
input_username="$1"
input_password="$2"

# Hash the input password
input_password_hash=$(echo -n "$input_password" | sha256sum | awk '{print $1}')

# Compare credentials
if [ "$input_username" == "$correct_username" ]; then
    if [ "$input_password_hash" == "$correct_password_hash" ]; then
        echo "true"
    else
        echo "bad_password"
    fi
else
    echo "bad_username"
fi
