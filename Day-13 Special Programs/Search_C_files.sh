suffix="c"
for i in ~/*/*; 
  do
    extension=`echo "$i" | cut -d'.' -f2`
    if [ -f "$i" ];
    then        
        if [ $extension == $suffix ];
	then
		echo "$i ends with .$suffix"
        else
            	echo "$i does NOT end with .$suffix"
        fi
    fi
  done


: '
Output:

C:/Operating-System-Hands-On/Day-09 Signals/Signal_01.c ends with .c
C:/Operating-System-Hands-On/Day-09 Signals/Signal_02.c ends with .c
C:/Operating-System-Hands-On/Day-09 Signals/Signal_03.c ends with .c
C:/Operating-System-Hands-On/Day-09 Signals/Signal_04.c ends with .c
C:/Operating-System-Hands-On/Day-09 Signals/search.sh does NOT end with .c
.
.
.
.
.
.
.
.
.
C:/C_Programs/P1.c ends with .c
'
