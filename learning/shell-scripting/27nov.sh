echo "printing from 1 to 10"
for ((i=1;i<11;i++))
do 
	echo $i
done
echo "printing from 10 to 1"
echo
for ((i=10;i>0;i--))
do 
	echo $i
done

echo
echo "printing even nos from 2 to 20"

for ((i=2;i<21;i++))
do 
	echo $i
done

echo
echo "sum of n numbers"
read -p "enter N: " n
sum=0
for((i=1;i< $n+1;i++))
do
	sum=$((sum+i))
done 
echo "sum of n numbers is $sum"

echo


echo "multiplication table"
read -p "enter N: " n
for((i=1;i< 11;i++))
do
	echo "$i x $n = $((i*n))"
done 

echo
pass=""
until [ "$pass" == "secret" ]
do 
	read -s -p "enter password: " pass
done

echo
num=1
until (( num == 0 ))
do
    read -p "enter a num: " num
done

echo

echo "avg of n numbers"
read -p "enter no of numbers: " n
sum=0;
for((i=0;i<n;i++))
do
    a=0
    read -p "enter a: " a
    sum=$((sum+a))
done
avg=$((sum/n))

echo "avg is $avg"

echo 

echo "even nos between 2 numbers "
read -p "enter starting no: " a
read -p "enter ending no: " b

for ((i=a; i<=b; i++))
do
    if (( i % 2 == 0 ))
    then
        echo "$i"
    fi
done

echo 
echo "printing a string using for loop"
read -p "enter a string: " str


for ((i=0; i<${#str}; i++))
do
    printf "%s" "${str:$i:1}"
done

echo
