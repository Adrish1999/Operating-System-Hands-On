echo "Enter a string :"
read str
echo "Enter the character to be searched :"
read ch
len=`echo $str | wc -c`
len=`expr $len - 1`
i=1
flag=0
pos=0
while [ $i -le $len ]
do
	character=`echo $str | cut -c $i`
	if [ "$character" = "$ch" ]
	then
		flag=1
		pos=$i
	fi
	i=`expr $i + 1`
done
if [ $flag -eq 1 ]
then
	echo "$ch was found in the string $str at position $pos"
else
	echo "$ch was not found in the string $str"
fi
