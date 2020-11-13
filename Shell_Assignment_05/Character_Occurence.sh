echo "Enter a string :"
read str
echo "Enter the character to be searched :"
read ch
len=`echo $str | wc -c`
len=`expr $len - 1`
i=1
count=0
pos=0
while [ $i -le $len ]
do
	character=`echo $str | cut -c $i`
	if [ "$character" = "$ch" ]
	then
		count=`expr $count + 1`
	fi
	i=`expr $i + 1`
done
if [ $count -gt 0 ]
then
	echo "$ch was found in the string $str $count times"
else
	echo "$ch was not found in the string $str"
fi




: '
Output


$ sh Character_Occurence.sh
Enter a string :
Assassin
Enter the character to be searched :
s
s was found in the string Assassin 4 times
'
