#!/bin/bash
LOCK=/var/tmp/mylock && while [ -f $LOCK ]; do sleep 1; done && touch $LOCK && for i in {1..10000}; do echo "$(($(grep  -Eo '^[0-9]+$' numbers.txt | tail -1)+1))" >> numbers.txt ; done && rm $LOCK 