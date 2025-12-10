#!/bin/bash
echo "-------------------------------"
echo "11. Count word occurrence in sentence"
echo "-------------------------------"
read -p "Enter a sentence: " sentence
read -p "Enter word to search: " word
echo "$sentence" | grep -o "$word" | wc -l
echo
echo "-------------------------------"
echo "12. Extract username from email"
echo "-------------------------------"
read -p "Enter email: " email
echo "Username: ${email%@*}"
echo
echo "-------------------------------"
echo "13. Check file existence"
echo "-------------------------------"
read -p "Enter filename: " file
if [ -f "$file" ]; then
  echo "File exists"
  ls -l "$file"
else
  touch "$file"
  echo "File created"
fi
echo
echo "-------------------------------"
echo "15. Count word occurrence in file"
echo "-------------------------------"
read -p "Enter file name: " f1
read -p "Enter word: " w1
grep -o "$w1" "$f1" | wc -l
echo
echo "-------------------------------"
echo "16. Sort file and save output"
echo "-------------------------------"
read -p "Enter input file: " in
read -p "Enter output file: " out
sort "$in" > "$out"
echo "Sorted data saved"
echo
echo "-------------------------------"
echo "17. Change directory permission"
echo "-------------------------------"
read -p "Enter directory: " dir
chmod 755 "$dir"
echo "Permission changed to 755"
echo
echo "-------------------------------"
echo "18. List executable files"
echo "-------------------------------"
for f in *
do
  if [ -x "$f" ]; then
    echo "$f"
  fi
done
echo
echo "-------------------------------"
echo "19. Student Record Management"
echo "-------------------------------"
while true
do
  echo "1 Add"
  echo "2 Display"
  echo "3 Search"
  echo "4 Highest Marks"
  echo "5 Sort by Name"
  echo "6 Exit"
  read -p "Choice: " ch
  case $ch in
    1)
      read -p "Roll: " r
      read -p "Name: " n
      read -p "Marks: " m
      echo "$r $n $m" >> students.txt
      ;;
    2)
      cat students.txt
      ;;
    3)
      read -p "Enter roll: " r
      grep "^$r " students.txt
      ;;
    4)
      sort -k3 -nr students.txt | head -1
      ;;
    5)
      sort -k2 students.txt
      ;;
    6)
      break
      ;;
    *)
      echo "Invalid choice"
      ;;
  esac
done
echo
echo "-------------------------------"
echo "20. Name Array Operations"
echo "-------------------------------"
read -p "Enter number of names: " n
for ((i=0;i<n;i++))
do
  read -p "Enter name: " names[$i]
done
read -p "Enter name to search: " s
found=0
for ((i=0;i<n;i++))
do
  if [ "${names[$i]}" = "$s" ]; then
    echo "Name found at position $((i+1))"
    found=1
  fi
done

if [ $found -eq 0 ]; then
  echo "Name not found"
fi
echo "Uppercase: ${s^^}"
echo "Lowercase: ${s,,}"
echo "Total names: ${#names[@]}"
