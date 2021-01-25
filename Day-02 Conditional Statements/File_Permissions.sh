if [ -e $1 ];
then
	echo "File exists"
else
	touch $1
fi
if [ -r $1 ];
then
	echo "File is readable"
else
	echo "File is not readable"
fi
ls -l $1

