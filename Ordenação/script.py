import os
import time
from multiprocessing import	 Process

#pra rodar python script.py
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
fileNames = ['heapsort', 'insertionsort', 'mergesort', 'selectionsort', 'quicksort']
entro = [10,50,90]
filesize = [100000, 500000,1000000]
open('time.txt','w').write("")

	

def fun(name, fileName):
	begin = time.time()
	#muda o comando aqui VVVVVV
	execPy = "./%s %s"%(name,fileName)
	#^^^^^^^^^
	import signal, subprocess
	p = subprocess.Popen(args=["./%s"%name, "%s"%fileName])
	begin = time.time()
	end = begin
	while p.poll() == None:
		if (end - begin) > 5*60:
			os.kill(p.pid, signal.SIGTERM)
			
		end = time.time()
	open('time.txt', 'a').write('%s - %s: %.3f ms\n'%(name,fileName,(end-begin)*1000))

for x in entro:
	for i in range(1,6):
		for a in filesize:
			fileName = '''instancias/%d.%d.%d.in'''% (x,a,i) 
			print(fileName)	
			for name in fileNames:
				fun(name, fileName)
				



