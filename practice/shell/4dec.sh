echo "Question 1"
nums=(1 2 3 4 5 6 7 8 9 10)
echo "length of the array: ${#nums[@]}"
echo "3rd element: ${nums[2]}"
echo "7rd element: ${nums[6]}"
echo 
echo "Question 2"
for ((i=0;i<5;i++))
do 
	read -p "enter a name: " name
	names[i]="${name}"
done
for((i=4;i>=0;i--))
do
	printf "%s" "${names[i]} , "
done
echo
echo "Question 3"
nums=(1 2 3 4 5 6 37 8 9 10)
min=100
max=0
for i in "${nums[@]}"
do
	if ((i>max))
	then
		max=${i}
	fi
	if ((i<min))
	then 
		min=${i}
	fi
done
echo "max no: ${max}"
echo "min no: ${min}"
echo
echo "Question 4"
l1=(2 4 5 5 7 5 4 3)
l2=(3 5 2 5 5 6 7 8)
ll1=${#l1[@]}
ll2=${#l2[@]}
j=0
for((i=ll1;i<ll1+ll2;i++))
do
	l1[i]=${l2[j]}
	j=$((j+1))
done
echo "${l1[@]}"
echo
echo "Question 5"
even=0
odd=0
for((i=0;i<${#nums[@]};i++))
do
    if((i `mod` 2=0))
then 
    even=$((even+1))
    fi 
    if(( i `mod` 2 ~=0))
then 
    odd=$((odd+1))
    fi
done
echo "odd count: ${odd}"
echo "even count: ${even}"


