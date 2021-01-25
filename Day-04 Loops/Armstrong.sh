echo "Enter the number"
read n
copy=$n
s=0
b=0
c=10
while [ $n -gt $b ]
do
	r=$((n % c))
	i=$((r * r * r))
	s=$((s + i))
	n=$((n / c))
done
if [ $s == $copy ]
then
	echo "$copy is an Armstrong number"
else
	echo "$copy is not an Armstrong number"
fi







: '
Output


$ sh Armstrong.sh
Enter the number
153
153 is an Armstrong number
'
