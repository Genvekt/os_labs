#!/bin/bash
for i in {1..10000}; do echo "$(($(grep  -Eo '^[0-9]+$' numbers.txt | tail -1)+1))" >> numbers.txt ; done 