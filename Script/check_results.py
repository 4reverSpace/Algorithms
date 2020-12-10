import matplotlib.pyplot as plt
name=input("Print name of programm ")
fig = plt.figure()
graph = fig.add_subplot(111)
x = []
y = []
for i in range(0, 100):
	r1 = open("results/output" + str(i).zfill(3) + ".txt", "r")
	r2 = open("true_results/output" + str(i).zfill(3) + ".txt", "r")
			
	input_argv1 = r1.read().splitlines()
	input_argv2 = r2.read().splitlines()
	argv_arr1=[int (i) for i in input_argv1[2].split()]
	argv_arr2=[int (i) for i in input_argv2[0].split()]
	if(len(argv_arr2)-1 != len(argv_arr1)):
		print("Len error in file "+str(i).zfill(3))
		exit();


	for j in range(0, len(argv_arr1)):
		if(argv_arr1[j] != argv_arr2[j]):
			print("Sort error in file" +str(i).zfill(3))
			exit();
	x.append(int(input_argv1[0]))
	y.append(int(input_argv1[1]))
	r1.close()
	r2.close()
print("YOU ARE AWESOME")
graph.plot(x,y)
graph.set_xlim([0,16000])
graph.grid(which='major',color = 'k')
graph.minorticks_on()
graph.grid(which='minor',color = 'gray',linestyle = ':')
graph.set_xlabel('number of elements')
graph.set_ylabel('time(mls)')
graph.set_title(name)
fig.savefig("Graph of "+name+'.jpg')