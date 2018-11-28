import os

def welcomeprompt():
	print('Welcome to the lab2 checker. Please make sure the bin-lab-ref file is in the same folder as this file.')
	while True:
		try:
			filename = input('Enter the path to your executable file surrounded by single quotes (i.e. \'./a.out\'): ')
		except:
			print('Did you forget the single quotes? Try again.')
			continue;
		if (os.path.exists(filename)):
			break;
		else:
			print('Invalid path name. Make sure to use ./ if your file is in this directory. Try again.')
	return filename

def checkfunc(f, file): # f = function number
	c = [i.split()[-1] for i in ref[f-1::5]] # c for correct
	m = [i.split()[-1] for i in results[f-1::5]] # m for mine
	correct = True
	file.write('results for function {0}\n'.format(f))
	for i in range(50):
		if c[i] != m[i]:
			correct = False
			file.write('!')
		file.write('%-12s%-12s%-12s\n' % ('x = {0}'.format(i+1), 'ref: {0}'.format(c[i]), 'yours: {0}'.format(m[i])))
	if correct:
		print('all checks passed for f{0}'.format(f))
	else:
		print('some errors in f{0}'.format(f))

filename = welcomeprompt()
results = [0]*250
ref = [0]*250
for i in range(1,51):
	t = os.popen('echo {0} | {1}'.format(i, filename)).read().splitlines()
	r = os.popen('echo {0} | ./bin-lab-ref'.format(i)).read().splitlines()
	for j in range(5):
		line = (i-1)*5+j
		ref[line] = r[j].split()[-1]
		results[line] = t[j].split()[-1]

file = open('testdetails.txt', 'w')
for i in range(1, 6):
	checkfunc(i, file)
file.close()
print('see testdetails.txt for more detailed results')
print('Thank you for using the lab2 checker. If you have any questions, issues, or suggestions, please contact Jacinta at jh5372@nyu.edu')
