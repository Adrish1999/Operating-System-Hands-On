result=$(grep -c "$1" /etc/passwd)
if [ $result -eq 1 ]
then
        echo "User exists"
else
        echo "User does not exist"
fi


: '
Output: 

Adrish@test-server:~$ sh Valid_User.sh Adrish
User exists

'
