#!/usr/bin/env python3
import sys,os
if len(sys.argv) < 2:
	print("usage: "+sys.argv[0]+" <ic files to scan>")
	exit(1)
filenames = sys.argv[1:]

for filename in filenames:
	with open(filename, 'r') as file:
		for line in file.readlines():
			line = line.strip()
			if line.startswith('#include'):
				line = line[8:].strip()
				if line[0]=='"':
					stem = line.split('"')[1][:-1]
					os.system('make obj/'+stem+'c')
					os.system('make obj/'+stem+'h')
					os.system('make obj/'+stem+'o')
