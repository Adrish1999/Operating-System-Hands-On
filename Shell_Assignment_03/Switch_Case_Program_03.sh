echo "***** Menu Driven Program *****"
echo "Enter 1 to display number of presently active users"
echo "Enter 2 to display some desired number of files from a desired file"
echo "Enter 3 to update the access time of a desired file to current time"
echo "Enter your choice"
read choice
case $choice in
	1)	echo "Number of presently active users are: "
		who | wc -l;;
	2)	echo "Enter the file name whose contents you want to display"
		read filename
		if [ -e $filename ];
		then
			echo "Enter the number of lines to display: "
			read n
			head -n $n $filename
		else
			echo "No such file exists"
		fi;;
	3)	echo "Enter the filename whose access time you want to change: "
		read filename
		if [ -e $filename ];
		then
			touch -a $filename
		else
			echo "No such file exists"
		fi;;
	*)	echo "Invalid Option";;
esac
