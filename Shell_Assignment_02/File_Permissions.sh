file=$(echo $1)
if [ -e $file ];
then
	echo "File exists"
else
	touch $file
fi
if [ -r $file ];
then
	echo "File is readable"
else
	echo "File is not readable"
fi
ls -l $file

