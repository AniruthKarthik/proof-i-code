echo "grep"
echo "========================================="
grep -l -r "alice" .
echo "========================================="
grep -c -r "alice" sample.txt
echo "========================================="
grep -c -r --exclude=*.sh "echo" .
echo "========================================="
grep -iw -H -o "alice" sample.txt 
echo "========================================="
grep -n -E --color=auto "^A.*$" sample.txt 
echo "========================================="
find . -type f -exec grep "alice" {} +
echo "========================================="
grep -n -E -A 6 --color=auto "^A.*$" sample.txt 
echo "========================================="
echo ""
echo ""
echo "========================================="
echo "find"
echo "========================================="
find . -name "*.txt" 
echo "========================================="
find . -mtime +10 -type f
echo "========================================="
find . -size +3k -ls 
echo "========================================="
find ./.. -user ani -type f -name "*.hs"
echo "========================================="
find . -type d -empty -delete 
echo "========================================="
find ~/Pictures/ ! -name "*.png" | head -n 3
echo "========================================="
find . -mtime -1 -ls
echo "========================================="
stat students.txt
echo "========================================="
file output.sh
echo "========================================="
less students.txt
echo "========================================="
locate output.sh
echo "========================================="
which clangd
echo "========================================="
wc -lcw o.sh
echo "========================================="
sort -run o.sh | head -n 2
echo "========================================="
uniq -c o.sh | head -n 4
echo "========================================="
cut -c 2-3 o.sh | head -n 2
echo "========================================="
ps aux |head -n 5
echo "========================================="
ps aux | grep kitty
echo "========================================="
ps aux --sort=%cpu | head -n 3
echo "========================================="
pgrep -c kitty
echo "========================================="
pgrep -l kitty
echo "========================================="
pgrep -u ani | head -n 3
echo "========================================="
ps aux | grep "^ani" | head -n 3
echo "========================================="
awk '{print $1,$2}' s.txt
echo "========================================="
awk '/Alice/ {print}' s.txt
echo "========================================="
awk '$1 > 90 {print $1}' s.txt | head -n 3
echo "========================================="
echo ""
echo ""
echo "========================================="
echo "awk"
echo "========================================="
awk '{print}' s.txt
echo "========================================="
awk 'NR==2' s.txt
echo "========================================="
awk '$4>80' s.txt
echo "========================================="
awk '/CS/' s.txt
echo "========================================="
awk 'NR>1 {sum+=$4;c++} END {print "avg: %.2f",sum/c}' s.txt
echo "========================================="
awk 'NR>1 {dept[$3]++} END {for(d in dept)print d,dept[d]}' s.txt
echo "========================================="
cat s.txt | sort -nrk 3,3 | head -n 3
echo "========================================="
awk 'NR>1 {val=$1*$4;tot+=val} END {print tot}' s.txt
echo "========================================="
ps aux | awk 'NR>1 {print $2,$3}' | sort -nr | head -n 3
echo ""
echo "========================================="
echo "let us start with shell scripting"
echo "========================================="
read -p "enter your name:" name
greet(){
    echo "hi $1"
}
greet $name
read -p "enter age:" age 
if [ $age -ge 18 ]
then 
    echo "adult" 
else 
    echo "minor kunju" 
fi
for i in {1..4..2}
do 
    echo $i 
done 
echo "========================================="
for ((i=0;i<5;i++))
do 
    echo $i
done
echo "========================================="
i=1
sum=0
while [[ $i -le 5 ]]
do
    echo $i
    ((sum+=i))
    ((i++)) 
done
echo "sum of 1st 5 nos: $sum"
echo "========================================="
arr=(10 20 30 40)
sum=0
# for x in ${arr[@]}
for ((i=0;i<${#arr[@]};i++))
do 
    ((sum+=arr[i]))
done 
echo "sum of array $sum"
echo "========================================="
s="shells ctiodko"
c=0
i=0
while [ $i -lt ${#s} ]
do 
    char=${s:$i:1}
    if [[ $char == [aeiou] ]]
    then 
        ((c++))
    fi
    ((i++))
done
echo "vowel count: $c"
echo "========================================="
result=""
for word in Linux shell scripting is powerful
do
    result="$result $word"
done
echo "$result"
echo "========================================="

while true
do 
    echo "options here"
    read -p "enter ur choice: " c 

    case $c in 
        1)
            echo "logged in users"
            who | awk '{print $1}'|sort | uniq
            ;;
        2)
            echo "top 5 mem process"
            ps aux | sort -nrk 4 | head -5
            ;;
        3)
            read -p "enter dir path: " path 
            ls "$path" | wc -l 
            ;;
        4)
            read -p "enter word to search: " word
            read -p "enter file to search: " file
            grep -i "$word" "$file" | wc -l
            ;;
        5)
            du -h ~ | sort -hr | head -5
            ;;
        6)
            echo "bye"
            break
            ;;
        *)
            echo "invalid"
            ;;
    esac 
    echo 
done
    

