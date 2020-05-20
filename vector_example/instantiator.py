#!/usr/bin/env python3
import sys,os
if len(sys.argv) != 4:
	print("usage: "+sys.argv[0]+" <template filename> <substitution string> <output filename>")
	exit(1)
template_filename = sys.argv[1]
arguments_string = sys.argv[2]
output_filename = sys.argv[3]

parameters = template_filename.split('.')[1:-2]
arguments = arguments_string.split('.')

if len(parameters) != len(arguments):
	print("error, template expects "+str(len(parameters))+" parameter(s), but got "+str(len(arguments))+" argument(s)")
	exit(2)

os.system('cp {t} {f}'.format(t=template_filename,f=output_filename))
for parameter,argument in zip(parameters,arguments):
	os.system('sed -i.bak -e "s/{p}/{a}/g" {f}'.format(p=parameter, a=argument, f=output_filename))

#print(prefix)
#print(suffix)
