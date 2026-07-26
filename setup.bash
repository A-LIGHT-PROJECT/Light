#!/bin/bash

echo "Welcome to Light setup!"

if [[ ! command -v g++ || ! command -v gcc ]]; then
  echo "[Setup] gcc isn't installed, cannot keep going forward"
fi

if 
