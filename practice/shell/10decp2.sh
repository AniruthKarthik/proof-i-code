#!/bin/bash
echo "----------------------------------"
echo "1. Array operations"
echo "----------------------------------"
arr=(10 20 30 40 50 60 70 80 90 100)
echo "All elements: ${arr[@]}"
echo "Array length: ${#arr[@]}"
echo "3rd element: ${arr[2]}"
echo "7th element: ${arr[6]}"
echo
echo "----------------------------------"
echo "2. Read 5 names and reverse"
echo "----------------------------------"
for i in {0..4}
do
  read -p "Enter name $((i+1)): " names[$i]
done
echo "Names in reverse order:"
for ((i=4; i>=0; i--))
do
  echo "${names[$i]}"
done
echo
echo "----------------------------------"
echo "3. Largest and Smallest in array"
echo "----------------------------------"
nums=(12 45 3 22 89 7)
small=${nums[0]}
large=${nums[0]}
for n in "${nums[@]}"
do
  if [ $n -lt $small ]; then
    small=$n
  fi
  if [ $n -gt $large ]; then
    large=$n
  fi
done
echo "Smallest value: $small"
echo "Largest value: $large"
echo
echo "----------------------------------"
echo "4. Merge two arrays"
echo "----------------------------------"
a1=(1 2 3)
a2=(4 5 6)
a3=("${a1[@]}" "${a2[@]}")
echo "Merged array: ${a3[@]}"
echo
echo "----------------------------------"
echo "5. Count even and odd numbers"
echo "----------------------------------"
arr=(10 15 20 35 40)
even=0
odd=0
for n in "${arr[@]}"
do
  if [ $((n % 2)) -eq 0 ]; then
    even=$((even+1))
  else
    odd=$((odd+1))
  fi
done
echo "Even numbers count: $even"
echo "Odd numbers count: $odd"
echo
echo "----------------------------------"
echo "6. Numbers from 1 to 100 (stop at 57)"
echo "----------------------------------"
for i in {1..100}
do
  if [ $i -eq 57 ]; then
    break
  fi
  echo $i
done
echo
echo "----------------------------------"
echo "7. Positive / Negative / Zero"
echo "----------------------------------"
read -p "Enter a number: " num
if [ $num -gt 0 ]; then
  echo "Positive number"
elif [ $num -lt 0 ]; then
  echo "Negative number"
else
  echo "Zero"
fi
echo
echo "----------------------------------"
echo "8. Vowel or Consonant"
echo "----------------------------------"
read -p "Enter a character: " ch
case $ch in
  a|e|i|o|u|A|E|I|O|U)
    echo "Vowel"
    ;;
  *)
    echo "Consonant"
    ;;
esac
echo
echo "----------------------------------"
echo "9. Menu-driven Calculator"
echo "----------------------------------"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read -p "Enter choice: " choice
read -p "Enter first number: " x
read -p "Enter second number: " y
case $choice in
  1) echo "Result: $((x + y))" ;;
  2) echo "Result: $((x - y))" ;;
  3) echo "Result: $((x * y))" ;;
  4) echo "Result: $((x / y))" ;;
  *) echo "Invalid choice" ;;
esac
echo
echo "----------------------------------"
echo "10. Palindrome check"
echo "----------------------------------"
read -p "Enter a string: " str
rev=$(echo "$str" | rev)
if [ "$str" = "$rev" ]; then
  echo "Palindrome"
else
  echo "Not a palindrome"
fi

