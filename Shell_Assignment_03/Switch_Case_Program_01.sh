echo "Enter 1 to merge contents of file 1 and file 2"
echo "Enter 2 to search for a given word in a file"
read choice
case $choice in
	1)	cat file1.txt file2.txt > file3.txt
		echo "Contents of file1.txt: "
		cat file1.txt
		echo "Contents of file2.txt: "
		cat file2.txt
		echo "Contents of the new file: "
		cat file3.txt;;
	2)	echo "Enter the file name in which to search: "
		read filename
		if [ -e $filename ];
		then
			echo "Enter the pattern to search for: "
			read pattern
			grep $pattern $filename
		else
			echo "No such file exists"
		fi;;
	*)	echo "Invalid choice";;
esac
