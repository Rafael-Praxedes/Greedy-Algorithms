from os import listdir
import sys
import subprocess

def run():
	
	if len(sys.argv) < 2:
		print("Error! Unspecified method")
		return -1;
	
	for inputFile in listdir("In/"):
		process = subprocess.Popen("./greedy-algorithms" + " " + sys.argv[1] + " " + inputFile, shell = True)
		process.wait()
run()
