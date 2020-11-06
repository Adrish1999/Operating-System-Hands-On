echo "Enter 3 numbers"
read num1
read num2
read num3

for i in $num1 $num2 $num3
do
	for j in $num1 $num2 $num3
	do
		for k in $num1 $num2 $num3
		do
			echo "$i$j$k"
		done
	done
done
