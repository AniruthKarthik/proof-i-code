#!/bin/bash
echo "1st - Problem:"
for i in {1..10}
	do
    		echo $i
	done
echo "2nd - Problem:"
for i in {10..1}
	do
    		echo $i
	done
echo "3rd - Problem:"
for ((i=2; i<=20; i+=2))
	do
    		echo $i
	done
echo "4th - Problem:"
read -p "Enter a number N: " N
sum=0
for ((i=1; i<=N; i++))
	do
    		sum=$((sum+i))
	done
echo "Total = $sum "
echo "5th - Problem:"
read -p "Enter a number N: " N
for ((i=1; i<=10; i++))
	do
 		echo "$N x $i = $((N * i))"
	done
echo "6th - Problem:"
password=""
while [ "$password" != "secret" ]
	do
    		read -p "Enter password: " password
	done
echo "Access granted!"
echo "7th - Problem:"
total=0
while true
	do
    		read -p "Enter a number (0 to stop): " n
    		if [ $n -eq 0 ]; then
        		break
    		fi
    			total=$((total+n))
	done
echo "Total = $total"
echo "8th - Problem:"
read -p "Enter N: " N
sum=0
for ((i=1; i<=N; i++))
	do
    		read -p "Enter number $i: " num
    		sum=$((sum + num))
	done
avg=$(echo "$sum / $N" | bc -l)
echo "Average = $avg"
echo "9th - Problem:"
read -p "Enter start: " start
read -p "Enter end: " end
for ((i=start; i<=end; i++))
	do
    		if (( i % 2 == 0 )); then
        		echo $i
    		fi
	done
echo "10 - th Problem:"
read -p "Enter a word: " word
len=${#word}
for ((i=len-1; i>=0; i--))
	do
    		echo -n "${word:$i:1}"
	done
echo
