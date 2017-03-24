[code language="bash", collapse=true, title=compileC.sh]
#!/bin/bash

if [[ $# = 1 ]]; then
    code=$1
else 
    echo "Provide program name eg: code.c" 
    exit 1;
fi

#remove .c part
exec=(`ls -1 ${code} |cut -d"." -f1-1`)

#compile
echo "gcc -Wall -Wextra -pedantic -std=c99 ${code} -lm -o ${exec}" 
gcc -Wall -Wextra -pedantic -std=c99 ${code} -lm -o ${exec} 

[/code]

