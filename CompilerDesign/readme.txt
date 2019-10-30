run the program with:
./a.out < [Input file name]
you can also dump the program output to an output file with:
./a.out < [Input file name] >> [Output file name]
note: 1. If the file is not empty, the output will be concatenated to the end of the file.
      2. the escaped EOL(\n) are printed out as a actual EOL and the normal EOL are ignored.