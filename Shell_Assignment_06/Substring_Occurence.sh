echo "Enter a string :"
read str
echo "Enter the substring to be searched :"
read substr

len_string=`echo $str | wc -c`
len_substring=`echo $substr | wc -c`
len_string=`expr $len_string - 1`
len_substring=`expr $len_substring - 1`


i=1
count=0
start_pos=0
last_pos=0


len_substring=`expr $len_substring - 1`
copy=`expr $len_string - $len_substring`

echo "Substrings generated are :"
while [ $i -le $copy ]
do
	index=`expr $i + $len_substring`
	character=`echo $str | cut -c$i-$index`
	echo "$character"
	if [ "$character" = "$substr" ]
	then
		count=`expr $count + 1`
		start_pos=$i
		last_pos=$index
	fi
	i=`expr $i + 1`
done
if [ $count -gt 0 ]
then
	echo "Substring $substr was found in the string $str from position $start_pos to position $last_pos"
else
	echo "Substring $substr was not found in the string $str"
fi




: '

Output:


$ sh Substring_Occurence.sh
Enter a string :
Pineapple
Enter the substring to be searched :
ppl
Substrings generated are :
Pin
ine
nea
eap
app
ppl
ple
Substring ppl was found in the string Pineapple from position 6 to position 8

'
