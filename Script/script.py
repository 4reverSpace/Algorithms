import subprocess
from subprocess import PIPE

def script():
	name =input("Write file for testing(without c or cpp) ")
	compilation = subprocess.run("g++ -o " + name + ".exe " + name +".cpp")
	if(compilation.returncode != 0):
		print("C++/C compilation error")
		return 0
	for i in range(0, 100):
		file="input/input" + str(i).zfill(3) + ".txt"
		cmd = subprocess.Popen(name + ".exe " + file,  stdout=PIPE)
		cmd_out, cmd_err = cmd.communicate()
		if(cmd_err != None):
			print("The program exited with a nonzero code. Exite code: " + str(cmd_err))

			return 0
		print("Pass ",i)
		to_file = cmd_out.decode("utf-8")
		
		output_txt = open("results/output" + str(i).zfill(3) + ".txt", "w")

		output_txt.write(to_file)
		
		output_txt.close()

	print("Test completed successfully")

script();