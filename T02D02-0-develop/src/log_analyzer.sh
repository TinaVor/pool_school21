# #!/bin/bash

read -p "enter the path to the files.log " path

if [ -f "$path" ]; then
	touch stdout
	kol_str=$(cat $path | wc -l)
	kol_zap=$(sort files.log -u -k1,1)
	hush=$(sort files.log -k1 | cut -d " " -f1 files.log | uniq -d | wc -l)
	echo "$kol_str $kol_zap $hush" >> stdout
else echo "Error,  wrong file path"
fi
