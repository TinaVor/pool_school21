# #!/bin/bash

read -p "enter the path to the file " path

if [ -f "$path" ]; then
	read -p "enter string to replace " oldstr
	if grep -q "$oldstr" "$path"
   		then read -p "enter new string " newstr
		sed "s/${oldstr}/${newstr}/g" $path |  tee $path >/dev/null
		touch stat.txt
		stat $path | tee stat.txt >/dev/null
		waight=$(cut -d " " -f 8 stat.txt)
		time=$(date +"%Y-%m-%d %H:%M")
		hush=$(shasum -a 256 $path | cut -d ' ' -f 1 )
		echo "$path - $waight - $time - $hush - sha256" >> files.log
		rm stat.txt
	else echo "Error, replacement string does not exist"
	fi
else echo "Error,  wrong file path"
fi
